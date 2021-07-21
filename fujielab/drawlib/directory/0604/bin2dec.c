/* 標準入力から16ケタの2進数を読み込み，
   符号なし整数として表示する */
#include <stdio.h>

int main(void) {
  unsigned short x = 0;
  unsigned short n = 32768;
  unsigned int c;
  int i;
  
  for(i = 0; i < 16; i++) {
    scanf("%1u", &c);
    if (c != 0 && c != 1) {
      printf("入力が不正\n");
      return 0;
    }
    x += c * n;
    n /= 2;
  }
  printf("DEC: %hu, HEX: 0x%04hX\n", x, x);
  
  return 0;
}
