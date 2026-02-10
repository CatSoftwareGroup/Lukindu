/*
*
*    Lukindu - Unix Simulator
*    rm.cpp
*
*/

#include <iostream>
#include <filesystem>
#include <fstream>


using namespace std;
namespace fs = std::filesystem;


void helpdialog(){

}


int main(int argc, char const *argv[])
{
    if (argc < 2){
        cout << "Error: No file specified \"rm -h\" to help";
    } else {
        if (strcmp(argv[1], "--help") == 0){
            helpdialog();
        } else if (strcmp(argv[1], "-h") == 0){
            helpdialog();
        }
        
        
    }
    
    return 0;
}
