#include <stdio.h>

/* 符号無し16ビット整数を2進数で
   標準出力に表示する関数 */
void printb(unsigned short x);

int main(void) {
  short x, y, z;
  
  x = 2361;
  y = -x;
  z = x + y;
  
  /* 10進数，16進数，2進数の順で表示 */
  printf("     x: %6hd %04hX ... ", x, x);
  printb(x);
  printf("\n");
  printf("     y: %6hd %04hX ... ", y, y);
  printb(y);
  printf("\n");
  printf(" x + y: %6hd %04hX ... ", z, z);
  printb(z);
  printf("\n");
  
  return 0;
}

void printb(unsigned short x) {
  unsigned short n = 32768;
  int i;
  
  for(i = 0; i < 16; i++) {
    if(x / n != 0) {
      x = x % n;
      printf("1");
    } else 
      printf("0");
    if (i % 4 == 3)
      printf(" ");
    n /= 2;
  }
}
