@echo off
:: Files
set out=eight-figure_puzzles.exe
set main_input=unit_testing.c
set base_input=search\bfs.c type\book.c type\state.c
:: Option
set std=-std=c99

:: Compiling
echo Building...
gcc %std% -o %out% %main_input% %base_input%

:: Executing
cls
%out%
pause>nul&exit