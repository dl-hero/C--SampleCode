#include <iostream>

using namespace std;

class Line
{
	public:
		double length;
		void setlength(double len);
		double getlength(void);
};

double Line::getlength(void)
{
	return length;
}

void Line::setlength(double len)
{
	length = len;
}

int main()
{
	Line line;

	line.setlength(7.8);
	cout<<"length of line:"<<line.getlength()<<endl;

	line.length=18.7;
	cout<<"length of line:"<<line.length<<endl;


	return 0;
}
