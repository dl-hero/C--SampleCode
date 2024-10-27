#include <iostream>
using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int h)
        {
            hour=h;
            cout<<"call constructor"<<endl;
             cout<<"mytime.hour: "<<hour<<endl;
            cout<<"mytime.minute: "<<minute<<endl;
            cout<<"mytime.second: "<<second<<endl;
        }
        //委托构造函数
        Time(int h,int m):Time(h)
        {
            minute=m;
            cout<<"call delegating constructor"<<endl;
        }
   
        void printtime()
        {
            cout<<"mytime.hour: "<<hour<<endl;
            cout<<"mytime.minute: "<<minute<<endl;
            cout<<"mytime.second: "<<second<<endl;
        }

};

int main()
{
    Time mytime1(30);
    Time mytime(10,20);
     Time mytime2(40);
    Time mytime3(50,60);
    mytime.printtime();

    return 0;
}

