#include <iostream>
using namespace std;

class Box
{
	public:
		double length;
		double breadth;
		double height;
		double get(void);
		void set(double len,double bre,double hei);
};

double Box::get(void)
{
	return length*breadth*height;
}
void Box::set(double len,double bre,double hei)
{
	length=len;
	breadth=bre;
	height=hei;
}

int main()
{
	Box box1;
	Box box2;
	Box box3;
	double volume=0.0;
	
	box1.length=5.1;
	box1.breadth=3.2;
	box1.height=8.7;

	box2.length=4.8;
	box2.breadth=2.5;
	box2.height=5.8;

	volume=box1.height*box1.length*box1.breadth;
	cout<<"Box1体积："<<volume<<endl;

	volume=box2.height*box2.length*box2.breadth;
	cout<<"Box2体积："<<volume<<endl;

	box3.set(9.8,6.6,12.4);
	volume=box3.get();
	cout<<"Box3体积："<<volume<<endl;

	return 0;


}
