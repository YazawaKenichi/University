// 64bit OS を想定。-lm 必須。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool arithmeticmode = true;

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

void arith()
{
    char code, inputnum[1024];
    double result, resultbuf;
    bool breaking = false;
    
    while(1)
    {
        printf(">>> ");
        scanf("%*c%c", &code);   // '\n' を変数に代入しない。
        scanf("%s", &inputnum[0]);

        resultbuf = atof(inputnum); //文字列を

        switch(code)
        {
            case '+':
                result += resultbuf;
                break;
            case '-':
                result -= resultbuf;
                break;
            case '*':
                result *= resultbuf;
                break;
            case '/':
                result /= resultbuf;
                break;
            case 'q':
                breaking = true;
                break;
            case 'a':
                printf("すでに四則演算モードです。\n\n");
                break;
            case 'f':
                arithmeticmode = false;
                break;
            default:
                printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
                break;
        }

        if(breaking) break;

        printf("Middle Answer : %f\n", result);
    }
}

void funct()
{
        while(1)
    {
        printf(">>> ");
        scanf("%*c%c", &code);   // '\n' を変数に代入しない。
        scanf("%c", &function);
        scanf("%s", &inputnum[0]);

        resultbuf = tri(function, atof(inputnum));

        switch(code)
        {
            case '+':
                result += resultbuf;
                break;
            case '-':
                result -= resultbuf;
                break;
            case '*':
                result *= resultbuf;
                break;
            case '/':
                result /= resultbuf;
                break;
            case 'q':
                breaking = true;
                break;
            default:
                printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
                break;
        }

        if(breaking) break;

        printf("Middle Answer : %f\n", result);
    }
}

void main()
{
    char code;
    char function;
    char inputnum[1024];
    double result, resultbuf;
    bool breaking = false;
    bool arithmeticmode = true;

    printf("calclator.c\n");

    // 一周目の処理
    printf(">>> ");
    scanf("%s", &inputnum[0]);

    resultbuf = atof(inputnum);
    result = 0 + resultbuf;

    while(1)
    {
Default:
        switch(arithmeticmode)
        {
            case true:
                arith();
                break;
            case false:
                funct();
                break;
            default:
                goto(Default);
                break;
        }
    }
}

/// Reference
/// https://qiita.com/nogtk_/items/eb09ebc10f55590ba513
