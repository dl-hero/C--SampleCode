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

//base class
class PaintCost
{
	public:
		int getCost(int area)
		{
			return (area*70);
		}	
};

//inheritance class
class Rectangle:public Shape,public PaintCost
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
	int area;

	rect.setWidth(189);
	rect.setHeight(76);

	area=rect.getArea();

	//print Rectangle area
	cout<<"Total Area:"<<rect.getArea()<<endl;

	//print total cost
	cout<<"Total cost:"<<rect.getCost(area)<<endl;
	
	return 0;
}
