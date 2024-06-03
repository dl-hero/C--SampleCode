#include <iostream>
using namespace std;

//base class
class Shape
{
	public:
		void setWidth(int w)
		{
			width=w;
		}
		void setHeight(int h)
		{
			height=h;
		}
	protected:
		int width;
		int height;
};

//inheritance class
class Rectangle:public Shape
{
	public:
		int getArea()
		{
			return (width*height);
		}
};

int main()
{
	Rectangle rect;

	rect.setWidth(38);
	rect.setHeight(56);

	//print Rectangle area
	cout<<"Total Area:"<<rect.getArea()<<endl;
}
