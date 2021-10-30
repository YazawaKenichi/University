@echo off
setlocal

gcc %calclatorbuckup%.c -o %calclatorbuckup%.exe -lm

%calclatorbuckup%.exe
