@echo off
echo Last Login %date% %time%
if %usrinput% equ root goto rootprompt
goto usrprompt

:usrprompt
prompt %systemhostname%$$ 
set "PATH=%PATH%;%~d0\rootfs\bin;%PATH%"
cmd /k
goto end



:rootprompt
prompt %systemhostname%# 
set "PATH=%PATH%;%~d0\rootfs\bin;%PATH%"
cmd /k
goto end


:end