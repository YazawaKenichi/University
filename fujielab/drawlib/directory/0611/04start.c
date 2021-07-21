#include <drawlib.h>
#include <stdio.h>

int main(void) {
  /* --- 変数宣言 --- */
  float wait_time = 0.01; /* drawlibの待機時間 */

  /* スコア関係の変数 */
  int score = 0; /* スコア */
  int sx = DL_WIDTH / 2 - 120, sy = 50; /* スコアの表示位置(X座標, Y座標) */
  char sscore[10]; /* スコアを文字列化するための文字列 */

  /* 制御関係の変数 */
  int start = 0; /* 開始，終了画面のループ判定用 */
  int t, k, x, y; /* dl_get_event用 */

  dl_initialize(1.0);

  /* --- 開始画面の表示 --- */
  dl_stop();
  dl_clear(DL_C("black"));
  dl_text("PUSH 'F' to start", 160, 220, 1.0, DL_C("white"), 1);
  dl_resume();

  /* --- Fキーが押されるまで待機 --- */
  start = 0;
  while(start == 0) {
    /* Fキーが押されたら start を 1 にする */ 
    dl_wait(wait_time);
  }

  /* --- メインループ --- */
  while(1) {
    score += 1;

    if (score > 500)
      break;
    
    /* 描画処理 */
    dl_stop();
    dl_clear(DL_C("black"));
    sprintf(sscore, "%5d", score);
    dl_text(sscore, sx, sy, 2.0, DL_C("white"), 2);
    dl_resume();
    dl_wait(wait_time);
  }

  /* --- 終了画面の表示 --- */
  dl_stop();
  dl_clear(DL_C("black"));
  sprintf(sscore, "%5d", score);
  dl_text(sscore, sx, sy, 2.0, DL_C("white"), 2);
  dl_text("GAME OVER", 160, 220, 1.0, DL_C("white"), 1);
  dl_text("push 'F' to quit", 160, 300, 1.0, DL_C("white"), 1);
  dl_resume();

  /* --- Fキーが押されるまで待機 --- */
  /* 練習問題 開始画面と同じことをする */
  
  return 0;
}
