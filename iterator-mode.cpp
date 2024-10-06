#include <iostream>
#include <vector>

using namespace std;

//定义一个Iterator的类，但此基类没有具体内容，因此主要提供接口
class Iterator
{
    public:     //定义公共类
        virtual bool hasNext() const=0;     //在基类中使用关键字virtual声明的函数,实现任意点根据调用的对象类型选择调用函数，也叫动态链接/后期绑定
        virtual int next()=0;       
/* 上面2个是存虚函数，没有具体函数内容*/
};

//定义了Iterator基类的ConcreteIterator的派生类
class ConcreteIterator:public Iterator
{
    private://定义私有类成员
        vector<int> Aggregate;      //定义一个容器
        int index=0;
    public:
        ConcreteIterator(const vector<int>& vec)    //定义构造函数，并且带引用参数
        {
            Aggregate = vec;        //将初始化的引用参数赋值给私有成员
        }
        /*在派生类中重新定义了基类中的纯虚函数，override关键字明确表明此函数体是基类虚函数的重载*/
        bool hasNext() const override
        {
            return index<Aggregate.size();
        }
        int next() override
        {
            return Aggregate[index++];
        }
};

//定义基类，但此基类没有具体内容，因此主要提交接口
class Aggregate
{
    public:
        virtual Iterator* createIterator() const=0; //定义返回值是Iterator类型指针的纯虚函数
};

class ConcreteAggregate:public Aggregate
{
    private:
        vector<int> elements;
    public:
        ConcreteAggregate(const vector<int>& vec)   //定义此派生类的构造函数，并且带初始化参数
        {
            elements=vec;
        }
        Iterator* createIterator() const override
        {
           return new ConcreteIterator(elements);
        }
};

void traverseElements(ConcreteAggregate Aggregate)
{
    Iterator* iterator=Aggregate.createIterator();
    while(iterator->hasNext())
    {
        int element=iterator->next();
        cout<<element<<" ";
    }
    cout<<endl;
    delete iterator;
}

int main()
{
    vector<int> elements={1,2,3,4,5,6,7,8,9,0};     //定义一个全局的vector容器
    ConcreteAggregate Aggregate(elements);
    traverseElements(Aggregate);

    return 0;
}

