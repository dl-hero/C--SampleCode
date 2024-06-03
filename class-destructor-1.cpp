#include <iostream>
using namespace std;

class Line
{
	public:
		void setLength(double len);
		double getLength(void);
		Line();		//this is constructor
		~Line();		//this is destructor
	private:
		double length;
};

//定义成员函数，包括构造函数
Line::Line(void)
{
	cout<<"object is being created!"<<endl;
}

Line::~Line(void)
{
	cout<<"object is being deleted!"<<endl;
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
	int i=0;
	Line line;

	line.setLength(8.0);
	cout<<"Length of line:"<<line.getLength()<<endl;

	for (i=0;i<10;i++)
	{
		cout<<i<<endl;
	}
	return 0;
}
