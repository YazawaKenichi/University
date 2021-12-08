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
#include <typeinfo> // 変数から型を推測するための関数に必要なヘッダ // typeid() のための include
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

#define DEBUGMODE 0
#define DEBUGMODE2 1
#define DEBUGMODE3 1

typedef struct
{
    int X;
    int Y;
} WindowSize;

typedef struct
{
    int x;
    int y;
} Vector;

typedef struct
{
    float x;
    float y;
    float z;
    float w;
} Quaternion;

typedef struct
{
    float x;
    float y;
} Vectorfloat;

typedef enum
{
    TRIANGLE = 3,   // 三角形のプログラムも実装してぇ...
    SQUARE = 4,
    CIRCLE = 36
} Polygon;

class Ball
{
private:
    Polygon _polygon = CIRCLE;
public:
    static unsigned int count;  // この一つの変数を全ての Ball インスタンスが共有する。
    Vectorfloat position;
    Quaternion rotation;
    Vectorfloat scale;
    float r;    // 半径
    Ball(Vectorfloat, Quaternion, Vectorfloat);
    Ball(Vector);
    Ball(Vectorfloat, float);
}

Ball::Ball(Vectorfloat argumentposition, Quaternion argumentrotation, Vector argumentscale)
{
    position = argumentposition;
    rotation = argumentrotation;
    scale = argumentscale;
}

Ball::Ball(Vectorfloat argumentposition, float argumentr)
{
    position = argumentposition;    // 小数値で代入するのでそのまま glVertex にぶち込める。
    rotation = {0, 0, 0, 1};
    scale = {r, r}
}

glVertex(Vector vector)
{
    glVertex2f(2 * vector.x / WINDOWSIZE.X - 1, -2 * vector.y / WINDOWSIZE.Y + 1);
}

static const double QUARTER = M_PI / 2;
static const double r = 0.1; // パックマン自身の大きさ
static const WindowSize WINDOWSIZE = {300, 300};

template <typename T>   // 対応する型は Vector か Vectorfloat の二択
void glVertex(T argumentvector)
{
    if(typeid(argumentvector) == "Vector")
    {
        glVertex(2 * argumentvector.x / WINDOWSIZE.X - 1, -2 * argumentvector.y / WINDOWSIZE.Y + 1);
    }
    else if(typeid(argumentvector) == "Vectorfloat")
    {
        glVertex(argumentvector.x, argumentvector.y);
    }
    else
    {
        cout << "template type error" << endl;
    }
}

double direction;  // 向く方向を決める。あとで値が PI / 4 倍されることに注意。
bool timeren = true;
Vector mousevector = {0, 0};
Vectorfloat mousevectorfloat = {0, 0};
Polygon polygon;

//////////////////////////// 以下 コールバック関数 display //////////////////////

void display(void)
{
    double theta;

    glClearColor(0.0, 0.0, 0, 1); // バッファを塗りつぶしたい色
    glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 0);

    double keepout = (CIRCLE == polygon) ? M_PI * signedeg / 180 : 0;   // 円モードのときは回転でバッグラインを表示しない。
    signed short int minus = +1;

    mousevectorfloat.x = 2 * (double)mousevector.x / WINDOWSIZE.X - 1;
    mousevectorfloat.y = - 2 * (double)mousevector.y / WINDOWSIZE.Y + 1;

    for(int j = 0; j < 2; j++)
    {
        minus = pow(-1, j); // 下で行われる for の、一周目は theta が正になるように、二週目は theta が負になるようにする。
        for(int i = 0; i <= polygon / 2; i++)
        {
            theta = (2 * M_PI / polygon) * i;
            if(2 * M_PI * i / polygon >= keepout / 2)
            {
                // 回転運動の実現はこの direction に適切な値を入れれば良い。QUARTER が掛けられていることに注意。
                glVertex2d(r * cos(minus * theta + QUARTER * direction) + mousevectorfloat.x, r * sin(minus * theta + QUARTER * direction) + mousevectorfloat.y);
                glVertex2d(0 + mousevectorfloat.x, 0 + mousevectorfloat.y);   // 本プログラムの問題点は、パックマンの口の裂け目が円の中心から始まっていることを前提としている点である。実物の PACMAN をよく見ると中心からずれている。ただでさえ面倒くさかったのに更にそれを考慮するのはかなり面倒くさすぎるので妥協する。
            }
        }
    }
    glEnd();
//    glFlush();
    glutSwapBuffers();    // 処理の強制実行。
}

///////////////////////////////////// 以上 被コールバック関数 display ///////////////////////////////////

void idle()   // 1 秒ごとに呼び出される。
{
    glutPostRedisplay();
}

void mouse(int button, int state, int argumentx, int argumenty)
{
    // なぜかここで計算できてない
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                polygon = CIRCLE;
                mousevector.x = argumentx;   // argumentx, y は int 型、つまりピクセル座標が入る。それを OpenGL 特有の画面スケール座標に変換するためにウィンドウのサイズで割り算する。
                mousevector.y = argumenty;
                glutIdleFunc(idle);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN)
            {
                polygon = SQUARE;
                mousevector.x = argumentx;   // argumentx, y は int 型、つまりピクセル座標が入る。それを OpenGL 特有の画面スケール座標に変換するためにウィンドウのサイズで割り算する。
                mousevector.y = argumenty;
                glutIdleFunc(idle);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state == GLUT_DOWN)
            {
                glutIdleFunc(NULL);
                mousevector.x = argumentx;   // argumentx, y は int 型、つまりピクセル座標が入る。それを OpenGL 特有の画面スケール座標に変換するためにウィンドウのサイズで割り算する。
                mousevector.y = argumenty;
            }
            break;
        default:
            glutIdleFunc(NULL);
            break;
    }
}

void reshape()
{
    glutReshapeWindow(WINDOWSIZE.X, WINDOWSIZE.Y);
}

void timer(int hogehoge)
{
    glutTimerFunc(1 * pow(10, -3), timer, 0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);    // GLUT の初期化。
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);   // ウィンドウのカラーモデルやバッファの設定を行うための関数。
    glutInitWindowSize(WINDOWSIZE.X, WINDOWSIZE.Y);
    glutCreateWindow("Faling");    // ウィンドウを生成。
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);

    glutReshapeFunc(reshape);
    glutDisplayFunc(display); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
//    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);   // イベント処理関数が一度呼ばれると爆速で呼び出されまくるので正直 timer の需要がない。
    glutTimerFunc(1, timer, 0);
    glutDisplayFunc(display);

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

