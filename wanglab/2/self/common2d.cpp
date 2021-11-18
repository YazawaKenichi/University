#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "common2d.h"

using namespace std;

// コールバック関数の初めに差し込んで使う関数。バッファの初期化を梱包。
void commonbufferinit(GLbitfield mask, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    glClearColor(red, green, blue, alpha);
    glClear(mask);
}

// main 関数の初めに差し込んで使う関数。GLUT の初期化を梱包。
void commonglutinit(int argc, char *argv[], Coordinate windowposition, Scale windowsize, unsigned int mode)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(windowposition.x, windowposition.y);
    glutInitWindowSize(windowsize.x, windowsize.y);
    glutInitDisplayMode(mode);
}

/*
    基本構造

    void disp(void)
    {
        commonbufferinit(GL_COLOR_BUFFER_BIT, 1.0, 0.75, 0.75, 1.0);    // バッファの初期化
        // 描画の開始。
    }

    int main(int argc, char *argv[])
    {
        commonglutinit(argc, argv); // glut の初期化
        glutCreateWindow("This is top level window.");  // トップレベルウィンドウを生成する
        glutDisplayFunc(run);  // コールバック関数の登録
        glutMainLoop(); // 最後に呼び出されるべき関数
    }
*/

GLdouble Coordinatetranslate::x(int inx)    // クラスメンバメソッドの内容の定義。ゆーて OpenGL 特有の座標系を直感的にわかりやすいように記述できるようにするだけの関数。
{
    return (2 / WINDOWSIZE.x) * inx - 1;
}

GLdouble Coordinatetranslate::y(int iny)
{
    return (2 / WINDOWSIZE.y) * iny - 1;
}

void commonglVertex2d(int x, int y) // 自作した直感的にわかりやすい座標で指定できるように改造した Vertex2d で、特に抵抗無く使えるはず...
{
    glVertex2d(Coordinatetranslate::x(x), Coordinatetranslate::y(y));
}


