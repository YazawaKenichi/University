#include <GL/glut.h>

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 
  glBegin(GL_LINE_LOOP);    // 最初の頂点から最後の頂点まで線分を結合して描画する。 
  glVertex2d(-0.9, -0.9);
  glVertex2d(0.9, -0.9);
  glVertex2d(0.9, 0.9);
  glVertex2d(-0.9, 0.9);
  glEnd();
  glFlush();    // 処理の強制実行。
}

void init(void)
{
  glClearColor(0.0, 0.0, 1.0, 1.0); // glViewPort で指定した範囲を塗りつぶすことが可能らしいが、glViewPort ってなんや？
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);    // GLUT の初期化。
  glutInitDisplayMode(GLUT_RGBA);   // ウィンドウのカラーモデルやバッファの設定を行うための関数。
  glutCreateWindow(argv[0]);    // ウィンドウを生成。
  glutDisplayFunc(display); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
  init();   // 自作関数：塗りつぶし
  glutMainLoop();   // GLUT がイベント処理ループに入るようにする。こうすればトップレベルウィンドウが破棄されるまで処理は戻ってこない。
  return 0;
}

/*
 *
 * glClear(GLbitfield mask);    // 指定したバッファを特定の色で消去する。特定の色というのは glClearColor() で指定可能。 
 * GLbitfield GL_COLOR_BUFFER_BIT;  // カラーバッファを消去する。 
 * GLbitfield GL_DEPTH_BUFFER_BIT;  // デプスバッファを消去する。 
 * GLbitfield GL_ACCUM_BUFFER_BIT;  // アキュムレーションバッファを消去する。 
 * GLbitfield GL_STENCIL_BUFFER_BIT;    // ステンシルバッファを消去する。 
 * 
 * それぞれのバッファの役割と使用方法
 * >>>未完了<<<
 * 
 * 前段知識
 * ・プリミティブ：ここではオブジェクト・コンポーネント（例えば点、線、ポリゴン、ビットマップ、画像）のこと。
 * ・レンダリング：3D の情報で定義されたプリミティブを画面を出力するために 2D に直すこと。
 * 
 * glBegin(GLenum mode);    // プリミティブを記述するために頂点を指定する関数。これを一度呼び出せば頂点が定義できるようになる。// 頂点の指定終了は glEnd() 関数を使用して終了。  
 * GLenum GL_POINTS;    // 各頂点を単独の点として扱う。頂点 n は、点 n を意味し、n という点が描画される。 
 * GLenum GL_LINES; // ２つの頂点をペアとし、それぞれのペアを独立した線分として扱う。 
 * GLenum GL_LINE_STRIP;    // 最初の頂点から最後の頂点まで線分を連結して描画する。 
 * GLenum GL_LINE_LOOP; // すべての頂点を線分で結合する。 
 * GLenum GL_TRIANGLES; // 三つの頂点をペアとし、それぞれ独立した三角形として扱う。 
 * GLenum GL_TRIANGLE_STRIP;    // 連結した三つの三角形のグループを描画する。 
 * GLenum GL_TRIANGLE_FAN;  // 最初の頂点を軸に連結した三角形のグループを描画する。 
 * GLenum GL_QUADS; // 四つの頂点をペアとし、それぞれ独立した四角形として扱う。 
 * GLenum GL_QUAD_StRIP;    // 連結した四角形のグループを描画する。 
 * GLenum GL_POLYGON;   // 単独の凸ポリゴンを描画する。 
 * 
 * // 頂点の記述ができる関数。 
 * // 2D のユークリッド点
 * void glVertex2d(GLdouble x , GLdouble y);
 * void glVertex2f(GLfloat x , GLfloat y);
 * void glVertex2i(GLint x , GLint y);
 * void glVertex2s(GLshort x , GLshort y);
 * // 3D のユークリッド点
 * void glVertex3d(GLdouble x , GLdouble y , GLdouble z);
 * void glVertex3f(GLfloat x , GLfloat y , GLfloat z);
 * void glVertex3i(GLint x , GLint y , GLint z);
 * void glVertex3s(GLshort x, GLshort y, GLshort z);
 * // 3D 同次座標
 * void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
 * void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
 * void glVertex4i(GLint x, GLint y, GLint z, GLint w);
 * void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
 * // なにこれ
 * void glVertex2dv(const GLdouble *v);
 * void glVertex2fv(const GLfloat *v);
 * void glVertex2iv(const GLint *v);
 * void glVertex2sv(const GLshort *v);
 * void glVertex3dv(const GLdouble *v);
 * void glVertex3fv(const GLfloat *v);
 * void glVertex3iv(const GLint *v);
 * void glVertex3sv(const GLshort *v);
 * void glVertex4dv(const GLdouble *v);
 * void glVertex4fv(const GLfloat *v);
 * void glVertex4iv(const GLint *v);
 * void glVertex4sv(const GLshort *v);
 * 
 * glFlush()
 * // クライアント/サーバモデルの OpenGL において、サーバがクライアントから受け取ったコマンドを強制実行する。 
 * 
 * glClearColor(float r, float g, float b, float a);    // glClear() を呼び出してバッファを塗りつぶす時に、初期化する色を選ぶことができる。
 * 
 * glutInit(int *argcp, char **argv);   // ウィンドウを表示させるには GLUT を初期化する必要があり、それをするのが glutInit() 関数。
 *  // argcp には main() 関数の argc パラメータへのポインタを渡す。
 *  // argv には main() 関数の argv パラメータへのポインタを渡す。
 * 
 * 前段知識
 * ・バッファ：すべてのピクセル情報を保存する領域。
 * ・ビットプレーン：ピクセルに関する１ビットの情報を保存するバッファ。RGBA かカラー参照テーブルを参照する値が保存される。
 * 
 * glutCreateWindow(char *name);    // トップレベルウィンドウを生成できる。しかし生成するだけで、表示まではしてくれない。name にはウィンドウの名前を示す ASCII 文字列を渡す。
 * 
 * glutDisplayFunc(void (*func)(void)); // ウィンドウが処理するべき基本的な処理を実現することができる。
 *  // GLUT はコールバック関数を登録することでイベントを処理する。
 *  // ウィンドウの再描画が必要と判断された時に呼び出すべきディスプレイコールバックを登録する関数。
 *  // func には登録するディスプレイコールバック関数へのポインタを指定する。
 *  // サンプルプログラムでは display を指定しているぞ？？？これって自作関数だよな？
 * 
 *  // glutMainLoop() // GLUT がイベント処理ループに入る。
 *  // この関数を呼び出せば、トップレベルウィンドウが破棄されるまで処理は戻ってこない。
 * 
 * ...OpenGL むずいぞ？？？
 * 
 * 
 * 
 * 
 * 
 * 
 * */


