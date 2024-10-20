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
        Complex operator+(const Complex& obj)  const //定义用于complex +运算的重载运算符，参数通过引用传递，追加第一个const表示不会修改参数，第二个const表示不会修改此类中的成员
        {
            Complex temp;
            //this表示class自身
            temp.real=this->real+obj.real;
            temp.imag=this->imag+obj.imag;
            return temp;
        }

        void setValue(const float& val1,const float& val2)  //参数通过引用方式传递，追加const表示不会修改参数
        {
            real=val1;
            imag=val2;
        }

        void output() const
        {
           if(imag<0)
           {
               cout<<"Output Complex number:"<<real<<imag<<"i";
           }
           else
           {
                cout<<"Output Complex number:"<<real<<"+"<<imag<<"i";
           }
            cout<<endl;
        }
};

int main()
{
    Complex complex1,complex2,result;
    float a=2.0,b=3.0,c=4.0,d=5.0;
    complex1.setValue(a,b);
    complex2.setValue(c,d);

    //complex1调用重载的operator+
    //complex2作为函数的参数传进去
    result=complex1+complex2;
    result.output();
    return 0;
}


