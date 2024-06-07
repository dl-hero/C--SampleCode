#include <iostream>
using namespace std;

int main()
{
	double* pvalue=NULL;	//初始化为null的指针
	pvalue=new double;	//为变量请求内存
				
	if(!(pvalue))
	{
		throw"Error:out of memory!";
		exit(1);
	}

	*pvalue=29249.456;	//在分配的地址存储
	cout<<"Vaule of pvalue: "<<*pvalue<<endl;

	delete pvalue;		//release memory
				
	return 0;

}
