/* 符号なし16ビット整数を2進数で
   表示するプログラム */
#include <stdio.h>

int main (void) {
  unsigned short x = 64;
  unsigned short xt;
  unsigned short n = 32768;
  int i;
  
  printf("DEC: %hu, ", x);
  printf("BIN: ");
  xt = x;
  for(i = 0; i < 16; i++) {
    if(xt / n != 0) {
      xt = xt % n;
      printf("1");
    } else 
      printf("0");
    if (i % 4 == 3)
      printf(" ");
    n /= 2;
  }
  printf(", ");
  printf("HEX: 0x%04hx\n", x);
  
  return 0;
}
