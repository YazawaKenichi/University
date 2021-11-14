#include <GL/glut.h>
#include <iosteream>
#include "common.h"

using namespace std;

// コールバック関数の初めに差し込んで使う関数。バッファの初期化を梱包。
void commonbufferinit(GLbitfield mask, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    glClearColor(red, green, blue, alpha);
    glClear(mask);
}

// main 関数の初めに差し込んで使う関数。GLUT の初期化を梱包。
void commonglutinit(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(WINDOWPOSITION.x, WINDOWPOSITION.y);
    glutInitWindowSize(WINDOWSIZE.x, WINDOWSIZE.y);
    glutInitDisplayMode(GLUT_RGBA);
}




