/*
*
*    Lukindu - Unix Simulator
*    pwd.cpp
*
*/

#include <iostream>


using namespace std;
/*
* I couldn't use getenv to retrieve the %cd% variable from Windows.
*/
int main(){
    system("echo %cd%");
    return 0;
}