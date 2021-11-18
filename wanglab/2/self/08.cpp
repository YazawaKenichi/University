#include <GL/gl.h>
#include <GL/glut.h>
#include "common2d.h"

const GLfloat vertex[] = {-0.9, 0.9, 0.9, 0.9, 0, -0.9};

void disp(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);   // 配列を有効にする。

