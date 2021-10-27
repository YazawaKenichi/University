// ANSI エスケープシーケンスを使用。

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
#define DELETE "\033[0K"    // 行中右側を消去
#define HIDDEN "\033[0m" // 次からの文字列を隠す
#define EX "\033[39m"    // 次から文字の装飾をなくす
#define RED "\033[31m"  // 文字色を赤くする
#define YELLOW "\033[33m"   // 文字色を黄色にする
#define GREEN "\033[32m"    // 文字色を緑にする
#define CYAN "\033[36m"     // 文字色をシアンにする

#define DEBUGMODE 0 // デバッグする時 1

typedef enum Help {ARITHMETIC, FUNCTIONAL} help;

bool initialized;

/*** 文字列出力系関数 ***/
void printred(char *str)    // 赤文字で表示するだけの関数   // プログラム上で想定されていない処理エラー用
{
    printf(RED);
    printf("\nWARNING!\n");
    printf("%s", str);
    printf(EX);
}

void printyellow(char *str)    // 黄文字で表示するだけの関数    // ユーザの入力ミス用
{
    printf(YELLOW);
    printf("\nINPUTERROR ;)\n");
    printf("%s", str);
    printf(EX);
}

void printcyan(char *str)
{
    printf(CYAN);
    printf("%s", str);
    printf(EX);
}

void printd(char *str)  // 緑文字で表示するだけの関数   // debug 時の出力用
{
    printf(GREEN);
    printf("%s", str);
    printf(EX);
}

void printi()   // 入力を促す矢印を表示する関数
{
    printf("\r>>> ");
    printf(DELETE);
}

void printl()   // ロゴの出力
{
    printf(CLS);
    printf(GASHIO0);
    printf(GASHIO1);
    printf(GASHIO2);
    printf(GASHIO3);
    printf(GASHIO4);
    printf(GASHIO5);
    sleep(3);
    printf(CLS);
}

void printh(help place)
{
    switch(place)
    {
        case ARITHMETIC:
            printf("四則演算のヘルプ\n");
            break;
        case FUNCTIONAL:
            printf("関数演算のヘルプ\n");
            break;
        default:
            break;
    }
}

void printk(int i)
{
    printf("三元連立方程式を解きます。\n\n");
    printf("ax + by + cz = k で表される数式において、\n");
    char str[12][256] = {
        "１つめの等式\n左辺\nx の係数 = ",
        "y の係数 = ",
        "z の係数 = ",
        "右辺\n定数項 = ",
        "2つめの等式\n左辺\nx の係数 = ",
        "y の係数 = ",
        "z の係数 = ",
        "右辺\n定数項 = ",
        "3つめの等式\n左辺\nx の係数 = ",
        "y の係数 = ",
        "z の係数 = ",
        "右辺\n定数項 = "
    };
    printf("%s", str[i]);
}

bool numarray(char *str)    // atof が機能するときに true を返す
{
    while(*str != '\0')
    {
        switch(*str)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '.':
                break;
            default:
                if(!isdigit(*str))
                {
                    // ポインタの示す値が文字の時
                    return false;
                }
                break;
        }
        str++;
    }
    return true;
}

double tri(char function, double inputnum)
{
    switch(function)
    {
        case 's':
        case 'S':
            return sin(inputnum * M_PI / 180);
        case 'c':
        case 'C':
            return cos(inputnum * M_PI / 180);
        case 't':
        case 'T':
            return tan(inputnum * M_PI / 180);
        default:
            printf("そんな関数またはコマンドはありません。ヘルプは '?' で表示できます。\n\n");
        break;
    }
}

