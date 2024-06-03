#include <iostream>
using namespace std;

class Line
{
	public:
		void setLength(double len);
		double getLength(void);
		Line(double len);		//this is constructor
	private:
		double length;
};

//定义成员函数，包括构造函数
//Line::Line(double len)
Line::Line(double len):length(len)
{
//	length=len;
	cout<<"object is being created! length="<<len<<endl;
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
	Line line(9.3);
	cout<<"Length of line:"<<line.getLength()<<endl;


	line.setLength(8.0);
	cout<<"set length again,Length of line:"<<line.getLength()<<endl;

	return 0;
}
