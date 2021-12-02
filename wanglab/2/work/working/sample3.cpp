// sample3.c
// 四角形の描画の部分を sample1.c の描画部分に置き換えて、多角形か円形に描画できるようにする。
// その描画した正方形か円形を横に移動できるようにする。
// Sub-Project1:多角形の端点を追加し、円に近似
// Sub-ProJect2:正方形か円を横方向に移動できるようにする
// Sub-Project3:両端の壁を作り、ボールが壁に接触したら、止まったり跳ね返ったりして移動することをシミュレーションする。
// Sub-Project4:上下の壁も作り、閉じた空間の中に、ボールが二次元平面での並進運動をし、上下左右の壁に跳ね返ることを実現。
// Sub-Project5:ボールを床の上に転がることをシミュレーションする（設置点が滑らないように、並進移動と回転を正しくシミュレーションする）
// Sub-Project6:ニコのボールを作って、同様に空間中での自由運動、転がりを実現するとともに、ボール間の衝突をシミュレーション（複数のボールへの拡張）
// Sub-Project7:衝突に伴うエネルギー損失と、床での転がりの際の摩擦抵抗による速度の減少をシミュレーション
// チャレンジ課題：キー入力による走っているプログラムへの制御の方法を勉強し、初期的なコンピュータゲームのチャレンジ

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

static GLfloat ang = 0.0;
static const int POLYGON = 36;
static const double r = 0.75;

void display(void)
{
    double theta;
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    signed short int minus = +1;
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLE_STRIP);

    for(int j = 0; j < 2; j++)
    {
        minus = pow(-1, j);
        for(int i = 0; i <= POLYGON / 2; i++)
        {
            theta = (2 * M_PI / POLYGON) * i;
            glVertex2d(r * cos(minus * theta + ang), r * sin(minus * theta + ang));
            glVertex2d(0, 0);
            printf("theta = %5.3lf r = %5.3lf r * minus * theta + ang = %5.3lf", theta, r, r * minus * theta + ang);
            printf("\n");
        }
    }
    glEnd();
    glFlush();
}

void simu(void)
{
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
                glutIdleFunc(simu);
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == '\x1b')
        exit(0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}



