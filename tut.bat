@echo off
rem Usage - tut <filename> <weeknumber> [<d>]
set sn=1008009744

robocopy ./ "C:/Users/Faraz Malik/Desktop" "%1.c"
ren "C:\Users\Faraz Malik\Desktop\%1.c" "Week%2_Tutorial_%sn%.c"
echo Submission created
if "%3" == "d" (
    pause
    del "C:\Users\Faraz Malik\Desktop\Week%2_Tutorial_%sn%.c"
    echo File deleted
)