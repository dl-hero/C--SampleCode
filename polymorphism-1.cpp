#include <iostream>
using namespace std;

class Shape
{
	protected:
		int width,height;
	public:
		//constructor function
		Shape(int a=0,int b=0)
		{
			width=a;
			height=b;
		}
		virtual	int area()
		{
			cout<<"Parent class area: "<<endl;
			return 0;
		}
};
class Rectangle:public Shape
{
	public:
		Rectangle(int a=0,int b=0):Shape(a,b){}
		int area()
		{
			cout<<"Rectangle class area: "<<endl;
			return(width*height);
		}
};
class Triangle:public Shape
{
	public:
		Triangle(int a=0,int b=0):Shape(a,b){}
		int area()
		{
			cout<<"Triangle class area: "<<endl;
			return(width*height/2);
		}	
};

int main()
{
	Shape *shape;
	Rectangle rec(10,7);
	Triangle tri(10,5);
	Shape sha(6,8);

	shape=&sha;
	shape->area();

	shape=&rec;	//获取存储矩形的地址
	shape->area();	//调用矩形的求面积函数area
			
	shape=&tri;	//获取存储三角形的地址
	shape->area();	//调用三角形的求面积函数area
	
	return 0;
}

