/*
*
*    Lukindu - Unix Simulator
*    ls.cpp
*
*/

#include <iostream>
#include <string>
#include <filesystem>


namespace fs = std::filesystem;
using namespace std;



void helpdialog(){

}

int main(int argc, char const *argv[]){
        string pathtolist;
        string listcommand;
        string fullcommand;
        if (strcmp(argv[1], "-l") == 0){
            listcommand = "dir";
            if (argc < 3){
                pathtolist = ".";
            } else {
                pathtolist = argv[2];
            }
            fullcommand = listcommand + " " + pathtolist;
            system(fullcommand.c_str());
        } else if (argv[1] == "-la"){
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
        } else if (argv[1] == "-h"){
            helpdialog();
        } else if (argv[1] == "--help"){
            helpdialog();
        } else {
            listcommand = "dir /b ";
            pathtolist = ".";
            fullcommand = listcommand + pathtolist;
            system(fullcommand.c_str());
        }
    
}