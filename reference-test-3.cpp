#include <iostream>

using namespace std;

double vals[]={10.1,12.6,33.1,24.1,50.0};

double& setValues(int i,double *vals_p)
{

//	double& ref=*(vals_p+i);
	return *(vals_p+i);
}

int main()
{
	cout << "改变前的值："<<endl;
	for (int i=0; i<5;i++)
	{
		cout<<"vals{"<<i<<"]:";
		cout<<vals[i]<<endl;	
	}

	setValues(1,vals)=36.8;
	setValues(2,vals)=48.9;
	setValues(3,vals)=24.7;
	
	cout << "改变后的值："<<endl;
	for (int i=0; i<5;i++)
	{
		cout<<"vals{"<<i<<"]:";
		cout<<vals[i]<<endl;	
	}


}
