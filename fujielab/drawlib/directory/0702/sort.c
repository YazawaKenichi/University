#include <stdio.h>

/* 
   与えられた配列のバブルソートを行う関数．
   第1引数は，ソートしたい配列の先頭要素のアドレス．
   第2引数は，配列の要素数
*/
void bubble_sort(int *, int);

int main(void) {
  int array[10] = {7, 10, 1, 9, 3, 5, 6, 8, 4, 2};
  int i, n = 10;

  printf("BEFORE: ");
  for(i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  /* 関数bubble_sortを呼ぶ． 配列の先頭アドレスと，
     配列の要素数を引数に渡す */
  bubble_sort(array, n);

  printf("AFTER: ");
  for(i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

/*
  関数bubble_sortの関数定義．
  xに配列の先頭要素のアドレスを受け取る．
  これにより，関数内ではx[i]で，main関数のarray[i]と
  同じ意味になる．配列の先頭要素のアドレスだけでは
  配列の要素数は不明なので，引数として受け取る必要がある．
*/
void bubble_sort(int *x, int n) {
  int i, j, s;

  for(i = 0; i < n - 1; i++) {
    for(j = 0; j < n - i - 1; j++){
      if (x[j] > x[j + 1]) {
        s = x[j];
        x[j] = x[j + 1];
        x[j + 1] = s;
      }
    }
  }

  return;
}
