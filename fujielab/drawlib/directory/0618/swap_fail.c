/* 配列の要素の入れ替えのダメな例 */
#include <stdio.h>

int main(void) {
  int x[] = {10, 20, 30};
  int i;

  printf("BEFORE ");
  for(i = 0; i < 3; i++) {
    printf("%d ", x[i]);
  }
  printf("\n");

  x[0] = x[1];
  x[1] = x[0];

  printf("AFTER  ");
  for(i = 0; i < 3; i++) {
    printf("%d ", x[i]);
  }
  printf("\n");

  return 0;
}
