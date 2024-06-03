#include <iostream>
using namespace std;

class Check
{
	private:
		int i;
	public:
		Check():i(3){}//构造函数，初始化i=3
		Check operator--()	//给Class定义重载运算符(前缀--)
		{
			Check temp;
			temp.i=--i;
			return temp;
		}
		Check operator--(int)	//给class定义重载运算符(后缀--)
		{
			Check temp;
			temp.i=i--;
			return temp;
		}

		void display()
		{
			cout<<"i= "<<i<<endl;
		}
};

int main()
{
	Check obj,obj1;
	obj.display();
	obj1.display();

	obj1=--obj;
//	obj1=++obj;
	obj.display();
	obj1.display();

	obj1=obj--;
	obj.display();
	obj1.display();

	return 0;
}
