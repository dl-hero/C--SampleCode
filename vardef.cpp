#include <iostream>
using namespace std;


//声明变量
extern int a,b;
extern int c;
extern float f;

class MyClass {
	public:
		static int class_var;
};

int MyClass::class_var = 30;

int main () {
	//变量定义
	int a,b;
	int c;
	float f;

	//实际初始化
	a = 10;
	b = 20;
	c = a + b;
	
	cout << c << endl;

	f = 70.0/3.0;

	cout << f << endl;

	int i = 10;
	{
		int i = 20 ;
		std::cout << "块变量：" << i << std::endl;
	}
	std::cout << "外部变量：" << i << std::endl;

	std::cout << "类变量" << MyClass::class_var << std::endl;

	return 0;
}

