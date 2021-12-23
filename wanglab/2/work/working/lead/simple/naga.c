#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

typedef struct
{
    GLfloat x;
    GLfloat y;
} Position;

typedef struct
{
    GLfloat alpha;
} Rotation;

typedef struct
{
    GLfloat x;
    GLfloat y;
    GLfloat r;
} Scale;

typedef struct
{
    Position position;
    Rotation rotation;
    Scale scale;
} Ball;

Ball ball;

void ballinit()
{
    ball.position = {0, 0};
    ball.rotation = {0, 0};
    ball.scale.r = 0.05;
    ball.scale = {2 * r, 2 * r};
}

void display()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 1);

    for(int i = 0; i <= 36; i++)
    {
        theta = (2 * M_PI / 36) * i;
        glVertex2d(ball.scale.r * cos(theta + ball.rotation.theta) + ball.position.x, ball.scale.r * sin(theta + ball.rotation.theta) + ball.position.y);
        glVertex2d(ball.position.x, ball.position.y);
    }

    glEnd();
    glutSwapBuffers();
}

void timer(int a)
{
    ball.accel.y = ball.g;
    ball.physics();
    glutTimerFunc(DT, timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case '0x1b':
            exit(0);
            break;
        default:
            break;
    }
}

/*
void mouse(int button, int state, int x, int y)
{
}
*/

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow(argv);
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(1, timer, 0);
    
    glutMainLoop();
    return 0;
}
























