#include "Engine.hpp"

void drawing(Rigidbody *object)
{
    double theta;
    signed char minus = +1;
    double keepout = (CIRCLE == object->_polygon) ? M_PI * object->signedeg / 100 : 0; // デバッグライン
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(object->color.r, object->color.g, object->color.b);
    for(int j = 0; j < 2; j++)
    {
        minus = pow(-1, j);
        for(int i = 0; i <= object->_polygon / 2; i++)
        {
            theta = (2 * M_PI / object->_polygon) * i;
            if(2 * M_PI * i / object->_polygon >= keepout / 2)
            {
                theta = minus * ((2 * M_PI / object->_polygon) * i);
                glVertex2d(object->scale.x * cos(theta + object->rotation.z) + object->position.x, object->scale.y * sin(theta + object->rotation.z) + object->position.y);
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

