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
    string pathToList;
    if (argc < 2){
        pathToList = ".";
    } else {
        if (argv[1] == "-l"){
            if (argc < 3){

            }
        } else if (argv[1] == "-la"){
            if (argc < 3){

            }
        } else if (argv[1] == "-a"){
            if (argc < 3){

            }
        } else if (argv[1] == "-h"){
            helpdialog();
        } else if (argv[1] == "--help"){
            helpdialog();
        } else {
            
        }
        
    }
    
}