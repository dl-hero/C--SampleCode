#define _CRT_SECURE_NO_WARNING

#include <iostream>

using namespace std;

class Base
{
	public:
		Base()
		{
			num=5;
			cout<<"Base constructor call:"<<protectMumber<<endl;
		}
		Base(int n)
		{
			num=n;
			cout<<"Base constructor callnum:"<<protectMumber<<endl;
	
		}
		~Base()
		{
			cout<<"Base constructor call:"<<protectMumber<<endl;
		}
	protected:
		int protectMumber=0;
		int num;
};

class Derived1:public Base
{
	public:
		using Base::Base;	//这行声明继承父类的构造方法
		void modifymember(int newValue)
		{
			protectMumber=newValue;		//修改父类成员
			cout<<"Derived1:"<<num<<endl;
		}
};

class Derived2:public Base
{
	public:
		void modifymember(int newValue)
		{
			protectMumber=newValue;		//修改同一个父类成员
			cout<<"Derived2:"<<num<<endl;
		}
};

int main()
{
	Derived1 d1(88);
	Derived2 d2;

	d1.modifymember(10);
	d2.modifymember(20);

	return 0;
}



