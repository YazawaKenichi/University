#include <drawlib.h>
#include <stdio.h>

int main(void) {
  /* --- 変数宣言 --- */
  float wait_time = 0.01; /* drawlibの待機時間 */

  /* スコア関係の変数 */
  int score = 0; /* スコア */
  int sx = DL_WIDTH / 2 - 120, sy = 50; /* スコアの表示位置(X座標, Y座標) */
  char sscore[10]; /* スコアを文字列化するための文字列 */

  dl_initialize(1.0);

  /* --- メインループ --- */
  while(1) {
    score += 1;
    
    /* 描画処理 */
    dl_stop();
    dl_clear(DL_C("black"));
    sprintf(sscore, "%5d", score);
    dl_resume();
    dl_wait(wait_time);
  }

  return 0;
}
