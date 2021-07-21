#include <stdio.h>

int main(void) {
  int x = 0;
	
  /*
    while (1) または for(;;) は
    条件式が常に真と判断されてブロックが
    繰り返し実行される
  */
  while (1) {
    printf ("%d\n", x++);
    
    /* break を実行すると
       ループを抜け出すことができる． */
    break;
  }
  
  return 0;
}
