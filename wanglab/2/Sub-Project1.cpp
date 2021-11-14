#include <GL/glut.h>
#include <iostream>

using namespace std;

typedef struct Coordinate   // 座標型
{
    int x;
    int y;
};

typedef struct Size
{
    int x;
    int y;
}

class Transform  // 基底クラス  // 位置・大きさ・（できれば）回転角度を格納する。
{
private:
    // Empty

protected:  // このクラス自身と、このクラスを継承したクラスからのみアクセスが可能。
    Coordinate position_offset;  // 初期位置を格納する。
    Corrdinate position; // 現在位置を格納する。
    Size size_offset;   // 初期サイズを格納する。
    Size size;  // 現在サイズを格納する。

public:
    void posofs(Coordinate cood)    // 初期位置を代入する関数
    {
        offset.x = cood.x;
        offset.y = cood.y;
        cout << "初期位置を決定しました。" << endl;
    }
    void position(Coordinate cood)
    {
        pos.x = cood.x
        pos.y = cood.y
    }
};

class Size
{
private:
    // Empty
protected:
    

class Ball : public Transform, public Rigidbody
{
public:
    draw()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 0.5, 0.5)
};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0.5, 0.5);   // プリミティブの色を指定。   // Begin() する前に記述する必要がある。
    glBegin(GL_QUAD_STRIP); // ここを GL_QUADS にしたら、頂点が一つ凹んだ五角形になった。なんでや。
    glVertex2d(0.5, 0.5);
    glVertex2d(0.5, -0.5);
    glVertex2d(-0.5, 0.5);
    glVertex2d(-0.5, -0.5);
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0, 0.75, 0.75, 1.0); // 背景をピンク色に指定。
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}

/// References
// http://web.wakayama-u.ac.jp/~wuhy/03_color.html  // プリミティブの色を変更する方法
// http://vivi.dyndns.org/tech/cpp/class-basic.html // C++ クラスの定義
// https://programming.pc-note.net/cpp/class2.html  // クラスの定義の仕方と public private protected の違い。
// https://programming.pc-note.net/cpp/inheritance.html // クラス継承の方法

