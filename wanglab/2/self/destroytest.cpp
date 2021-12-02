#include <iostream>

class MonoBehaviour
{
public:
    static long int count = 0;
    MonoBehaviour(long int);
    ~MonoBehaviour();
}

MonoBehaviour::MonoBehaviour()
{
    count++;
}

MonoBehaviour::~MonoBehaviour()
{
    count--;
}

void Destroy(MonoBehaviour *monobehaviour)
{
    delete *monobehaviour;
    std::cout << "Destroy" << endl;
}

int main()
{
    MonoBehaviour instance1;
    MonoBehaviour instance2;
    MonoBehaviour instance3;
    std::cout << 



