#include <iostream>
using namespace std;

class Addr
{
	public:
		//constructor function
		Addr(int i=0)
		{
			total=i;
		}
		// interface fucntion for out
		void addNum(int number)
		{
			total += number;
		}
		int getTotal()
		{
			return total;
		}
	private:
		//对外隐藏的数据
		int total;
};

int main()
{
	Addr add;

	cout<<"Total: "<<add.getTotal()<<endl;

	add.addNum(10);
	add.addNum(30);
	add.addNum(50);

	cout<<"Total: "<<add.getTotal()<<endl;

	return 0;
}
