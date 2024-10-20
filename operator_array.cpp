#include <iostream>

using namespace std;

//声明
template <typename T>   //定义模板
class Arrar
{
public:
    Arrar();    //定义析构函数
    virtual ~Array(); //定义析构函数，并且定义为纯虚函数

    //不允许值拷贝
    Array<T>& operator=(const Array<T>& rhs)=delete;
    Array(const Array<T>& src)=delete;

    //根据索引查找元素，定义成员函数接口
    const T& getElementAt(size_t x)const;

    //根据索引写入元素,定义成员函数接口
    void setElementAt(size_t x,const T& value);

    //定义成员函数函数接口
    size_t getSize() const;
};
