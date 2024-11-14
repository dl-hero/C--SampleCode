#include <iostream>
#include <memory>       //智能指针的头文件

using namespace std;

//weak_ptr<> 智能指针，指向shared_ptr<>所管理的指针,定义指向的变量是int型，引用方式传递参数
void Check(weak_ptr<int>& wp)
{
    shared_ptr<int> sp=wp.lock();   //获取weak_ptr指针指向的shared_ptr的实例

    if(nullprt!=sp)
        cout<<"still"<<endl;
    else
        cout<<"pointer is invaild"<<endl;
}

int main()
{
   shared_ptr<int> sp1(new int(40));    //定义shared_ptr的实例sp1，sp1指向的变量为int，初始值为40;
   shared_ptr<int> sp2=sp1;
   weak_ptr<int> wp=sp1;    //weak_ptr定义的wp指向shared_ptr<int>定义的sp1实例

   cout<<*sp1<<endl;
   cout<<*sp2<<endl;


}
