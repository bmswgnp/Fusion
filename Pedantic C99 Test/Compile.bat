@echo off

REM Add GCC compiler to system path. See: http://www.mingw.org/
set path=C:\MinGW\bin;%PATH%

REM Run GCC compiler
gcc -Wall -pedantic -std=c99 ..\Fusion\FusionAhrs.c ..\Fusion\\FusionBias.c ..\Fusion\\FusionCompass.c Main.c -o Main

REM Pause to view warnings or errors
pause

REM Run compiled executable
Main

REM Pause to view output
pause
