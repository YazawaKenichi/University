#include "templatetest.h"

template <typename T>
T funca(T a)
{
    return (a + a);
}
template int funca<int>(int);    // ヘッダファイルに分けてテンプレートを記述するときはこの一行が必要になるそうだ。

template <typename T>
T Classname::method()
{
    return (7 + 3);
}
template int Classname::method<int>();
template float Classname::method<float>();
template double Classname::method<double>();

template <typename hogehoge>
hogehoge Classname::method2(hogehoge fugafuga)
{
    return (fugafuga + fugafuga);
}
template int Classname::method2<int>(int);
template float Classname::method2<float>(float);
template double Classname::method2<double>(double);
