#ifndef ENGINE_H
#define ENGINE_H

#include <math.h>
#include <typeinfo> // 変数から型を推測するための関数に必要なヘッダ
// typeid() を使っている。

typedef struct
{
    int X;
    int Y;
} WindowSize;

typedef struct
{
    int x;
    int y;
} Vector;

typedef struct
{
    float x;
    float y;
    float z;
    float w;
} Quaternion;

typedef struct
{
    float x;
    float y;
} Vectorfloat;

typedef struct
{
    float r;
    float g;
    float b;
} Color;


typedef enum
{
    TRIANGLE = 3,
    SQUARE = 4,
    CIRCLE = 36
} Polygon;

static const double QUARTER = M_PI / 2;
#ifndef WINDOWSIZE
static const WindowSize WINDOWSIZE = {300, 300};
#endif

class Mouse
{
public:
    Vector vector;
    Vectorfloat vectorfloat;
    Mouse();
    void setvector(vector);
}

class Object
{
public:
    Vectorfloat position;
    Quaternion rotation;
    Vectorfloat scale;
    Color color;
    void setcolor(Color);
    float r;
    double signedeg;
}

class Ball : public Object
{
private:
    Polygon _polygon = CIRCLE;
public:
    static unsigned int count;
    Ball(Vectorfloat, Quaternion, Vectorfloat);
    Ball(Vectorfloat, float);
    void draw();
}

class Box : public Object
{
private:
    Polygon _polygon = SQUARE;
public:
    static unsigned int count;
    Box(Vectorfloat, Quaternion, Vectorfloat);
    Box(Vectorfloat, float);
    void draw();
}

template <typename T>
void glVertex(T);

#endif
