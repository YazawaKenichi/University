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

#include <stdio.h>
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
} Coordinate;

typedef struct
{
    float x;
    float y;
} Coordinatefloat;

typedef enum
{
    TRIANGLE = 3,   // 三角形のプログラムも実装してぇ...
    SQUARE = 4,
    CIRCLE = 36
} Polygon;

static const double QUARTER = M_PI / 2;
static const double r = 0.1; // パックマン自身の大きさ
static const WindowSize WINDOWSIZE = {300, 300};

#if DEBUGMODE2
static const unsigned short int signedeg = 0;   // 回転運動が出来ているか見るためのサイン   // 回転でバッグライン
#endif

#if DEBUGMODE
static const unsigned short int LINEDEG = 10; // 何度置きに線を引くか
#endif

double direction;  // 向く方向を決める。あとで値が PI / 4 倍されることに注意。
bool timeren = true;
Coordinate mousecoordinate = {0, 0};
Coordinatefloat mousecoordinatefloat = {0, 0};
Polygon polygon;

//////////////////////////// 以下 コールバック関数 display //////////////////////

void display(void)
{
    double theta;

    glClearColor(0.0, 0.0, 0, 1); // バッファを塗りつぶしたい色
    glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 

#if DEBUGMODE   // 15 度置きに線を引く（デバッグ用）
    glColor3f(0.5, 0.5, 1);
    glBegin(GL_LINES);
    for(int i = 0; i < 360 / LINEDEG; i++)
    {
        glVertex2d(cos(i * M_PI * LINEDEG / 180), sin(i * M_PI * LINEDEG / 180));
        glVertex2d(0, 0);
    }
    glEnd();
#endif

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 0);

    double keepout = (CIRCLE == polygon) ? M_PI * signedeg / 180 : 0;   // 円モードのときは回転でバッグラインを表示しない。
    signed short int minus = +1;

    mousecoordinatefloat.x = 2 * (double)mousecoordinate.x / WINDOWSIZE.X - 1;
    mousecoordinatefloat.y = - 2 * (double)mousecoordinate.y / WINDOWSIZE.Y + 1;

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
                glVertex2d(r * cos(minus * theta + QUARTER * direction) + mousecoordinatefloat.x, r * sin(minus * theta + QUARTER * direction) + mousecoordinatefloat.y);
#if DEBUGMODE
                printf("theta = %5.3lf direction = %5.3lf cos(%5.3lf) = %5.3lf sin(%5.3lf) = %5.3lf mousecoordinatefloat.x = %5.3f mousecoordinatefloat.y = %5.3f", theta, direction, minus * theta + QUARTER * direction, cos(minus * theta + QUARTER * direction), minus * theta + QUARTER * direction, sin(minus * theta + QUARTER * direction), mousecoordinatefloat.x, mousecoordinatefloat.y);
                printf("\n");
#endif
#if DEBUGMODE2
                printf("mousecoordinatefloat = {%5.3f, %5.3f}\n", mousecoordinatefloat.x, mousecoordinatefloat.y);
#endif
                glVertex2d(0 + mousecoordinatefloat.x, 0 + mousecoordinatefloat.y);   // 本プログラムの問題点は、パックマンの口の裂け目が円の中心から始まっていることを前提としている点である。実物の PACMAN をよく見ると中心からずれている。ただでさえ面倒くさかったのに更にそれを考慮するのはかなり面倒くさすぎるので妥協する。
            }
        }
    }
#if DEBUGMODE
    printf("\n");
#endif

    glEnd();
//    glFlush();
    glutSwapBuffers();    // 処理の強制実行。
}

///////////////////////////////////// 以上 被コールバック関数 display ///////////////////////////////////

void idle()   // 1 秒ごとに呼び出される。
{
//    glutPostRedisplay();  // この行をコメントアウトするとディスプレイが描画されなくなるはずなのに、ちゃんと描画される。なんで？
    // サポセン曰く、他のところでどこか再描画されるようになってるっぽい。
    // でもどの関数で再描画されるようになってんのかよくわかんないから、いつか沼りそう。
/*
    if(count == 0)
    {
        glutTimerFunc(1000, timer, count + 1);
        // この部分で OpenGL のタイマについてわかったことがある。
        // OpenGL のタイマは、glutTimerFunc で自分を呼び出すと永遠に自分を呼び続けるようになっている。
        // 実際にこの DEBUGMODE2 を 1 にしてこのプログラムを実行してみるとわかるが
        // 一周目は count がゼロで、glutTimerFunc を実行し
        // 二週目からは 引数に入っている count + 1 によって count には 1 が入り
        // その後三週目に入ろうとしても count != 0 となり glutTimerFunc は実行出来ない。
        // しかし count = 1 の状態で実行し続けることから、一度コールバックに登録すると永遠にコールバックされ続けることが分かった。
        // また、if(count == 0) と条件文の中に書かなくても同様の動作をする。
        // 具体的には、二週目までは同じ動作をし、三週目に入る時に count = 1 + 1 となり、三週目の count の値は 2 になるはずが、
        // 実際には 1 となっており、もうわけがわからない。
    }
*/
}

void mouse(int button, int state, int argumentx, int argumenty)
{
    // なぜかここで計算できてない
#if DEBUGMODE2
    printf("\033[3m In mouse\033[0m\n");
    printf("argumentx = %4d, argumenty = %4d\n", argumentx, argumenty);
#endif

    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                polygon = CIRCLE;
                mousecoordinate.x = argumentx;   // argumentx, y は int 型、つまりピクセル座標が入る。それを OpenGL 特有の画面スケール座標に変換するためにウィンドウのサイズで割り算する。
                mousecoordinate.y = argumenty;
                printf("mousecoordinate = {%4d, %4d}\n", mousecoordinate.x, mousecoordinate.y);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN)
            {
                polygon = SQUARE;
                mousecoordinate.x = argumentx;   // argumentx, y は int 型、つまりピクセル座標が入る。それを OpenGL 特有の画面スケール座標に変換するためにウィンドウのサイズで割り算する。
                mousecoordinate.y = argumenty;
                printf("mousecoordinate = {%4d, %4d}\n", mousecoordinate.x, mousecoordinate.y);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state == GLUT_DOWN)
            {
                mousecoordinate.x = argumentx;   // argumentx, y は int 型、つまりピクセル座標が入る。それを OpenGL 特有の画面スケール座標に変換するためにウィンドウのサイズで割り算する。
                mousecoordinate.y = argumenty;
                printf("mousecoordinate = {%4d, %4d}\n", mousecoordinate.x, mousecoordinate.y);
            }
            break;
        default:
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);   // ウィンドウのカラーモデルやバッファの設定を行うための関数。
    glutInitWindowSize(WINDOWSIZE.X, WINDOWSIZE.Y);
    glutCreateWindow("click");    // ウィンドウを生成。
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);

    glutReshapeFunc(reshape);
//    glutDisplayFunc(display); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
//    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);   // イベント処理関数が一度呼ばれると爆速で呼び出されまくるので正直 timer の需要がない。
//    glutTimerFunc(1, timer, 0);
    glutDisplayFunc(display);
//    glutIdleFunc(NULL);

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
#endif

