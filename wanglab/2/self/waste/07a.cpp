#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "common2d.h"

using namespace std;

static const unsigned short int r = 0.75; // パックマン自身の大きさ
static const unsigned short int POLYGON = 36;


void disp(void)
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0);
    glBegin(GL_POLYGON);
    double theta;
    for(int i = 0; i < POLYGON; i++)
    {
        theta = (2 * M_PI / POLYGON) * i;
        glVertex2d(r * cos(theta), r * sin(theta));
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("This is a top level window.");
    glutInitWindowSize(1280, 720);
    glClearColor(0, 0, 0, 1);

    glutDisplayFunc(disp);

    glutMainLoop();
    return 0;
}



