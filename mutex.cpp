#include <iostream>
#include <chrono>   //时间定义的库文件
#include <mutex>    //互斥体与锁管理的库文件
#include <thread>   //进程管理的库文件
#include <vector>   //容器定义的库文件

using namespace std;

int main()
{
   int counter=0;

    mutex counter_mutex;    //定义一个mutex互斥体的实体对象
    vector<thread> threads;     //定义一个类型为thread类的容器

   //定义一个lambda表达式，[capture](params)->returntype{}
   //[&]通过引用隐式捕获，所有局部变量通过引用使用
    auto worker_task=[&](int id){
        //定义一个mutex类型的容器lock，存放互斥体的锁定器
        unique_lock<mutex> lock(counter_mutex);
        ++counter;
        cout<<id<<", initial counter: "<<counter<<'\n';
        lock.unlock();  //释放有当前线程持有的锁
        //sleep_for让当前线程休眠x秒，并且让出CPU给其他线程
        this_thread::sleep_for(chrono::seconds(1));
        lock.lock();//此线程将尝试获取锁，获取不到就会阻塞
        ++counter;
        cout<<id<<", final counter: "<<counter<<'\n';
    };

    for(int i=0;i<5;i++)
    {
        //通过进程调用上面的worker_task的lambda函数
        //通过emplace_back直接在threads容器的尾部构造worker_task的线程
        threads.emplace_back(worker_task,i);
    }

    for(auto& thread:threads)
    {
        thread.join();
    }
    return 0;

}   

