#include "UnityEngine.h"

Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}

Vector3::~Vector()
{
    delete this;
}

Quaternion::Quaternion()
{
    identity = {0, 0, 0, 1};
}

Transform::Transform()
{
}

Transform::Transform(Vector3 vector3, Quaternion, quaternion, Vector3 vector3)
{
}

Transform::~Transform()
{
}

void Transform::Translate(Vector3 translation)
{
    position.x += translation.x;
    position.y += translation.y;
    position.z += translation.z;
}

void Transform::Rotate(Vector3 eulers)
{
    rotation.x += eulers.x;
    rotation.y += eulers.y;
    rotation.z += eulers.z;
}

void addForce(Vector3 force)
{
    position.x = 
}

void Destroy(MonoBehaviour *monobehaviour)
{
    delete *monobehaviour;
}

