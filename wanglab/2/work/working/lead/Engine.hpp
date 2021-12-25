#ifndef ENGINE_H
#define ENGINE_H

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
static const unsigned short int utheta = 20;    // 物体が滑り出す傾き
static const unsigned short int DT = 10;  // 物理計算の積分周期 (ms)
static const double G = 50;// 9.80665;    // 重力加速度
static const double E = 0.8; // 0.745;  // 反発係数
#define U (tan(2 * M_PI * utheta / 360))    // 摩擦係数
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
    Vectorfloat collide;  // 衝突して受ける力の単位ベクトル
    bool usegravity;
    float r;    // 外接円半径
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
    Ball(Vectorfloat, Quaternion, Vectorfloat);
    Ball(Vectorfloat, float);
//    bool collided(Rigidbody);   // 相手のオブジェクトを指定する
    // その物体と衝突しているときには true が返され、その時の相手の位置ベクトルが Vectorfloat collide に格納される。
    // 衝突していないときは false が返され、collide の値は NULL になる。
};

class Box : public Rigidbody
{
public:
    Box(Vectorfloat, Quaternion, Vectorfloat);
    Box(Vectorfloat, float);
//    bool collided(Rigidbody);   // 相手のオブジェクトを指定する
    // その物体と衝突しているときにはその時の相手の相対位置ベクトルが Vectorfloat collide に格納される。
    // 衝突していないときは false が返され、collide の値は NULL になる。
};


void drawing(Rigidbody);
Vectorfloat vectordifference(Vectorfloat, Vectorfloat);
Vectorfloat vectorquotient(Vectorfloat, double);
// void physics(Rigidbody *);
// void timerfunc(int, void *, int);
// void reshapefunc(int, int);
// void registor();

#endif



