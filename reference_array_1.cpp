#include <iostream>
using namespace std;

int main()
{
	int *p;
	int a[]={1,2,3,4,5,6};
	int (&t)[6]=a;
	p=a;

	cout<<t<<endl;
	cout<<p<<endl;
	cout<<a<<endl;

	return 0;
}
