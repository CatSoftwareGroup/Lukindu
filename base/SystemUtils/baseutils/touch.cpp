/*
*
*    Lukindu - Unix Simulator
*    touch.cpp
*
*/
#include <iostream>
#include <filesystem>


using namespace std;
namespace fs = std::filesystem;


void helpdialog(){
    cout << "Lukindu Baseutils - touch command" << endl << endl;
    cout << "touch [filename] - create a new empty file";
}


int main(int argc, char const *argv[]) {
    if (argc < 2){
        cout << "Error: No input file specified. try \"-h\" to help";
    } else {
        if (strcmp(argv[1], "-h")){
            helpdialog();
        } else if (strcmp(argv[1], "--help")){
            helpdialog();
        }
        
    }
    
    return 0;
}
