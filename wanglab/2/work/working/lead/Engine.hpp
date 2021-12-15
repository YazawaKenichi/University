#ifndef ENGINE_H
#define ENGINE_H

#include <math.h>
// #include <typeinfo> // 変数から型を推測するための関数に必要なヘッダ
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

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
    void setvector(Vector);
};

class Object
{
public:
    Color color;
    void setcolor(Color);
};

class Rigidbody : public Object
{
public:
    Polygon _polygon;
    Vectorfloat position;
    Quaternion rotation;
    Vectorfloat scale;
    float r;
    double signedeg;
    void draw();
};

class Ball : public Rigidbody 
{
public:
    static unsigned int count;
    Ball(Vectorfloat, Quaternion, Vectorfloat);
    Ball(Vectorfloat, float);
};

class Box : public Rigidbody
{
public:
    static unsigned int count;
    Box(Vectorfloat, Quaternion, Vectorfloat);
    Box(Vectorfloat, float);
};

void drawing(Rigidbody);

#endif
