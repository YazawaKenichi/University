#include <GL/gl.h>
#include <GL/glut.h>
#include "common2d.h"

GLfloat fore[4], back[4];

void disp(void)
{
    glColor3fv(fore);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, -0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, 0.9);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    commonglutinit(argc, argv, {100, 50}, {400, 300}, GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("This is a top level window.");
    glutDisplayFunc(disp);
    glGetFloatv(GL_CURRENT_COLOR, back);
    glGetFloatv(GL_CLEAR_BUFFER, fore);

    glutMainLoop();

    return 0;
}



