#include <iostream>

using namespace std;

//base class

class D
{
	public:
		D(){cout<<"D()"<<endl;}		//构造函数
		~D(){cout<<"~D()"<<endl;}	//析构函数
	protected:
		int d;
};

//class B:virtual public D
class B:public D
{
	public:
		B(){cout<<"B()"<<endl;}
		~B(){cout<<"~B()"<<endl;}
	protected:
		int b;
};
//class A:virtual public D
class A:public D
{
	public:
		A(){cout<<"A()"<<endl;}
		~A(){cout<<"~A()"<<endl;}
	protected:
		int a;
};

class C:public B,public A
{
	public:
		C(){cout<<"C()"<<endl;}
		~C(){cout<<"~C()"<<endl;}
	protected:
		int c;
};

int main()
{
	cout<<"Hello World!"<<endl;
	C c;
	cout<<sizeof(c)<<endl;
	return 0;
}


