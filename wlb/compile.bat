@echo off
setlocal

set STR="calclatorbuckup"

gcc %STR%.c -o %STR%.exe -lm

%STR%.exe
