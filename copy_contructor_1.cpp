#include <iostream>
using namespace std;

class Wall
{
private:
    double length;
    double hight;
public:
    //定义构造函数并且初始化
   Wall(double len,double hgt)
   {
        length=len;
        hight=hgt;
   }

    //定义拷贝构造函数
    Wall(const Wall& temp)
    {
        length=temp.length;
        hight=temp.hight;
    }
    
    //定义求面积的方法
    double GetArea() const
    {
        return length*hight;
    }
};

int main()
{
    //定义一个wall类，并且进行初始化
    Wall wall1(10.3,14.6);
    //定义另外一个类，并且用第一个类赋值
    Wall wall2=wall1;

    //打印两个类的面积
    cout<<"the wall1 of area"<<wall1.GetArea()<<endl;
    cout<<"the wall2 of area"<<wall2.GetArea()<<endl;

    return 0;

}
