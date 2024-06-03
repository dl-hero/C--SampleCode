#include <iostream>
using namespace std;

class Line
{
	public:
		void setLength(double len);
		double getLength(void);
		Line();		//this is constructor
	private:
		double length;
};

//定义成员函数，包括构造函数
Line::Line(void)
{
	cout<<"object is being created!"<<endl;
}

void Line::setLength(double len)
{
	length=len;
}

double Line::getLength(void)
{
	return length;
}

//main loop
int main()
{
	Line line;

	line.setLength(8.0);
	cout<<"Length of line:"<<line.getLength()<<endl;

	return 0;
}
