#include <iostream>
using namespace std;

class Box
{
	public:
		
		double getVolume(void)
		{
			return length*breadth*height;
		}

		void setLength(double len)
		{
			length=len;
		}
		void setBreadth(double bre)
		{
			breadth=bre;
		}
		void setHeight(double hei)
		{
			height=hei;
		}
		//重载+运算符，用于把两个box对象相加
		Box operator+(const Box& b)
		{
			Box box;
			box.length=this->length+b.length;
			box.breadth=this->breadth+b.breadth;
			box.height=this->height+b.height;

			return box;
		}
	private:
		double length;
		double breadth,height;
};

int main()
{
	Box box1,box2,box3;
	double volume=0.0;

	box1.setLength(3.2);
	box1.setBreadth(4.5);
	box1.setHeight(5.4);

	box2.setLength(6.8);
	box2.setBreadth(7.3);
	box2.setHeight(8.2);

	cout<<"volume of box1:"<<box1.getVolume()<<endl;
	cout<<"volume of box2:"<<box2.getVolume()<<endl;

	box3=box1+box2;
	cout<<"volume of box3:"<<box3.getVolume()<<endl;

	return 0;

	
}
