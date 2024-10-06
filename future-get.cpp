/* 通过std::future调用get()传递异常给另一个线程处理，std::thread启动的线程无法获得线程计算结果，如果异常没有被线程本身处理，应用程序就会终止*/
#include <stdio.h>
#include <stdlib.h>
#include <future>   //获取异步进程/任务的结果
#include <iostream>
#include <stdexcept>

using namespace std;

//线程函数
int CalculateSum()
{
    int sum=0;

    //求1~100的合计
    for(auto i=1;i<=100;i++){
        sum=sum+i;
    }
    system("sleep 3");
   
    throw runtime_error("Exception throw from CalculateSum.");  //抛出一个字符串的异常对象，内容“Exception throw from CalculateSum.”
    
   return sum;
}

int main()
{
    auto future_obj=async(launch::async,CalculateSum);  //launch::async：启动一个新线程异步处理CalculateSum函数
    //此处虽然返回了异常对象字符串，但仍然被正常执行;
    cout<<"100"<<endl;
    //新线程异步处理CalculateSum函数，需要等待3秒返回合计，主线程理解打印下面文字
        cout<<"新线程异步执行CalculateSum函数，主线程打印此语句"<<endl;
    try{
        /*如果上面的throw不被注释掉，那么run到throw时就是直接返回异常对象字符串，并且从CalculateSum函数中退出*/
        /*下面的get()就是异常对象的字符串，无法打印合计,直接到catch块，捕获异常*/
        int res=future_obj.get();
        cout<<"1000"<<endl;     //如果future_get()返回异常，try块红的剩余程序将不被执
        cout<<res<<endl;

    }
    catch(const exception& err_exc){
        cerr<<"Caught exception: "<<err_exc.what()<<endl;
    }

    return 0;
}
