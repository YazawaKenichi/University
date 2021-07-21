#include <stdio.h>

int main(void) {
  int x, m;

  scanf("%d", &x);
  m = x;
  scanf("%d", &x);
  if (x > m)
    m = x;
  scanf("%d", &x);
  if (x > m) 
    m = x;
  printf ("最大値は%dです\n", m);

  return 0;
}
