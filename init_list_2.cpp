#include <iostream>
using namespace std;

class A
{
	public:
		A()
		{
			cout<<"call A()"<<endl;
		}
};

class B:A
{
	public:
		B(int val):A(),value(val)
		{
			cout<<val<<endl;
			cout<<value<<endl;
			val=0;	//重新赋值
			cout<<"Call B()"<<endl;
			cout<<val<<endl;
			cout<<value<<endl;
		}
	private:
		int value;
};

int main()
{
	B b(10);
	return 0;
}
