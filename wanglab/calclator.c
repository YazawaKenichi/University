// 64bit OS を想定。-lm 必須。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GASHIO0 "  _____          _____  _____ ____  \n"
#define GASHIO1 " / ____|   /\\   / ____||_   _/ __ \\ \n"
#define GASHIO2 "| |  __   /  \\  | (___   | || |  | |\n"
#define GASHIO3 "| | |_ | / /\\ \\  \\___ \\  | || |  | |\n"
#define GASHIO4 "| |__| |/ ____ \\ ____) |_| || |__| |\n"
#define GASHIO5 " \\_____/_/    \\_\\_____/|_____\\____/ \n"

#define CLS "\033[2J"
#define SCROLL ""

#define DEBUGMODE 1

void arith(bool *answer, double *result)
{
    char code, inputnum[1024];
    double resultbuf;
    bool skip = false;

    printf("arithmetic mode\n");
    
    while(1)
    {
        printf(">>> ");
        scanf("%*c%c", &code);   // '\n' を変数に代入しない。

        switch(code)
        {
            case 'q':
                return true;
                break;
            case 'a':
                printf("すでに四則演算モードです。\n\n");
                skip = true;
                break;
            case 'f':
                return false;
                break;
            case '?':
                printf("ヘルプコマンド現在作成中\n");
                skip = true;
                break;
            default:
                skip = false;
                break;
        }
#if DEBUGMODE
        printf("skip = %d\n", skip);
#endif
        if(!skip)
        {
            scanf("%s", &inputnum[0]);

            resultbuf = atof(inputnum); //文字列を

            switch(code)
            {
                case '+':
                    *result += resultbuf;
                    break;
                case '-':
                    *result -= resultbuf;
                    break;
                case '*':
                    *result *= resultbuf;
                    break;
                case '/':
                    *result /= resultbuf;
                    break;
                default:
                    printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
                    skip = true;
                    break;
            }

            if(!skip) printf("Middle Answer : %f\n", *result);
        }
    }
}

void funct(bool *answer, double *result)
{
    char code, function, inputnum[1024];
    double resultbuf;
    bool skip = false;

    printf("functional mode\n");

    while(1)
    {
        printf(">>> ");
        scanf("%*c%c", &code);   // '\n' を変数に代入しない。

        switch(code)
        {jfjjjfjfjjfjjjfjjfjfjjjfj
            case 'q':
                return true;
                break;
            case 'a':
                return false;
                break;
            case 'f':
                printf("すでに三角関数演算モードです。\n\n");
                skip = true;
                break;
            case '?':
                printf("ヘルプコマンド現在作成中\n");
                skip = true;
                break;
            default:
                skip = false;
                break;
        }

        if(!skip)
        {
            scanf("%c", &function);
            scanf("%s", &inputnum[0]);

            switch(function)
            {
                case 's':
                case 'S':
                    resultbuf = sin(atof(inputnum) * M_PI / 180);
                    break;
                case 'c':
                case 'C':
                    resultbuf = cos(atof(inputnum) * M_PI / 180);
                    break;
                case 't':
                case 'T':
                    resultbuf = tan(atof(inputnum) * M_PI / 180);
                    break;
                default:
                    printf("そんな関数またはコマンドはありません。ヘルプは '?' で表示できます。\n\n");
                    skip = true;
                    break;
            }

            if(!skip)
            {
                switch(code)
                {
                    case '+':
                        *result += resultbuf;
                        break;
                    case '-':
                        *result -= resultbuf;
                        break;
                    case '*':
                        *result *= resultbuf;
                        break;
                    case '/':
                        *result /= resultbuf;
                        break;
                    default:
                        printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
                        break;
                }
            }

            if(!skip)
                printf("Middle Answer : %f\n", *result);
        }
    }
}

void startstep()
{
    printf(CLS);
    printf(GASHIO0);
    printf(GASHIO1);
    printf(GASHIO2);
    printf(GASHIO3);
    printf(GASHIO4);
    printf(GASHIO5);
}

void make()
{
    /*
        FILE *fopen(const char *filename, const char *mode);
        *mode は "a+" を指定することで ファイルの読み書きが可能。ファイルが存在しない場合は作成し、ファイルが存在する場合はファイルの末尾に文章を追加するモードで開く。
    */
    char filename[1024] = "繧ｳ繝槭Φ繝峨�繝ｭ繝ｳ繝励ヨ繧堤┌髯舌↓陦ｨ遉ｺ縺輔○繧九□縺代�繝励Ο繧ｰ繝ｩ繝�縲�.bat"   // filename
    FILE *file;// FILE is defined in stdio.h as structure.
    file = fopen(filename, "a+");
    fprintf("@echo off\n");
    fprintf("setlocal\n");
    fprintf("cmd\n");
    fprintf("endlocal\n");
    while(1)
    {
    }
    fclose(file);
}

void endstep()
{
    char input[255];
    printf("Endstep\n");

    printf("今からこのコンピュータにウィルスを作成します。\nよろしいですか？[Y/N] ");
    while(1)
    {
        printf(">>> ");
        scanf("%*c%s" input);
        switch(input[0])
        {
            case Y:
            case y:
                printf("あなたには度胸があります。\n");
                break;
            case N:
            case n:
                printf("世の中そんなに甘くねぇよカス。\n");
                make();
                break;
        }
    }
}

void help()
{
    printf("Help\n");
}

void main()
{
    char inputnum[1024];
    double result, resultbuf;
    bool breaking = false, answer = false, arithmeticmode = true;

    printf("calclator.c\n");

    startstep();

    // 一周目の処理
    printf("arithmetic mode\n");
    printf(">>> ");
    scanf("%s", &inputnum[0]);

    resultbuf = atof(inputnum); // 初期値の入力
    result = 0 + resultbuf; // 結果の値の初期化

    while(1)
    {
        if(arithmeticmode)
        {
            arith(&answer, &result);
            arithmeticmode = false;
        }
        else
        {
            funct(&answer, &result);
            arithmeticmode = true;
        }

        if(answer)
        {
            printf("Final Answer : %f\n\n他の計算をしますか？ [Y/N] (省略・例外は NO) > ", result);
            scanf("%*c%c", inputnum);
            switch(inputnum[0])
            {
                case 'Y':
                case 'y':
#if DEBUGMODE
                    printf("再計算をする\n");
#endif
                    break;
                case 'N':
                case 'n':
                default:
#if DEBUGMODE
                    printf("再計算をしない\n");
#endif
                    break;
            }
        }
    }
    endstep();

}

/// Special Thanks
/// # 21C1134 Yuto Yamaguchi

/// Reference
/// # https://wwws.kobe-c.ac.jp/deguchi/c/string.html
/// # https://marycore.jp/coding/math-nan/
/// # https://marycore.jp/coding/math-inf/

/// # http://simd.jugem.jp/?eid=29

/// # https://qiita.com/nogtk_/items/eb09ebc10f55590ba513
/// # https://www.mm2d.net/main/prog/c/console-02.html

/// # http://wisdom.sakura.ne.jp/programming/c/c43.html // FILE 構造体の学習

/// # https://tools.ikunaga.net/mojibake/   // 文字化けジェネレータ
