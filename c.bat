@echo off
rem c <filename> <delete|nc>
rem d - delete executable afterwards
rem nc - don't compile, run existing executable
if "%2" == "nc" goto execution
gcc "%1.c" -o "%1.exe"
:execution
"%1.exe"
if "%2" NEQ "d" EXIT /B
del "%1.exe"