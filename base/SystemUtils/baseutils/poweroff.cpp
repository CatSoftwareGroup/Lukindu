/*
*
*    Lukindu - Unix Simulator
*    poweroff.cpp
*
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <io.h>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "SYSTEM SHUTDOWN NOW" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));//Sleep 3 seconds
    if(_access("\\rootfs\\System\\Library\\shutdownScript.cmd", 0) == 0){//Check if file exists
        system("\\rootfs\\System\\Library\\shutdownScript.cmd");
    } else {
        system("TASKKILL /im cmd.exe");
        system("taskkill /im mach_kernel.exe");
    }
    return 0;
}

