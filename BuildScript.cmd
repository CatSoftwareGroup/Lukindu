@echo off
rem Compiler configuration
set CC=clang -v
set CXX=clang++ -v
echo Building Lukindu
mkdir build
%CC% kernel\kernel.c -o build\mach_kernel.exe
mkdir build\dev
mkdir build\bin
mkdir build\usr
mkdir build\System
mkdir build\System\Lukit
%CC% base\SystemServices\Lukit\lukit.c -o build\System\Lukit\Lukit.exe
mkdir build\System\Services
mkdir build\System\sysinfo
copy base\sysinfo\*.plist build\System\sysinfo
echo UFS Filesystem > build\dev\root
echo Color Display > build\dev\display
echo USB Device > build\dev\usb
copy base\SystemServices\Lukit\initrc.cmd build\System\Services
copy base\SystemServices\DriverLoader\drvloader.cmd build\System
copy base\SystemServices\Lukit\su_shell.cmd build\System\Lukit
mkdir build\Users\root
mkdir build\dev
mkdir build\etc
mkdir build\etc\packages
mkdir build\etc\package_cache
mkdir build\usr
mkdir build\bin
mkdir build\boot
mkdir build\boot\drivers
%CXX% base\SystemServices\LoginService\LoginService.cpp -o build\System\Services\loginService.exe
%CXX% base\SystemUtils\userutils\useradd.cpp -o build\bin\useradd.exe
%CXX% base\SystemUtils\userutils\userdel.cpp -o build\bin\userdel.exe
%CXX% base\SystemUtils\userutils\passwd.cpp -o build\bin\passwd.exe
%CXX% base\SystemUtils\baseutils\cat.cpp -o buildl\bin\cat.exe
%CXX% base\SystemUtils\baseutils\iam.cpp -o buildl\bin\iam.exe
%CXX% base\SystemUtils\baseutils\ls.cpp -o buildl\bin\ls.exe
%CXX% base\SystemUtils\baseutils\pwd.cpp -o buildl\bin\pwd.exe
%CXX% base\SystemUtils\baseutils\rm.cpp -o buildl\bin\rm.exe
%CXX% base\SystemUtils\baseutils\su.cpp -o buildl\bin\su.exe
%CXX% base\SystemUtils\baseutils\touch.cpp -o buildl\bin\touch.exe
%CXX% base\SystemUtils\baseutils\poweroff.cpp -o buildl\bin\poweroff.exe
%CXX% base\SystemUtils\baseutils\uname.cpp -o buildl\bin\uname.exe
%CC% base\drivers\LukinduSATAController.c -o build\boot\drivers\LukinduSATAController.exe -lsetupapi
%CC% base\drivers\LukinduDisplayDriver.c -o build\boot\drivers\LukinduDisplayDriver.exe
%CC% base\drivers\LukinduUSBDriver.c -o build\boot\drivers\LukinduUSBDriver.exe
copy base\SystemUtils\baseutils\shell.cmd.cmd build\bin\shell.cmd
copy base\SystemUtils\pkgutil\pkgutil.cmd build\bin\pkgutil.cmd
copy base\SystemUtils\pkgutil\unzip.exe build\bin\unzip.exe
copy base\SystemUtils\pkgutil\zip.exe build\bin\zip.exe
copy base\SystemUtils\pkgutil\bzip2.dll build\bin\bzip2.dll
echo Welcome to Lukindu > build\etc\motd.txt
echo localhost> build\etc\hostname.cfg
echo password=dG9vcg==> build\usr\root.cfg
echo Build %date% %time%> build\System\sysinfo\kernelbuild.plist
set /p kernelversion=<"build\System\sysinfo\kernelversion.plist"
set /p kernelrelease=<"build\System\sysinfo\kernelrelease.plist"
set /p kernelbuild=<"build\System\sysinfo\kernelbuild.plist"
set /p kernelversionmin=<"build\System\sysinfo\kernelversionmin.plist"
echo %kernelversion% %kernelbuild% %kernelrelease% > build\etc\versioninfo.sym
echo DriverKit %kernelversionmin% >> build\etc\versioninfo.sym
echo Lukindu Standalone> build\System\sysinfo\osversion.plist
goto end




:end