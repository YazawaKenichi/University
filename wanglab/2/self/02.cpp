// できたー！
#include "common2d.h" // こいつが GL/gl.h と GL/glut.h と iostream を include してくれる

void run(void)
{
    commonbufferinit(GL_COLOR_BUFFER_BIT, 0.0, 0.00, 0.00, 0.0);
    glBegin(GL_TRIANGLES); // プリミティブを記述するための頂点の指定開始
    glColor3ub(0xFF, 0, 0);
    glVertex2f(0, 0);
    glColor3f(0, 0, 1);
    glVertex2f(-1, 0.9);
    glVertex2f(1, 0.9);

    glColor3i(2147483647, 0, 0);
    glVertex2f(0, 0);
    glColor3b(0, 127, 0);
    glVertex2f(-1, -0.9);
    glVertex2f(1, -0.9);
    glEnd();    // プリミティブを記述するための頂点の描画終了
    glFlush();
}

int main(int argc, char *argv[])
{
    Coordinate winpos = {100, 50};
    Scale winsiz = {500, 500};
    commonglutinit(argc, argv, winpos, winsiz, GLUT_SINGLE | GLUT_RGBA); // glutInit glutInitWindowPosition glutInitWindowSize glutInitDisplayMode

    glutCreateWindow("This is top level window.");
    glutDisplayFunc(run);
    glutMainLoop();

    return 0;
}


