#include <iostream>
using namespace std;

/*
void test01()
{
	cout << "test01" << endl;
	auto Add = [](int a,int b) -> int {
		return a+b;
	};

	cout << Add(1,2)<<endl;
}
*/

/*void test02()
{
	cout << "test02" << endl;
	auto Add = [](int a,int b) {
		return a+b;
	};

	cout << Add(1,2)<<endl;
}
*/
void test03( )
{
	int c =20;
	int d=30;

	cout << "test03" << endl;
	auto Add = [c,d](int a,int b) {
		cout << "d="<<d<<endl;
		cout << "a+b="<<a+b<<endl;
		return c;
	};
	d = 10;
	cout << Add(1,2)<<endl;
}

void test04( )
{
	int c =20;
	int d=30;

	cout << "test04" << endl;
	auto Add = [c,&d](int a,int b) {	//被捕获的变量是在lambda表达式被创建时拷贝，而不是调用时拷贝
		cout << "d="<<d<<endl;
		cout << "c="<<c<<endl;
		cout << "a+b="<<a+b<<endl;
		return c;
	};
	d = 10;
	cout << Add(1,2)<<endl;
}

void test05( )
{
	int c =20;
	int d=30;

	cout << "test05" << endl;
	//引用捕获 
	auto Add = [&](int a,int b) {	//被捕获的变量是在lambda表达式被创建时拷贝，而不是调用时拷贝
		cout << "d="<<d<<endl;
		cout << "c="<<c<<endl;
		cout << "a+b="<<a+b<<endl;
		return c;
	};
	d = 10;
	c = 5;
	cout << Add(1,2)<<endl;
}

void test06( )
{
	int c =20;
	int d=30;

	cout << "test06" << endl;
	//值捕获
	auto Add = [=](int a,int b) {	//被捕获的变量是在lambda表达式被创建时拷贝，而不是调用时拷贝
		cout << "d="<<d<<endl;
		cout << "c="<<c<<endl;
		cout << "a+b="<<a+b<<endl;
		return c;
	};
	d = 10;
	c = 5;
	cout << Add(1,2)<<endl;
}

int main(int argc,char **arg)
{
//	test01();
	
//	test02();
	
//	test03();

//	test04();

	test05();

	test06();

	return 0;
}
