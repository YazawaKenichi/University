#include <iostream>

class Quaternion
{
public:
    int x;
    int y;
    int z;
};

class Translate
{
public:
    int x;
    int y;
    Quaternion identity;
};

int main()
{
    Translate translate;
    std::cout << translate.identity.x << std::endl;

    return 0;
}
