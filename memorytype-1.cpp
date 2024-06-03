#include <iostream>
#include <limits>
using namespace std;

//全局变量，具有外部链接，默认存储类型extern
auto globalvar=12345; 
auto globalfloat = 3.14;
auto globaldouble = -3.12;
/* auto int var:语法错误
 * auto  var:语法正确，根据初始化复制自动定义变量类型
 *
 */


void function() {
	//局部变量，具有自动存储期 
	auto localvar =  10;
	//静态变量，生命周期贯穿整个程序 
	static int staticvar = 20;

	//定义常量，默认为静态变量存储期 
	const int constvar = 30;

//	constvar = 40;

	cout <<"localvar:"<<sizeof(localvar)<<endl;
	class MyClass {
		mutable int mutablevar;

		void constMemberFunc() const {
			mutablevar = 50;	//允许修改const变量
		}
	};
	
	//线程局部变量，每个线程都有独立副本 
	thread_local int threadvar = 60;
}

int main () {
	//生命具有外部链接的变量 
	extern int externalvar;

	function();

	cout <<"golbalvar："<< sizeof(globalvar) << endl;
	cout <<"globalfloat："<< sizeof(globalfloat) << endl;
	cout <<"grolbaldouble："<< sizeof(globaldouble) << endl;


	return 0;
}
