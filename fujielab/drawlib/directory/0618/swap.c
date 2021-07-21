/* 配列の要素の入れ替えの例 */
#include <stdio.h>

int main(void) {
  int x[] = {10, 20, 30};
  int i, s;

  printf("BEFORE ");
  for(i = 0; i < 3; i++) {
    printf("%d ", x[i]);
  }
  printf("\n");

  s = x[0];
  x[0] = x[1];
  x[1] = s;

  printf("AFTER  ");
  for(i = 0; i < 3; i++) {
    printf("%d ", x[i]);
  }
  printf("\n");

  return 0;
}
