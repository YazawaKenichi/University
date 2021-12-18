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
    glColor3f(rigidbody->color.r, rigidbody->color.g, rigidbody->color.b);
#if DEBUGMODE_HPP
    cout << "glColor3f()" << endl;
    cout << "Rigidbody->Position = { " << rigidbody->position.x << ", " << rigidbody->position.y << " }" << endl;
    cout << "Rigidbody->Scale = { " << rigidbody->scale.x << ", " << rigidbody->scale.y << " }" << endl;
    cout << "Rigidbody->Rotation = { " << rigidbody->rotation.z << " }" << endl;
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
    time = 0;
    seconds = 0;
    minits = 0;
    hours = 0;
    miltime = 0;
}

Rigidbody::Rigidbody()
{
    g = 9.80665;
}

Rigidbody::Rigidbody(Vectorfloat positionoffset, Vectorfloat velocityoffset, Vectorfloat acceloffset)
{
    g = 9.80665;
    position = positionoffset;
    velocity = velocityoffset;
    accel = acceloffset;
}

void Object::setcolor(Color argumentcolor)
{
    this->color.r = argumentcolor.r;
    this->color.g = argumentcolor.g;
    this->color.b = argumentcolor.b;
}

void Rigidbody::draw()
{
    drawing(this);
}

Ball::Ball(Vectorfloat argumentposition, Quaternion argumentrotation, Vectorfloat argumentscale)
{
    _polygon = CIRCLE;
    position = argumentposition;
    rotation = argumentrotation;
    scale = argumentscale;
    signedeg = 0;
//    count++;
}

Ball::Ball(Vectorfloat argumentposition, float argumentr)
{
    _polygon = CIRCLE;
    position = argumentposition;
    rotation = {0, 0, 0, 1};
    r = argumentr;
    scale = {r * 2, r * 2};
    signedeg = 0;
//    Ball::count++;
}

Box::Box(Vectorfloat argumentposition, Quaternion argumentrotation, Vectorfloat argumentscale)
{
    _polygon = SQUARE;
    position = argumentposition;
    rotation = argumentrotation;
    scale = argumentscale;
    signedeg = 0;
//    Ball::count++;
}

Box::Box(Vectorfloat argumentposition, float argumentr)
{
    _polygon = SQUARE;
    position = argumentposition;
    rotation = {0, 0, 0, 1};
    r = argumentr;
    scale = {r * 2, r * 2};
    signedeg = 0;
//    Box::count++;
}

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
    this->velocity.x += this->accel.x * dt;
    this->velocity.y += this->accel.y * dt;
    this->position.x += this->velocity.x * dt;
    this->position.y += this->velocity.y * dt;
}

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




