#include <iostream>

using namespace std;

class Translate
{
public:
    int hogehoge;
    Translate(int);
};

Translate::Translate(int piyopiyo)
{
    cout << "Transform Constractor" << endl;
    hogehoge = piyopiyo;
}

class GameObject
{
public:
    int fugafuga;
    Translate translate(int fugafuga);
    GameObject(int);
};

GameObject::GameObject(int hogehoge)
{
    cout << "GameObject Constractor" << endl;
    cout << translate.hogehoge << endl;
}

int main()
{
    GameObject gameobject(1);

    return 0;
}

