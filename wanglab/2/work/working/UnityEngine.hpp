#ifndef UNITYENGINE_H
#define UNITYENGINE_H

#include <string>
// #include <iostream>  // もしかしたら必要になるかも

typedef struct Identity // 初期回転状態
{
    float x;
    float y;
    float z;
    float w;
};

class Quaternion   // 回転状態 // より Unity の文法に寄せたいがために w を用意したが、使うつもりはない
{
public:
    float x;
    float y;
    float z;
    float w;
    static Quaternion identity;
    Quaternion();
};

class Vector3
{
public:
    float x;
    float y;
    float z;
    Vector3();
    Vector3(float, float, float);
    ~Vector3();
};

private class Transform // RIgidBody を継承させることで Transform が同時に継承される。
{
public:
    Vector3 position;
    Quaternion rotation;
    Vector3 scale;
    void Transform();
    void Transform(Vector3, Quaternion, Vector3);
    void ~Transform();
    void Translate(Vector3 translation);
    void Rotate(Vector3 eulers);
};

class RigidBody : Transform // 本当は継承していないけど、Unity が内部でどのように Rigidbody から positinon を操作しているのかわからなかったから継承させた。
{
public:
    bool useGravity;
    float mass;
    float e;
    RigidBody();
    ~RigidBody();
    void addForce(Vector3 force);
};

class GameObject : RigidBody
{

};

class MonoBehaviour
{
public:
    void Start();
    void Update();
    string tag;
    string name;
    template <typename Typename>
        Typename GetComponent();
};

class GameObject : MonoBehaviour
{
}

void Destroy(MonoBehaviour *);

#endif

