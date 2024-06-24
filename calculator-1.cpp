#include <iostream>
#include <map>	//map容器的库

using namespace std;

float add(float num1,float num2){ return num1+num2;}
float subtract(float num1,float num2){return num1-num2;}
float multiply(float num1,float num2){return num1*num2;}
float divide(float num1,float num2){return num1/num2;}

int main()
{
	map<char,float (*)(float,float)> fun;

	fun['+']=add;
	fun['-']=subtract;
	fun['*']=multiply;
	fun['/']=divide;

	char op;
	float num1,num2;

	cout<<"input operator: +、-、*、/： ";
	cin>>op;

	cout<<"please input two numbers：";
	cin>>num1>>num2;

	try 
	{
		if(fun.count(op)>0)
		{
			cout<<"result："<<fun[op](num1,num2)<<endl;
		}
		else
		{
			cout<<"error! please input current operator"<<endl;
		}
	}
	catch(const std::exception& e)
	{
		cout<<"error! 除数不能为0"<<endl;
	}

	return 0;
}

