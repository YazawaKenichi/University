#include <stdio.h>

int main(void) {
  int r, x;
  
  while (1) {
    r = scanf("%d", &x);
    if (r < 0)
      break;
    printf ("x = %d\n", x);
  }
  
  return 0;
}
