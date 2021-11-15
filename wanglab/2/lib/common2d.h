#ifndef COMMON2D_H
#define COMMON2D_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

typedef struct
{
    int x;
    int y;
} Coordinate;

typedef struct
{
    int x;
    int y;
} Scale;

class Coordinatetranslate   // OpenGL 特有の座標系を直感的にわかりやすい解像度指定で記述できるようにするための変換関数の作成
{
public:
    static GLdouble x(int); // 実態が無くても使えるように static 型として定義する   // これどうやって C で実装するんだ？Class の概念が存在しない C で struct を用いてこれを実装する方法が知りたいかも。
    static GLdouble y(int);
};

static const Coordinate WINDOWPOSITION = {100, 100};
static const Scale WINDOWSIZE = {400, 400};

void commonbufferinit(GLbitfield, GLclampf, GLclampf, GLclampf, GLclampf);
void commonglutinit(int argc, char *argv[], Coordinate, Scale, unsigned int);
void commonglVertex2d(int, int);

#endif

