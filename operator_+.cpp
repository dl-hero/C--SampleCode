#include <iostream>
using namespace std;

class Complex       //定义Complex Base Class
{
    private:
        float real;
        float imag;
    public:
        Complex():real(0),imag(0){} //定义构造函数，并且设定成员变量real和imag的初始之为0

        //重载operator +
        Complex operator+(const Complex& obj)   //定义用于complex +运算的重载运算符，参数通过引用传递
        {
            Complex temp;
            temp.real=real+obj.real;
            temp.imag=imag+obj.imag;
            return temp;
        }

        void setvalue(float val1,float val2)
        {
            real=val1;
            imag=val2;
        }

        void output()
        {
           if(imag<0)
           {
                
           }
           else
           {
                
           }
        }
}
