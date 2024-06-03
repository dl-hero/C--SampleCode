#include <iostream>
using namespace std;

class Distance
{

	private:
		int feet;
		int inches;
	public:
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
		friend ostream &operator<<(ostream &output,
						const Distance &D)
		{
			output<<"F: "<<D.feet<<"I: "<<D.inches;
			return output;
		}
		friend istream &operator>>(istream &input,
						const Distance &D)
		{
			input>>D.feet>>D.inches;
			return input;
		}

		Distance operator+(const Distance &dis)
		{
			Distance distance;
			distance.feet=feet+dis.feet;
			distance.inches=this->inches+dis.inches;

			return distance;
		}
};

int main()
{
	Distance D1(11,10),D2(5,11),D3,D4;

	cout<<"Enter the value of project:"<<endl;
	cin<<D3;
	cout<<"First Distance: "<<D1<<endl;
	cout<<"second Distance: "<<D2<<endl;
	cout<<"third Distance: "<<D3<<endl;

	D4= D1+D2;
	cout<<"4th Distance: "<<D4<<endl;

	return 0;
}


