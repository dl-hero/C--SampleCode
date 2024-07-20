#include <iostream>
#include <string>

using namespace std;

class student
{
	private:
		string _name;
		const int _age=18;
		const int& _alias=_age;
	public:
		student(string name)
		{
			_name=name;
		}
};

int main()
{
	student stu("wang");
	student* p_stu=new student("lin");
	return 0;
}
