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

#define DEBUGMODE 1 // デバッグする時 1

typedef enum State {STATEAGAIN, COLLECT, STATEQUIET, INPUTA, INPUTF, INPUTH, NOTNUM, MODESELECT, NOWMODEDEFAULT, ARITHMETICINPUTH, FUNCTIONALINPUTH, ARITHMETICINITIALIZEDEFAULT} state;
typedef enum Mode {DEFAULT, MODEAGAIN, ERROR, MODEQUIET, ARITHMETICMODE, FUNCTIONALMODE, INITIALIZEDDEFAULT, RETURN} mode;

mode initialized = DEFAULT;

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

bool printh(state place) // ヘルプを表示し、その後 true を返す関数   // skip = printh(PLACE) とすることで、ヘルプの表示と同時に skip を ture にできる
{
    char arithstr[] = "\n\t四則演算モード\n\n演算する際は基本的に１項づつ Enter で区切って入力してください。\n\n\t演算子の紹介\n '+' : 和\n '-' : 差\n '*' : 積\n '/' : 商\n\n'f' を入力して関数演算モードに切り替えることが可能です。\n\n";
    char functstr[] = "\n\t関数演算モード\n\n演算する際は基本的に１項づつ Enter で区切って入力してください。\n\n\t演算子の紹介\n '+' : 和\n '-' : 差\n '*' : 積\n '/' : 商\n\t関数の紹介\n 's' : 正弦\n 'c' : 余弦\n 't' : 正接\n ※角度は度数法。\n\n'a' を入力して四則演算モードに切り替えることが可能です。\n\n";
    char selectmode[] = "\n'a' を入力で四則演算モード\n'f' を入力で関数演算モード\n\n";

    switch(place)
    {
        case STATEAGAIN:
            printyellow("\n入力が不適切です。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        case ARITHMETICINPUTH:
            printcyan(arithstr);
            return true;
            break;
        case FUNCTIONALINPUTH:
            printcyan(functstr);
            return true;
            break;
        case MODESELECT:
            printcyan(selectmode);
            return true;
            break;
        case INPUTA:
            printyellow("\n既に四則演算モードです。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        case INPUTF:
            printyellow("\n既に関数演算モードです。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        case NOWMODEDEFAULT:
            printred("\nプログラムエラー modeenum が default に行きました。\n\n");
            return true;
            break;
        case ARITHMETICINITIALIZEDEFAULT:
            printred("\nプログラムエラー ARITHMETICINITIALIZEDEFAULT\n\n");
            break;
        default:
            printred("\nプログラムエラー printh() 不当な引数。\n\n");
            return false;
            break;
    }
}

state inputnum(long double *output)
{
    char inputstr[1024];

    scanf("%s", &inputstr[0]);

    for(int i = 0; i <= sizeof(inputstr) / sizeof(char); i++)
    {
        switch(inputstr[i])
        {
            case '\0':
                *output = atof(inputstr);
                return COLLECT;
                break;
            case 'a':
            case 'A':
                return INPUTA;
                break;
            case 'f':
            case 'F':
                return INPUTF;
                break;
            case 'q':
            case '=':
                return STATEQUIET;
                break;
            case '+':
            case '-':
            case '.':
            case '\n':
                break;
            default:
                if(!isdigit(inputstr[i]))
                {
                    return INPUTH;
                }
                break;
        }
    }
}

mode arithmeticmethod(long double *result)  // 想定内エラーは MODEAGAIN 想定外エラーは ERROR 計算・初期化成功は ARITHMETICMODE F 入力は FUNCTIONALMODE
{
    char code;
    long double resultbuf = *result;

    if(initialized != DEFAULT) // 初期化されているならば
    {
        scanf("%c", &code);

        switch(code)
        {
            case '+':
                if(inputnum(&resultbuf) == COLLECT)
                {
                    #if DEBUGMODE
                        printd("arithmeticmode inputnum ++++++\n");
                    #endif
                    *result += resultbuf;   // 
                    return ARITHMETICMODE;
                }
                else
                {
                    // 入力が数列ではない時の処理
                    printh(NOTNUM);
                    return ERROR;
                }
                break;
            case '-':
                if(inputnum(&resultbuf) == COLLECT)
                {
                    *result -= resultbuf;
                    return ARITHMETICMODE;
                }
                else
                {
                    printh(NOTNUM);
                    return ERROR;
                }
                break;
            case '*':
                if(inputnum(&resultbuf) == COLLECT)
                {
                    *result *= resultbuf;
                    return ARITHMETICMODE;
                }
                else
                {
                    printh(NOTNUM);
                    return ERROR;
                }
                break;
            case '/':
                if(inputnum(&resultbuf) == COLLECT)
                {
                    *result /= resultbuf;
                    return ARITHMETICMODE;
                }
                else
                {
                    printh(NOTNUM);
                    return ERROR;
                }
                break;
            case 'a':
                printh(INPUTA);
                return MODEAGAIN;
                break;
            case 'f':
                return FUNCTIONALMODE;
                break;
            case '?':
                printh(ARITHMETICINPUTH);
                return MODEAGAIN;
                break;
            case 'q':
            case '=':
                return MODEQUIET;
                break;
            case '\n':
                return RETURN;
                break;
            default:
                printh(MODEAGAIN);
                return MODEAGAIN;
                break;
        }
    }
    else    // initializeed == DEFAULT のとき
    {
        // *result に初期値を代入する処理
        #if DEBUGMODE
            printd("init >>> ");
        #endif

        switch(inputnum(&resultbuf))
        {
            case COLLECT:
                *result = resultbuf;
                return ARITHMETICMODE;
                break;
            case INPUTA:
                printh(INPUTA);
                return MODEAGAIN;
                break;
            case INPUTF:
                return FUNCTIONALMODE;
                break;
            case INPUTH:
                printh(ARITHMETICINPUTH);
                return MODEAGAIN;
                break;
            default:
                printh(ARITHMETICINITIALIZEDEFAULT);
                return MODEAGAIN;
                break;
        }
    }
}

// 未完成
mode functionalmethod(long double *result)
{
    return ARITHMETICMODE;
}

// 完成
mode modeselector() // a, f 入力を mode 列挙体に変換する。その他は MODEAGAIN
{
    char modeval;

    printf("\rmode >>> ");
    scanf("%c", &modeval);

    switch(modeval)
    {
        case 'a':
            return ARITHMETICMODE;
            break;
        case 'f':
            return FUNCTIONALMODE;
            break;
        default:
            return MODEAGAIN;
            break;
    }
}

// 完成
mode init() // 初期モードを入力させる関数。返り値は mode.ARITHMETICMODE か mode.FUNCTIONALMODE の二択。それ以外はループして再入力させる。
{
    #if DEBUGMODE   // init() に入ったことの合図
        printd("into init()\n");
    #endif
    mode modeval = DEFAULT;

    do
    {
        // モードを入力させる関数
        modeval = modeselector();
        if(modeval == MODEAGAIN)
        {
            printh(MODESELECT);
        }
    } while(!(modeval == ARITHMETICMODE || modeval == FUNCTIONALMODE));

    return modeval;
}

int main(void)
{
    mode buffer = DEFAULT, modeenum = DEFAULT, initswitch = DEFAULT;
    long double result;

    while(1)
    {
        // 完成
        while(initialized != ARITHMETICMODE && initialized != FUNCTIONALMODE)  // mode initialized = DEFAULT;   // initialized がどちらでもない時常にループ
        {
            #if DEBUGMODE   // 初期化開始の合図
                    printd("initialize\n");
            #endif
            initswitch = init();    // initswitch には必ず ARITHMETICMODE か FUNCTIONALMODE のいずれかが必ず入っている。ループ
            modeenum = MODEAGAIN;
            while(modeenum == MODEAGAIN)
            {
                switch(initswitch)
                {
                    case ARITHMETICMODE:
                        #if DEBUGMODE
                            printd("into arithmeticmode\n");
                        #endif
                        printf("\r>>> ");
                        modeenum = arithmeticmethod(&result);
                        break;
                    case FUNCTIONALMODE:
                        #if DEBUGMODE
                            printd("into functionalmode\n");
                        #endif
                        printf("\r>>> ");
                        modeenum = functionalmethod(&result);
                        break;
                    case MODEAGAIN:
                        break;
                    default:
                        printh(INITIALIZEDDEFAULT);
                        initialized = DEFAULT;
                        break;
                }
            }

            switch(modeenum)
            {
                case ARITHMETICMODE:
                    initialized = ARITHMETICMODE;
                    break;
                case FUNCTIONALMODE:
                    initialized = FUNCTIONALMODE;   // 
                    break;
                case MODEAGAIN:
                    initialized = DEFAULT;
                    break;
                default:
                    initialized = DEFAULT;  // もう一度ループさせる。
                    break;
            }
        }

        modeenum = initialized; // 初期化完了

#if DEBUGMODE   // 初期化が完了した時の状態の表示
        printf(GREEN);
        printf("result = %Lf, modeenum = %d\n", result, modeenum);
        printf(EX);
#endif

        printf("\r>>> ");

        while(1)
        {
            switch(modeenum)
            {
                case ARITHMETICMODE:
                    modeenum = arithmeticmethod(&result);   // MODEAGAIN ERROR ARITHMETICMODE FUNCTIONALMODE RETURN
                    if(modeenum == RETURN || modeenum == MODEAGAIN || modeenum == ERROR)
                    {
                    #if DEBUGMODE   // 
                        printd("ARITHMETICMODE modeenum = arithmeticmethod(&result)\n");
                    #endif

                        modeenum = ARITHMETICMODE;
                    }
                    else
                    {
                        printf("\r>>> ");
                    }
                    break;
                case FUNCTIONALMODE:
                    modeenum = functionalmethod(&result);
                    if(modeenum == RETURN || modeenum == MODEAGAIN || modeenum == ERROR)
                    {
                        modeenum = FUNCTIONALMODE;
                    }
                    else
                    {
                        printf("\r>>> ");
                    }
                    break;
                default:
                    printh(NOWMODEDEFAULT);
                    #if DEBUGMODE
                        return 0;
                    #endif
                    break;
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

