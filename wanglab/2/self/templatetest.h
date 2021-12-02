#ifndef TEMPLATETEST_H
#define TEMPLATETEST_H

template <typename T>
T funca(T);

// template <typename hogehoge> // 外に出してみる
class Classname
{
public:
    int x;
    template <typename Typename>
    Typename method();
    template <typename hogehoge>  // ここにあるべき template の定義を外に出すだけでコンパイルエラーするので、template はすぐに使う必要がある。
    hogehoge method2(hogehoge);
};


#endif
