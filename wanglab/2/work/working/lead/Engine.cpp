#include "Engine.hpp"
#include <iostream>

using namespace std;

#define DEBUGMODE_HPP 1
#define DEBUGMODE_HPP1 0
#define DEBUGMODE_HPP2 0

void drawing(Rigidbody *rigidbody)
{
    double theta;
    signed char minus = +1;
    double keepout = (CIRCLE == rigidbody->_polygon) ? M_PI * rigidbody->signedeg / 100 : 0; // デバッグライン
    glBegin(GL_TRIANGLE_STRIP);
    glColor4f(rigidbody->color.r, rigidbody->color.g, rigidbody->color.b, rigidbody->color.a);
#if DEBUGMODE_HPP2
    cout << "glColor3f()" << endl;
#endif
    for(int j = 0; j < 2; j++)
    {
        minus = pow(-1, j);
        for(int i = 0; i <= rigidbody->_polygon / 2; i++)
        {
            theta = (2 * M_PI / rigidbody->_polygon) * i;
            if(2 * M_PI * i / rigidbody->_polygon >= keepout / 2)
            {
                theta = minus * ((2 * M_PI / rigidbody->_polygon) * i);
                glVertex2d(rigidbody->scale.x * cos(theta + rigidbody->rotation.z) + rigidbody->position.x, rigidbody->scale.y * sin(theta + rigidbody->rotation.z) + rigidbody->position.y);
                glVertex2d(rigidbody->position.x, rigidbody->position.y);
#if DEBUGMODE_HPP1
                cout << "then" << endl;
#endif
#if DEBUGMODE_HPP2
#endif
            }
        }
    }
    glEnd();
}

Mouse::Mouse()
{
    vector = {0, 0};
    vectorfloat = {0, 0};
}

void Mouse::setvector(Vector argumentmousevector)   // int 型の座標から float 型の座標に変換するための関数
{
    vectorfloat.x = 2 * (double) argumentmousevector.x / WINDOWSIZE.X - 1;
    vectorfloat.y = - 2 * (double) argumentmousevector.y / WINDOWSIZE.Y + 1;
}

Time::Time()
{
    clockup = 0;
    time = 0;
    seconds = 0;
    minutes = 0;
    hours = 0;
    miltime = 0;
}

void Time::clock()
{
    if(clockup++ % (1000 / DT) == (1000 / DT) - 1)
    {
        time++;
    }
    if(clockup % DT == (DT) - 1)
    {
        miltime += DT;
    }
//    minutes = time % 60;
//    seconds = time - 60 * minutes;
}

Rigidbody::Rigidbody()
{
    // NULL
}

Rigidbody::Rigidbody(Vectorfloat positionoffset, Vectorfloat velocityoffset, Vectorfloat acceloffset)
{
    position = positionoffset;
    velocity = velocityoffset;
    accel = acceloffset;
}

void Rigidbody::draw()
{
    drawing(this);
}

void Rigidbody::printf()
{
    cout << "Rigidbody->usegravity = " << this->usegravity << endl;
    cout << "Rigidbody->accel = { " << this->accel.x << ", " << this->accel.y << " }" << endl;
    cout << "Rigidbody->velocity = { " << this->velocity.x << ", " << this->velocity.y << " }" << endl;
    cout << "Rigidbody->Position = { " << this->position.x << ", " << this->position.y << " }" << endl;
    cout << "Rigidbody->Scale = { " << this->scale.x << ", " << this->scale.y << " }" << endl;
    cout << "Rigidbody->Rotation = { " << this->rotation.z << " }" << endl;
}

void Object::setcolor(Color argumentcolor)
{
    this->color.r = argumentcolor.r;
    this->color.g = argumentcolor.g;
    this->color.b = argumentcolor.b;
    this->color.a = argumentcolor.a;
}

Ball::Ball(Vectorfloat argumentposition, Quaternion argumentrotation, Vectorfloat argumentscale)
{
    usegravity = true;
    _polygon = CIRCLE;
    position = argumentposition;
    rotation = argumentrotation;
    scale = argumentscale;
    signedeg = 0;
//    count++;
}

Ball::Ball(Vectorfloat argumentposition, float argumentr)
{
    usegravity = true;
    _polygon = CIRCLE;
    position = argumentposition;
    rotation = {0, 0, 0, 1};
    r = argumentr;
    scale = {r * 2, r * 2};
    signedeg = 0;
//    Ball::count++;
}

