#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;

	int& ref_a=a;
	int& ref_b=b;

	a=3;
	b=6;

	cout<<"a="<<a<<endl;
	cout<<"ref_a="<<ref_a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"ref_b="<<ref_b<<endl;

	return 0;
		
}
