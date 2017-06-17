@echo off
:: Option
set debug=1
:: Files
set out=eight-figure_puzzles.exe
set main_input=unit_testing.c
set base_input=search\bfs.c type\book.c type\state.c type\list.c
:: Compiler Option
set cc=gcc
set std=-std=c99

:: Compiling
echo Building...
%cc% %std% -o %out% %main_input% %base_input%

:: Executing
if debug==0 (
  cls
)
%out%
pause>nul&exit