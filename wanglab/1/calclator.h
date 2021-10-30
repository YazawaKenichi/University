// 64bit OS を想定。-lm 必須。ANSI エスケープシーケンスを使用。
#ifndef CALCLATOR_H // ここはいらない
#define CALCLATOR_H // ここはいらない

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

// ＣＡＳＩ○ っぽいアスキーアート
#define GASHIO0 "  _____          _____  _____ ____  \n"
#define GASHIO1 " / ____|   /\\   / ____||_   _/ __ \\ \n"
#define GASHIO2 "| |  __   /  \\  | (___   | || |  | |\n"
#define GASHIO3 "| | |_ | / /\\ \\  \\___ \\  | || |  | |\n"
#define GASHIO4 "| |__| |/ ____ \\ ____) |_| || |__| |\n"
#define GASHIO5 " \\_____/_/    \\_\\_____/|_____\\____/ \n"

#define CLS "\033[2J"   // 画面を消去する
#define SCROLL "\033[1S"    // 一行分スクロールする
#define HIDDEN "\033[0m" // 次からの文字列を隠す
#define EX "\033[39m"    // 次から文字の装飾をなくす
#define RED "\033[31m"  // 文字色を赤くする
#define GREEN "\033[32m"    //文字色を緑にする
#define YELLOW "\033[33m"   // 文字色を黄色にする
#define CYAN "\033[36m"   // 文字色をシアンにする
#define DELETE "\033[0K"    // 行中右側の文字列を消去

typedef enum Status{COLLECT, AGAIN, ATOF, FTOA, CHANGE} status;
typedef enum HelpTag {INPUTERROR, ARITHMETIC, FUNCTIONAL, MODESELECT, ALREADYARI, ALREADYFUN} helptag;

/*** 文字列出力系関数 ***/
void printred(char *str);
void printyellow(char *str);
void printcyan(char *str);
void printd(char *str);
void printi();
void printl();
bool printh(helptag place);

/*** 電卓機能関数 ***/
bool arith(long double *result, bool *quiet, char *count);
bool funct(long double *result, bool *quiet, char *count);

/*** 補助関数 ***/
bool inputnum(long double *ptr, bool *arithmeticmode);
bool inputfunct(long double *result, bool *arithmeticmode);

/*** シーケンス整理関数 ***/
bool inita(long double *result, bool *arithmeticmode);
bool initf(long double *result, bool *arithmeticmode);
bool init(long double *result, bool *arithmeticmode, char *count);
bool finalize(bool *quiet, bool *end);

#endif  // ここはいらない
