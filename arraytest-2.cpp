#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

int main()
{
	double runoobArray[5]={1000.0,2.0,3.4,17.0,50.0};
	double *p;

	p=runoobArray;

	cout << "使用指针的数组值"<<endl;
	for (int i=0;i<5;i++)
	{
		cout<<"*(p + "<<i<<"): ";
		cout<<*(p+i)<< "     " << p+i <<endl;
	}

	cout <<"使用runoobArray作为地址的数组"<<endl;
	for (int i=0;i<5;i++)
	{
		cout<<"*(runoobArray + "<<i<<"): ";
		cout<<*(runoobArray+i)<< "     " << runoobArray+i <<endl;
	}

	return 0;

}
