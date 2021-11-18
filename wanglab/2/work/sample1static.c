// sample1.c をパックマンに改造した形。direction を用いてパックマンの向きを変更できる。とりあえず提出できるように作ったプログラム。

///////////////////////memo////////////////////////////
//
// あとは キー入力を受け付けて、キーによって Direction を変更するプログラムを追加したい。
// キーを押下している間は口の開閉を繰り返すプログラムを追加したい。
//
///////////////////////////////////////////////////////

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

// #include <iostream>

#define DEBUGMODE 0

// using namespace std;

enum Direction{RIGHT, UP, LEFT, DOWN} direction;    // これに quarter を掛ければ方向（toward）がけっていして、±keepou/2 だけ黒塗りすれば完成t

static const int POLYGON = 36;  // 何角形
static const double QUARTER = M_PI / 2;

float r = 0.75; // パックマン自身の大きさ

int keepoutdeg = 90;  // パックマンの口の角度を度数法で指定する。
double toward;

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

    direction = RIGHT;

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
                glVertex2d(0, 0);
            }
        }
    }
#if DEBUGMODE
    printf("\n");
#endif

    glEnd();
    glFlush();    // 処理の強制実行。
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // glViewPort で指定した範囲を塗りつぶすことが可能らしいが、glViewPort ってなんや？
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);    // GLUT の初期化。
    glutInitDisplayMode(GLUT_RGBA);   // ウィンドウのカラーモデルやバッファの設定を行うための関数。
    glutCreateWindow(argv[0]);    // ウィンドウを生成。
    glutInitWindowSize(1280, 720);
    init();

    glutDisplayFunc(display); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
    glutMainLoop();   // GLUT がイベント処理ループに入るようにする。こうすればトップレベルウィンドウが破棄されるまで処理は戻ってこない。
    return 0;
}



