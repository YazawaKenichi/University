#include <iostream>
#include "templatetest.h"

using namespace std;

template <typename T>   // typename T で、新しい型 T を定義している
T funcb(T a)    // 新しく作った型 T を返す関数 funcb を定義し、引数に T 型の変数 a を新しく定義している
{
    return (a + a);
}

int main()
{
    cout << funca<int>(2) << endl;  // こっちはファイル外で定義されたテンプレート関数を使用する
    cout << funcb<int>(3) << endl;  // <> の中に型を入れると、上で定義された T がそのまま int 型と等しくなるという仕組み
    // 勉強してみれば何ら難しいものではなかったようだ...

    Classname instance;
    cout << instance.method<int>() << endl;
    cout << instance.method<float>() << endl;
    cout << instance.method<double>() << endl;

    return 0;
}
