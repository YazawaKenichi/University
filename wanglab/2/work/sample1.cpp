// sample1.c をパックマンに改造した形。キー入力を受け付けるタイプの完全形。

#if false
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
#define DEBUGMODE2 1

// using namespace std;

enum Direction{RIGHT, UP, LEFT, DOWN} direction;    // これに quarter を掛ければ方向（toward）がけっていして、±keepou/2 だけ黒塗りすれば完成t

static const int POLYGON = 36;  // 何角形
static const double QUARTER = M_PI / 2;
static const double r = 0.75; // パックマン自身の大きさ

// パックマンの口の開き方のパターン
static const unsigned short int MAXIMUM = 90;
static const unsigned short int MIDDLE = 30;
static const unsigned short int MINIMUM = 0;

unsigned short int keepoutdeg;  // パックマンの口の角度を度数法で指定する。
bool timeren = true;

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
    for(int i = 0; i < 360 / 15; i++)
    {
        glVertex2d(cos(i * M_PI * 15 / 180), sin(i * M_PI * 15 / 180));
        glVertex2d(0, 0);
    }
    glEnd();
#endif

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 0);

    double keepout = M_PI * keepoutdeg / 180;
    signed short int minus = +1;

//    direction = RIGHT;

    for(int j = 0; j < 2; j++)
    {
#if DEBUGMODE
        printf("j = %2d ", j);
#endif
        minus = pow(-1, j); // 一周目は theta が正になるように、二週目は theta が負になるようにする。
#if DEBUGMODE
        printf("minus = %3d ", minus);
        printf("\n");
#endif
        for(int i = 0; i <= POLYGON / 2; i++)
        {
            theta = (2 * M_PI / POLYGON) * i;
#if DEBUGMODE
            printf("i = %3d ", i);
            printf("\n");
#endif
            if(2 * M_PI * i / POLYGON >= keepout / 2)
            {
#if DEBUGMODE
                printf("2 * M_PI * i / POLYGON >= keepout / 2 ");
                printf("\n");
#endif
                glVertex2d(r * cos(minus * theta + QUARTER * direction), r * sin(minus * theta + QUARTER * direction));
#if DEBUGMODE
                printf("theta = %5.3lf direction = %2d cos(%5.3lf) = %5.3lf sin(%5.3lf) = %5.3lf", theta, direction, minus * theta + QUARTER * direction, cos(minus * theta + QUARTER * direction), minus * theta + QUARTER * direction, sin(minus * theta + QUARTER * direction));
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

void timer(int hogehoge)    // 引数の名称を舐め腐った名称にすることで使わないことを明示
{
    if(timeren)
    {
        static bool closing;
        if(keepoutdeg > MIDDLE)
        {
            keepoutdeg = MIDDLE;
            closing = true;
        }
        else if(MAXIMUM > keepoutdeg && keepoutdeg > MINIMUM)
        {
            if(closing)
            {
                keepoutdeg = MINIMUM;
            }
            else
            {
                keepoutdeg = MAXIMUM;
            }
        }
        else if(MIDDLE > keepoutdeg)
        {
            keepoutdeg = MIDDLE;
            closing = false;
        }
        glutPostRedisplay();
    }
    timeren = false;
    glutTimerFunc(50, timer, 0);
}

void keyboard(unsigned char key, int hogehoge, int fugafuga)
{
    switch(key)
    {
        // キーの判断
        case 'f':
            direction = RIGHT;
            break;
        case 'e':
            direction = UP;
            break;
        case 's':
            direction = LEFT;
            break;
        case 'd':
            direction = DOWN;
            break;
        default:
            break;
    }

    switch(key)
    {
        case 'f':
        case 'e':
        case 's':
        case 'd':
            timeren = true;
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);    // GLUT の初期化。
    glutInitDisplayMode(GLUT_RGBA);   // ウィンドウのカラーモデルやバッファの設定を行うための関数。
    glutCreateWindow("PACMAN");    // ウィンドウを生成。
    glutInitWindowSize(720, 720);
    glClearColor(0, 0, 0, 1);
    keepoutdeg = 0;

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

#endif

