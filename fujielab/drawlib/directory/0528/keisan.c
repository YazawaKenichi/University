#include <stdio.h>

int main(void) {
  int x, y;

  printf("Xを入力してください: ");
  scanf("%d", &x);
  printf("Yを入力してください: ");
  scanf("%d", &y);

  printf("X + Y = %d\n", x + y);
  printf("X - Y = %d\n", x - y);
  printf("X * Y = %d\n", x * y);
  printf("X / Y = %d ... %d\n", x / y, x % y);

  return 0;
}
