/*
*
*    Lukindu - Unix Simulator
*    userdel.cpp
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;


void helplist(string progname){
    cout << progname << ": Usage: userdel USER";
}

int main(int argc, char const *argv[]){
    if (argc < 2){
        helplist(argv[0]);
    } else {
        string user = argv[1];
        try {
            if(!filesystem::remove("\\rootfs\\usr\\" + user)){
                cout << argv[0] << ": No user to delete";
            }
        }
        catch(const std::filesystem::filesystem_error& err) {
            cout << argv[0] << ": Failed to delete user: " << err.what() << '\n';
        }
    }
    return 0;
}