#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

//学科科目类
class Subject
{
	public:
		string proName;//学科名
		double proScore;//分数

		//在一行显示科目和分数，格式：左对齐(left)+科目名+45个空格(Setw(45))+分数+6个宽度
		void showCpInfo()
		{
			cout<<left<<setw(45)<<proName;
			cout<<left<<setw(6)<<proScore<<endl;
		}	

		//输出属性名，只显示总积分
		void showHeader()
		{
			cout<<left<<setw(45)<<"科目";
			cout<<left<<setw(6)<<"分数"<<endl;
		}
};

//学生类
class Student
{
	public:
		string stuNum;		//学号
		string stuname；	//姓名
		string gender;		//性别
		int gradeNum;		//年级
		string department;	//专业
		int classNum;		//班级
		vector<Subject>	cps;	//学生的各个科目，创建一个Subjuect类型的空vector，用于保存各个科目信息
		int cpNum;		//科目门数
		double AverageScore;	//平均分

		//构造函数
		Student()
		{
		
		}
		//建立构造函数的重构函数
		Student(string stuNum,string stuName,string gender,int gradeNum,string department,int classNum,vector<subject> cps,int cpNum,double AverageScore)
		{
			this->stuNum=stuNum;
			this->stuName=sutName;
			this->gender=gender;
			this->gradeNum=gradeNum;
			this->department=department;
			this->classNum=classNum;
			this->cps=cps;
			this->cpNum=cpNum;
			this->AverageScore=AverageScore;
		}
		//析构函数
		~Student()
		{
		}

		//输出属性值
		void showStuInfo()
		{
			cout<<left<<setw(12)<<stuNum;			//左对齐+学号+12个空格
			cout<<left<<setw(10)<<stuName;			//左对齐+姓名+10个空格
			cout<<left<<setw(6)<<gender;			//左对齐+性别+6个空格
			cout<<left<<setw(8)<<gradeNum;			//左对齐+年级+8个空格
			cout<<left<<setw(23)<<department;		//左对齐+专业+23个空格
			cout<<left<<setw(6)<<classNum;			//左对齐+班级+6个空格
			cout<<left<<setw(6)<<AverageSocre<<endl;	//左对齐+平均分+6个空格+换行
		}

		//输出属性名
		void showHeader()
		{
			cout<<left<<setw(12)<<"学号";			//左对齐+学号+12个空格
			cout<<left<<setw(10)<<"姓名";			//左对齐+姓名+10个空格
			cout<<left<<setw(6)<<"性别";			//左对齐+性别+6个空格
			cout<<left<<setw(8)<<"年级";			//左对齐+年级+8个空格
			cout<<left<<setw(23)<<"专业";			//左对齐+专业+23个空格
			cout<<left<<setw(6)<<"班级";			//左对齐+班级+6个空格
			cout<<left<<setw(6)<<"平均分"<<endl;		//左对齐+平均分+6个空格+换行
		}
};

//学生列表类
class StudentList
{
	private:
		vector<Student>	stuList;
	public:
		StudentList()
		{
		}
		StudentList(vector<student> stuList)
		{
			this->stuList=stuList;
		}
		~Studentlist()
		{
		}

		//初始化
		void init()
		{
			readFile();	//读取文件
		}
		//主菜单
		void MainMenu()
		{
			string sel="0";
			system("cls");		//清空屏幕
			cout<<"\t\t\t**********欢迎来到学生成绩管理系统**********"<<endl;
			cout<<"\t\t\t你可以进入以下的操作："<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   1    添加学生信息		 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   2    删除学生信息		 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   3    修改学生信息		 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   4    查询学生信息		 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   5    显示信息列表		 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   6    统计学生数据		 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   7    清空系统数据		 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   0    推出			 |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t请选择【0-7】：";
			cin>>sel;
			while("0"!=sel
				&&"1"!=sel
				&&"2"!=sel
				&&"3"!=sel
				&&"4"!=sel
				&&"5"!=sel
				&&"6"!=sel
				&&"7"!=sel)
			{
				cout<<"\t\t\t输入不合法，请重新选择【0-7】：";
				cin<<sel;
			}
			if ("1"==sel)
			{
				this->insertList();
				this->MainMenu();
			}
			else if("2"==sel)
			{
				this->deleteList();
				this->MainMenu();
			}
			else if("3"==sel)
			{
				this->updateList();
				this->MainMenu();
			}
			else if("4"==sel)
			{
				this->selectList();
				this->MainMenu();
			}
			else if("5"==sel)
			{
				this->displayList();
				this->MainMenu();
			}
			else if("6"==sel)
			{
				this->statisticlist();
				this->MainMenu();
			}
			else if("7"==sel)
			{
				this->clearList();
				this->MainMenu();
			}
			else if("0"==sel)
			{
				cout<<"See you Next!!!"<<endl;
				exit(0);
			}
		}

		//读取文件
		void readFile()
		{
			ifstream ifs;	//以输入方式打开文件
			ifs.open("stuList.txt",iso::in);	//打开stuList.txt文件，并将数据写入内存
			int n=0;	//用来接收学生数量的值
			
			ifs>>n;
			for(int i=0;i<n;i++)
			{
				Student stu;
				ifs>>stu.stuNum>>stu.stuName>>stu.gender>>stu.gradeNum>>stu.department>>stu.classNum>>stu.cpNum>>stu.AverageScore;
				for(int j=0;j<stu.cpNum;j++)
				{
					Subject cp;
					ifs>>cp.proName>>cp.proScore;
					stu.cps.push_back(cp);
				}
				stuList.push_back(stu);
			}
			ifs.close();
		}
		//写入文件
		void writeFile()
		{
			ofstream ofs;
			ofs.open("stuList.txt",ios::out);	//打开stuList.txt文件，并且写入模式
			ofs.stuList.size()<<endl;		//先写入学生的数量

			for(int i=0;i<stuList.size();i++)
			{
				ofs<<stulist[i].stuNum<<" "<<stuList[i].stuName<<" "<<stuList[i].gender
					<<" "<<stuList[i].gradeNum<<" "<<stuList[i].department<<" "<<stuList[i].classNum
					<<" "<<stuList[i].cpNum<<" "<<stulist[i].AverageScore<<endl;
				for(j=0;j<stuList[i].cps.size();j++)
				{
					ofs<<stuList[i].cps[j].proName<<" "<<stuList[i].cps[j].proScore<<endl;
				}
			}
			ofs.close();
		}

		//添加学生信息
		void insertList()
		{
			while(true)
			{
				system("cls");
				cout<<"\t\t**********************欢迎来到添加学生信息功能*********************"<<endl;
				cout<<"\t\t学生基本信息一栏表："<<endl;
				displaystu();
				cout<<endl;
				cout<<"\t\t---------------"<<endl;
				cout<<"\t\t1 添加学生信息"<<endl;
				cout<<"\t\t2 返回主菜单"<<endl;
				cout<<"\t\t---------------"<<endl;
				cout<<"\t\t请选择【1-2】：";
				string sel;
				cin>>sel;
				while("1"!==sel&&"2"!==sel)
				{
					cout<<"\t\t输入不合法，请重新输入【1-2】：";
					cin>>sel;
				}
			
			}		
		}

};


int main()
{
	StudentList stulist;
	stulist.init();	//读入文件数据初始化
	stulist.menu();	//打开主菜单

	return 0;
}
