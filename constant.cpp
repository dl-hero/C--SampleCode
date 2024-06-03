#include<iostream>
#include<string>
using namespace std;

//#define LENGTH	10
//#define WIDTH		20
//#define NEWLINE	'\n'

int main() {

	cout << "Hello\tworld\n\n";

	string greeting="Hello,runoob";
	cout << greeting;
	cout << "\n";
	string greeting2="Hello,\
			  runoob";
	cout << greeting2<<endl;

	int area;
	const int LENGTH = 10;
	const int WIDTH	= 20;
	const char NEWLINE = '\n';

	area = LENGTH * WIDTH;
	cout << area;
	cout << NEWLINE;

	return 0;
}
