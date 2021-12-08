#include "Engine.hpp"

void drawing(Object *object)
{
    double theta;
    signed char minus = +1;
    double keepout = M_PI * object->signedeg / 100; // デバッグライン
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
                glVertex2d(object->r * cos(theta + object->rotation.z) + object->position.x, object->r * sin(theta + object->rotation.z) + object->position.y);
            }
        }
    }
    glEnd();
}

Mouse::Mouse()
{
    mousevector = {0, 0};
}

void Mouse::setmousevector(Vector argumentmousevector)   // int 型の座標から float 型の座標に変換するための関数
{
    vectorfloat.x = 2 * (double) argumentmousevector.x / WINDOWSIZE.X - 1;
    vectorfloat.y = - 2 * (double) argumentmousevector.y / WINDOWSIZE.Y + 1;
}

Ball::Ball(Vectorfloat argumentposition, Quaternion argumentrotation, Vectorfloat argumentscale)
{
    position = argumentposition;
    rotation = argumentrotation;
    scale = argumentscale;
    signedeg = 0;
    count++;
}

Ball::Ball(Vectorfloat argumentposition, float argumentr)
{
    position = argumentposition;
    rotation = {0, 0, 0, 1};
    r = argumentr;
    scale = {r, r};
    signedeg = 0;
    count++;
}

void Ball::draw();
{
    drawing(this);
}

Box::Box(Vectorfloat argumentposition, Quaternion argumentrotation, Vectorfloat argumentscale)
{
    position = argumentposition;
    rotation = argumentrotation;
    scale = argumentscale;
    signedeg = 0;
    count++;
}

Box::Box(Vectorfloat argumentposition, float argumentr)
{
    position = argumentposition;
    rotation = {0, 0, 0, 1};
    r = argumentr;
    scale = {r, r};
    signedeg = 0;
    count++;
}

void Box::draw()
{
    drawing(this);
}

template <typename T>   // 対応する型：Vector Vectorfloat
void glVertex(T argumentvector)
{
    if(typeid(argumentvector) == "Vector")
    {
        glVertex(2 * argumentvector.x / WINDOWSIZE.X - 1, -2 * argumentvector.y / WINDOWSIZE.Y + 1);
    }
    else if(typeid(argumentvector) == "Vectorfloat")
    {
        glVertex(argumentvector.x, argumentvector.y);
    }
    else
    {
        cout << "template type error" << endl;
    }
}   // 使い方：glVertex<Vector>(vector); | glVertex<Vectorfloat>(vectorfloat);
template void glVertex<Vector>(Vector);
template void glVertex<Vectorfloat>(Vectorfloat);


