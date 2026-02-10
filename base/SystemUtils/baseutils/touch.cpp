/*
*
*    Lukindu - Unix Simulator
*    touch.cpp
*
*/
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;


void helpdialog(){
    cout << "Lukindu Baseutils - touch command" << endl << endl;
    cout << "touch [filename] - create a new empty file";
}


int main(int argc, char const *argv[]) {
    fstream fs;
    if (argc < 2){
        cout << "Error: No input file specified. try \"-h\" to help";
    } else {
        if (strcmp(argv[1], "-h") == 0){
            helpdialog();
        } else if (strcmp(argv[1], "--help") == 0){
            helpdialog();
        } else {
            string filename = argv[1];
            fs.open(argv[1], ios::out);
            fs.close();

        }   
    }
    return 0;
}
