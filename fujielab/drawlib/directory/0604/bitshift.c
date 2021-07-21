#include <stdio.h>

/* 符号無し16ビット整数を2進数で
   標準出力に表示する関数 */
void printb(unsigned short x);

int main(void) {
  unsigned short x, y;
  
  x = 60; /* 0000 0000 0011 1100 */
  
  /* 10進数，16進数，2進数の順で表示 */
  printf("     x: %5u %04X ... ", x, x);
  printb(x);
  printf("\n");
  
  /* 左に3シフト */
  y = x << 3;
  printf("x << 3: %5u %04X ... ", y, y);
  printb(y);
  printf("\n");
  
  /* 右に2シフト */
  y = x >> 2;
  printf("x >> 2: %5u %04X ... ", y, y);
  printb(y);
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
