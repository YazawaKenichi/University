// 64bit OS を想定。-lm 必須。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // You can use boolean object.
#include <string.h>
#include <math.h>

#define DEBUGMODE 1
#define PI M_PI

void input(*stringpointer)    // 何文字入力されても最初の一文字だけ取り出す関数
{
    scanf("%s", stringpointer);
}

void majorprocess(*charactor)  // 主要処理 // 入力された文字列に応じて四則演算・関数演算を行う関数
{
    bool arithmeticmode;  // 1byte 変数にモードを書き込んでいく   // 詳細はプログラム下部 "詳細" 参照
    if(arithmeticmode)
    {
        // 四則演算
        arithmetic();
    }
    else
    {
        // 関数演算
        function();
    }
}

void main()
{
    char charactor = '\0';  // この変数いらないかも
    char string[1023] = {'\0'}; // 入力された文字列を格納する
    char code = '+';    // 符号を格納する
    unsigned long long int resultint = 0;   // 整数部分を格納する    // 32bit OS 対応
    unsigned long long double resultdouble = 0; // 小数部分を格納する   // 32bit OS 対応

    while(1)
    {
        // 入力を受け付ける
        input(&string[0]);
        // 入力文字の解析とそれに応じた必要な処理
        major(&string[0]);
    }
}

/*
    目標
    マルチモードの作成ができる。
    i.e.) 四則演算モード・関数演算モードの入れ替えをしてほしい。

    仕様決定
    'a' を押すか 'f' を押すかでモードの切り替えができる。
    'q' を押したら電卓を終了する。

    工夫点
    計算結果を、符号・整数部分・小数部分の三つに分けることで多少大きな桁数を扱うことができるようにする。

    必要な処理
    入力した文字が数字か文字かを判断する関数。
    主要計算処理
*/

/*
    詳細
*/

/*
    wang memo
    scanf("%c", &sw);
    while(sw == \n);
        scanf("%c",&sw);
*/

/// Special Thanks: 21C1134 Yuto Yamaguchi

/// Reference
/// https://kaworu.jpn.org/c/bool
