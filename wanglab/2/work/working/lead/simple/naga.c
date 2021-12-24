#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

static const float G = -9.8;
static const float GRAVITY_RATE = -7.0;

static const float DT = 25;     // 単位 ms のはずなんだけどなぁ...

typedef struct
{
    float x;
    float y;
} Vector;

typedef struct
{
    float alpha;
} Rotation;

typedef struct
{
    float x;
    float y;
    float r;
} Scale;

typedef struct
{
    Vector position;
    Rotation rotation;
    Scale scale;
    Vector velocity;
    Vector accel;
} Ball;

Ball ball;

void printstate()
{
    printf("ball.accel = {%5.3f, %5.3f}\n", ball.accel.x, ball.accel.y);
    printf("ball.velocity = {%5.3f, %5.3f}\n", ball.velocity.x, ball.velocity.y);
    printf("ball.position = {%5.3f, %5.3f}\n", ball.position.x, ball.position.y);
    printf("\n");
}

void ballinit()
{
    ball.position.x = 0;
    ball.position.y = 0;
    ball.velocity.x = 0;
    ball.velocity.y = 0;
    ball.accel.x = 0;
    ball.accel.y = G * pow(10, GRAVITY_RATE);
    ball.rotation.alpha = 0;
    ball.scale.r = 0.05;
    ball.scale.x = 2 * ball.scale.r;
    ball.scale.y = 2 * ball.scale.r;
    printf("initialized\n");
    printstate();
}

void display()
{
    double theta;
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 1);

    for(int i = 0; i <= 36; i++)
    {
        theta = (2 * M_PI / 36) * i;
        glVertex2d(ball.scale.r * cos(theta + ball.rotation.alpha) + ball.position.x, ball.scale.r * sin(theta + ball.rotation.alpha) + ball.position.y);
        glVertex2d(ball.position.x, ball.position.y);
    }

    glEnd();
    glutSwapBuffers();
}

void timer(int a)
{
    ball.velocity.x += ball.accel.x * DT;
    ball.velocity.y += ball.accel.y * DT;
    ball.position.x += ball.velocity.x * DT;
    ball.position.y += ball.velocity.y * DT;
    printstate();
    printf("\x1b[4F");  // 4行上の先頭に移動
    printf("\x1b[0J");  // カーソルより後ろの画面を消去
    glutPostRedisplay();
    glutTimerFunc(DT, timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case '\x1b':
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
    glutCreateWindow(argv[0]);
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
    ballinit();
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
//    glutMouseFunc(mouse);
    glutTimerFunc(1, timer, 0);
    
    glutMainLoop();
    return 0;
}

