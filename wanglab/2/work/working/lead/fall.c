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

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

// #include <iostream>  // C++ で書いてた頃の残骸。

#define DEBUGMODE 0
#define DEBUGMODE2 0

// using namespace std;

// enum Direction{RIGHT, UP, LEFT, DOWN} direction;    // これに quarter を掛ければ方向（toward）がけっていして、±keepou/2 だけ黒塗りすれば完成 // パックマンプログラムの名残

typedef struct
{
    int X;
    int Y;
} WindowSize;

typedef enum
{
    TRIANGLE = 3,   // 三角形のプログラムも実装してぇ...
    SQUARE = 4,
    CIRCLE = 36
} Polygon;

// static const int POLYGON = 36;  // 何角形
static const double QUARTER = M_PI / 2;
static const double r = 0.75; // パックマン自身の大きさ
static const double SPEED = 4; // 口の開閉速度  // 一秒間に SPEED 周期
static const WindowSize WINDOWSIZE = {300, 300};

// パックマンの口の開き方のパターン
// static const unsigned short int MAXIMUM = 90;
// static const unsigned short int MIDDLE = 30;
// static const unsigned short int MINIMUM = 0;
static const unsigned short int signedeg = 0;   // 回転運動が出来ているか見るためのサイン

unsigned short int keepoutdeg;  // パックマンの口の角度を度数法で指定する。初期値 90 deg
double direction;  // 向く方向を決める。あとで値が PI / 4 倍されることに注意。
bool timeren = true;
Polygon polygon;

//////////////////////////// 以下 変更するな //////////////////////

void display(void)
{
    double theta;
//    double toward = quarter * UP; // Direction から一つ選ぶとパックマンがその方向を向く。

    glClearColor(0.0, 0.0, 0, 1); // バッファを塗りつぶしたい色
    glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 

#if DEBUGMODE   // 15 度置きに線を引く（デバッグ用）
    glColor3f(0.5, 0.5, 1);
    glBegin(GL_LINES);
    static const unsigned short int LINEDEG = 10; // 何度置きに線を引くか
    for(int i = 0; i < 360 / LINEDEG; i++)
    {
        glVertex2d(cos(i * M_PI * LINEDEG / 180), sin(i * M_PI * LINEDEG / 180));
        glVertex2d(0, 0);
    }
    glEnd();
#endif

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 0);

    double keepout = (CIRCLE == polygon) ? M_PI * keepoutdeg / 180 : 0;
    signed short int minus = +1;

//    direction = RIGHT;

    for(int j = 0; j < 2; j++)
    {
#if DEBUGMODE
        printf("j = %2d ", j);
#endif
        minus = pow(-1, j); // 下で行われる for の、一周目は theta が正になるように、二週目は theta が負になるようにする。
#if DEBUGMODE
        printf("minus = %3d ", minus);
        printf("\n");
#endif
        for(int i = 0; i <= polygon / 2; i++)
        {
            theta = (2 * M_PI / polygon) * i;
#if DEBUGMODE
            printf("i = %3d ", i);
            printf("\n");
#endif
            if(2 * M_PI * i / polygon >= keepout / 2)
            {
#if DEBUGMODE
                printf("2 * M_PI * i / polygon >= keepout / 2 ");
                printf("\n");
#endif
                // 回転運動の実現はこの direction に適切な値を入れれば良い。QUARTER が掛けられていることに注意。
                glVertex2d(r * cos(minus * theta + QUARTER * direction), r * sin(minus * theta + QUARTER * direction));
#if DEBUGMODE
                printf("theta = %5.3lf direction = %5.3lf cos(%5.3lf) = %5.3lf sin(%5.3lf) = %5.3lf", theta, direction, minus * theta + QUARTER * direction, cos(minus * theta + QUARTER * direction), minus * theta + QUARTER * direction, sin(minus * theta + QUARTER * direction));
                printf("\n");
#endif
                glVertex2d(0, 0);   // 本プログラムの問題点は、パックマンの口の裂け目が円の中心から始まっていることを前提としている点である。実物の PACMAN をよく見ると中心からずれている。ただでさえ面倒くさかったのに更にそれを考慮するのはかなり面倒くさすぎるので妥協する。
            }
        }
    }
#if DEBUGMODE
    printf("\n");
#endif

    glEnd();
    glFlush();    // 処理の強制実行。
}

///////////////////////////////////// 以上 被コールバック関数 display ///////////////////////////////////

void timer(int first)   // 1 秒ごとに呼び出される。
{
    if(timeren)
    {
        keepoutdeg = signedeg;
        glutPostRedisplay();
    }
    timeren = false;
    glutTimerFunc(1000 * 1 / (4 * SPEED), timer, 0);
}

void keyboard(unsigned char key, int hogehoge, int fugafuga)
{
    switch(key)
    {
        // キーの判断
        case 'c':
            polygon = CIRCLE;
            break;
        case 's':
            polygon = SQUARE;
            break;
        default:
            break;
    }

    switch(key)
    {
        default:
            timeren = true;   // どこかで timeren = true にする必要がある。
            break;
    }
}

void reshape()
{
    glutReshapeWindow(WINDOWSIZE.X, WINDOWSIZE.Y);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);    // GLUT の初期化。
    glutInitDisplayMode(GLUT_RGBA);   // ウィンドウのカラーモデルやバッファの設定を行うための関数。
    glutInitWindowSize(WINDOWSIZE.X, WINDOWSIZE.Y);
    glutCreateWindow("PACMAN");    // ウィンドウを生成。

    glutReshapeFunc(reshape);
    glutDisplayFunc(display); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
    glutTimerFunc(1, timer, 0);
    glutKeyboardFunc(keyboard);
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

