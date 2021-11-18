#include "common2d.h"

using namespace std;

void disp(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void motion(int x, int y)
{
    cout << "X = " << x << " : Y = " << y << endl;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(400, 300);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("This is a top level window.");
    glutDisplayFunc(disp);
    glutMotionFunc(motion);

    glutMainLoop();
    return 0;
}

