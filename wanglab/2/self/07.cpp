#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "common2d.h"

using namespace std;

void disp(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glEdgeFlag(GL_TRUE);
    glEdgeFlag(GL_TRUE); glVertex2f(-0.9 , -0.5);   // glEdgeFlag の引数に GL_TRUE を入れると、ポリゴンの境界を使うことができるようになる。
    // これを使うことで任意の図形の塗りつぶしを作ることが可能。
    glEdgeFlag(GL_TRUE); glVertex2f(-0.85 , 0.9);
    glEdgeFlag(GL_FALSE);glVertex2f(0 , 0.3);

    // glEdgeFlag に GL_TRUE を渡した後の頂点は、境界辺の開始点であると判断され、GL_FALSE を渡した後の頂点は、境界辺の開始点ではないと判断される。
    // この状態をエッジフラグという。
    glEdgeFlag(GL_TRUE); glVertex2f(-0.9 , -0.5);
    glEdgeFlag(GL_FALSE);glVertex2f(0.9 , -0.5);
    glEdgeFlag(GL_TRUE); glVertex2f(0 , 0.3);

    // なんか参考サイトは
    // 「複雑なポリゴンの描画は複数個の三角形で構成します。しかし、複数の三角形で複雑なポリゴンを構成する場合、一部の辺が図の内部に埋もれます。これでは境界線がどこにあるのかわかりません。」
    // って、ポリゴンの境界線は重なってない方がいい。どこに境界があるかわかったほうがいい。みたいな記述してるけど、それなんか意味あんの？
    // ポリゴンの境界が明示的になって何かメリットはあるの？
    glEdgeFlag(GL_TRUE); glVertex2f(0.85 , 0.9);
    glEdgeFlag(GL_FALSE);glVertex2f(0.9 , -0.5);
    glEdgeFlag(GL_FALSE);glVertex2f(0 , 0.3);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    commonglutinit(argc, argv, {100, 50}, {400, 300}, GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("This is a top level window.");
    glutDisplayFunc(disp);

    glutMainLoop();

    return 0;
}



