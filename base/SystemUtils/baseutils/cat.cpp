/*
*
*    Lukindu - Unix Simulator
*    cat.cpp
*
*/

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

string text;

int main(int argc, char const *argv[]){

    if (argc < 2) {
        cout << argv[0] << ": Usage '" << argv[0] << " filename'";
    } else {
        ifstream input({argv[1]});

        while (getline (input, text)) {
            cout << text << endl;
        }
    }
    return 0;
}