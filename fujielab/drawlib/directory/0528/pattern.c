#include <drawlib.h>

int main(void) {
  int i;
  
  dl_initialize(1.0);
  
  for (i = 0; i < 10; i++) {
    dl_line(0, 0, 10 + i * 50, i * i * 5, 
            DL_C("blue"), 5 - i / 2);
  }  
  
  while (1) {
    dl_wait(1.0);
  } 
  
  return 0;
}
