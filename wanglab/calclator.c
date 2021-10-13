// 64bit OS を想定。-lm 必須。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool arithmeticmode = true, quiet = false;

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

void arith(double *result)
{
    char code, inputnum[1024];
    double resultbuf;

    printf("arithmetic mode\n");
    
    while(1)
    {
Arimore:
        printf(">>> ");
        scanf("%*c%c", &code);   // '\n' を変数に代入しない。

        switch(code)
        {
            case 'q':
                quiet = true;
                break;
            case 'a':
                printf("すでに四則演算モードです。\n\n");
                goto Arimore;
                break;
            case 'f':
                arithmeticmode = false;
                break;
        }
        if(!arithmeticmode || quiet) break;

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
                break;
        }


        printf("Middle Answer : %f\n", *result);
    }
}

void funct(double *result)
{
    char code, function, inputnum[1024];
    double resultbuf;

    printf("functional mode\n");

    while(1)
    {
Funmore:
        printf(">>> ");
        scanf("%*c%c", &code);   // '\n' を変数に代入しない。

        switch(code)
        {
            case 'a':
                arithmeticmode = true;
                break;
            case 'f':
                printf("すでに三角関数演算モードです。\n\n");
                goto Funmore;
                break;
            case 'q':
                quiet = true;
                break;
        }

        scanf("%c", &function);
        scanf("%s", &inputnum[0]);

        resultbuf = tri(function, atof(inputnum));

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

        if(arithmeticmode || quiet) break;

        printf("Middle Answer : %f\n", *result);
    }
}

void main()
{
    char code, function, inputnum[1024];
    double result, resultbuf;
    bool breaking = false;

    printf("calclator.c\n");

    // 一周目の処理
    printf("arithmetic mode\n");
    printf(">>> ");
    scanf("%s", &inputnum[0]);

    resultbuf = atof(inputnum); // 初期値の入力
    result = 0 + resultbuf; // 結果の値の初期化

    while(1)
    {
        if(arithmeticmode)
            arith(&result);
        else
            funct(&result);
        if(quiet) break;
    }

    printf("Final Answer : %f\n", result);
}

/// Reference
/// https://qiita.com/nogtk_/items/eb09ebc10f55590ba513
