#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max(T const& a,T const& b)
{
	return a<b?a:b;
}

int main()
{
	int i=39;
	int j=20;
	cout<<"Max(i,j): "<<Max(i,j)<<endl;

	double f1=13.56;
	double f2=29.45;
	cout<<"Max(f1,f2): "<<Max(f1,f2)<<endl;

	string s1="JinNuo";
	string s2="Liuqiuyan";
	cout<<"Max(s1,s2): "<<Max(s1,s2)<<endl;
}
