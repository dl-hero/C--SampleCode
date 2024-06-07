#include <iostream>
using namespace std;

int main()
{
	int **p;
	int i,j;	//p[4][8];

	//开发分配4行8列的二维数组
	p=new int* [4];	//申请保存4各地址的数据内存；
	for(i=0;i<4;i++)
	{
		p[i]=new int [8];
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			p[i][j]=i*j;	//保存4行8列的数组数据
		}
	}
	
	//print data
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			cout<<p[i][j]<<"\t";	//打印4行8列的数组数据
		}
		if(8==j)cout<<endl;
	}

	//release memory
	for(i=0;i<4;i++)
	{
		delete [] p[i];
	}
	delete [] p;
	return 0;

}
