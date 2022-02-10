@echo off
Setlocal EnableDelayedExpansion
rem This is so the dynamic variable "test" and "results" work
(set nl=^

)
rem Newline workaround

rem Usage: c <filename> <d|nc|n> <t>
rem d - delete executable afterwards
rem nc - don't compile, run existing executable
rem n - no compiling option
rem t - Test with appropriate test file

if "%2" == "nc" goto execution
gcc -Wall "%1.c" -o "%1.exe"
:execution
if "%3" == "t" goto testing

"%1.exe"
goto deletion

:testing

rem Test case file formatting
rem <input data
rem ....
rem ....>
rem result
rem <expected output
rem ......
rem .....>
rem case
rem <input data for case 2>...
rem 
rem ... and so on. Save this textfile with the same name as c file but with file extension .tc
rem Supports multiple cases, just concatonate them in the file as shown above

rem Some declarations
set allpass=true
copy NUL test > NUL
copy NUL res > NUL
set mod=test
set /A n=1

for /F "tokens=*" %%L in (%1.tc) do (
    if "%%L" == "case" (
        echo Running test !n!:
        echo Input:
        type test
        echo.
        (type test) | "%1.exe" > results
        type results
        echo.
        echo Expected output:
        type res

        fc /w res results >nul&&echo Passed||(echo Failed & set allpass=%n%)
        echo ---------------------------------------

        set /A n+=1

        rem Clear test case vars
        copy NUL test > NUL
        copy NUL res > NUL
        set mod=test
    ) else (
        if "%%L" == "result" (
            set mod=res
        ) else (
            if "!mod!" == "test" (
                (echo %%L^
                ) >> test
            ) else (
                rem Results section
                (echo %%L^
                ) >> res
            )
        )
    )
)

if "%allpass%" == "true" (
    echo All cases passed
) else (
    echo Case %allpass% failed
)

del test
del results
del res

:deletion
if "%2" == "d" del "%1.exe"
