#include <string>
#include <iostream>

using namespace std;

void RunCode(int&& m)
{
    cout<<"right value reference:"<<m<<endl;
}
void RunCode(int& m)
{
    cout<<"left value reference:"<<m<<endl;
}
void RunCode(const int&& m)
{
    cout<<"const right value reference:"<<m<<endl;
}
void RunCode(const int& m)
{
    cout<<"const left value reference:"<<m<<endl;
}

template <typename T>
void PerfectForward(T&& t)
{
    RunCode(forward<T>(t));     //forward,不改变变量的左右值属性

}

int main()
{
    int a=1;
    int b=2;
    const int c=3;
    const int d=4;
    PerfectForward(a);      //变量a是左值，因此调用左值引用的RunCode函数;
    PerfectForward(move(b));//变量b是左值，但通过move强制转换为右值，因此调用右值引用的RunCode函数
    PerfectForward(c);  //c是const常量，但定义的是变量，可以作为左值引用，因此调用常量左值引用RunCode函数
    PerfectForward(move(d));//同常量c,但通过move强制转换为右值，因此调用常量右值引用RunCode函数

    return 0;
}



