#ifndef UNITYENGINE_H
#define UNITYENGINE_H

#include <string>
// #include <iostream>  // もしかしたら必要になるかも

typedef struct Identity
{
    float x;
    float y;
    float z;
    float w;
};

typedef struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
    static Quaternion identity
}

class Vector3
{
public:
    float x;
    float y;
    float z;
    Vector3();
    Vector3(float, float, float);
    ~Vector3();
}

class Transform
{
public:
}

class MonoBehaviour
{
public:
    void Start();
    void Update();
    string tag;
    string name;
    template <typename Typename>
        Typename GetComponent();
}

void Destroy(MonoBehaviour *);

#endif

