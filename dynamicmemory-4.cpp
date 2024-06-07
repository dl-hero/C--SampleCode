#include <iostream>
using namespace std;

class Box
{
	public:
		//构造函数-constructor function
		Box()
		{
			cout<<"constructor function"<<endl;
		}
		//析构函数-destructor function
		~Box()
		{
			cout<<"destructor function"<<endl;
		}
};

int main()
{
	Box* myBoxArray=new Box[4];

	cout<<"-------------------"<<endl;

	delete [] myBoxArray;

	return 0;
}
