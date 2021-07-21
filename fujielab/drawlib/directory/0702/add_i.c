#include <stdio.h>

/* 関数 add_i のプロトタイプ宣言．
   戻り値の型は int
   関数名は add_i
   2つのint型の引数をとり，
   それぞれの変数名はa, bである．
   引数の変数名は省略できる． */
int add_i(int a, int b);

int main(void) {
	int x = 10, y = 20, z;
	
	/* 関数add_iの呼び出し．
	   引数にxとyを渡し，戻り値をzに代入している．
	   引数の個数や型がプロトタイプ宣言と
	   一致していないとエラーや警告が出る． */
	z = add_i(x, y);
	
	printf("%d + %d = %d\n", x, y, z);
	
	return 0;
}

/* 関数add_iの定義．
   引数や型はプロトタイプ宣言と一致している
   必要がある．引数の名前は，実行時に使うので
   省略できない． */
int add_i(int a, int b) {
	int c;
	
	c = a + b;
	 
	return c;
}
