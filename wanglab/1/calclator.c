// 64bit OS を想定。-lm 必須。ANSI エスケープシーケンスを使用。

#include "calclator.h"

#define DEBUGMODE 1

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

bool printh(helptag place) // ヘルプを表示し、その後 true を返す関数   // skip = printh(PLACE) とすることで、ヘルプの表示と同時に skip を ture にできる
{
    char arithstr[] = "\n\t四則演算モード\n\n演算する際は基本的に１項づつ Enter で区切って入力してください。\n\n\t演算子の紹介\n '+' : 和\n '-' : 差\n '*' : 積\n '/' : 商\n\n'f' を入力して関数演算モードに切り替えることが可能です。\n\n";
    char functstr[] = "\n\t関数演算モード\n\n演算する際は基本的に１項づつ Enter で区切って入力してください。\n\n\t演算子の紹介\n '+' : 和\n '-' : 差\n '*' : 積\n '/' : 商\n\t関数の紹介\n 's' : 正弦\n 'c' : 余弦\n 't' : 正接\n ※角度は度数法。\n\n'a' を入力して四則演算モードに切り替えることが可能です。\n\n";
    char selectmode[] = "\n'a' を入力で四則演算モード\n'f' を入力で関数演算モード\n\n";

    switch(place)
    {
        case INPUTERROR:
            printyellow("\n入力が不適切です。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        case ARITHMETIC:
            printcyan(arithstr);
            return true;
            break;
        case FUNCTIONAL:
            printcyan(functstr);
            return true;
            break;
        case MODESELECT:
            printcyan(selectmode);
            return true;
            break;
        case ALREADYARI:
            printyellow("\n既に四則演算モードです。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        case ALREADYFUN:
            printyellow("\n既に関数演算モードです。ヘルプは '?' で表示できます。\n\n");
            return true;
            break;
        default:
            printred("\nプログラムエラーprinth() 不当な引数。\n\n");
            return false;
            break;
    }
}

/*** 電卓機能関数 ***/
bool arith(long double *result, bool *quiet, char *count)
{
    char code, inputnum[1024];
    long double resultbuf;
    bool skip = false;

    if((*count)++ != 1)
        printf("arithmetic mode\n");
    printi();
    
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
                printi();
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

            resultbuf = atof(inputnum);

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
                    skip = printh(INPUTERROR);
                    break;
            }

            if(!skip)
            {
                printf(" = %Lf\n>>> ", *result);
                skip = false;
            }
        }
    }
}

bool funct(long double *result, bool *quiet, char *count)
{
    char code, function, inputnum[1024];
    long double resultbuf;
    bool skip = false;

    if((*count)++ != 1)
        printf("functional mode\n");

    while(1)
    {
        printi();
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
                        skip = printh(INPUTERROR);
                        break;
                }
            }

            if(!skip)
                printf(" = %Lf\n", *result);
        }
    }
}

/*** 補助関数 ***/
bool inputnum(long double *ptr, bool *arithmeticmode)  // 数列を入力させる関数。入力成功が true。    // 数字を代入したい変数を引数に渡す。
{
    char inputstr[1024];
    printf(DELETE);
    scanf("%s", &inputstr[0]);
    for(int i = 0; inputstr[i] != '\0'; i++)   // inputstr の要素をすべてスキャンできるか、NULL が現れるまでスキャンし続ける。
    {
#if DEBUGMODE
        printf(GREEN);
        switch(inputstr[i])
        {
            case '\0':
                printf("inputstr[%d] = [NULL]\n", i);
                break;
            case '\n':
                printf("inputstr[%d] = [ENTER]\n", i);
                break;
            default:
                printf("inputstr[%d] = %c\n", i, inputstr[i]);
                break;
        }
#endif
        switch(inputstr[i])
        {
            case '.':
            case '+':
            case '-':
                break;
            case '?':
                if(*arithmeticmode)
                {
                    printh(ARITHMETIC);
                    return false;
                }
                else
                {
                    printh(FUNCTIONAL);
                    return false;
                }
            case 'a':
                if(*arithmeticmode)
                {
                    // 四則演算モード
                    printh(ALREADYARI);
                    return false;
                }
                else
                {
                    // 関数演算モード
                    *arithmeticmode = true; // 関数演算モードで a が押された時
                    return false;
                }
                break;
            case 'f':
                if(!(*arithmeticmode))
                {
                    // 関数演算モード
                    printh(ALREADYFUN);
                    return false;
                }
                else
                {
                    // 四則演算モード
                    *arithmeticmode = true;    // 関数演算モードで f が押された時
                    return false;
                }
                break;
            default:     // 小数点 NULL 和 差 ←これらでないとき
                if(!isdigit(inputstr[i]))   // 数字ですらない時
                {
                    printh(INPUTERROR);
                    return false;
                }
                break;
        }
#if DEBUGMODE
        printd("scanning str\n");
#endif
    }
    *ptr = atof(inputstr);
#if DEBUGMODE
    printf(GREEN);
    printf("atof(inputstr) = *ptr = %Lf\n", *ptr);
    printf(EX);
#endif
    return true;
}

