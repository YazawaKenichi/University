#include <stdio.h>

int main(void) {
  /* この部分（スラッシュとアスタリスクの記号で
     囲まれた部分）はコメントと呼ばれ，
     コンパイル時に無視されるので，
     プログラムの動作には影響しない． */

  /* printf関数を呼び出す．
     引数は "Hello, World\n"と言う文字列．
     \n は改行を表す．
     printf関数は標準出力（現環境の場合はターミナル）に
     引数に与えられた文字列を出力する． */
  printf("Hello, World\n");

  return 0;
}
