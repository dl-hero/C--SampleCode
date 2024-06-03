#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;

	myVector.push_back(3);
	myVector.push_back(5);
	myVector.push_back(9);
	myVector.push_back(20);

	cout<<"Elements in the vertor:"<<endl;
	for(int element:myVector){
		cout<<element<<" ";
	}
		cout<<endl;

	cout<<"First element:"<<myVector[0]<<endl;
	cout<<"second element:"<<myVector.at(1)<<endl;
	cout<<"size of the vector:"<<myVector.size()<<endl;

	myVector.erase(myVector.begin()+2);
	
	cout<<"Elements in the vertor after erase:"<<endl;
	for(int element:myVector){
		cout<<element<<" ";
	}
	cout<<endl;

	myVector.clear();
	cout<<"size of the vector after clean:"<<myVector.size()<<endl;




	return 0;
}
