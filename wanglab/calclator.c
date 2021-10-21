// 64bit OS を想定。-lm 必須。

/*
    課題
    arithmeticmode になってから a を入力すると mode >>> がいくつも表示されやがる。
*/

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
#define DELETE "\033[0K"    // 行中右側の文字列を消去

#define OMAKE 0 // おまけプログラムもコンパイルする時 1
#define DEBUGMODE 0 // デバッグする時 1

unsigned static const char INPUTERROR = 0;  // 不適切な入力
unsigned static const char ARITHMETIC = 1;  // 四則演算のヘルプ
unsigned static const char FUNCTIONAL = 2;  // 関数演算のヘルプ
unsigned static const char MODESELECT = 3;  // モード選択のヘルプ
unsigned static const char ALREADYARI = 4;  // 既に四則演算
unsigned static const char ALREADYFUN = 5;  // 既に関数演算

unsigned char count = 0;
long double result;

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

void printd(char *str)  // 緑文字で表示するだけの関数   // debug 時の出力用
{
    printf(GREEN);
    printf("%s", str);
    printf(EX);
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

bool printh(unsigned char place) // ヘルプを表示し、その後 true を返す関数   // skip = printh(PLACE) とすることで、ヘルプの表示と同時に skip を ture にできる
{
    char arithstr[] = "\n\t四則演算モード。\n\n演算する際は基本的に１項づつ Enter で区切って入力してください。\n\t演算子の紹介\n '+' : 和\n '-' : 差\n '*' : 積\n '/' : 商\n";
    char functstr[] = "\n\t関数演算モード。\n\n演算する際は基本的に１項づつ Enter で区切って入力してください。\n\t演算子の紹介\n '+' : 和\n '-' : 差\n '*' : 積\n '/' : 商\n\t関数の紹介\n 's' : 正弦\n 'c' : 余弦\n 't' : 正接\n ※角度は度数法。";
    char selectmode[] = "\n'a' を入力で四則演算モード\n'f' を入力で関数演算モード\n\n\n";

    switch(place)
    {
        case 0:
            printyellow("\n入力が不適切です。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        case 1:
            printf(arithstr);
            return true;
            break;
        case 2:
            printf(functstr);
            return true;
            break;
        case 3:
            printf(selectmode);
            return true;
            break;
        case 4:
            printyellow("\n既に四則演算モードです。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        case 5:
            printyellow("\n既に関数演算モードです。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        default:
            printred("\nプログラムエラーprinth() 不当な引数。\n\n");
            return false;
            break;
    }
}

bool arith(bool *quiet)
{
    char code, inputnum[1024];
    double resultbuf;
    bool skip = false;

    if(count++ != 1)
        printf("arithmetic mode\n");
    printf(">>> ");
    
    while(1)
    {
#if DEBUGMODE
        printd("\tarith while\r\033[4C");
#endif
        skip = false;
        scanf("%c", &code);   // '\n' を変数に代入しない。
        switch(code)
        {
            case 'q':
#if DEBUGMODE
                printd("arith while switch case 'q'\n");
#endif
                *quiet = true;
                return false;
                break;
            case 'a':
#if DEBUGMODE
                printd("arith while switch case 'a'\n");
#endif
                skip = printh(ALREADYARI);
                break;
            case 'f':
#if DEBUGMODE
                printd("arith while switch case 'f'\n");
#endif
                return true;
                break;
            case '?':
#if DEBUGMODE
                printd("arith while switch case '?'\n");
#endif
                skip = printh(ARITHMETIC);
                printf(">>> ");
                break;
            case '\n':
                skip = true;
                break;
        }

#if DEBUGMODE
        if(skip)
            printd("\t\t\tskip\r\033[4C");
#endif

        if(!skip)
        {
#if DEBUGMODE
            printd("\033[1A\t\t\t\tinputnum[0]\n");
#endif
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
                default:
                    skip = printh(INPUTERROR);
                    break;
            }

            if(!skip)
            {
                printf(" = %Lf\n>>> ", result);
                skip = false;
            }
        }
    }
}

bool funct(bool *quiet)
{
    char code, function, inputnum[1024];
    double resultbuf;
    bool skip = false;

    if(count++ != 1)
        printf("functional mode\n");

    while(1)
    {
        printf(">>> ");
        scanf("%c", &code);

        switch(code)
        {
            case 'q':
                *quiet = true;
                return false;
                break;
            case 'a':
                return true;
                break;
            case 'f':
                printf("すでに三角関数演算モードです。\n\n");
                skip = true;
                break;
            case '?':
                skip = printh(FUNCTIONAL);
                break;
        }

        if(!skip)
        {
            scanf("%c", &function);
            if(function != 's' || function != 'S' || function != 'c' || function != 'C' || function != 't' || function != 'T')
                skip = printh(INPUTERROR);
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
                    skip = printh(INPUTERROR);
                    break;
            }

            if(!skip)
            {
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
                    default:
                        skip = printh(INPUTERROR);
                        break;
                }
            }

            if(!skip)
                printf(" = %Lf\n", result);
        }
    }
}

#if OMAKE
// 未完成
void make()
{
    /*
    ///    FILE *fopen(const char *filename, const char *mode);
    ///    *mode は "a+" を指定することで ファイルの読み書きが可能。ファイルが存在しない場合は作成し、ファイルが存在する場合はファイルの末尾に文章を追加するモードで開く。
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
    */
}

// 未完成
void malware()
{
    char input[16];

    while(1)
    {
        printf("今からこのコンピュータにウィルスを作成します。\nよろしいですか？[Y/N] ");
        printf(">>> ");
        scanf("%s", &input[0]);
        switch(input[0])
        {
            case 'Y':
            case 'y':
                printf("あなたには度胸があります。\n");
                return ;
                break;
            case 'N':
            case 'n':
                printf("世の中そんなに甘くねぇよカス。\n");
                make();
                return ;
                break;
        }
    }
}
#endif

// 未完成
void quiet()
{
    printf("プログラムを終了するには、何か一つキーを押してください...");
    printf("\033[8mおっと、見つかってしまいましたか。\n");  // 8m is hidden. 0m is clear
    printf("hogehoge\n");
}

// 未完成
void endstep()
{
    printf("Endstep\n");
}

// 未完成
void help()
{
    printf("Help\n");
}

// 完成しているか吟味する必要がある
bool input(long double *ptr)  // 数列を入力させる関数。入力成功が true。
{
    char inputstr[1024];
    printf("\r>>> ");
    printf(DELETE);
    scanf("%s", &inputstr[0]);
    for(int i = 0; i <= sizeof(inputstr) / sizeof(char); i++)
    {
        if(!isdigit(inputstr[i]) && (inputstr[i] != '.' || inputstr[i] != '\n' || inputstr[i] != '\0')) // 数字じゃないし、return でもないし、NULL でもない時
            return false;
    }
    *ptr = atof(inputstr);
    return true;
}

// 完成しているか吟味する必要がある
bool inita() // 入力失敗で false
{
    bool success = false;
    printf("arithmeticmode\n");
    while(!success)
    {
        printf(">>> ");
        success = input(&result);
        printd("in while");
    }
    printd("input SUCCESS!");
    return success;
}

// こっちも完成しているか吟味する必要がある
bool initf() // 入力失敗で false
{
    char function;
    long double resultbuf;
    printf("functionalmode\n");
    printf(">>> ");
    scanf("%c", &function);
    switch(function)
    {
        case 's':
        case 'S':
            input(&resultbuf);
            result = sin(resultbuf * M_PI / 180);
            break;
        case 'c':
        case 'C':
            input(&resultbuf);
            result = cos(resultbuf * M_PI / 180);
            break;
        case 't':
        case 'T':
            input(&resultbuf);
            result = tan(resultbuf * M_PI / 180);
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool init(bool *arithmeticmode) // 初期化成功で true 失敗で false
{
    bool skip = false;
    char code = '\0';
    // 一周目のモード入力とスイッチ
    count = 1;  // defined as grobal
    // 初期化するときに文字を入力するエラーに対処出来てない。
    printf("mode >>> ");
    scanf("%c", &code);
    switch(code)
    {
        case 'a':
            skip = !inita();
#if DEBUGMODE
            printf(GREEN);
            printf("%d", skip);
            printf(EX);
#endif
            *arithmeticmode = true;
            break;
        case 'f':
            skip = !initf();
#if DEBUGMODE
            printf(GREEN);
            printf("%d", skip);
            printf(EX);
#endif
            *arithmeticmode = false;
            break;
        default:
            return false;
            break;
    }
    if(!skip) return true;
    else return false;
}

bool finalize(bool *quiet, bool *end) // 入力成功で true を返す。
{
    char inputstr[8];
    printf("\n\n他の計算をしますか？ [Y/N] > ");
    scanf("%s", inputstr);
    switch(inputstr[0])
    {
        case 'Y':
        case 'y':
            *quiet = false;  // quiet フラグを false に戻す。
            *end = false;   // end フラグを false にして while break の阻止。
            break;
        case 'N':
        case 'n':
            *end = true;    // end フラグを true にして while break する。
            break;
        default:
            *quiet = true;  // quiet フラグを true にしてもう一度入力させる。
            return false;
    }
}

int main()
{
    char code = '\0';
    bool quiet = false, arithmeticmode = true, initialized = false, end = false;

    printf("calclator.c\n");

    while(!end)
    {
        while(!initialized)
        {
            initialized = init(&arithmeticmode);
        }

        while(1)
        {
            if(!quiet)
            {
                if(arithmeticmode)
                {
                    // 四則演算
                    // arith は quiet フラグを立てる。モードチェンジを検出したときに true を返す。
                    arithmeticmode = !arith(&quiet);
                }
                else
                {
                    // 関数演算
                    // funct は quiet フラグを立てる。モードチェンジを検出したときに true を返す。
                    arithmeticmode = funct(&quiet);
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

    endstep();  // おまけプログラム

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
