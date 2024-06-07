#include <iostream>
using namespace std;

//第一命名空间
namespace first_space
{
	void func()
	{
		cout<<"Inside first_space"<<endl;
	}
}
//第二命名空间
namespace second_space
{
	void func()
	{
		cout<<"Inside sencod_space"<<endl;
	}
}

using namespace first_space;
int main()
{
	//调用第一命名空间中的函数
//	first_space::func();

	//调用第二命名空间中的函数
//	second_space::func();

	func();

	return 0;
}

