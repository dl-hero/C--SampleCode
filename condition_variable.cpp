#include <condition_variable>   //包含条件变量的头文件，条件变量一定程度可以避免线程的死锁
#include <iostream>     //输入输出流的头文件
#include <mutex>    //互斥体头文件
#include <queue>    //

using namespace std;

//定义模板的使用
template <typename T>
class TSQueue
{
private:
    queue<T> m_queue;   //定义类型为T的容器queue
    
    //mutex for thread synchronization
    mutex m_mutex;  //定义一个mutex的互斥体的实体对象

    //condition variable for singaling
    condition_variable m_cond;

public:
    void push(T item)
    {
        //定义一个类型为mutex的容器lock，存放互斥体的锁定器
        //acquire lock
        unique_lock<mutex> lock(m_mutex);
    
        //向容器的后面推进一个T类型变量;
        m_queue.push(item);

        //notify one thread that is waiting唤醒等待这个条件变量的线程之一
        m_cond.notify_one();
    }

    T pop()
    {
        //acquire lock
        unique_lock<mutex> lock(m_mutex);

        //wait until queue is not empty
        //使用lamdba函数
        m_cond.wait(lock,[this](){return !m_queue.empty();});

        T item=m_queue.front();
        m_queue.pop();

        return item;
    }
};

int main()
{
    TSQueue<int> q;

    //push some data
    q.push(30);
    q.push(40);
    q.push(50);

    //pop some data
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    return 0;

}


