#include <iostream>
using namespace std;

class Distance
{
	private:
		int feet;
		int inches;
	public:
		//构造函数
		Distance()
		{
			feet=0;
			inches=0;
		}
		Distance(int f,int i)
		{
			feet=f;
			inches=i;
		}
		Distance operator()(int a,int b,int c)
		{
			Distance D;

			D.feet=a+c+10;
			D.inches=b+a+100;

			return D;
		}
		void displayDistance()
		{
			cout<<"F: "<<feet<<" and I: "<<inches<<endl;
		}

};
int main()
{
	Distance D1(10,11),D2;

	cout<<"First Distance: ";
	D1.displayDistance();

	D2=D1(9,9,9);	//invoke operator()
	cout<<"second Distance: ";
	D2.displayDistance();



	return 0;	
}
