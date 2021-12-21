// sample1.c で円を描画してからそれを落とすプログラム。

#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>
#include "../Engine.hpp"

#define DEBUGMODE 1
#define DEBUGMODE2 0
#define DEBUGMODE3 0

// glVertex2f(2 * vector.x / WINDOWSIZE.X - 1, -2 * vector.y / WINDOWSIZE.Y + 1);

double direction;  // 向く方向を決める。あとで値が PI / 4 倍されることに注意。
bool timeren = true;
Mouse mouse;
unsigned char ballcount = 0;
Vectorfloat zero = {(float) 0, (float) 0};
Color offsetcolor = {1, 1, 0};
Ball ball(zero, 0.05f);
ball.usegravity = true;
Time t;

//////////////////////////// 以下 コールバック関数 display //////////////////////

void displayfunc(void)
{
    glClearColor(0.0, 0.0, 0, 1); // バッファを塗りつぶしたい色
    glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 

    ball.draw();
#if DEBUGMODE
    printf("ball.draw()\n");
#endif

    glEnd();
//    glFlush();
    glutSwapBuffers();    // 処理の強制実行。
}

///////////////////////////////////// 以上 被コールバック関数 display ///////////////////////////////////

void reshapefunc(int hogehoge, int fugafuga)
{
    glutReshapeWindow(WINDOWSIZE.X, WINDOWSIZE.Y);
}

void timerfunc(int hogehoge)
{
    // ここに物理計算を記述する
    ball.accel.y = ball.g;
    ball.physics(); // 設定された速度と加速度から座標を更新する。
    if(mouse.hover)
    {
        mouse.hovertime++;
    }
#if DEBUGMODE
    printf("time = %4llu, miltime = %4llu\n", t.time, t.miltime);
#endif
    t.clock();
    glutTimerFunc(DT, timerfunc, 0);    // ms
}

void keyboardfunc(unsigned char key, int x, int y)
{
    switch(key)
    {
        case '\033':
            exit(0);
            break;
        default:
            break;
    }
}

void mousefunc(int button, int state, int argumentx, int argumenty)
{
    if(state == GLUT_DOWN)
    {
        Vector getpos = {argumentx, argumenty};
        mouse.setvector(getpos);    // mouse.vectorfloat に値が代入される。
        switch(button)
        {
            case GLUT_LEFT_BUTTON:
                ball.position = mouse.vectorfloat;
                ball.velocity = zero;
#if DEBUGMODE
                printf("getpos = { %5d, %5d }\n", getpos.x, getpos.y);
                printf("ball.position = { %5.3f, %5.3f }\n", ball.position.x, ball.position.y);
#endif
                break;
            case GLUT_RIGHT_BUTTON:
                break;
            case GLUT_MIDDLE_BUTTON:
                break;
            default:
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);    // GLUT の初期化。
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);   // ウィンドウのカラーモデルやバッファの設定を行うための関数。
    glutInitWindowSize(WINDOWSIZE.X, WINDOWSIZE.Y);
    glutCreateWindow("Faling");    // ウィンドウを生成。
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
    ball.setcolor(offsetcolor);

    glutDisplayFunc(displayfunc); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
    glutKeyboardFunc(keyboardfunc);
    glutMouseFunc(mousefunc);   // イベント処理関数が一度呼ばれると爆速で呼び出されまくるので正直 timer の需要がない。
    glutTimerFunc(1, timerfunc, 0);
    glutReshapeFunc(reshapefunc);

    glutMainLoop();   // GLUT がイベント処理ループに入るようにする。こうすればトップレベルウィンドウが破棄されるまで処理は戻ってこない。
    return 0;
}

#if false
/// REFERENCE
// https://lazesoftware.com/tool/hugeaagen/ // AA ジェネレータ
// https://www.exa-corp.co.jp/technews/files/OpenGL-text-091.pdf    // 塗りつぶし多角形の描画
//
// http://wisdom.sakura.ne.jp/system/opengl/gl2.html    // GLUT
// http://wisdom.sakura.ne.jp/system/opengl/gl3.html    // glBegin glColor
// http://wisdom.sakura.ne.jp/system/opengl/gl4.html    // glFlush
// http://wisdom.sakura.ne.jp/system/opengl/gl10.html   // glutTimerFunc glutKeyboardFunc
// 
// http://wisdom.sakura.ne.jp/system/opengl/index.html  // このサイトには本当にお世話になったし、これからもお世話になる。
// 

/// 今回は上記インターネットの情報を頼りに、誰にも聞くこと無くプログラムしました。王教授はここまでのものを求めていなかったような気はしてますが、興に乗ってしまってつい....

#endif

/*
 *
 * マウスを押す度に増えるようにするためのプログラムの実装。
 * 問題点としては、マウスを押す度に増えるということは実装次第でメモリ領域を可変にする必要があるということ。
 * 実際にそのプログラムを作るというのは難しそうなので、別の方法を考える。
 * 初歩に戻って、「クリックされた回数を画面に表示する」プログラムを考えてみると簡単かもしれない。
 * クリックされた回数をカウントして、描画する度にその数のオブジェクトを配置するという方法だ。
 * しかしこちらにも問題がある。
 * 今回のプログラムは物理運動を実現するために、描画毎に前回の値を使って計算する。
 * しかし毎回インスタンスを生成する方法を用いるとその「前回の値」を使うことができなくなってしまう。
 * そこで思いついた方法として、オブジェクトの有効性を示す「bool enable」の実装。
 * enable == true ならば 円の描画と当たり判定の開始
 * enable == false ならば 円を描画せず（あるいは背景色にし）当たり判定を切る。
 * オブジェクト配列を用いて for で計算すればより現実的なプログラムになるだろう。
 *
 * */






