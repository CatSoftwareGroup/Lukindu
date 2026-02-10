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
    cout << "Lukindu Baseutils - rm command" << endl << endl;
    cout << "\"rm filename\" - delete file" << endl;
    cout << "\"rm -r directory name\" - delete directory and all files inside" << endl;
    cout << "\"rm -f filename\" - force delete file" << endl;
    cout << "\"-rf directory or file\" - force delete directory and all files inside" << endl;
    cout << "\"-h\" or \"--help\" - show this dialog" << endl;
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
        } else {

        }
        
        
    }
    
    return 0;
}
