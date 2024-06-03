#include <iostream>
using namespace std;

void swap(int& x,int& y);

int main()
{
	int a=3;
	int b=4;

	cout<<"before change, a="<<a<<endl;
	cout<<"after change,b="<<b<<endl;

	swap(a,b);
	
	cout<<"before change, a="<<a<<endl;
	cout<<"after change,b="<<b<<endl;

	return 0;

}

void swap(int& x,int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
