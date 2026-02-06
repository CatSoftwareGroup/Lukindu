/*
*
*    Lukindu - Unix Simulator
*    useradd.cpp
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


int main(int argc, char const *argv[]){
    string password;
    string user;
    cout << "New Unix Username: ";
    getline(cin, user);
    cout << "New Unix Password: ";
    getline(cin, password);
    string passwordBase64 = base64_encode(password);
    filesystem::path finalFile = "\\rootfs\\usr\\" + user + ".cfg";
    ofstream file(finalFile);
    if (!file.is_open()){
       cout << argv[1] << ": Error on creating user file";
    }
    file << "password=" << passwordBase64;
    file.close();
    if (!filesystem::create_directory("\\rootfs\\Users\\" + user)){
        cout << argv[1] << ": Error on creating user home folder";
    }
    return 0;
}