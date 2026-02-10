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
        if (argv[1] == "-l"){
        } else if (argv[1] == "-la"){

        } else if (argv[1] == "-a"){

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