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

void Destroy(MonoBehaviour *monobehaviour)
{
    delete *monobehaviour;
}

