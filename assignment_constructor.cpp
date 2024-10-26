#include <iostream>
using namespace std;

//定义一个类
class Time
{
    //定义类成员
    private:
        int hour;
        int minute;
        int second;
    //定义类的方法
    public:

    //构造函数,构造函数初始化列表,以冒号开始
    Time(int h,int m,int s):hour(0),minute(0),second(0)
    {
        hour=h;
        minute=m;
        second=s;

        cout<<"call constructor function"<<endl;
    }

    //拷贝构造函数
    Time(const Time& t)
    {
        hour=t.hour;
        minute=t.minute;
        second=t.second;

        cout<<"call copy constructor function"<<endl;
    }

    //赋值构造函数
    Time& operator=(const Time& t)
    {
        hour=t.hour;
        minute=t.minute;
        second=t.second;

        cout<<"call assignment constructor function"<<endl;
        
        return *this;
    }
};

int main()
{
    //定义类变量
   Time time1(14,2,44);
   Time time2=time1;
   Time time3(0,0,0);
   time3=time2;
    
    return 0;
}
