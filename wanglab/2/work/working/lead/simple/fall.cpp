// sample1.c で円を描画してからそれを落とすプログラム。

#if false   // 実行ファイルが大きくならないようにする配慮   // こんなことしなくてもコメントアウトはビルドされないのかもしれないけど...
/*
                       ■                                                                                   ■    ■■                    ■                                                                                                        
                 ■■   ■■■                                                                                 ■■■  ■■■■                  ■■■                                                                                                       
                 ■■■  ■■■                                                                                 ■■■   ■■■                  ■■■                                                                                                       
                 ■■■  ■■■                                                                                 ■■■   ■■■                  ■■■                                                                ■■                                     
         ■       ■■■  ■■■                                                                                 ■■■   ■■■                  ■■■                                                               ■■■                                     
        ■■■      ■■■  ■■■                                                                                 ■■■   ■■■             ■■■■■■■■■■■■■■                                                         ■■■                                     
        ■■■      ■■■  ■■■■                                                                                ■■■■  ■■■            ■■■■■■■■■■■■■■■■                                                        ■■■                                     
        ■■■      ■■■   ■■■                                                                                 ■■■  ■■■             ■■■■■■■■■■■■■■■                                                        ■■■                                     
        ■■■      ■■■   ■■■                                                                                 ■■■   ■■                  ■■■    ■■■                                                        ■■■                                     
        ■■■      ■■■    ■                                                                                  ■■               ■■■■■■■■■■■■■■■■■■■■■■                                                      ■■■   ■■■                              
        ■■■                                                                                     ■■■■■■■■■                  ■■■■■■■■■■■■■■■■■■■■■■■■                                                ■■■■■■■■■■■■■■■                             
        ■■■                                                ■■                        ■■■■■■■■■■■■■■■■■■■■■                  ■■■■■■■■■■■■■■■■■■■■■■                                                 ■■■■■■■■■■■■■■                              
■■■■■■■■■■■■■■■■■■■■                                      ■■■■                       ■■■■■■■■■■■■■■■■■■■■                            ■■■    ■■■                                       ■            ■■■■■■■■■■■■                                
■■■■■■■■■■■■■■■■■■■■■                                     ■■■                         ■■■■■■■■■■■■■■■■■                        ■■■■■■■■■■■■■■■■                 ■■■                  ■■■               ■■■                                     
■■■■■■■■■■■■■■■■■■■■■                                    ■■■■                                  ■■■■■■                          ■■■■■■■■■■■■■■■                  ■■■                  ■■■■              ■■■                                     
■■■               ■■■                     ■■             ■■■                                  ■■■■■                            ■■■■■■■■■■■■■■■                  ■■■                   ■■■              ■■■                  ■                  
■■■               ■■■                    ■■■            ■■■■                                  ■■■■                                   ■■■                        ■■■                   ■■■              ■■■         ■■■■■■■■■■■                 
■■■               ■■■                    ■■■            ■■■                                  ■■■■                              ■■■■■■■■■■■■■■■■                 ■■■                    ■■■             ■■■        ■■■■■■■■■■■■                 
■■■               ■■■                   ■■■            ■■■■                                 ■■■■                              ■■■■■■■■■■■■■■■■■■                ■■■                    ■■■             ■■■         ■■■■■■■■■■■                 
■■                ■■■                  ■■■■            ■■■                                  ■■■                                ■■■■■■■■■■■■■■■■                  ■■■  ■■■              ■■■             ■■■                ■■■                  
■■               ■■■■                 ■■■■             ■■■         ■■■                     ■■■                                       ■■■                         ■■■  ■■■              ■■■            ■■■                ■■■■                  
■■               ■■■                 ■■■■             ■■■          ■■■                     ■■■                             ■■■■■■■■■■■■■■■■■■■■■■■■              ■■■  ■■■              ■■■            ■■■                ■■■                   
                 ■■■               ■■■■■              ■■■           ■■■                    ■■■                             ■■■■■■■■■■■■■■■■■■■■■■■■              ■■■ ■■■■              ■■■            ■■■                                      
                ■■■■             ■■■■■■              ■■■            ■■■■                   ■■■                             ■■■■■■■■■■■■■■■■■■■■■■■■              ■■■ ■■■               ■■■            ■■■                                      
                ■■■           ■■■■■■■■■              ■■■             ■■■■                  ■■■                                                                    ■■■■■■              ■■■■           ■■■                                       
               ■■■■          ■■■■■■ ■■■             ■■■               ■■■                  ■■■                                  ■■■■■■■■■■■■■■                    ■■■■■■              ■■■            ■■■                              ■■■■■■■  
              ■■■■           ■■■■   ■■■             ■■■■■■■■■■■■■■■■■■■■■■                  ■■■                                ■■■■■■■■■■■■■■■■                   ■■■■■               ■■■                                             ■■■■■■■■ 
             ■■■■                   ■■■            ■■■■■■■■■■■■■■■■■■■■■■■■                 ■■■■                               ■■■■■■■■■■■■■■■■                    ■■■■                ■■                                            ■■■■  ■■■ 
            ■■■■                    ■■■             ■■■■■■■■■■■■■■■■■■■■■■■                  ■■■■                              ■■■          ■■■                    ■■■■                                           ■■                 ■■■    ■■■
          ■■■■■                     ■■■                                  ■■■                 ■■■■■■                            ■■■■■■■■■■■■■■■■                    ■■■                                            ■■■               ■■■     ■■■
         ■■■■■                      ■■■                                  ■■■                   ■■■■■■■                         ■■■■■■■■■■■■■■■■                     ■                                             ■■■■■■   ■■       ■■■     ■■■
        ■■■■■                       ■■■                                                         ■■■■■■■                        ■■■■■■■■■■■■■■■■                                                                    ■■■■■■■■■■■       ■■     ■■■
         ■■                          ■■                                                           ■■■■                         ■■■          ■■■                                                                     ■■■■■■■■■■       ■■■   ■■■■
                                                                                                                               ■■■          ■■■                                                                        ■■■■          ■■■■■■■■■ 
                                                                                                                               ■■■■■■■■■■■■■■■■                                                                                       ■■■■■■■  
                                                                                                                                ■■■■■■■■■■■■■■                                                                                         ■■■■■   
 * */
