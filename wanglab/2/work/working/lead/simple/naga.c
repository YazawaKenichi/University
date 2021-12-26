#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h>

static const float G = 9.8;
static const double E = 0.95; // 0.745;  // 反発係数

static const float DT = 10;     // 単位 ms のはずなんだけどなぁ...

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
    char wallclmode;
    char floorclmode;
    Vector position;
    Rotation rotation;
    Scale scale;
    Vector velocity;
    Vector accel;
} Ball;

Ball ball;

void ballprintf()
{
    printf("accel = {%5.3lf, %5.3lf}\n", ball.accel.x, ball.accel.y);
    printf("velocity = {%5.3lf, %5.3lf}\n", ball.velocity.x, ball.velocity.y);
    printf("Position = {%5.3lf, %5.3lf}\n", ball.position.x, ball.position.y);
    printf("Rotation = {%5.3lf}\n", ball.rotation.alpha);
    printf("Scale = {%5.3lf, %5.3lf}\n", ball.scale.x, ball.scale.y);
}

void ballinit()
{
    ball.wallclmode = 0;
    ball.floorclmode = 0;
    ball.position.x = 0;
    ball.position.y = 0;
    ball.velocity.x = 0;
    ball.velocity.y = 0;
    ball.accel.x = 50;
    ball.accel.x = 0;
    ball.accel.y = 0;
    ball.rotation.alpha = 0;
    ball.scale.r = 0.05;
    ball.scale.x = 2 * ball.scale.r;
    ball.scale.y = 2 * ball.scale.r;
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
    if(a)
    {
        srand((unsigned int) time(NULL));
        ball.accel.x = ((rand() % (200 + 1)) - 100) * 2;
        glutTimerFunc(1, timer, 0);
        return ;
    }
    float htangent = ball.position.y + ball.scale.y * ((ball.position.y > 0) ? 1 : -1) / 2;
    if(!ball.wallclmode && (htangent <= -1 || 1 <= htangent))
    {
        ball.wallclmode = 1;
        if(htangent > 0)
        {
            printf("天井に衝突\n");
            ball.position.y = 1 - ball.scale.y / 2;
        }
        if(htangent < 0)    // 床だった時
        {
            printf("床に衝突\n");
            ball.position.y = -(1 - ball.scale.y / 2);
        }
        ball.velocity.y += ball.accel.y * DT / 1000;
        ball.accel.y = -G;
        ball.velocity.y = -E * ball.velocity.y;
        ball.position.y += ball.velocity.y * DT / 1000;
    }
    else
    {
        printf("天井にも床にも衝突してない\n");
        ball.wallclmode = 0;
        ball.velocity.y += (-G + ball.accel.y) * DT / 1000;
        ball.position.y += ball.velocity.y * DT / 1000;
        ball.accel.y = -G * DT / 1000;
    }

    float vtangent = ball.position.x + ball.scale.x * ((ball.position.x > 0) ? 1 : -1) / 2;
    if(!ball.floorclmode && (vtangent < -1 || 1 < vtangent))
    {
        ball.floorclmode = 1;
        if(vtangent > 0)    // 右壁に衝突
        {
            printf("右壁に衝突\n");
            ball.position.x = 1 - ball.scale.x / 2;
            ball.accel.x = 0;
        }
        if(vtangent < 0)    // 左壁
        {
            printf("左壁に衝突\n");
            ball.position.x = -(1 - ball.scale.x / 2);
            ball.accel.x = 0;
        }
        ball.velocity.x += ball.accel.x * DT / 1000;
        ball.velocity.x = -E * ball.velocity.x;
        ball.position.x += ball.velocity.x * DT / 1000;
        ball.accel.x = 0;
    }
    else
    {
        printf("壁には衝突していない\n");
        ball.floorclmode = 0;
        ball.velocity.x += ball.accel.x * DT / 1000;
        ball.position.x += ball.velocity.x * DT / 1000;
        ball.accel.x = 0;
    }

    ballprintf();

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
    ballinit();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow(argv[0]);
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
//    glutMouseFunc(mouse);
    glutTimerFunc(1, timer, 1);
    
    glutMainLoop();
    return 0;
}

