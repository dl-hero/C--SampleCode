#include <iostream>     //字符流输出输出
#include <vector>       //定义容器
#include <initializer_list> //定义可变初始化类成员

using namespace std;

class point
{
private:
    vector<int> array;
public:
    //constructor accepts a initializer list as argument
    //下面构造函数使用了引用方式传递参数，并且定义了构造函数的初始化列表
    point(const initializer_list<int>& list):array(list){}

    void display()
    {
        for(int i:array) cout<<i<<" , ";
        cout<<endl;
    }
};

template<typename... Args>
void print(Args...args)
{
    //初始化标准模板定义lamdba函数
    initializer_list<int>{
        ([&]{cout<<args<<" ";}(),0)...
    };
    cout<<endl;
}

int main()
{
        point pointobj({1,2,3,4,5});
        pointobj.display();

        print(1,2,"test",4);

        return 0;
}
