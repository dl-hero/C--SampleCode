#include <iostream>
using namespace std;

double Division(int a,int b)
{
	if (0==b)
	{
		throw"Division by zero condition!";
	}
	return (a/b);
}

int main()
{
	int x=50;
	int y=0;
	double z=0;

	try
	{
		z=Division(x,y);
		cout<<z<<endl;
	} catch(const char* msg)
	{
		cerr<<msg<<endl;	
	}

	return 0;
}
