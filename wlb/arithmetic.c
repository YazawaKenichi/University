#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{
    char code;    // 一周目でこいつに数値が入ってしまう可能性がある
    char inputnum[1024];
    double result, resultbuf;
    bool breaking = false;

    printf("arithmetic.c\n");

    /// 一周目の処理
    printf(">>> ");
    scanf("%s", &inputnum[0]);

    resultbuf = atof(inputnum);
    result = 0 + resultbuf;

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
            default:
                printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
                break;
        }

        if(breaking) break;

        printf("Middle Answer : %f\n", result);
    }

    printf("Final Answer : %f\n", result);
}

// オープニングの表示
/*
    仕様決定
    a を押すか f を押すかでモードの切り替えができる。
    q を押したら電卓を終了する。

    工夫点
    計算結果を符号・整数部分・小数部分の三つに分けることで多少大きな桁数を扱うことができるようにする。
    
    必要な処理
    入力した文字が数字か文字か判断する関数
    主要計算処理
*/

/*
    scanf("%c", &code);
    scanf("%c", &fname);
    scanf("%ld", &inputnum);

    switch(fname)
    {
        case 's':
        case 'S':
        resultbuf = sin(inputnum);
        break;
        case 'c':
        case 'C':
        resultbuf = cos(inputnum);
        break;
        case 't':
        case 'T':
        resultbuf = tan(inputnum);
        break;
        default:
        printf("そんな関数はありません。ヘルプは '?' で表示できます。\n\n");
        break;
    }

    switch(code)
    {
        case '+':
        result += reslutbuf;
        break;
        case '-':
        result -= reslutbuf;
        break;
        case '*':
        result *= reslutbuf;
        break;
        case '/':
        result /= reslutbuf;
        break;
        default:
        printf("そんな符号または演算子はありません。ヘルプは '?' で表示できます。\n\n");
        break;
    }

    if(nowmode == 'a')
        nowmode = 'f';
    else if(nowmode == 'f')
        nowmode = 'a';
*/

/// Special Thanks
/// # 21C1134 Yuto Yamaguchi

/// Reference
/// # https://wwws.kobe-c.ac.jp/deguchi/c/string.html
/// # https://marycore.jp/coding/math-nan/
/// # https://marycore.jp/coding/math-inf/
