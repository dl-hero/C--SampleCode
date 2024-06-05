#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char data[100];
	int age;

	//以写模式打开文件
	ofstream outfile;
	outfile.open("afile.data");

	cout<<"Writing to the file"<<endl;
	cout<<"Enter your name:";
	cin.getline(data,100);	//从外部读取一行

	//向文件写入用户数据
	outfile<<data<<endl;

	cout<<"Enter your age: ";
//	cin>>data;
//	cin.ignore();	//忽略掉之前语句留下的多于数据
	cin>>age;

	//再次向文件写入用户数据
//	 outfile<<data<<endl;	
	outfile<<age<<endl;

	 //关闭打开的文件
	 outfile.close();

	 //以读模式打开文件
	 ifstream infile;
	 infile.open("afile.data");

	 cout<<"Reading from the file"<<endl;
	infile>>data;

	//在屏幕上写入数据
	cout<<data<<endl;

	//再次从文件读取数据，并显示它
//	infile>>data;
//	cout<<data<<endl;
	infile>>age;
	cout<<age<<endl;

	//关闭打开的文件
	infile.close();

	return 0;
}
