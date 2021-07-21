#include <stdio.h>

int main(void) {
  int n, m;

  m = 7;
  n = 0;

  /*
    while文は()の中に条件式を書き，続けてブロックを書く．
    条件式が真であれば，ブロックの中身を実行する．
    （条件式が偽であれば，ブロックは実行されず，次の処理に移る）
    ブロックの中身を実行した後，再度，条件式を評価し，
    真であればブロックの中身を実行する．
    これを，条件式が真である限り続ける．

    下の例では，n は最初 0 であり，
    0 は 100 以下なので条件式は真である．そのためブロックが実行され，
    0 + 7 は 7 なので，n は 7 に更新される．以降，
    7, 14, 21, ..., 91, 98
    と，n は 7 ずつ増えて7の倍数でありながら，条件式がチェックされる．
    105 で初めて条件式が偽となるため，while文の実行が終了し，
    次に処理が移る．
  */
  while (n <= 100) {
    n = n + m;
  }

  printf("100を初めて超える7の倍数は、%3dです。\n", n);

  return 0;
}
