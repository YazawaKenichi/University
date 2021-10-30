#include <stdio.h>
#include <math.h>
#define PI 3.1415926

#define CLS "\033[2J"   // 画面を消去する
#define SCROLL "\033[1S"    // 一行分スクロールする
#define HIDDEN "\033[0m" // 次からの文字列を隠す
#define EX "\033[39m"    // 次から文字の装飾をなくす
#define RED "\033[31m"  // 文字色を赤くする
#define YELLOW "\033[33m"   // 文字色を黄色にする
#define GREEN "\033[32m"    //文字色を緑にする

void printd(char *str)  // 緑文字で表示するだけの関数   // debug 時の出力用
{
    printf(GREEN);
    printf("%s", str);
    printf(EX);
}


int main(void)
{
	int num, kazu, fg;
	double ang, rst, x, y, kei;
	float a, b, sum;
	char moji, kotoba, sw, kigou;

	rst = 0;
	y = 0;

	printf("整数と少数の四則演算 : 1  三角関数 : 2\n");
    printf(">>> ");
	scanf("%d", &fg);

	if (fg == 1)
    {
		printf("整数と少数の四則演算\n");
		scanf("%f", &a);

		while (1)
        {
			scanf("%c", &sw);
			while (sw == '\n')
				scanf("%c", &sw);

			scanf("%f", &b);

			switch (sw)
            {
                case '+':
                    sum = a + b;
                    break;
                case '-':
                    sum = a - b;
                    break;
                case '*':
                    sum = a * b;
                    break;
                case '/':
                    sum = a / b;
                    break;
                default:
                    break;
			}

			printf("%f\n", sum);

			a = sum;

			printf("終了する場合 : 0  続行する場合 : それ以外の数字を入力\n");
			scanf("%d", &num);

			if (num == 0) {
				break;
			}

		}
	}

	if (fg == 2)
    {
		printf("三角関数\n");
        printf(">>> ");
		scanf("%c", &moji); // 関数の入力   //ここで moji に \n が入ってる気がする。
        while(moji == '\n')
        {
            printf(">>> ");
            scanf("%c", &moji);
        }
        printf(GREEN);
        printf("moji = %c\n", moji);
        printf(EX);

        printf(">>> ");
		scanf("%lf", &ang); // 角度の入力
        printf(GREEN);
        printf("%lf\n", ang);
        printf(EX);

		switch (moji)   // 値の算出
        {
            case 's':
                rst = sin(ang * PI / 180.0);
                break;
            case 'c':
                rst = cos(ang * PI / 180.0);
                break;
            case 't':
                rst = tan(ang * PI / 180.0);
                break;
		}
        printf(GREEN);
        printf("%lf\n", rst);
        printf(EX);

		while (1)   // 第二数の入力
        {
            printf(">>> ");
			scanf("%c", &kigou);    // 演算子の入力 // 第一数を入力し終えた段階で残っている \n が一度出力されてしまう。
			while (kigou == '\n')
            {
                printf(">>> ");
                scanf("%c", &kigou);    // '\n' の時読み飛ばす
			}
            printf(GREEN);
            printf("%c", kigou);
            printf(EX);

            printf(">>> ");
			scanf("%c", &kotoba);   // 関数の入力
            while(kotoba == '\n')
            {
                printf(">>>");
                scanf("%c", &kigou);
            }
            printf(GREEN);
            printf("%c\n", kotoba);
            printf(EX);

            printf(">>> ");
			scanf("%lf", &x);   // 角度の入力   // '\n' は読み飛ばされる
            printf(GREEN);
            printf("%lf\n", x);
            printf(EX);

			switch (kotoba)
            {
                case 's':
                    y = sin(x * PI / 180.0);
                    break;
                case 'c':
                    y = cos(x * PI / 180.0);
                    break;
                case 't':
                    y = tan(x * PI / 180.0);
                    break;
			}
            printf("%lf\n", y);

			switch (kigou)
            {
                case '+':
                    kei = rst + y;
                    break;
                case '-':
                    kei = rst - y;
                    break;
                case '*':
                    kei = rst * y;
                    break;
                case '/':
                    kei = rst / y;
                    break;
                default:
                    break;
			}

			printf("= %lf\n", kei);

			rst = kei;

			printf("終了する場合 : 0  続行する場合 : それ以外の数字を入力\n");
            printf(">>> ");
			scanf("%d", &kazu);

			if (kazu == 0) {
				break;
			}
		}
	}

	return 0;
}
 