/*
bool Ball::collided(Rigidbody opponent)
{
}
*/

Box::Box(Vectorfloat argumentposition, Quaternion argumentrotation, Vectorfloat argumentscale)
{
    usegravity = false;
    _polygon = SQUARE;
    position = argumentposition;
    rotation = argumentrotation;
    scale = argumentscale;
    signedeg = 0;
}

Box::Box(Vectorfloat argumentposition, float argumentr)
{
    usegravity = false;
    _polygon = SQUARE;
    position = argumentposition;
    rotation = {0, 0, 0, 1};
    r = argumentr;
    scale = {r * 2, r * 2};
    signedeg = 0;
}

/*
bool Box::collided(Rigidbody *opponent)
{
    Vectorfloat difference = vectordifference(opponent->position, this->position);
    // 衝突しているかどうかを戻す条件式を作成
    return false;
}
*/

void glVertexint(Vector argumentvector)
{
    glVertex2f(2 * argumentvector.x / WINDOWSIZE.X - 1, -2 * argumentvector.y / WINDOWSIZE.Y + 1);
}

void glVertexfloat(Vectorfloat argumentvector)
{
    glVertex2f(argumentvector.x, argumentvector.y);
}

void Rigidbody::physics()
{
    /*
    this->velocity.x += this->accel.x * DT / 1000;
    this->velocity.y += ((usegravity) ? this->g : 0) + this->accel.y * DT / 1000;
    this->position.x += this->velocity.x * DT / 1000;
    this->position.y += this->velocity.y * DT / 1000;
    */
    cout << "this->position.y - this->scale.y / 2 = " << this->position.y - this->scale.y / 2 << endl;

    // y 軸方向の主要処理
    float holizontaltangent = this->position.y + this->scale.y * ((this->position.y > 0) ? 1 : -1);
    if(!this->wallcollision && (holizontaltangent <= -1 || 1 <= holizontaltangent))   // 床の作成
    {
        cout << "床または天井に到達しました" << endl;
        this->wallcollision = true;
        this->accel.y = 0;  // a = g - g    // ∵ 作用反作用
        this->velocity.y = -E * this->velocity.y;
        this->position.y += this->velocity.y * DT / 1000;
        this->position.y = ((holizontaltangent > 0) ? 1 : -1) * (1 - this->scale.y);
    }
    else
    {
        cout << "まだ床または天井に達していません" << endl;
        this->wallcollision = false;
        this->accel.y = (usegravity ? -G : 0) * DT / 1000;  // a = g - g    // ∵ 作用反作用
        this->velocity.y += this->accel.y * DT / 1000;
        this->position.y += this->velocity.y * DT / 1000;
    }

    // x 軸方向の主要処理
    float verticaltangent = this->position.x + this->scale.x * ((this->position.x > 0) ? 1 : -1);
    if(!this->floorcollision && (verticaltangent <= -1 || 1 <= verticaltangent))
    {
        cout << "壁に接触しました" << endl;
        this->floorcollision = true;
        this->velocity.x = -E * this->velocity.x;
        this->position.x += this->velocity.x * DT / 1000;
        this->position.x = ((verticaltangent > 0) ? 1 : -1) * (1 - this->scale.x);
        this->accel.x = 0;
    }
    else
    {
        cout << "まだ壁に接触していません" << endl;
        this->floorcollision = false;
        this->velocity.x += this->accel.x * DT / 1000;
        this->position.x += this->velocity.x * DT / 1000;
        this->accel.x = 0;
    }

    if(abs(this->velocity.x) < 0.2)
    {
        cout << "横移動の停止" << endl;
        this->accel.x = 0;
        this->velocity.x = 0;
        this->position.x = this->position.x;
    }

    this->printf();
}

Vectorfloat vectordifference(Vectorfloat a, Vectorfloat b)
{
    Vectorfloat c = {a.x - b.x, a.y - b.y};
    return c;
}

Vectorfloat vectorquotient(Vectorfloat a, double b)
{
    Vectorfloat c = {((float) a.x) / ((float) b), ((float) a.y) / ((float) b)};
    return c;
}

// ぶつかった

/*
void registor()
{
    glutDisplayFunc(displayfunc);
    glutKeyboardFunc(keyboardfunc);
    glutMouseFunc(mousefunc);
    glutTimerFunc(1, timerfunc, 0);
    glutReshapeFunc(reshapefunc);
}
*/




