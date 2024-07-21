#include <iostream>
using namespace std;

//基类
class A
{
	public:
		A(){n=0;};
		~A(){};
		int getA(){return n;}
		void setA(int t){n=t;}
	private:
		int n;
};

//派生类
class B:public A
{
	public:
		B(){n=0;};
		~B(){};
		int getB(){return n;};
		void setB(int t){n=t;};
	private:
		int n;
};

int main()
{
	B b;
	b.setA(10);//设置基类的成员变量n;
	
	cout<<"A::n="<<b.getA()<<endl;
	cout<<"B::n="<<b.getB()<<endl;

	b.setB(9);//设置派生类的成员函数n;
	cout<<"A::n="<<b.getA()<<endl;
	cout<<"B::n="<<b.getB()<<endl;

	return 0;
}
