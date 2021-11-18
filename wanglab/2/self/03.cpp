#include <GL/gl.h>
#include <GL/glut.h>
#include "common2d.h"

void disp(void)
{
    commonbufferinit(GL_COLOR_BUFFER_BIT, 1.0, 0.75, 0.75, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9, 0.9);
    glVertex2f(-0.9, -0.9);
    glVertex2f(0.9, 0.9);
    glEnd();
    glFinish(); // glFlush(); と違うのは、glFlush はコマンドの終了を待たずに一定時間以内に処理を再開しに戻ってくるが、Finish はコマンドの実行が終了するまで戻ってこない。
}

int main(int argc, char *argv[])
{
    commonglutinit(argc, argv, WINDOWPOSITION, WINDOWSIZE, GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("This is top level window.");
    glutDisplayFunc(disp);
    glutMainLoop();

    return 0;
}

