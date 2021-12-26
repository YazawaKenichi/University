// ヘッダファイル

#ifndef ENGINE_H
#define ENGINE_H

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
    float a;
} Color;

typedef enum
{
    TRIANGLE = 3,
    SQUARE = 4,
    CIRCLE = 36
} Polygon;

static const double QUARTER = M_PI / 2;
static const unsigned short int utheta = 20;    // 物体が滑り出す傾き
static const unsigned short int DT = 25;  // 物理計算の積分周期 (ms)
static const double G = 9.80665;    // 重力加速度
static const double E = 0.8; // 0.745;  // 反発係数
#define U (tan(2 * M_PI * utheta / 360))    // 最大静止摩擦係数
static const double ud = U;  // 動摩擦係数
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
    Vectorfloat vectorfloatbuffer;
    Mouse();
    void setvector(Vector);
};

class Time
{
public:
    unsigned short int clockup;
    unsigned long long int time;
    unsigned short int seconds;
    unsigned short int minutes;
    unsigned short int hours;
    unsigned long long int miltime;
    void clock();
    Time();
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
    Vectorfloat position;   // 位置
    Quaternion rotation;    // 回転量
    Vectorfloat scale;  // サイズ
    Vectorfloat velocity;   // 速度
    Vectorfloat accel;    // 加速度
    bool enable;
    bool usegravity;
    bool wallcollision;
    bool floorcollision;
    float r;    // 外接円半径
    float m;    // 質量
    double signedeg;
    void draw();
    void printf();  // Rigidbody の情報を見るための printf をいくつも用意した関数。デバッグ用
    Rigidbody();
    Rigidbody(Vectorfloat, Vectorfloat, Vectorfloat);
    void physics();
};

class Ball : public Rigidbody 
{
public:
    Rigidbody buffer;
    Ball(Vectorfloat, Quaternion, Vectorfloat);
    Ball(Vectorfloat, float);
};

class Box : public Rigidbody
{
public:
    Box(Vectorfloat, Quaternion, Vectorfloat);
    Box(Vectorfloat, float);
};

float vectorlength2(Vectorfloat);
float totangent(Vectorfloat);
void printrotating(Rigidbody, Rigidbody, Rigidbody, Rigidbody);
void drawing(Rigidbody);
void rotationmatrix(Vectorfloat *, Vectorfloat *, float);
void collision(Rigidbody *, Rigidbody *);
Vectorfloat vectoradd(Vectorfloat, Vectorfloat);
Vectorfloat vectordifference(Vectorfloat, Vectorfloat);
Vectorfloat vectorproduct(Vectorfloat, float);
Vectorfloat vectorquotient(Vectorfloat, double);


#endif