char arithmetic(long double *result)
{
    char code;
    char inputnum[1024];
    bool breaking = false, returned = false;
    long double resultbuf;

    while(1)
    {
        printf("\r>>> ");
        if(initialized)
        {
            scanf("%c", &code);   // '\n' を変数に代入しない。
            while(code == '\n')
            {
                printf("\r>>> ");
                scanf("%c", &code);   // '\n' を変数に代入しない。
            }

            switch(code)
            {
                case '+':
                    scanf("%s", &inputnum[0]);
                    resultbuf = atof(inputnum); //文字列を
                    *result += resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'a';
                    break;
                case '-':
                    scanf("%s", &inputnum[0]);
                    resultbuf = atof(inputnum); //文字列を
                    *result -= resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'a';
                    break;
                case '*':
                    scanf("%s", &inputnum[0]);
                    resultbuf = atof(inputnum); //文字列を
                    *result *= resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'a';
                    break;
                case '/':
                    scanf("%s", &inputnum[0]);
                    resultbuf = atof(inputnum); //文字列を
                    *result /= resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'a';
                    break;
                case 'q':
                    return 'q';
                    break;
                case 'f':
                    return 'f';
                    break;
                case '?':
                    printh(ARITHMETIC);
                    break;
                default:
                    printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
                    break;
            }
        }
        else
        {
            scanf("%s", &inputnum[0]);

            resultbuf = atof(inputnum);

            *result = resultbuf;
            initialized = true;
            return 'a';
        }
    }   // while(1)
}

char functional(long double *result)
{
    char code, function, inputnum[1024];
    bool breaking = false;
    long double resultbuf;

    while(1)
    {
        printf("\r>>> ");
        if(initialized)
        {
            scanf("%c", &code);   // '\n' を変数に代入しない。
            while(code == '\n')
            {
                printf("\r>>> ");
                scanf("%c", &code);   // '\n' を変数に代入しない。
            }

            switch(code)
            {
                case '+':
                    scanf("%c", &function);
                    scanf("%s", &inputnum[0]);
                    resultbuf = tri(function, atof(inputnum));
                    *result += resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'f';
                    break;
                case '-':
                    scanf("%c", &function);
                    scanf("%s", &inputnum[0]);
                    resultbuf = tri(function, atof(inputnum));
                    *result -= resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'f';
                    break;
                case '*':
                    scanf("%c", &function);
                    scanf("%s", &inputnum[0]);
                    resultbuf = tri(function, atof(inputnum));
                    *result *= resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'f';
                    break;
                case '/':
                    scanf("%c", &function);
                    scanf("%s", &inputnum[0]);
                    resultbuf = tri(function, atof(inputnum));
                    *result /= resultbuf;
                    printf(" = %Lf\n", *result);
                    return 'f';
                    break;
                case 'q':
                    return 'q';
                    break;
                case 'a':
                    return 'a';
                    break;
                case '?':
                    printh(FUNCTIONAL);
                    break;
                default:
                    printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
                    break;
            }
        }
        else    // !initialized
        {
            scanf("%c", &function);
            while(function == '\n')
            {
                printf("\r>>> ");
                scanf("%c", &function);
            }
            scanf("%s", &inputnum[0]);
            if(numarray(&inputnum[0]))
            {
                resultbuf = tri(function, atof(inputnum));
                *result = resultbuf;
                initialized = true;
                return 'f';
            }
        }
    }   // while(1)
}

