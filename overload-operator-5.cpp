#include <iostream>
using namespace std;
const int SIZE=10;

class safeary
{
	private:
		int ary[SIZE];
	public:
		safeary()//构造函数
		{
			/*register*/ int i;
			for(i=0;i<SIZE;i++)
			{
				ary[i]=i;
			}
		}
		int& operator[](int i)	//define operator []
		{
			if(i>=SIZE)
			{
				cout<<"索引超过最大值"<<endl;
				//返回第一元素
				return ary[0];
			}
			return ary[i];
		}
};

int main()
{
	safeary A;

	cout<<"A[2]的值为： "<<A[2]<<endl;
	cout<<"A[8]的值为： "<<A[8]<<endl;
	cout<<"A[42]的值为： "<<A[42]<<endl;


}
