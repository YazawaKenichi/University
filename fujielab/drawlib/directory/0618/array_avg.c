#include <stdio.h>

int main(void) {
  int score[3];
  int sum, i;
  float avg;

  score[0] = 80;
  score[1] = 90;
  score[2] = 70;
  
  sum = 0;
  for(i = 0; i < 3; i++) {
    sum += score[i];
  }
  avg = sum / 3.0;

  printf("合計点: %d\n", sum);
  printf("平均点: %.1f\n", avg);

  return 0;
}
  
