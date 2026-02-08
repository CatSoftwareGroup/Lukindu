/*
*
*    Lukindu - Unix Simulator
*    passwd.cpp
*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;


static const string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";


string base64_encode(const string& input)
{
    string output;
    int val = 0, valb = -6;

    for (unsigned char c : input)
    {
        val = (val << 8) + c;
        valb += 8;

        while (valb >= 0)
        {
            output.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    if (valb > -6)
        output.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);

    while (output.size() % 4)
        output.push_back('=');

    return output;
}

void helplist(string progname){
    cout << progname << ": Usage: userdel USER";
}

int main(int argc, char const *argv[]){
    string password;
    if (argc < 2){
        helplist(argv[0]);
    } else {
        string user = argv[1];
        try {
            cout << "New Unix Password: ";
            getline(cin, password);
            string passwordBase64 = base64_encode(password);
            filesystem::remove("\\rootfs\\usr\\" + user + ".cfg");
            filesystem::path finalFile = "\\rootfs\\usr\\" + user + ".cfg";
            ofstream file(finalFile);
            if (!file.is_open()){
            cout << argv[1] << ": Error on accessing user file";
            }
            file << "password=" << passwordBase64;
            file.close();
        }
        catch(const std::filesystem::filesystem_error& err) {
            cout << argv[0] << ": Failed to change password: " << err.what() << '\n';
        }
    }
    
    

    return 0;
}