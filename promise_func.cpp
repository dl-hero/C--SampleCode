/*std::promise和std::future组合可以实现线程间的异步通信，promise线程中设置一个值，在另外线程通过future访问这个值 */
#include <iostream>
#include <thread>
#include <future>

using namespace std;
/*promise是一个模板类，泛用定义：template<typename T>,promise<string>&& proms-temp定义promise模板的类型string,名称为proms-temp的右值引用的类*/
void modfiyMessage(promise<string>&& proms-temp,string msg)
{
        string metaMsg=msg+"has been modified";
        proms-temp.set_value(metaMsg);   //使用promise模板类中的set_value成员函数设定线程返回值为metaMsg
}

int main()
{
    string msg_str="My Message";

    //创建promise模板类的对象proms，类型为string
    promise<string> proms;

    //创建一个关联的future模板类的对象future_obj,返回与线程关联的future
    future<string> future_obj=proms.get_future();

    //给线程传递promise对象
    //move()强制将左值转换为右值
    thread t1(modfiyMessage,move(proms),msg_str);    //创建线程需要一个可调用的函数或者函数对象，作为线程入口函数
                                                    //基本语法：thread t(functon_name,args,...)
                                                    //functon_name是线程入口函数或者可调用对象名称
                                                    //args，...是传递给函数的参数

    //打印原始msg_str
    cout<<"Original message from main(): "<<msg_str<<endl;

    //打印被子线程修改的msg_str
    string messageFromThread = future_obj.get();
    cout<<"Modified message from thread(): "<<messageFromThread<<endl;

    //通过joinable方法返回布尔值，判断线程是否可以调用join函数
    bool isJoin=t1.joinable();
    if(isJoin){
        //主线程中调用t1.join()
        t1.join();   //t1.join()方法等待线程完成
                     //阻塞主线程，让主线程等待t1子线程执行完成后，再继续
    }

    return 0;
}
