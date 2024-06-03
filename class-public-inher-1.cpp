#include <iostream>
#include <assert.h>

using namespace std;

class A
{
	public:
		int a;
		A(){	//Class A的构造函数 
			a1=1;
			a2=2;
			a3=3;
			a=4;
		}
		void fun(){	//Class A的成员函数 
			cout<<a<<endl;
			cout<<a1<<endl;
			cout<<a2<<endl;
			cout<<a3<<endl;
		}
	public:
		int a1;
	protected:
		int a2;
	private:
		int a3;
};

class B:public A
{
	public:
		int a;
		B(int i){	//Class B的构造函数(带参数)
			A();
			a=i;
		}
		void fun(){	//Class B的成员函数 
			cout<<a<<endl;
			cout<<a1<<endl;
			cout<<a2<<endl;
//			cout<<a3<<endl;		//Class A的私有变量，无法使用
			
		}
};

int main()
{
	B b(10);

	cout<<b.a<<endl;
	cout<<b.a1<<endl;
//	cout<<b.a2<<endl;	//Class A的保护便令，无法使用 
//	cout<<b.a3<<endl;	//Class A的私有变量，无法使用
	
	system("pause");

	return 0;
}
