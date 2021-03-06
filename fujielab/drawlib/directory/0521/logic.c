#include <stdio.h>

int main(void) {
  int x;
	
  printf("Input X: ");
  scanf("%d", &x);

  /*
    2つの条件式が同時に真の場合や，
    片方どちらかが真の場合などに実行
    したい処理がある場合などは，
    論理演算子を利用する．
    C言語の論理演算子には以下がある．
    条件式1 && 条件式2 ... AND演算（論理積演算）
	両方とも真のときに限り全体が真になる
	（片方が偽であれば全体が偽になる）
    条件式1 || 条件式2 ... OR演算（論理和演算）
        片方が真であれば全体が真になる
	（両方とも偽のときに限り全体が偽になる）
    ! 条件式 ... NOT演算（否定演算）
        条件式が偽であれば，全体が真になる
  */
  if (x % 2 == 0) {
    printf("Xは偶数\n");
  }
  
  if (x % 3 == 0 && x % 4 == 0) {
    printf("Xは3の倍数，かつ4の倍数\n");
  }

  if (x % 3 == 0 || x % 4 == 0) {
    printf("Xは3の倍数，または4の倍数\n");
  }
  
  /*
    練習(1)
    -------
    xが0から100の間の5の倍数であることは
    どうやったら調べられるか考えてプログラムを
    書いてみよう．
  */

  /*
    練習(2)
    -------
    Xが5の倍数でないことを表示するプログラムに
    してみよう．
  */

  return 0;
}
