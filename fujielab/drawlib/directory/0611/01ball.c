#include <drawlib.h>
#include <stdio.h>

int main(void) {
  /* --- 変数宣言 --- */
  float wait_time = 0.01; /* drawlibの待機時間 */

  /* ボール関係の変数 */
  float bx, by;    /* ボールのX座標, Y座標 */
  float bvx, bvy;  /* ボールのX方向の速度, Y方向の速度 */
  float bay, bvy0; /* ボールのY方向の加速度, 初速 */
  int br = 15;     /* ボールの半径 */
  
  int bary = 440;  /* ボールの下限位置 */

  /* --- 未決定のボール関係の変数を設定 --- */
  bx = 0.0;       /* ボールの初期位置(X座標) */
  by = bary - br; /* ボールの初期位置(Y座標) */

  /* ボールの加速度と初速を入力してもらう */
  printf("input bay: ");
  scanf("%f", &bay);
  printf("input bvy0: ");
  scanf("%f", &bvy0);

  bvy = bvy0;   /* ボールの速度(Y方向) */
  bvx = 1.0;    /* ボールの速度(X方向) */

  dl_initialize(1.0);

  /* --- メインループ --- */
  while(1) {
    /* ボールの移動処理 */
    by += bvy;  /* Y座標にY方向の速度を加える */
    bx += bvx;  /* X座標にX方向の速度を加える */

    /* ボールの境界処理(右) */
    if (bx + br > DL_WIDTH) {
      bvx *= -1.0; /* 速度の正負を反転させる */
      bx = DL_WIDTH - br; /* 位置の微調整 */  
    }

    /* 下限判定 */
    if (by + br > bary) {
      bvy = bvy0; /* Y方向の速度は初速に戻す */
      by = bary - br; /* 位置の微調整 */
    }

    /* 描画処理 */
    dl_stop();
    dl_clear(DL_C("black"));
    dl_circle((int)bx, (int)by, br, DL_C("blue"), 1, 1);
    dl_resume();
    dl_wait(wait_time);
  }

  return 0;
}
