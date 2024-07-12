#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

//::作用域区分符
class student
{
	public:
		char name[20];
		char sex[10];
		float math;
		float english;
		float cprogram;
		void input_name();
		void input_sex();
		void input_math();
		void input_english();
		void input_cprogram();
		void input(class student *stu);
		void show_student_message(class student *stu);
};

inline void student::input_name()
{
	cout<<"输入学生名字："<<endl;
	cin.getline(name,sizeof(name));
	cout<<"学生姓名"<<name<<endl;
}

inline void student::input_sex()
{
	cout<<"输入学生性别："<<endl;
	cin.getline(sex,sizeof(sex));
	cout<<"学生性别："<<sex<<endl;
}
inline void student::input_math()
{
	cout<<"输入学生数学成绩："<<endl;
	cin>>math;
}
inline void student::input_english()
{
	cout<<"输入学生英语成绩："<<endl;
	cin>>english;
}
inline void student::input_cprogram()
{
	cout<<"输入学生C语言成绩："<<endl;
	cin>>cprogram;
}
inline void student::show_student_message(class student *stu)
{
	cout<<"学生姓名："<<stu->name<<endl;
	cout<<"学生性别："<<stu->sex<<endl;
	cout<<"学生数学成绩："<<stu->math<<endl;
	cout<<"学生英语成绩："<<stu->english<<endl;
	cout<<"学生C语言成绩："<<stu->cprogram<<endl;
}
inline void student::input(class student *stu)
{
	stu->input_name();
	stu->input_sex();
	stu->input_math();
	stu->input_english();
	stu->input_cprogram();
}

int main()
{
	student xiaoming;
	student *xiaoming_p=&xiaoming;
	xiaoming.input(xiaoming_p);
	cout<<"----------display info----------"<<endl;
	xiaoming.show_student_message(xiaoming_p);
	return 0;
}

