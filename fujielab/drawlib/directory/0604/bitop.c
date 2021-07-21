#include <stdio.h>

/* 符号無し16ビット整数を2進数で
   標準出力に表示する関数 */
void printb(unsigned short x);

int main(void) {
  unsigned short a, b, x;
	
  a = 60; /* 0000 0000 0011 1100 */
  b = 90; /* 0000 0000 0101 1010 */
  
  /* 10進数，16進数，2進数の順で表示 */
  printf("    a: %5u %04X ... ", a, a);
  printb(a);
  printf("\n");
  printf("    b: %5u %04X ... ", b, b);
  printb(b);
  printf("\n");
  
  /* AND演算は，両者が1のときのみ1になる */
  x = a & b;
  printf("a & b: %5u %04X ... ", x, x);
  printb(x);
  printf("\n");
  
  /* OR演算は，片方が1であれば1になる */	
  x = a | b;
  printf("a | b: %5u %04X ... ", x, x);
  printb(x);
  printf("\n");
  
  /* XOR演算は，両者が異なれば1になる */
  x = a ^ b;
  printf("a ^ b: %5u %04X ... ", x, x);
  printb(x);
  printf("\n");
  
  /* NOT演算は，元々0であれば1になる */
  x = ~a;
  printf("   ~a: %5u %04X ... ", x, x);
  printb(x);
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
