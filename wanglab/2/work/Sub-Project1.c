// C++ で書きたかった人生（大げさ）

#include <GL/glut.h>
#include <stdio.h>

static const int WINDOWWIDTH = 1280, WINDOWHEIGHT = 720;    // ウィンドウサイズの決定。

typedef struct  // ユークリッド型
{
    int x;
    int y;
} Coordinate;

typedef struct  // サイズ型
{
    int x;
    int y;
} Size;

typedef struct  // 回転角型 
{
    double arg;
} Rotate;

void Vertex2d(int x, int y)
{
    glVertex2d(x * 2 / WINDOWWIDTH - 1, y * 2 / WINDOWHEIGHT - 1);
}

typedef struct _Transform  // 基底クラス  // 位置・大きさ・（できれば）回転角度を格納する。
{
    Coordinate position_offset;  // 初期位置を格納する。
    Coordinate position; // 現在位置を格納する。
    Size size_offset;   // 初期サイズを格納する。
    Size size;  // 現在サイズを格納する。
    Rotate rotation_offset; // 初期回転角を格納する.
    Rotate rotation;    // 現在回転角を格納する。
} Transform;

void setpositionoffset(Coordinate *position_offset, Coordinate cood)    // 初期位置を代入する関数
{
    position_offset->x = cood.x;
    position_offset->y = cood.y;
    printf("初期位置を決定しました。\n");
}

void setposition(Coordinate *position, Coordinate cood)   // 現在位置を代入する関数
{
    position->x = cood.x;
    position->y = cood.y;
    printf("現在位置を決定しました。\n");
}

void setsizeoffset(Size *size_offset, Size siz)    // 初期サイズを代入する関数
{
    size_offset->x = siz.x;
    size_offset->y = siz.y;
    printf("初期サイズを決定しました。\n");
}

void setsize(Size *size, Size siz)  // 現在サイズを代入する関数
{
    size->x = siz.x;
    size->y = siz.y;
    printf("現在サイズを決定しました。\n");
}

typedef struct _Ball
{
    Transform transform;    // 疑似継承
/*
    void draw()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 0.5, 0.5);
        glBegin(GL_QUAD_STRIP);
        Vertex2d(position.x + size.x, position.y + size.y); // 右上の点
        Vertex2d(position.x + size.x, position.y - size.y); // 右下の点
        Vertex2d(position.x - size.x, position.y - size.y); // 左下の点
        Vertex2d(position.x - size.x, position.y + size.y); // 左上の点
        glEnd();
        glFlush();
    }
*/
} Ball;

void drawBall() // 悔しいけど代替策。これするくらいならわざわざ Ball をクラスにしないんだよなぁ。   // C++ 時代のメモ
{
    Ball obj;
    Coordinate nowpos = {50, 100};
    Size nowsiz = {70, 20};
    setposition(&obj.transform.position, nowpos);
    setsize(&obj.transform.size, nowsiz);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0.5, 0.5);
#if DEBUGMODE
    printf("glColor3f(1, 0.5, 0.5);\n");
#endif
    glBegin(GL_QUAD_STRIP);
    Vertex2d(obj.transform.position.x + obj.transform.size.x, obj.transform.position.y + obj.transform.size.y);
    Vertex2d(obj.transform.position.x + obj.transform.size.x, obj.transform.position.y - obj.transform.size.y);
    Vertex2d(obj.transform.position.x - obj.transform.size.x, obj.transform.position.y - obj.transform.size.y);
    Vertex2d(obj.transform.position.x - obj.transform.size.x, obj.transform.position.y + obj.transform.size.y);
    glEnd();
#if DEBUGMODE
    printf("glEnd();\n");
#endif
    glFlush();
#if DEBUGMODE
    printf("glFlush();\n");
#endif
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
    glutInitWindowSize(WINDOWWIDTH, WINDOWHEIGHT);
    // void (ball::*functionpointer)() = ball::draw;   // メンバメソッドポインタの定義と代入 // 言われてみればわかるけど普通にむずい
    // glutDisplayFunc((ball.*functionpointer)()); // メンバメソッドポインタの呼び出し  // やべー、メンバメソッドポインタで渡してぇ。でも全然やり方わかんねぇ。 // 参考サイト：http://www7b.biglobe.ne.jp/~robe/cpphtml/html03/cpp03057.html このサイトが一番読んでて納得できそうだった。結局わからずじまいだったけど...
    init();
    glutDisplayFunc(drawBall);
    glutMainLoop();
#if DEBUGMODE
    printf("glutMainLoop();\n");
#endif

    return 0;
}

/// References
// http://web.wakayama-u.ac.jp/~wuhy/03_color.html  // プリミティブの色を変更する方法
// http://vivi.dyndns.org/tech/cpp/class-basic.html // C++ クラスの定義
// https://programming.pc-note.net/cpp/class2.html  // クラスの定義の仕方と public private protected の違い
// https://programming.pc-note.net/cpp/inheritance.html // クラス継承の方法
// https://plaza.rakuten.co.jp/wasserblau/diary/200610260000/   // ウィンドウサイズの固定方法

/*

    プログラムの形状

    Ball クラスの中に、自己座標を決める Coordinate と、大きさを決める Size と、回転量を決める Rotate がある。これら三つを transform として継承している。(C プログラムなのであくまで擬似継承)

*/