bool finalize() // ここがおまけ
{
    // 連立方程式プログラム
    long double array[12];
    char str[1024];
    for(int i = 0; i < 12; i++)
    {
        printk(i);  // 
        do
        {
            scanf("%s", &str[0]);
        } while(!numarray(str));
        array[i] = atof(str);
    }
    long double a[3][4] = {{array[0], array[1], array[2], array[3]}, {array[4], array[5], array[6], array[7]}, {array[8], array[9], array[10], array[11]}};
    long double Aabs = (a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1]);
    #if DEBUGMODE
        printf(GREEN);
        for(int n = 0; n < 3; n++)
        {
            for(int m = 0; m < 4; m++)
            {
                printf("a[%d][%d] = %Lf", n, m, a[n][m]);
                if(m != 3)
                    printf(", ");
            }
            printf("\n");
        }
        printf("Aabs = %Lf\n", Aabs);
        printf(EX);
    #endif
    if(Aabs == 0)
    {
        printf("解が不定か存在しません。\n");
        return false;
    }
    long double ainv[3][3] = {
        {(1 / Aabs) * (a[1][1] * a[2][2] - a[1][2] * a[2][1]), -(1 / Aabs) * (a[0][1] * a[2][2] - a[0][2] * a[2][1]), (1 / Aabs) * (a[0][1] * a[1][2] - a[0][2] * a[1][1])},
        {-(1 / Aabs) * (a[1][0] * a[2][2] - a[1][2] * a[2][0]), (1 / Aabs) * (a[0][0] * a[2][2] - a[0][2] * a[2][0]), -(1 / Aabs) * (a[0][0] * a[1][2] - a[0][2] * a[1][0])},
        {(1 / Aabs) * (a[1][0] * a[2][1] - a[1][1] * a[2][0]), -(1 / Aabs) * (a[0][0] * a[2][1] - a[0][1] * a[2][0]), (1 / Aabs) * (a[0][0] * a[1][1] - a[0][1] * a[1][0])}};
    long double b[3][1] = {{a[0][3]}, {a[1][3]}, {a[2][3]}};
    long double ainvb[3][1] = {{ainv[0][0] * b[0][0] + ainv[0][1] * b[1][0] + ainv[0][2] * b[2][0]}, {ainv[1][0] * b[0][0] + ainv[1][1] * b[1][0] + ainv[1][2] * b[2][0]}, {ainv[2][0] * b[0][0] + ainv[2][1] * b[1][0] + ainv[2][2] * b[2][0]}};
    #if DEBUGMODE
        for(int n = 0; n < 3; n++)
        {
            for(int m = 0; m < 3; m++)
            {
                printf(GREEN);
                printf("ainv[%d][%d] = %Lf", n, m, ainv[n][m]);
                if(m != 2)
                    printf(", ");
                printf(EX);
            }
            printf("\n");
        }
        for(int n = 0; n < 3; n++)
        {
            for(int m = 0; m < 1; m++)
            {
                printf(GREEN);
                printf("b[%d][%d] = %Lf", n, m, b[n][m]);
                if(m != 0)
                    printf(", ");
                printf(EX);
            }
            printf("\n");
        }
        for(int n = 0; n < 3; n++)
        {
            for(int m = 0; m < 1; m++)
            {
                printf(GREEN);
                printf("ainvb[%d][%d] = %Lf", n, m, ainvb[n][m]);
                if(m != 0)
                    printf(", ");
                printf(EX);
            }
            printf("\n");
        }
    #endif
    // 解は ainvb の要素。
    printf("(x, y, z) = (%Lf, %Lf, %Lf)\n", ainvb[0][0], ainvb[1][0], ainvb[2][0]);
    return true;
}

int main()
{
    bool initialized = false;
    char initmode;
    long double result;
    char mode = '\0';
    char modebuf = 'a';

    printl();

    while(mode == '\0')
    {
        printf("\rmode >>> ");
        scanf("%c", &initmode);
        switch(initmode)
        {
            case 'a':
                if(modebuf != mode)
                    printf("arithmetic\n");
                mode = arithmetic(&result);
                break;
            case 'f':
                if(modebuf != mode)
                    printf("functional\n");
                mode = functional(&result);
                break;
            case '\n':
                mode = '\0';
                break;
            default:
                break;
        }
    }

    initialized = true;

    while(mode != 'q')
    {
        modebuf = mode;
        switch(mode)
        {
            case 'a':
                mode = arithmetic(&result);
                if(modebuf != mode && mode == 'f')
                {
                    printf("functional\n");
                }
                break;
            case 'f':
                mode = functional(&result);
                if(modebuf != mode && mode == 'a')
                {
                    printf("arithmetic\n");
                }
                break;
            default:
                break;
        }
    }

    printf("Final Answer : %Lf\n", result);

    sleep(2);

    printf("\n\n");

    printf("\tおまけプログラム\n\n");

    finalize();

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
/// # http://simd.jugem.jp/?eid=29 // math.h > sin, cos, tan Reference
/// # https://www.sejuku.net/blog/48301 // sleep
/// # https://www.javadrive.jp/cstart/num/index5.html   // Clang string type Escape code
/// # https://www.mm2d.net/main/prog/c/console-02.html  // ANSI Escape code
/// # https://www.k-cube.co.jp/wakaba/server/func/isdigit.html  // isdigit

