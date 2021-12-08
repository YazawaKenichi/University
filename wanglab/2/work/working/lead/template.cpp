//

// #include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

typedef struct
{
    int X;
    int Y;
} WindowSize;

static const unsigned short int ms = 1; // mil sec

//////////////////////////// 以下 コールバック関数 display //////////////////////

void display(void)
{
    glClearColor(0.0, 0.0, 0, 1); // バッファを塗りつぶしたい色
    glClear(GL_COLOR_BUFFER_BIT); // 指定したバッファを特定の色で消去する。 

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 0);

    glEnd();
//    glFlush();
    glutSwapBuffers();    // 処理の強制実行。   // glutSwapBuffers() は、glInitDisplayMode() で GL_DOUBLE を指定したときにだけ
}

///////////////////////////////////// 以上 被コールバック関数 display ///////////////////////////////////

void idle()   // 1 秒ごとに呼び出される。
{
    glutPostRedisplay();
}

void keyboard(int key, int x, int y)
{
    switch(key)
    {
        default:
            glutIdleFunc(NULL);
            break;
    }
}

void mouse(int button, int state, int argumentx, int argumenty)
{
    // なぜかここで計算できてない
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                glutIdleFunc(idle);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN)
            {
                glutIdleFunc(idle);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state == GLUT_DOWN)
            {
                glutIdleFunc(idle);
            }
            break;
        default:
            glutIdleFunc(NULL);
            break;
    }
}

void timer(int value)
{
    glutTimerFunc(ms * pow(10, -3), timer, 0);
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
    glutCreateWindow("");    // ウィンドウを生成。
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);

    glutDisplayFunc(display); // ウィンドウの再描画が必要であると判断された時に呼び出される。ディスプレイコールバックの登録。
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);   // イベント処理関数が一度呼ばれると爆速で呼び出されまくるので正直 timer の需要がない。
    glutTimerFunc(1, timer, 0);
    glutReshapeFunc(reshape);

    glutMainLoop();   // GLUT がイベント処理ループに入るようにする。こうすればトップレベルウィンドウが破棄されるまで処理は戻ってこない。
    return 0;
}





