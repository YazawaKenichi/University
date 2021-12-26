// sample1.c で円を描画してからそれを落とすプログラム。

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "../Engine.hpp"

#define DEBUGMODE 1
#define DEBUGMODE2 0
#define DEBUGMODE3 0

#define ARRAYLENGTH 2

using namespace std;

// glVertex2f(2 * vector.x / WINDOWSIZE.X - 1, -2 * vector.y / WINDOWSIZE.Y + 1);

double direction;  // 向く方向を決める。あとで値が PI / 4 倍されることに注意。
bool timeren = true;
Mouse mouse;
unsigned char ballcount = 0;
unsigned short int counter = 0;
Vectorfloat zero = {(float) 0, (float) 0};
Vectorfloat out = {(float) 2, (float) 2};
Color zerocolor = {0, 0, 0, 0};
Color offsetcolor = {1, 1, 0, 1};
Ball ball1(out, 0.05f);
Ball ball2(out, 0.05f);
Ball *ball[2] = {&ball1, &ball2};
Time t;

//////////////////////////// 以下 コールバック関数 display //////////////////////

void displayfunc(void)
{
    glClearColor(0.0, 0.0, 0, 1); // バッファを塗りつぶしたい色
    glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 

    for(int i = 0; i < ARRAYLENGTH; i++)
    {
        ball[i]->draw();
#if DEBUGMODE
        printf("ball[%d]->.draw()\n", i);
#endif
    }

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

    // ここまで
    for(int i = 0; i < ARRAYLENGTH; i++)
    {
        if(ball[i]->enable)
        {
            ball[i]->setcolor(offsetcolor);
            ball[i]->usegravity = true;
        }
        else
        {
            ball[i]->usegravity = false;
#if DEBUGMODE2
            cout << "ball[i]->color = {" << ball[i]->color.r << ", " << ball[i]->color.g << ", " << ball[i]->color.b << " }" << endl;
#endif
        }
        ball[i]->physics(); // 設定された速度と加速度から座標を更新する。
    }
#if DEBUGMODE2
    printf("time = %4llu, miltime = %4llu\n", t.time, t.miltime);
#endif
    t.clock();
    glutPostRedisplay();
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
                // ボールを一つづつ表示
                if(counter == 0)
                {
                    int i = counter;
                    if(!ball[i]->enable && state == GLUT_DOWN)
                    {
                        ball[i]->enable = true;
                        ball[i]->velocity = {0, 0};
                        srand((unsigned int) time(NULL));
                        ball[i]->accel.x = ((rand() % (20 + 1)) - 10) * 10;
                        ball[i]->position = mouse.vectorfloat;
                        ball[i]->enable = true;
                    }
                }
                if(counter == 1)
                {
                    int i = counter;
                    if(!ball[i]->enable && state == GLUT_DOWN)
                    {
                        ball[i]->enable = true;
                        ball[i]->velocity = {0, 0};
                        srand((unsigned int) time(NULL));
                        ball[i]->accel.x = ((rand() % (20 + 1)) - 10) * 10;
                        ball[i]->position = mouse.vectorfloat;
                        ball[i]->enable = true;
                    }
                }
                if(counter <= 2)
                {
                    counter++;
                }
                break;
            case GLUT_RIGHT_BUTTON:
                for(int i = 0; i < ARRAYLENGTH; i++)
                {
                    if(ball[i]->enable)
                    {
                        // 一時停止
                        ball[i]->enable = false;
                        ball[i]->buffer.velocity = ball[i]->velocity;
                        ball[i]->velocity = {0, 0};
                    }
                    else
                    {
                        // 再生
                        ball[i]->enable = true;
                        ball[i]->velocity = ball[i]->buffer.velocity;
                    }
                }
                break;
            case GLUT_MIDDLE_BUTTON:
                for(int i = 0; i < ARRAYLENGTH; i++)
                {
                    // リセット
                    counter = 0;
                    ball[i]->enable = false;
                    ball[i]->setcolor(zerocolor);
                    ball[i]->velocity = zero;
                    ball[i]->position = out;
                }
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
    for(int i = 0; i < ARRAYLENGTH; i++)
    {
        ball[i]->enable = false;
        ball[i]->usegravity = false;
        ball[i]->wallcollision = false;
        ball[i]->floorcollision = false;
    }

    glutDisplayFunc(displayfunc); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
    glutKeyboardFunc(keyboardfunc);
    glutMouseFunc(mousefunc);   // イベント処理関数が一度呼ばれると爆速で呼び出されまくるので正直 timer の需要がない。
    glutTimerFunc(1, timerfunc, 1);
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






