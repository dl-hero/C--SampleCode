#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

class MyData
{
    public:
        MyData(int tmpValue)        //定义myData的构造函数，进行初始化
        {
            value=tmpValue;
        }
        int value;
};

template<typename T,typename outIt>     //定义模板，把类型定义为参数，不能有分号
outIt print_data(const list<T>& container,outIt out)    //定义container为引用T类型的list容器，out为outIt类型
{
    for(const auto& data:container)     //容器的遍历功能,data作为container的引用
    {
        *out++="[";
        *out++=to_string(data.value);
        *out++="]";
    }
    cout<<endl;
    return out;
}

int main()
{
    list<MyData> datalist={10,20,30,40,50,60,70,80};    //MyData类型定义了list容器
    ostream_iterator<string> outIter(cout);      //绑定到输出流迭代器,将数据写到指定的输出流，比如out
                                                 //也可追加间隔副，比如(cout,",")
                                                    //初始化输出流迭代器并初始化,outIter相当于cout的指针
                                                    //ostream_iterator定义的可以是string,也可以是int/char等
    print_data(datalist,outIter);   //按照定义的函数方式输出数据
    return 0;
}
