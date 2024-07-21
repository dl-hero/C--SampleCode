#include <iostream>
using namespace std;

int main()
{
	int rats=50;
	int &rodent=rats;

	cout<<"rats="<<rats<<", rodent="<<rodent<<endl;
	cout<<"rats address="<<&rats<<endl;
	cout<<"rodent address = "<<&rodent<<endl;

	cout<<"========================================="<<endl;

	int bunnies=50;
	rats=bunnies;

	cout<<"rats="<<rats<<", rodent="<<rodent<<",bunnies="<<bunnies<<endl;
	cout<<"rats address="<<&rats<<endl;
	cout<<"rodent address="<<&rodent<<endl;
	cout<<"bunnies address="<<&bunnies<<endl;

	return 0;

}
