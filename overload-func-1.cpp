#include <iostream>
using namespace std;

class printData
{
	public:
		void print(int i)
		{
			cout<<"整数为："<<i<<endl;
		}
		
		void print(double f)
		{
			cout<<"浮点数为："<<f<<endl;
		}
		void print(char c[])
		{
			cout<<"字符串为："<<c<<endl;
		}
};

int main(void)
{
	printData pd;

	pd.print(3);
	pd.print(3.56);
	
	char c[]="Hello C++=你好，C++";
	pd.print(c);

	return 0;
}
