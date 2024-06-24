#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//创建一个向量存储 int
	vector<int> vec;
	int i;

	//显示vec的原始大小
	cout<<"vector size = "<<vec.size()<<endl;

	//推入5个值到向量中
	for(i=0;i<5;i++)
	{
		vec.push_back(i);
	}

	//显示vec扩展后的大小
	cout<<"extended vector size = "<<vec.size()<<endl;

	//访问向量中的5个值
	for(i=0;i<5;i++)
	{
		cout<<"value of vec ["<<i<<"]= "<<vec[i]<<endl;
	}

	//使用迭代器iterator访问值
	vector<int>::iterator v=vec.begin();
	while(v !=vec.end())
	{
		cout<<"value of v = "<<*v<<endl;
		v++;
	}

	return 0;
}