#endif

// #include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>
#include "../Engine.hpp"

#define DEBUGMODE 0
#define DEBUGMODE2 1
#define DEBUGMODE3 1

// glVertex2f(2 * vector.x / WINDOWSIZE.X - 1, -2 * vector.y / WINDOWSIZE.Y + 1);

double direction;  // 向く方向を決める。あとで値が PI / 4 倍されることに注意。
bool timeren = true;
Mouse mouse;
unsigned char ballcount = 0;
Vectorfloat offset = {(float) 0, (float) 0};
Ball ball(offset, 0.1f);

//////////////////////////// 以下 コールバック関数 display //////////////////////

void displayfunc(void)
{
    double theta;

    glClearColor(0.0, 0.0, 0, 1); // バッファを塗りつぶしたい色
    glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 

    ball.draw();

    glEnd();
//    glFlush();
    glutSwapBuffers();    // 処理の強制実行。
}

///////////////////////////////////// 以上 被コールバック関数 display ///////////////////////////////////

void timerfunc(int hogehoge)
{
    // ここに物理計算を記述する
    glutTimerFunc(1 * pow(10, -3), timerfunc, 0);
}

void reshapefunc(int hogehoge, int fugafuga)
{
    glutReshapeWindow(WINDOWSIZE.X, WINDOWSIZE.Y);
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
#if DEBUGMODE
        printf("getops = { %5d, %5d }\n", getops.x, getops.y);
#endif
        mouse.setvector(getpos);    // mouse.vectorfloat に値が代入される。
        switch(button)
        {
            case GLUT_LEFT_BUTTON:
                ball.position = mouse.vectorfloat;
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

    glutDisplayFunc(displayfunc); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
    glutReshapeFunc(reshapefunc);
    glutKeyboardFunc(keyboardfunc);
    glutMouseFunc(mousefunc);   // イベント処理関数が一度呼ばれると爆速で呼び出されまくるので正直 timer の需要がない。
    glutTimerFunc(1, timerfunc, 0);

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

