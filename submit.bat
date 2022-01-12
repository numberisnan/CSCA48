@echo off
set sn=1008009744

robocopy ./ "C:/Users/Faraz Malik/Desktop" "%1.c"
ren "C:\Users\Faraz Malik\Desktop\%1.c" "%1_%sn%.c"
echo Submission created
if "%2" == "d" (
    pause
    del "C:\Users\Faraz Malik\Desktop\%1_%sn%.c"
    echo File deleted
)