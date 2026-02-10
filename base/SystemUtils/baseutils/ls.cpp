/*
*
*    Lukindu - Unix Simulator
*    ls.cpp
*
*/

#include <iostream>
#include <string>
#include <filesystem>

//Future implementation 
namespace fs = std::filesystem;

using namespace std;



void helpdialog(){
    cout << "Lukindu Baseutils - ls command" << endl << endl;
    cout << "\"-a\" - show hidden files" << endl;
    cout << "\"-l\" - long listing" << endl;
    cout << "\"-la\" - long listing with hidden files" << endl;
    cout << "\"-h\" or \"--help\" - show this dialog" << endl;
}

int main(int argc, char const *argv[]){
        string pathtolist;
        string listcommand;
        string fullcommand;
        /*
        * 
        * Alias Implementation 
        * I couldn't implement it with the filesystem library, but I'll try again in the future.
        */
        if (argc < 2) {
            listcommand = "dir /b ";
            pathtolist = ".";
            fullcommand = listcommand + pathtolist;
            system(fullcommand.c_str());
        } else {
            if (strcmp(argv[1], "-l") == 0){
                listcommand = "dir";
                if (argc < 3){
                    pathtolist = ".";
                } else {
                    pathtolist = argv[2];
                }
                fullcommand = listcommand + " " + pathtolist;
                system(fullcommand.c_str());
            } else if (strcmp(argv[1], "-la") == 0){
                listcommand = "dir /a";
                if (argc < 3){
                    pathtolist = ".";
                } else {
                    pathtolist = argv[2];
                }
                fullcommand = listcommand + " " + pathtolist;
                system(fullcommand.c_str());
            } else if (strcmp(argv[1], "-a") == 0){
                listcommand = "dir /a /b";
                if (argc < 3){
                    pathtolist = ".";
                } else {
                    pathtolist = argv[2];
                }
                fullcommand = listcommand + " " + pathtolist;
                system(fullcommand.c_str());
            } else if (strcmp(argv[1], "-h") == 0){
                helpdialog();
            } else if (strcmp(argv[1], "--help") == 0){
                helpdialog();
            } else {
                listcommand = "dir /b ";
                pathtolist = argv[1];
                fullcommand = listcommand + " " + pathtolist;
                system(fullcommand.c_str());
            }
        }

    
}