/*左值是可以被获得地址的变量，通常出现在赋值语句的左边*/
/*不属于左值的都是右值，通常出现在复制语句的右边，比如：字面量，临时对象，临时值 */
#include <string>
#include <future>
#include <iostream>

using namespace std;

void handleMessage(string& msg)     //左值引用(&)，引用左值，左值是指可以获取地址的变量
{
    cout<<"Handle message with left value reference."<<msg<<endl;
}

void handleMessage(string&& msg)    //右值引用(&&)，右值是指临时变量，字面量(常量)等
{
    cout<<"Handle message with right value reference."<<msg<<endl;
}

int main()
{
    string a="hello";
    handleMessage(a);   //因为是左值，因此调用左值引用作为参数调用函数
    handleMessage((string)"Hello"+(string)" World!");    //因为参数是右值，因此调用右值引用函数
                                                         //使用(string)将常量字符串强制转换为string类型
    return 0;
}




