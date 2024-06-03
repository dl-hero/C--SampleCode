#include <iostream>
using namespace std;

class Box
{
	public:
		double length;
		void setWidth(double wid);
		double getWidth(void);
		double getVolume(void);
	private:
		double width;
};


double Box::getWidth(void)
{
	return width;
}

void Box::setWidth(double wid)
{
	width = wid;
}

double Box::getVolume(void)
{
	return width*length;
}

int main()
{
	Box box;

	box.length=10.0;
	cout<<"Length of box:"<<box.length<<endl;	

	box.setWidth(11.0);
	cout<<"Width of box:"<<box.getWidth()<<endl;

	cout<<"Volume of box:"<<box.getVolume()<<endl;	


}