bool inputfunct(long double *result, bool *arithmeticmode)  // 関数を入力させる。成功で true  // 答えを引数に上書きする
{
    bool skip = false, arithbuf = *arithmeticmode;
    char funct;
    long double num;
    scanf("%c", &funct);
    switch(funct)
    {
        case 's':
        case 'S':
            skip = !inputnum(&num, &arithbuf);
            *arithmeticmode = arithbuf;
            if(!skip)
                *result = sin(num * M_PI / 180);
            break;
        case 'c':
        case 'C':
            skip = !inputnum(&num, &arithbuf);
            *arithmeticmode = arithbuf;
            if(!skip)
                *result = cos(num * M_PI / 180);
            break;
        case 't':
        case 'T':
            skip = !inputnum(&num, &arithbuf);
            *arithmeticmode = arithbuf;
            if(!skip)
                *result = tan(num * M_PI / 180);
            break;
        default:
            return false;
            break;
    }
}

/*** シーケンス整理関数 ***/
bool arithmeticinitializemethod() // 入力失敗で false
{
    printf("arithmeticmode\n");

    bool success = false, aribuf = *arithmeticmode;
    long double resultbuf = *result;

    while(!success)
    {
#if DEBUGMODE
        printd("arithmeticinitializemethod ");
        printi();
#else
//        printd("↓行復帰しています");
        printi();
#endif
        success = inputnum(&resultbuf, &aribuf);
        if(success)
            *result = resultbuf;
        else
        {
            // arithmeticmode がへんかしたかどうかを読み取って、変化したら関数演算モードになるようにしむける
            if(aribuf == *arithmeticmode)
            {
                // 失敗してかつモード変更を検出しなかった時の処理
                printh(INPUTERROR);
            }
            else
            {
                // 失敗してかつモード変更が検出された時の処理
                arithmeticmode = false;
                return false;
            }
        }
#if DEBUGMODE
        printf(GREEN);
        printf("success = %d\n", success);
        printf(EX);
#endif
    }
    return success;
}

bool functionalinitializemethod() // 入力失敗で false
{
    printf("functionalmode\n");

    long double resultbuf;
    bool catched = false, aribuf = *arithmeticmode;

#if DEBUGMODE
        printd("functionalinitializemethod ");
        printf(">>> ");
#else
//        printd("↓行復帰しています\n");
        printi();
#endif
    while(!catched)
    {
        catched = inputfunct(&resultbuf, &aribuf);
        *arithmeticmode = aribuf;
    }
    *result = resultbuf;
    return true;
}

status init() // 初期化成功で true 失敗で false // result を書き換える
{
    static ret;
    printf("\rmode >>> ");
    printf(DELETE);
    scanf("%c", &mode);
    switch(mode)
    {
        case 'a':
            ret = arithmeticinitializemethod();
            break;
        case 'f':
            ret = functionalinitializemethod();
            break;
        case '?':
            printh(MODESELECT);
            ret = AGAIN;
            break;
        default:
            ret = AGAIN;
    }

    return ret;
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
            break;
    }
}

