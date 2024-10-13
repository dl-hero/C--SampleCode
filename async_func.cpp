//thread 直接创建线程，async 异步创建一个任务，此任务可以是创建新线程，也可以不创建线程，可以避免资源占用

#include <stdio.h>
#include <stdlib.h>
#include <future>
#include <iostream>

using namespace std;

//线程函数
int CalculateSum(int a,int b) 
{
        cout<<"In other thread."<<endl;
        cout<<"Result:"<<a+b<<endl;
        system("sleep 2");      //在异步线程等待着2s
        return a+b;
}

int main()
{
    auto future_obj=async(CalculateSum,12,16);//建立一个新线程，异步执行CalculateSum函数
    system("sleep 1");
    cout<<"In main thread."<<endl;
    int res=future_obj.get();   //get,阻塞式的获得线程返回值
//    int res=future_obj.wait_for() ;   //wait_for,阻塞式的获得线程返回值

    cout<<res<<endl;
}
