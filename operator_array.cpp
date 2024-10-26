#include <iostream>
#include <memory>
using namespace std;

//声明
template <typename T>   //定义模板
class Array
{
public:
    Array();    //定义构造函数
    virtual ~Array(); //定义析构函数，并且定义为纯虚函数

    //不允许值拷贝,定义类型为class Array的容器
    Array<T>& operator=(const Array<T>& rhs)=delete;
    Array(const Array<T>& src)=delete;

    //根据索引查找元素，定义成员函数接口
    //函数名左侧const T&表示返回值为不可修改并且为引用方式，函数右侧const为函数内不变更传入的数据变量
    const T& getElementAt(size_t x)const;

    //根据索引写入元素,定义成员函数接口
    void setElementAt(size_t x,const T& value);

    //[]符号重载
    T& operator[](size_t x);

    //定义成员函数函数接口,size_t为C++标准库中定义的非负整数
    size_t getSize() const;

private:
    static const size_t kAllocSize=4;   //数组的默认大小，定义为静态常量
    void resize(size_t newSize);        //重新分配大小
    T* mElements = nullptr;      //定义T类型的空指针
    size_t mSize=0;
};

//具体实现
template <typename T>
//定义class Array的构造函数具体实现
Array<T>::Array()
{
    mSize=kAllocSize;
    mElements=new T[mSize]{};    //初始化一个空数组,{}表达全部为初始化为0
}

template <typename T>
//定义class Array的析构函数具体实现
Array<T>::~Array()
{
    delete[] mElements;  //删除申请的类型T的数组空间，因为是数组因此使用：delete[]
    mElements=nullptr;
}   

template <typename T>
void Array<T>::resize(size_t newSize)
{
    //创建一个更大的数组
    //auto是根据返回值定义类型,此处类型为auto=unique_ptr<T>类型
    //通过make_unique获得一个智能指针，智能指针的类型是unique_ptr
    auto newArray=make_unique<T[]>(newSize);    //make_unique是函数模板，申请内存，用于创建并返回一个
                                                //指向动态分配对象unique_ptr智能指针,并保内存证资源正确释放。
                                                //需要包含<memory>
                                                //定义了newSize大小的T[]类型数组
                                                //newArray是一个数组指针，newSize是这个数组的大小,数组类型就是T
                                                //auto newdata=make_unique<T>(newSize)  newdata是T类型指针，初始值就是newSize

    for(size_t i=0;i<mSize;i++)
    {
        newArray[i]=mElements[i];
    }

    //删除旧数组
    delete[] mElements;
    mSize=newSize;
    mElements=newArray.release();   //释放unique_ptr对象所指向的资源
}

template <typename T>
const T& Array<T>::getElementAt(size_t x)const
{
//    if(x>=mSize)
    if(x>mSize)
    {
        cout<<"x"<<x<<endl;
        cout<<"mSize"<<mSize<<endl;
        throw out_of_range("out of range");
    }
    return mElements[x];
}

template <typename T>
void Array<T>::setElementAt(size_t x,const T& value)
{
    if(x>=mSize)
    {
        resize(x+kAllocSize);
    }
    mElements[x]=value;
}

template <typename T>
size_t Array<T>::getSize()const
{
    return mSize;
}

template <typename T>
T& Array<T>::operator[](size_t x)
{
    if(x>=mSize)
    {
        resize(x+kAllocSize);
    }
    return mElements[x];
}

int main()
{
    Array<int>  myArray;

    for(size_t i=0;i<10;i++)
    {
//        myArray.setElementAt(i,i);
        myArray[i]=i;
        cout<<i;
    }

    for(size_t i=0;i<10;i++)
    {
//        cout<<myArray.getElementAt(i)<<"/"<<i<<endl;
        cout<<myArray[i]<<"/"<<i<<endl;
    }
    return 0;
}

