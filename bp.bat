@echo off
rem Usage: boilerplate <boilerplate_name> <filename>
rem No specific boilerplate: boilerplate <filename>
if "%2" == "" (
    robocopy ./boilerplates ./ basic.c /nfl /ndl /njs /ns /njh /nc
    ren basic.c "%1.c"
) else (
    robocopy ./boilerplates/ ./ "%1.c" /nfl /ndl /njs /ns /njh /nc
    ren "%1.c" "%2.c"
)

rem Create test case file
echo. > "%1.tc"