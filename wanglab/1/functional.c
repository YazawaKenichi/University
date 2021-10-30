#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

void main()
{
    char code;    // 一周目でこいつに数値が入ってしまう可能性がある
    char function;
    char inputnum[1024];
    double result, resultbuf;
    bool breaking = false;

    printf("functional.c\n");

    /// 一周目の処理
    printf(">>> ");
    scanf("%c", &function);
    scanf("%s", &inputnum[0]);

    resultbuf = tri(function, atof(inputnum));
    result = 0 + resultbuf;

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

    printf("Final Answer : %f\n", result);
}

/// Special Thanks
/// # 21C1134 Yuto Yamaguchi

/// Reference
/// # http://simd.jugem.jp/?eid=29
