#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <io.h>
#include <ctime>


using namespace std;

bool verifyLogin(const string& username,const string& password,const string& filename);
string b64_encode(string input);
void setVariable(std::wstring name, std::wstring value);
string getHostname();
void setVariable(std::string name, std::string value);

bool verifyLogin(const string& username,const string& password,const string& filename){
    ifstream inFile(filename);

    if (!inFile){
        cout << "LoginService: Failed to open Users Database";
        return false;
    }

    string line;
    string record = username + "," + password;

    while (std::getline(inFile,line)){
        if(line == record){
            return true;
        }
    }
    return false;   
}

string b64_encode(string input){
    string out; //This will hold the resulting Base64 encoded string.
    int val = 0, valb = -6; //The Variable "val" is used to accumulate the bits of the input characters.
    //Variable "valb" keeps track of how many bits are currently in "val".
    for (char c : input){
        /*
        * For each character "c" in the input string, it shifts val left by 8 bits and adds the ASCII value of "c".
        * It then increases "valb" by 8 (the number of bits added).
        * While there are at least 6 bits in "val", it extracts the top 6 bits and appends the corresponding Base64 character to "out".
        */
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0){
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb -= 6;
        }
    }
    if (valb>-6) {
        //If there are still bits left in "val" that haven't been encoded (i.e., "valb" is greater than -6), it processes those bits and appends the corresponding Base64 character.
        out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    }
    while (out.size()%4){
        out.push_back('=');
    } //Base64 encoding requires the output to be a multiple of 4 characters. If the encoded string is not, it appends "=" characters as padding.
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

int main(int argc, char const *argv[]){
    cout << getHostname() << "  Login" << endl << endl;
    setVariable("systemhostname",getHostname());
    string inputLogin;
    string inputPassword;
    string encodedPassword;
    bool loginOK = false;
    while (true) {
        while (loginOK = false) {
            cout << endl << "login: ";
            cin >> inputLogin;
            cout << endl << "Password: ";
            cin >> inputPassword;
            encodedPassword = b64_encode(inputPassword);
            if (verifyLogin(inputLogin,encodedPassword,"\\rootfs\\etc\\login.access"),0){
                loginOK = true;
            } else {
                cout << endl << "Login or password incorrect";
            }
        }
        time_t timestamp;
        time(&timestamp);
        cout << endl << "Last Login: ";
        cout << ctime(&timestamp);
        cout << endl;
        ifstream file("\\rootfs\\etc\\motd.txt");
        string content;
        setVariable("usrinput", inputLogin);
        setVariable("HOME","\\rootfs\\Users\\" + inputLogin);
        while(file >> content) {
            cout << content << ' ';
        }     
        system("\\rootfs\\bin\\shell.cmd");
        loginOK = false;
    }
}