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
#define YELLOW "\033[33m"   // 文字色を黄色にする
#define GREEN "\033[32m"    //文字色を緑にする

#define DEBUGMODE 0 // デバッグする時 1

unsigned static const char INPUTERROR = 0;  // 不適切な入力
unsigned static const char ARITHMETIC = 1;  // 四則演算のヘルプ
unsigned static const char FUNCTIONAL = 2;  // 関数演算のヘルプ
unsigned static const char MODESELECT = 3;  // モード選択のヘルプ
unsigned static const char ALREADYARI = 4;  // 既に四則演算
unsigned static const char ALREADYFUN = 5;  // 既に関数演算

bool input(double *inputnum)
{
    char inputstr[1024];
    printf("\r>>> \033[K"); // 行中で "">>> "" より後ろの文字列を消去
    scanf("%s", &inputstr[0]);
    for(int i = 0; i <= sizeof(inputstr) / sizeof(char); i++)
    {
        if(!isdigit(inputstr[i]) && (inputstr[i] != '.' || inputstr[i] != '\n' || inputstr[i] != '\0')) // 数字じゃないし、return でもないし、NULL でもない時
            return false;
    }
    inputnum = inputstr
    return true;
}

bool init() // 初期値を設定させる関数。
{
    return true / false;
}

int main(void)
{
    bool initialized = false, arithmeticmode = false;
    long double result;

    while(1)
    {
        while(!initialized)
        {
            initialized = init(arithmeticmode);
        }
        while(1)
        {
            if(arithmeticmode)
            {
                arithmetic(&result);
            }
            else
            {
                functional(&result);
            }
        }
    }
    return 0;
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////// Special Thanks ////////////////////////
/////////////////// # 21C1134 Yuto Yamaguchi ///////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

/// Reference
/// # https://wwws.kobe-c.ac.jp/deguchi/c/string.html   // string 操作系関数
/// # https://marycore.jp/coding/math-nan/  // nan の存在
/// # https://marycore.jp/coding/math-inf/  // inf の存在
/// # http://simd.jugem.jp/?eid=29 // math.h > sin, cos, tan Reference
/// # https://www.sejuku.net/blog/48301 // sleep
/// # https://www.javadrive.jp/cstart/num/index5.html   // Clang string type Escape code
/// # https://www.mm2d.net/main/prog/c/console-02.html  // ANSI Escape code
/// # http://wisdom.sakura.ne.jp/programming/c/c43.html // FILE 構造体の学習
/// # https://tools.ikunaga.net/mojibake/   // 文字化けジェネレータ
/// # https://qiita.com/nogtk_/items/eb09ebc10f55590ba513   // sl command source cord reading
/// # https://www.k-cube.co.jp/wakaba/server/func/isdigit.html  // isdigit

