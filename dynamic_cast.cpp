#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//父类
class A
{
public:
    virtual ~A()    //析构函数
    {}
};

//继承父类的子类
class B:public A
{};

int main()
{
    //heap中申请一个类型为class A的区域，赋值给指针p
    A* p=new A;

    //引用类型转换
    try {
        //将class A的内存指针p,动态转换为类型B的引用
        B& b=dynamic_cast<B&>(*p);
    }
    catch(bad_cast exp) //如果转换失败
    {
        cout<<"Caught bad reference east\n";
    }

    //指针类型转换
    try
    {
        B* pB=dynamic_cast<B*>(p);
        if(pB==NULL)
        {
            cout<<"NULL pointer\n";
        }
    }
    catch (bad_cast exp)
    {
        cout<<"caught bad pointer cast\n";
    }
}


