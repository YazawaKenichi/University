#include <stdio.h>

int main(void) {
  int x = 10, y = 20;
  
  /* 代入演算子 */
  /* 
     x += y は， x = x + y と同じ意味．
     実行前と実行後でxの値が異なるので注意．
  */ 
  x += y;
  printf ("(1) x = %d\n", x);
  /*
    以下同様に，
    x -= y と x = x - y
    x *= y と x = x * y
    x /= y と x = x / y
    x %= y と x = x % y
    は同じ意味．以下では例として
    x /= y を取り上げる．
  */
  x /= y;
  printf ("(2) x = %d\n", x);
   
  /* 
    代入演算子の右辺は式でもよい．
    例えば，
      x *= y + 10
    などと書けば，
      x = x * (y + 10)
    と同じ意味になる（計算順に注意）．
   */
  x *= y + 10;
  printf ("(3) x = %d\n", x);

  /*
    x++ と書くと，x += 1
    x-- と書くと，x -= 1
    と同じ意味になる．
    for文の再初期化式でよく使われる．
   */
  x++;
  printf("(4) x = %d\n", x);
  x--;
  printf("(5) x = %d\n", x);
 
  /*
    x++ や x-- は，
    ++x や --x と書いてもよい．
   */
  --x;
  printf("(6) x = %d\n", x);
  ++x;
  printf("(7) x = %d\n", x);
 
  return 0;
}
