#include <iostream>
#include <thread>
using namespace std;

class Counter
{
    private:
        int mId;
        int mNumIterations;

    public:
        //构造函数，并且追加初始化列表
        Counter(int id,int numiteration):mId(id),mNumIterations(numiteration)
        {
           cout<<"Call constructor function"<<endl; 
        }

        //运算符重载operator()
        void operator()()const
        {
            for(int i=0;i<mNumIterations;i++)
            {
                cout<<"Counter "<<mId<<" has Value : "<<i<<endl;
            }
        }
};

int main()
{
    //thread t1{Counter{1,4}}=t1(Counter(1,4))
    //建立子线程后就继续执行主线程的后面程序
    thread t1{Counter{1,4}};    

    Counter c(2,4);
    thread t2(c);

    t1.join();
    t2.join();

    cout<<"Main thread end!!!"<<endl;

    return 0;
}


