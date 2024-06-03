#include <iostream>
using namespace std;

int *createarray(int size) 
{
	int* arr = new int[size];

	for(int i=0;i<size;i++) 
	{
		arr[i]=i+100;
	}

	return arr;
}

int main()
{
	int inputnumber=0;
	cout<<"pleae input array number:";
	cin>>inputnumber;
	
	int* mainArray=createarray(inputnumber);

	for(int i=0;i<inputnumber;i++) 
	{
		cout <<mainArray[i]<<" ";
	}
	cout << endl;
	delete[] mainArray;//release memory
	return 0; 

}
