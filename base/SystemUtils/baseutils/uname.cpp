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

void getProcessorName()
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

void helpdialog(){
    cout << "Lukindu Baseutils - uname command" << endl << endl << endl;
    cout << "Print certain system information. With no OPTION, same as -s." << endl;
    cout << "-a, --all" << endl;
    cout << "     print all information, in the following order, except omit -p and -i if unknown: " << endl;
    cout << "-s, --kernel-name" << endl;
    cout << "     print the kernel name" << endl;
    cout << "-n, --nodename" << endl;
    cout << "     print the network node hostname " << endl;
    cout << "-r, --kernel-release" << endl;
    cout << "     print the kernel release" << endl;
    cout << "-v, --kernel-version" << endl;
    cout << "     print the kernel version" << endl;
    cout << "-m, --machine" << endl;
    cout << "     print the machine hardware name" << endl;
    cout << "-p, --processor" << endl;
    cout << "     print the processor type or \"unknown\" " << endl;
    cout << "-i, --hardware-platform" << endl;
    cout << "     print the hardware platform or \"unknown\"" << endl;
    cout << "-o, --operating-system" << endl;
    cout << "     print the operating system " << endl;
    cout << "--help" << endl;
    cout << "     display this help and exit" << endl;
}

int main(int argc, char const *argv[]){
    if (argc < 2){
        cout << getKernelName();
    } else if (strcmp(argv[1], "--help") == 0){
        helpdialog();
    } else if (strcmp(argv[1], "-h") == 0){
        helpdialog();
    } else if (strcmp(argv[1], "-a") == 0){
        cout << getKernelVersion() << " " << getKernelBuildDate() << " " << getKernelArch() << " " << getHostname() << " " << getSystemName(); 
    } else if (strcmp(argv[1], "-s") == 0){
        cout << getKernelName();
    } else if (strcmp(argv[1], "-r") == 0){
        cout << getKernelBuildDate();
    } else if (strcmp(argv[1], "-v") == 0){
        cout << getKernelVersion();
    } else if (strcmp(argv[1], "-m") == 0){
        cout << getKernelArch();
    } else if (strcmp(argv[1], "-i") == 0){
        cout << "unknown";
    } else if (strcmp(argv[1], "-o") == 0){
        cout << getSystemName();
    } else if (strcmp(argv[1], "--all") == 0){
        cout << getKernelVersion() << " " << getKernelBuildDate() << " " << getKernelArch() << " " << getHostname() << " " << getSystemName();
    } else if (strcmp(argv[1], "--kernel-name") == 0){
        cout << getKernelName();
    } else if (strcmp(argv[1], "--nodename") == 0){
        cout << getHostname();
    } else if (strcmp(argv[1], "--kernel-release") == 0){
        cout << getKernelBuildDate();
    } else if (strcmp(argv[1], "--kernel-version") == 0){
        cout << getKernelVersion();
    } else if (strcmp(argv[1], "--machine") == 0){
        cout << getKernelArch();
    } else if (strcmp(argv[1], "--processor") == 0){
        getProcessorName();
    } else if (strcmp(argv[1], "--hardware-platform") == 0){
        cout << "unknown";
    } else if (strcmp(argv[1], "--operating-system") == 0){
        cout << getSystemName();
    } else if (strcmp(argv[1], "-n") == 0){
        cout << getHostname();
    } else if (strcmp(argv[1], "-p") == 0){
        getProcessorName();
    } else {
        cout <<"Error: invalid argument try \"--help\" to more information";
    }
    
    return 0;
}
