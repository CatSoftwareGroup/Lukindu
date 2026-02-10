/*
*
*    Lukindu - Unix Simulator
*    su.cpp
*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <ctime>
using namespace std;
namespace fs = std::filesystem;


static const string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

string base64_encode(const string &in) {
    string out;
    int val = 0, valb = -6;

    for (unsigned char c : in) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    if (valb > -6)
        out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);

    while (out.size() % 4)
        out.push_back('=');

    return out;
}

string getHostname(){
    ifstream hostFile("\\rootfs\\etc\\hostname.cfg");
    string value;
    getline(hostFile,value);
    return value;
}


void setVariable(std::string name, std::string value) {
    _putenv_s(name.c_str(), value.c_str());
}

bool userExists(string user) {
    string path = "\\rootfs\\usr\\" + user + ".cfg";
    return fs::exists(path);
}

void loginUser(string user) {
    setVariable("systemhostname",getHostname());
    string password;
    string LUKINDU_LOGGED_USER = getenv("usrinput");
    if (LUKINDU_LOGGED_USER == user){
        cout << "you are already logged in " << user; 
    } else {
        if (!userExists(user)) {
            cout << "User does not exist";
            return;
        }

        cout << "Password: ";
        cin >> password;

        ifstream file("\\rootfs\\usr\\" + user + ".cfg");
        string line;
        getline(file, line);
        file.close();

        string base64SavedPassword = line.substr(line.find("=") + 1);
        string base64TypedPassword = base64_encode(password);

        if (base64TypedPassword == base64SavedPassword) {
            setVariable("usrinput", user);
            setVariable("HOME","\\rootfs\\Users\\" + user);
            system("\\rootfs\\bin\\shell.cmd");
        } else {
            cout << "password incorrect\n";
        }
    }
}

int main(int argc, char const *argv[])
{
    if (argc < 2){
        loginUser("root");
    } else {
        loginUser(argv[1]);
    }
    
    return 0;
}