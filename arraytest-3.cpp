#include <iostream>
using namespace std;

double getAverage(int arr[],int size);

int main()
{
	int balance[10]={0,1,2,3,4,5,6,7,8,9};
	double avg;

	avg = getAverage(balance,10);

	cout << "平均值是："<< avg << endl;

	return 0;
}


double getAverage(int arr[],int size)
{
	int i,sum=0;
	double avg;

	for (i=0;i<size;i++)
	{
		sum += arr[i];
	}

	avg = double(sum)/size;

	return avg;
}



