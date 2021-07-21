#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int n = 8;
  int x_min = 10, x_max = 100;
  int i, x;
  
  srand((unsigned int)time(NULL));

  for(i = 0; i < n; i++) {
    x = rand() % (x_max - x_min) + x_min;
    printf("%2d: %2d\n", i + 1, x);
  }
  
  return 0;
}
