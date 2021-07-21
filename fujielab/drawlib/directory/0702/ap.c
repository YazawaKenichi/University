#include <stdio.h>

int main(void) {
  char *str[] = {"fujie", "aoki"};
  char *p1, *p2;
  int r = 0;
	
  p1 = str[0];
  p2 = str[1];

  while (1) {
    if (*p1 == '\0' && *p2 == '\0') {
      r = 0;
      break;
    } else if (*p1 == '\0') {	
      r = -1;
      break;
    } else if (*p2 == '\0') {
      r = 1;
      break;
    }
    p1++;
    p2++;
  }

  printf("RESULT=%d\n", r);

  return 0;
}

