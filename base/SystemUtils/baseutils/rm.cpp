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


void deleteFile(string file){
    try {
        if (filesystem::is_directory(file)){
            cerr << "Error on deleting file: Is Directory";
        } else {
            fs::remove(file);
        }
        

    }
    catch(const fs::filesystem_error& err) {
        cerr << "Error on deleting file: " << err.what();
    }
    
}

void deleteAllFiles(string file){
    try {
        fs::remove_all(file);   
    }
    catch(const fs::filesystem_error& err){
        cerr << "Error on deleting file: " << err.what();
    }
    
}


int main(int argc, char const *argv[]) {
    if (argc < 2){
        cout << "Error: No file specified \"rm -h\" to help";
    } else {
        if (strcmp(argv[1], "--help") == 0){
            helpdialog();
        } else if (strcmp(argv[1], "-h") == 0){
            helpdialog();
        } else if (strcmp(argv[1], "-r") == 0){
            deleteAllFiles(argv[2]);
        } else if (strcmp(argv[1], "-f") == 0){
            deleteFile(argv[2]);
        } else if (strcmp(argv[1], "-rf") == 0){
            deleteAllFiles(argv[2]);
        } else {
            deleteFile(argv[1]);
        }
           
    }
    
    return 0; 
}
    
    
