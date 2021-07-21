#include <drawlib.h>
#include <stdio.h>

int main(void) {
  /* --- 変数宣言 --- */
  float wait_time = 0.01; /* drawlibの待機時間 */

  /* ラケット（バー）関係の変数 */
  int bary = 440;  /* バーの位置(Y座標) */
  int barh = 20;   /* バーの高さ */
  int bardiv = 7;  /* バーの幅を画面の何分割にするか */
  int barw = DL_WIDTH / bardiv; /* バーの幅 */
  int barx = barw * (bardiv / 2); /* バーの位置(X座標) */

  /* 制御関係の変数 */
  int t, k, x, y; /* dl_get_event用 */

  dl_initialize(1.0);

  /* --- メインループ --- */
  while(1) {
    /* 入力キーの処理 */
    while (dl_get_event(&t, &k, &x, &y)) {
      if (t == DL_EVENT_KEY) {
        /* Jキーが押されたらバーのX座標を右にずらす */ 
        if (k == 'j') {
          barx += barw;
        }
        /* Fキーが押されたらバーのX座標を右にずらす */ 
        if (k == 'f') {
          barx -= barw;
        }
      }
    }

    /* 描画処理 */
    dl_stop();
    dl_clear(DL_C("black"));
    dl_rectangle(barx, bary, barx + barw, bary + barh, DL_C("red"), 1, 1);
    dl_resume();
    dl_wait(wait_time);
  }

  return 0;
}
