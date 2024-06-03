#include <iostream>

//函数生命
void func(void);

//全局变量
static int cout = 10;

int main() {
	while(cout--) {
		func();
	}
	return 0;
}

void func(void)
{
	static int i = 5; //局部静态变量
	i++;
	std::cout<<"变量i为"<<i<<std::endl;
	std::cout<<"变量cout为"<<cout<<std::endl;

}
