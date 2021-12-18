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
static const unsigned short int DT = 1;  // 物理計算の積分周期 (ms)
unsigned double dt = DT / 1000;
#ifndef WINDOWSIZE
static const WindowSize WINDOWSIZE = {300, 300};
#endif

class Mouse
{
public:
    bool hover; // マウス長押し判定
    unsigned long long int hovertime;   // マウス長押し時間 (DT の回数が入る)
    Vector vector;
    Vectorfloat vectorfloat;
    Mouse();
    void setvector(Vector);
};

class Time
{
public:
    unsigned long long int time;
    unsigned short int seconds;
    unsigned short int minits;
    unsigned short int hours;
    unsigned long long int miltime;
    Time();
};

class Object : public Time
{
public:
    Color color;
    void setcolor(Color);
};

class Rigidbody : public Object
{
public:
    Polygon _polygon;
    Vectorfloat position;   // 位置
    Quaternion rotation;    // 回転量
    Vectorfloat scale;  // サイズ
    Vectorfloat velocity;   // 速度
    Vectorfloat accel;    // 加速度
    float g;    // 重力加速度
    float r;    // 外接円半径
    float e;    // 反発係数
    double signedeg;
    void draw();
    Rigidbody();
    Rigidbody(Vectorfloat, Vectorfloat, Vectorfloat);
    void physics();
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
// void physics(Rigidbody *);
// void timerfunc(int, void *, int);
// void reshapefunc(int, int);
// void registor();

#endif



