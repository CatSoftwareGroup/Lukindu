#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;

bool verifyLogin(const string& username,const string& password,const string& filename);
string b64_encode(string input);
string b64_decode(string input);


bool verifyLogin(const string& username,const string& password,const string& filename){
    ifstream inFile(filename);

    if (!inFile){
        cout << "LoginService: Failed to open Users Database";
        return false;
    }

    string line;
    string record = username + "," + password;

    while (std::getline(inFile,line)){
        if(line == record){
            return true;
        }
    }
    return false;   
}

string b64_encode(string input){
    string out; //This will hold the resulting Base64 encoded string.
    int val = 0, valb = -6; //The Variable "val" is used to accumulate the bits of the input characters.
    //Variable "valb" keeps track of how many bits are currently in "val".
    for (char c : input){
        /*
        * For each character "c" in the input string, it shifts val left by 8 bits and adds the ASCII value of "c".
        * It then increases "valb" by 8 (the number of bits added).
        * While there are at least 6 bits in "val", it extracts the top 6 bits and appends the corresponding Base64 character to "out".
        */
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0){
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb -= 6;
        }
    }
    if (valb>-6) {
        //If there are still bits left in "val" that haven't been encoded (i.e., "valb" is greater than -6), it processes those bits and appends the corresponding Base64 character.
        out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    }
    while (out.size()%4){
        out.push_back('=');
    } //Base64 encoding requires the output to be a multiple of 4 characters. If the encoded string is not, it appends "=" characters as padding.
    return out;
    
    
}

string b64_decode(string input){
    string out; //out: This will hold the resulting decoded string.
    vector<int> T(256,-1);//T: A lookup table initialized to -1 for all 256 ASCII characters.
    for (int i = 0; i < 64; i++){
        T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
    }
    
    int val=0, valb=-8;
    for (char c : input) {//For each character "c" in the input string, it checks if "c" is a valid Base64 character using the lookup table "T". 
        if (T[c] == -1){//If valid, it shifts "val" left by 6 bits and adds the value from T[c].
            break;
        }
        val = (val << 6) + T[c]; 
        valb += 6;
        if (valb >= 0){//If there are at least 8 bits in "val", it extracts the top 8 bits and appends the corresponding character to "out".
            out.push_back(char((val>>valb)&0xFF));
            valb -= 8;
        }
    }
    return out;
    
}

string getHostname(){
    ifstream hostFile("\\rootfs\\etc\\hostname.cfg");
    string value;
    getline(hostFile,value);
    return value;
}


int main(int argc, char const *argv[]){
    
}