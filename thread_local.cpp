#include <iostream>
#include <thread>
using namespace std;

void thread_func()
{
    //定义线程本地变量
    thread_local int stls_variable=0;
    stls_variable+=1;
    cout<<"thread_ID: "<<this_thread::get_id()<<", Variable: "<<stls_variable<<endl;

    //所有线程共享m
    int m=0;
    m+=1;
    cout<<"thread_ID: "<<this_thread::get_id()<<", Variable: "<<m<<endl;


}

int main()
{
    thread t1(thread_func);
    thread t2(thread_func);

    t1.join();
    t2.join();

    return 0;
}
