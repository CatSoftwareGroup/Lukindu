/*
*
*    Lukindu - Unix Simulator
*    uname.cpp
*
*/

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <intrin.h>

using namespace std;

string getHostname(){
    ifstream hostFile("\\rootfs\\etc\\hostname.cfg");
    string value;
    getline(hostFile,value);
    return value;
}

string getKernelVersion(){
    ifstream kernVersion("\\rootfs\\System\\sysinfo\\kernelversion.plist");
    string value;
    getline(kernVersion,value);
    return value;
}

string getKernelBuildDate(){
    ifstream kernBuildDate("\\rootfs\\System\\sysinfo\\kernelbuild.plist");
    string value;
    getline(kernBuildDate,value);
    return value;
}

string getKernelArch(){
    ifstream kernArch("\\rootfs\\System\\sysinfo\\kernelrelease.plist");
    string value;
    getline(kernArch,value);
    return value;
}

string getSystemName(){
    ifstream sysName("\\rootfs\\System\\sysinfo\\osversion.plist");
    string value;
    getline(sysName,value);
    return value;
}

void GetProcessorName()
{
	int CPUInfo[4] = {-1};
	char CPUBrandString[0x40];	
	__cpuid(CPUInfo, 0x80000000);
	unsigned int nExIds = CPUInfo[0];

	memset(CPUBrandString, 0, sizeof(CPUBrandString));

	// Get the information associated with each extended ID.
	for (int i=0x80000000; i<=nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		// Interpret CPU brand string.
		if  (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if  (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if  (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}
    cout << CPUBrandString;
}

string getKernelName(){
    return "Lukindu";
}

int main(int argc, char const *argv[]){
    
    return 0;
}
