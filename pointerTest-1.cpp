#include <iostream>
using namespace std;

const int MAX=3;

int main()
{
	int var[MAX]={0,100,200};
	int *ptr[MAX];

	for(int i=0;i<MAX;i++)
	{
		ptr[i]=&var[i];
	}

	for(int i=0;i<MAX;i++)
	{
		cout<<"value of var["<<i<<"]=";
		cout<<*ptr[i]<<endl;
		cout<<ptr[i]<<endl;
//语法错误，数组名称是常量		cout<<ptr++<<endl;
	}

	const char *name[MAX]={
		"Zara Ali",
		"Hina Ali",
		"Nuba Ali"
	};

	for(int i=0;i<MAX;i++)
	{
		cout<<"value of names["<<i<<"]=";
		cout<<name[i]<<endl;
		cout<<*name[i]<<endl;
	}

	int number;
	int *number_p;
	int **number_p_p;

	number=200;
	number_p=&number;
	number_p_p=&number_p;

	cout<<"number="<<number<<endl;
	cout<<"&number="<<&number<<endl;
	cout<<"*number_p="<<*number_p<<endl;
	cout<<"number_p="<<number_p<<endl;
	cout<<"**number_p_p="<<**number_p_p<<endl;
	cout<<"number_p_p="<<number_p_p<<endl;


	return 0;
}

