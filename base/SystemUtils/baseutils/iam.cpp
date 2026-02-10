/*
*
*    Lukindu - Unix Simulator
*    iam.cpp
*
*/


#include <iostream>
#include <string>


using namespace std;


int main(int argc, char const *argv[])
{
    string LUKINDU_LOGGED_USER = getenv("usrinput");
    cout << LUKINDU_LOGGED_USER;    
    return 0;
}
