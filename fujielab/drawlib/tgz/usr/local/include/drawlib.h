#ifndef ___DRAWLIB_H___
#define ___DRAWLIB_H___

/** ウィンドウの幅 */
#define DL_WIDTH 640
#define DL_HEIGHT 480

/** 
    初期化を行い，ウィンドウを生成する．
    全ての処理を行う前に1度呼び出す必要がある．
    ウィンドウサイズはscale倍される．
    scaleが1.0のときのサイズは640x480である．
    scaleは，単純に表示する際に拡大されているだけなので，
    scaleがいくつの値であろうと，
    X座標は0以上640未満，Y座標は0以上480未満の範囲である．
*/
int dl_initialize(double scale);

/**
   色の名前から，その色に対応する整数値を取得する．
   name は "black", "red", "yellow", "magenda", 
   "green", "cyan", "blue", "white" のいずれか．
 */
long dl_color_from_name(const char* name);

/**
   R(赤), G(緑), B(青)の強さから色に対応する
   整数値を取得する．
   r, g, b それぞれの値は 0 から 255 であること．
*/   
long dl_color_from_rgb(int r, int g, int b);

/* 色を名前から取得する関数の名前を短くするためのマクロ */
#define DL_C(name)   dl_color_from_name(name)
/* 色をRGBで取得する関数の名前を短くするためのマクロ */
#define DL_RGB(r,g,b)   dl_color_from_rgb(r,g,b)

/**
   線を引く．
   点(x1, y1)と点(x2, y2)間の線分を，
   colorで示された色と，thicknessで示された太さで結ぶ．
 */
void dl_line(int x1, int y1, int x2, int y2, long color, int thickness);

/**
   四角（長方形，または正方形）を描く．
   点(x1, y1)と点(x2, y2)を対角とした四角形を，
   colorで示された色と，thicknessで示された太さの線で描く．
   fillが1の場合四角形は塗りつぶされ，その他の場合は塗りつぶされない．
*/
void dl_rectangle(int x1, int y1, int x2, int y2, long color, int thickness, int fill);

/**
   円を描く．
   点(x1, y1)を中心とし，半径radiusの円を，
   colorで示された色と，thicknessで示された太さの線で描く．
   fillが1の場合四角形は塗りつぶされ，その他の場合は塗りつぶされない
*/
void dl_circle(int x1, int y1, int radius, long color, int thickness, int fill);

/**
   楕円，または円弧を描く．
   点(x1, y1)を中心とし，長径l，短径sで，angleだけ傾けた楕円のうち，
   start_angleからend_angleまでの部分を描く．
   他の描画と同様，colorで示された色と，thicknessで示された太さの線で描き，
   fillが1の場合四角形は塗りつぶされ，その他の場合は塗りつぶされない．
*/
void dl_ellipse(int x1, int y1, int l, int s,
		double angle,double start_angle, double end_angle,
		long color, int thickness, int fill);

/**
   テキストを描く．
   textに指定された文字列を，点(x1, y1)を左下とし，
   scale倍した大きさで描く．
   他の描画と同様，colorで示された色と，thicknessで示された太さの線で描く．
   textの文字数は255文字まで．256文字目以降は無視される．
*/
void dl_text(const char *text, int x1, int y1, double scale, long color, int thickness);

/**
   指定された色でウィンドウを塗りつぶす
 */
void dl_clear(long color);

/** イベントのタイプを表す定数 */
#define DL_EVENT_KEY 1
#define DL_EVENT_L_UP 2
#define DL_EVENT_L_DOWN 3
#define DL_EVENT_R_UP 4
#define DL_EVENT_R_DOWN 5

/** キーイベント時の特殊キーの番号 */
/* 矢印キー(左) */
#define DL_KEY_LEFT 65361
/* 矢印キー(上) */
#define DL_KEY_UP 65362
/* 矢印キー(右) */
#define DL_KEY_RIGHT 65363
/* 矢印キー(左) */
#define DL_KEY_DOWN 65364
/* エンター */
#define DL_KEY_ENTER 10
/* 左シフト */
#define DL_KEY_SHIFT_L 65505
/* 右シフト */
#define DL_KEY_SHIFT_R 65506

/**
   イベントを取得する．
   キューに溜まっているイベントのうち，もっとも古いものの情報が取得される．
   イベントの取得ができれば1，キューが空の場合は0を返す．
   イベントの取得ができた場合，各引数のポインタが指す変数には以下の値が代入される．

   event_typeにはイベントのタイプが代入される．
   イベントのタイプは，以下のいずれかの値である．
   DL_EVENT_KEY ... いずれかのキーが押された
   DL_EVENT_L_DOWN ... マウスの左ボタンが押された
   DL_EVENT_L_UP ... マウスの左ボタンが離された
   DL_EVENT_R_DOWN ... マウスの右ボタンが押された
   DL_EVENT_R_UP ... マウスの右ボタンが離された

   イベントのタイプがDL_EVENT_KEYの場合，keyには押されたキーのASCIIコードが代入される．

   イベントのタイプがマウスのボタン操作に関するイベントの場合，
   xとyには，その操作を行ったマウスポインタのx座標とy座標が代入される．
*/
int dl_get_event(int *event_type, int *key, int *x, int *y);

/**
   指定された秒数の間待機する．
   secは秒単位の待機時間．
 */
void dl_wait(float sec);

/**
   描画更新を一時停止する
*/
void dl_stop(void);

/**
   描画更新を再開する
*/
void dl_resume(void);
   



#endif // ___DRAWLIB_H___
