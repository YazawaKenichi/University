// 64bit OS を想定。-lm 必須。ANSI エスケープシーケンスを使用。
#include "calclator.h"

#define OMAKE 0 // おまけプログラムもコンパイルする時 1
#define DEBUGMODE 1 // デバッグする時 1

/*** メイン関数 ***/
int main()
{
    char count = '\0';
    long double result;
    bool quiet = false, arithmeticmode = true, end = false;
    status initialized = AGAIN;

    printf("calclator.c\n");

    while(!end)
    {
        while(initialized != COLLECT)
        {
            initialized = init(&result, &arithmeticmode, &count);
        }

#if DEBUGMODE
        printd("Collect Initialize\n");
#endif

        while(1)
        {
            if(!quiet)
            {
                if(arithmeticmode)
                {
                    // 四則演算
                    // arith は quiet フラグを立てる。モードチェンジを検出したときに true を返す。
                    arithmeticmode = !arith(&result, &quiet, &count);
                }
                else
                {
                    // 関数演算
                    // funct は quiet フラグを立てる。モードチェンジを検出したときに true を返す。
                    arithmeticmode = funct(&result, &quiet, &count);
                }
            }
            else
            {
                printf("\n\tFinal Answer : %Lf\n\n", result);
                finalize(&quiet, &end);
                if(end)
                    break;
            }
        }   // while(1)
    }
    return 0;
}   // main

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

// 一言感想：もっとサイズ小さくしてぇなぁ...
