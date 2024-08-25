#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stdlib.h>

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
		string stuNum;		    //学号
		string stuName;	        //姓名
		string gender;		    //性别
		int gradeNum;		    //年级
		string department;	    //专业
		int classNum;		    //班级
        int score;              //总分数
		vector<Subject>	cps;	//学生的各个科目，创建一个Subjuect类型的空vector，用于保存各个科目信息
		int cpNum;		        //科目门数
		double AverageScore;	//平均分

		//构造函数
		Student()
		{
		
		}
		//建立构造函数的重构函数
		Student(string stuNum,string stuName,string gender,int gradeNum,string department,int classNum,vector<Subject> cps,int cpNum,double AverageScore)
		{
			this->stuNum=stuNum;
			this->stuName=stuName;
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
			cout<<left<<setw(12)<<stuNum;			    //左对齐+(12-学号)个空格+学号
			cout<<left<<setw(10)<<stuName;			    //左对齐+(10-姓名)个空格+姓名
			cout<<left<<setw(10)<<gender;			    //左对齐+(10-性别)个空格+性别
			cout<<left<<setw(10)<<gradeNum;			    //左对齐+(10-年级)个空格+年级
			cout<<left<<setw(20)<<department;		    //左对齐+(20-专业)个空格+专业
			cout<<left<<setw(10)<<classNum;			    //左对齐+(10-班级)个空格+班级
			cout<<left<<setw(10)<<AverageScore<<endl;	//左对齐+(10-平均分)个空格+平均分+换行
		}

		//输出属性名
		void showHeader()
		{
			cout<<left<<setw(12)<<"学号";			    //左对齐+(12-学号)个空格+学号
			cout<<left<<setw(10)<<"姓名";			    //左对齐+(10-姓名)个空格+姓名
			cout<<left<<setw(10)<<"性别";			    //左对齐+(10-性别)个空格+性别
			cout<<left<<setw(10)<<"年级";			    //左对齐+(10-年级)个空格+年级
			cout<<left<<setw(20)<<"专业";			    //左对齐+(20-专业)个空格+专业
			cout<<left<<setw(10)<<"班级";			    //左对齐+(10-班级)个空格+班级
			cout<<left<<setw(10)<<"平均分"<<endl;		//左对齐+(10-平均分)个空格+平均分+换行
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
		StudentList(vector<Student> stuList)
		{
			this->stuList=stuList;
		}
		~StudentList()
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
            system("kill");
            system("clear");		//清空屏幕
			cout<<"\t\t\t**********欢迎来到学生成绩管理系统**********"<<endl;
			cout<<"\t\t\t你可以进入以下的操作："<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   1    添加学生信息	    |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   2    删除学生信息	    |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   3    修改学生信息	    |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   4    查询学生信息	    |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   5    显示信息列表	    |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   6    统计学生数据	    |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   7    清空系统数据	    |"<<endl;
			cout<<"\t\t\t|-------------------------------------------|"<<endl;
			cout<<"\t\t\t|		   0    退出	            |"<<endl;
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
				cin>>sel;
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
				this->statisticList();
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
			ifstream infile;	//以输入方式打开文件
//			ifs.open("stuList.txt",ios::in);	//打开stuList.txt文件，并将数据写入内存
			int n=0;	//用来接收学生数量的值
            Student stu_readFile;  
            Subject cp_readFile;

            infile.open("StudentDatabase.dat",ios::in);  //打开studentDataBase.dat文件，并且将数据写入内存
            if(!infile)         //文件读取失败，路径错误
            {
                cout<<"读取学生数据库失败，请确认数据库文件后再试！"<<endl;
                return;
            }
            else
            {
                infile>>n;              //将学生个数写入变量-n;
                for(int i=0;i<n;i++)
    			{
    				infile>>stu_readFile.stuNum>>stu_readFile.stuName>>stu_readFile.gender>>stu_readFile.gradeNum>>stu_readFile.department>>stu_readFile.classNum>>stu_readFile.cpNum>>stu_readFile.AverageScore;
    				for(int j=0;j<stu_readFile.cpNum;j++)
    				{
    					infile>>cp_readFile.proName>>cp_readFile.proScore;
    					stu_readFile.cps.push_back(cp_readFile);
    				}
    				stuList.push_back(stu_readFile);
    			}
            }
			infile.close();
		}
		//写入文件
		void writeFile()
		{
			ofstream outfile;
            outfile.open("studentDataBase.dat",ios::out);   //打开studentDataBase.dat文件，并且写入模式
            
            if(!outfile)        //打开学生数据库失败，路径错误
            {
                cout<<"学生数据库打开失败，请重新确认数据库文件后再试！"<<endl;
                return;
            }
            else
            {
                outfile<<stuList.size()<<endl;		//先写入学生的数量

	    		for(int i=0;i<stuList.size();i++)
	    		{
	    			outfile<<stuList[i].stuNum<<" "<<stuList[i].stuName<<" "<<stuList[i].gender
	    				<<" "<<stuList[i].gradeNum<<" "<<stuList[i].department<<" "<<stuList[i].classNum
	    				<<" "<<stuList[i].cpNum<<" "<<stuList[i].AverageScore<<endl;
	    			for(int j=0;j<stuList[i].cps.size();j++)
	    			{
	    				outfile<<stuList[i].cps[j].proName<<" "<<stuList[i].cps[j].proScore<<endl;
	    			}
                }
            }
			outfile.close();
		}

		//添加学生信息
		void insertList()
		{
			Student stu_insertList;
			Subject cp_insertList;
	
            while(true)
			{
				system("clear");
				cout<<"\t\t**********************欢迎来到添加学生信息功能*********************"<<endl;
				cout<<"\t\t学生基本信息一栏表："<<endl;
				displayStu();
				cout<<endl;
				cout<<"\t\t---------------"<<endl;
				cout<<"\t\t1 添加学生信息"<<endl;
				cout<<"\t\t2 返回主菜单"<<endl;
				cout<<"\t\t---------------"<<endl;
				cout<<"\t\t请选择【1-2】：";
				string sel;
				cin>>sel;
				while("1"!=sel&&"2"!=sel)
				{
					cout<<"\t\t输入不合法，请重新输入【1-2】：";
					cin>>sel;
				}
				if("1"==sel)	//添加学生信息
				{
					string flag="1";
					while("1"==flag)
					{
						cout<<"\t\t输入学生信息："<<endl;
						cout<<"\t\t学号:";
						bool check=false;
						do
						{
							check=false;
							cin>>stu_insertList.stuNum;
							for(int i=0;i<stuList.size();++i)
							{
								if(stu_insertList.stuNum==stuList[i].stuNum)
								{
									cout<<"\t\t该学号已存在，请重新输入：";
									check=true;
									break;
								}
							}
						}
						while(check);
						cout<<"\t\t姓名:";
						cin>>stu_insertList.stuNum;
						cout<<"\t\t性别:";
						cin>>stu_insertList.gender;
						cout<<"\t\t年级:";
						cin>>stu_insertList.gradeNum;
                        while(cin.fail())       //防止用户错误的输入字符
                        {
                            cout<<"\t\t输入错误，输出入代表年级的数字"<<endl;
                            cin.clear();
                            cin.ignore();
                            cout<<"\t\t年级：";
                            cin>>stu_insertList.gradeNum;
                        }
                        cout<<"\t\t专业:";
						cin>>stu_insertList.department;
						cout<<"\t\t班级:";
						cin>>stu_insertList.classNum;
	                    while(cin.fail())       //防止用户错误的输入字符
                        {
                            cout<<"\t\t输入错误，输出入代表班级的数字"<<endl;
                            cin.clear();
                            cin.ignore();
                            cout<<"\t\t班级：";
                            cin>>stu_insertList.classNum;
                        }
     					stu_insertList.score=0;
						string option="1";
						cout<<"\t\t是否添加成绩信息？（1是 0否）"<<endl;
						cout<<"\t\t请进行选择【0-1】：";
						cin>>option;
						while("0"!=option&&"1"!=option)
						{
							cout<<"\t\t输入不合法，请重新选择【0-1】：";
							cin>>option;
						}
						if("1"==option)	//添加成绩信息
						{
							int cnt=0;
							while("1"==option)
							{
								cnt++;
								cout<<"\t\t第"<<cnt<<"科科目名称:";
								cin>>cp_insertList.proName;
								cout<<"\t\t第"<<cnt<<"科科目成绩:";
								cin>>cp_insertList.proScore;
								stu_insertList.cps.push_back(cp_insertList);
								cout<<"\t\t该科成绩信息添加成功！是否继续添加？（1是 0否）"<<endl;
								cout<<"\t\t请进行选择【0-1】：";
								cin>>option;		//0：退出;1：继续添加
								while("0"!=option&&"1"!=option)
								{
									cout<<"\t\t输入不合法，请重新选择【0-1】：";
									cin>>option;
								}
							}
	    			    	cout<<"\n\t\t该名学生信息添加成功！是否继续添加？（1是 0否）"<<endl;
					    	cout<<"\t\t请进行选择【0-1】：";
					    	cin>>flag;
					    	while("0"!=flag&&"1"!=flag)
					    	{
						    	cout<<"\t\t输入不合法，请重新选择【0-1】：";
						    	cin>>flag;
						    }
						}
                        else        //0==option 不添加成绩信息
                        {
                            break;
                        }
		                for(int i=0;i<stu_insertList.cps.size();i++)
	    	        	{
		    	        	stu_insertList.score+=stu_insertList.cps[i].proScore;
			            }
		            	if(stu_insertList.cps.size()>0)stu_insertList.AverageScore=stu_insertList.score/stu_insertList.cps.size();	//计算平均分数
		        	    stu_insertList.cpNum=stu_insertList.cps.size();
		            	stuList.push_back(stu_insertList);
				    }
					cout<<"\t\t";
                    cout<<"\t\tPlease any key to continue...";
                    cin.ignore();
                    cin.get();
			}
				else    //2==sel 返回主菜单
				{
		          	writeFile();	//将缓存数据写入到文件
			    	break;
				}	
			}		
    	}

		//删除学生信息
		void deleteList()
		{
			while(true)
			{
				system("clear");
				cout<<"\t\t**********************欢迎来到删除学生信息功能*********************"<<endl;
				string sel="0";
				cout<<"\t\t--------------"<<endl;
				cout<<"\t\t1  按学号删除"<<endl;
				cout<<"\t\t2  按姓名删除"<<endl;
				cout<<"\t\t3  返回主菜单"<<endl;
				cout<<"\t\t--------------"<<endl;
				cout<<"\t\t请进行选择【1-3】：";
				cin>>sel;
				while("1"!=sel&&"2"!=sel&&"3"!=sel)
				{
					cout<<"\t\t输入不合法，请重新输入【1-3】：";
					cin>>sel;
				}
				if("1"==sel)	//选择按学号删除
				{
					string keyNum;
					bool flag=false;
					cout<<"\t\t请输入待删除学生的学号：";
					cin>>keyNum;
					for(vector<Student>::iterator it=stuList.begin();stuList.end()!=it;++it)
					{
						if(it->stuNum==keyNum)
						{
							flag=true;
							cout<<"\t\t待删除学生的信息如下："<<endl;
							cout<<"\t\t------------------------------------"<<endl;
							cout<<"\t\t";
//                            Student::showHeader();
                            it->showHeader();
							cout<<"\t\t---------------------------------------------"<<endl;
							cout<<"\t\t";
							it->showStuInfo();
							cout<<"\t\t---------------------------------------------"<<endl;
							cout<<"\t\t确认删除？（1是 0否）"<<endl;
							cout<<"\t\t请进行选择【0-1】：";
							string ch="0";
							cin>>ch;
							while("0"!=ch&&"1"!=ch)
							{
								cout<<"\t\t输入不合法，请重新选择【0-1】：";
								cin>>ch;
							}
							if("0"==ch)
							{
								break;
							}
							else
							{
								stuList.erase(it);
								writeFile();
								cout<<"\t\t删除成功！"<<endl;
								break;
							}

						}	
					}
					if(!flag)
					{
						cout<<"\t\t查无此人，无法删除！\n"<<endl;
					}
                    cout<<"\t\t";
					cout<<"\t\tPlease any key to contiune...";
//					system("kill");
                    //wait any key to return;
                    cin.ignore();
                    cin.get();
                }
				else if("2"==sel)	//选择按姓名删除
				{
					string KeyName;
					bool flag=false;
					cout<<"\t\t请输入待删除学生的姓名：";
//					cin>>KeyName;
                    cin>>KeyName;
                    for(vector<Student>::iterator it=stuList.begin();stuList.end()!=it;++it)
					{
						if(it->stuName==KeyName)
						{
							flag=true;
							cout<<"\t\t待删除学生的信息如下："<<endl;
							cout<<"\t\t------------------------------------------"<<endl;
							cout<<"\t\t\t";
							it->showHeader();
							cout<<"\t\t------------------------------------------"<<endl;
							cout<<"\t\t";
							it->showStuInfo();
							cout<<"\t\t------------------------------------------"<<endl;
							cout<<"\t\t确认删除？（1是 0否）"<<endl;
							cout<<"\t\t请进行选择【0-1】：";
							string ch="0";
							cin>>ch;
							while("0"!=ch&&"1"!=ch)
							{
								cout<<"\t\t输入不合法，请重新选择【0-1】：";
								cin>>ch;
							}
							if("0"==ch)
							{
								break;
							}
							else
							{
								stuList.erase(it);
								writeFile();
								cout<<"\t\t删除成功！"<<endl;
								break;
							}

						}	
					}
					if(!flag)
					{
						cout<<"\t\t查无此人，无法删除！\n"<<endl;
					}
					cout<<"\t\t";
					system("kill");

				}
				else
				{
					break;
				}
			}	
		}
		//修改学生信息
		void updateList()
		{
			Subject cp;
            while(true)
			{
				system("clear");
				cout<<"\t\t*************************欢迎来到修改学生信息功能**************************"<<endl;
				string sel="0";
				cout<<"\t\t--------------------"<<endl;
				cout<<"\t\t1 修改学生基本信息"<<endl;
				cout<<"\t\t2 修改学生成绩信息"<<endl;
				cout<<"\t\t3 返回主菜单"<<endl;
				cout<<"\t\t--------------------"<<endl;
				cout<<"\t\t请进行选择【1-3】：";
				cin>>sel;
				while("1"!=sel&&"2"!=sel&&"3"!=sel)
				{
					cout<<"\t\t输入不合法，请重新输入【1-3】:";
					cin>>sel;
				}
				if ("1"==sel)		//修改学生基本信息
				{
					bool flag=false;
					string keyNum;
					cout<<"\t\t请输入待修改学生的学号：";
					cin>>keyNum;
					for(int i=0;i<stuList.size();i++)
					{
						if(stuList[i].stuNum==keyNum)
						{
							flag=true;
							cout<<"\t\t待修改学生基本信息如下："<<endl;
							cout<<"\t\t------------------------------------------"<<endl;
							cout<<"\t\t\t";
//                            Student::showHeader();
                            stuList[i].showHeader();
                            cout<<"\t\t------------------------------------------"<<endl;
							cout<<"\t\t";
                            stuList[i].showStuInfo();
							cout<<"\t\t------------------------------------------"<<endl;
	
							Student s=stuList[i];
							cout<<"\t\t请输入修改后的学号：";
							bool check=false;
							do
							{
								check=false;
								cin>>s.stuNum;
								for(int j=0;j<stuList.size();++j)
								{
									if(s.stuNum==stuList[j].stuNum&&i!=j)
									{
										cout<<"\t\t该学号已被录入，请重新输入学号：";
										check=true;
										break;
									}
								}
							}
							while(check);
							cout<<"\t\t请输入修改后的姓名：";
							cin>>s.stuName;
							cout<<"\t\t请输入修改后的性别：";
							cin>>s.gender;
							cout<<"\t\t请输入修改后的年级：";
							cin>>s.gradeNum;
							cout<<"\t\t请输入修改后的专业：";
							cin>>s.department;
							cout<<"\t\t请输入修改后的班级：";
							cin>>s.classNum;
							cout<<"\t\t是否确定修改？（1是 0否）"<<endl;
							cout<<"\t\t请进行选择【0-1】：";
							string ch=0;
							cin>>ch;
							while("0"!=ch&&"1"!=ch)
							{
								cout<<"\t\t输入不合法，请重新选择【0-1】：";
								cin>>ch;
							}
							if("0"==ch)
							{
								break;
							}
							else
							{
								stuList[i]=s;
								writeFile();
								cout<<"\t\t修改成功！"<<endl;
								break;
							}
						}
					}
					if(!flag)cout<<"\t\t查无此人，无法修改！\n"<<endl;
				}
				else if("2"==sel)	//修改学生成绩信息
				{
					bool flag=false;
					string keyNum;
					cout<<"\t\t请输入待修改学生的学号：";
					cin>>keyNum;
					for(int i=0;i<stuList.size();i++)
					{
						if(stuList[i].stuNum==keyNum)
						{
							flag=true;
							cout<<"\t\t待修改学生成绩信息如下："<<endl;
							cout<<"\t\t------------------------------------------------"<<endl;
							cout<<"\t\t";
							cout<<left<<setw(8)<<"编号";
							cp.showHeader();
                            cout<<"\t\t------------------------------------------------"<<endl;
							for(int j=0;j<stuList[i].cps.size();j++)
							{
								cout<<"\t\t";
								cout<<left<<setw(8)<<j+1;
								stuList[i].cps[j].showCpInfo();
							}
							cout<<"\t\t------------------------------------------------"<<endl;
							Student s=stuList[i];
							cout<<"\t\t请学则修改方式："<<endl;
							string option="1";
							cout<<"\t\t-------------------------------"<<endl;
							cout<<"\t\t1 基于该学生原有成绩信息进行修改"<<endl;
							cout<<"\t\t2 清空该学生所有科目及成绩信息"<<endl;
							cout<<"\t\t-------------------------------"<<endl;
							cout<<"\t\t请进行选择【1-2】：";
							cin>>option;
							while("1"!=option&&"2"!=option)
							{
								cout<<"\t\t输入值不合法，请重新选择【1-2】：";
								cin>>option;
							}
//							Subject cp;
							//基于该学生原有成绩修改
							if("1"==option)	
							{
								s.cps.clear();
								s.score=0;
								s.cpNum=0;
								cout<<"\t\t输入修改后的学科成绩信息："<<endl;
								int cnt=0;
								while("1"==option)
								{
									cnt++;
									cout<<"\t\t第"<<cnt<<"科科目名称：";
									cin>>cp.proName;
									cout<<"\t\t第"<<cnt<<"科科目成绩：";
									cin>>cp.proScore;
									s.cps.push_back(cp);
									cout<<"\n\t\t添加成功！是否继续添加？（1是 0否）"<<endl;
									cout<<"\t\t请进行选择【0-1】：";
									cin>>option;
									while("0"!=option&&"1"!=option)
									{
										cout<<"\t\t输入不合法，请重新选择【0-1】：";
										cin>>option;
									}
								}
							}
							//清空该学生所有科目集成及
							else if("2"==option)
							{
								s.cps.clear();
								s.score=0;
								s.cpNum=0;
							}
							//计算平均分
							for(int i=0;i<s.cps.size();i++)
							{
								s.score+=s.cps[i].proScore;
							}
							if(s.cps.size()>0)s.cpNum=s.cps.size();
							cout<<"\t\t是否确认修改？（1是 0否）"<<endl;
							cout<<"\t\t请进行选择【0-1】：";
							string ch="0";
							cin>>ch;
							while("0"!=ch&&"1"!=ch)
							{
								cout<<"\t\t输入不合法，请重新选择【0-1】：";
								cin>>ch;
							}
							if("0"==ch)break;
							else
							{
								stuList[i]=s;
								writeFile();
								cout<<"\t\t修改成功！"<<endl;
								break;
							}
						}
					}
					if(!flag)cout<<"\t\t查无此人，无法修改！\n"<<endl;
				}
				else	//返回主菜单
				{
					break;
				}
				cout<<"\t\t";
	            cout<<"\t\tPlease any key to continue...";
                cin.ignore();
                cin.get();

			}
		}

		//查询学生信息
		void selectList()
		{
            Student stu;
            Subject cp;
            while(true)
			{
				system("clear");
				cout<<"\t\t**********************欢迎来到查询学生信息功能*********************"<<endl;
				cout<<"\t\t--------------"<<endl;
				cout<<"\t\t1  按学号查询"<<endl;
				cout<<"\t\t2  按姓名查询"<<endl;
				cout<<"\t\t3  返回主菜单"<<endl;
				cout<<"\t\t--------------"<<endl;
				cout<<"\t\t请进行选择【1-3】：";
				string sel="0";
				cin>>sel;
				while("1"!=sel&&"2"!=sel&&"3"!=sel)
				{
					cout<<"\t\t输入不合法，请重新输入【1-3】：";
					cin>>sel;
				}
				if("1"==sel)
				{
					string keyNum;
					bool flag=false;
					cout<<"\t\t请输入待查询学生的学号：";
					cin>>keyNum;
					cout<<"\t\t查询结果如下："<<endl;
					cout<<"\t\t基本信息："<<endl;
					cout<<"\t\t---------------------------------------------------------------"<<endl;
					cout<<"\t\t";
//					Student::showHeader();
                    stu.showHeader();
                    cout<<"\t\t---------------------------------------------------------------"<<endl;
					for(int i=0;i<stuList.size();i++)
					{
						if(stuList[i].stuNum==keyNum)
						{
							flag=true;
							cout<<"\t\t";
							stuList[i].showStuInfo();
							cout<<"\t\t---------------------------------------------------------------"<<endl;
							cout<<endl;
							cout<<"\t\t"<<stuList[i].stuName<<"成绩信息："<<endl;
							cout<<"\t\t-----------------------------------------------------"<<endl;
							cout<<"\t\t";
							cout<<left<<setw(8)<<"编号";
//							Subject::showHeader();
                            cp.showHeader();
                            cout<<"\t\t-----------------------------------------------------"<<endl;
							for(int j=0;j<stuList[i].cps.size();j++)
							{
								cout<<"\t\t";
								cout<<left<<setw(8)<<j+1;
								stuList[i].cps[j].showCpInfo();
							}
							cout<<"\t\t------------------------------------------------------"<<endl;
							break;
						}
					}
					if(!flag)cout<<"\t\t查无此人！\n"<<endl;
					cout<<"\t\t";
				}
				else if("2"==sel)
				{
					string keyName;
					bool flag=false;
					cout<<"\t\t请输入待查询学生的姓名：";
					cin>>keyName;
					cout<<"\t\t查询结果如下："<<endl;
					cout<<"\t\t基本信息："<<endl;
					cout<<"\t\t---------------------------------------------------------------"<<endl;
					cout<<"\t\t";
//					Student::showHeader();
                    stu.showHeader();
                    cout<<"\t\t---------------------------------------------------------------"<<endl;
					for(int i=0;i<stuList.size();i++)
					{
						if(stuList[i].stuName==keyName)
						{
							flag=true;
							cout<<"\t\t";
							stuList[i].showStuInfo();
							cout<<"\t\t---------------------------------------------------------------"<<endl;
							cout<<endl;
							cout<<"\t\t"<<stuList[i].stuName<<"成绩信息："<<endl;
							cout<<"\t\t-----------------------------------------------------"<<endl;
							cout<<"\t\t";
							cout<<left<<setw(8)<<"编号";
//							Subject::showHeader();
                            cp.showHeader();
                            cout<<"\t\t-----------------------------------------------------"<<endl;
							for(int j=0;j<stuList[i].cps.size();j++)
							{
								cout<<"\t\t";
								cout<<left<<setw(8)<<j+1;
								stuList[i].cps[j].showCpInfo();
							}
							cout<<"\t\t------------------------------------------------------"<<endl;
							break;
						}
					}
					if(!flag)cout<<"\t\t查无此人！\n"<<endl;
					cout<<"\t\t";
	                cout<<"\t\tPlease any key to continue...";
                    cin.ignore();
                    cin.get();
				}
				else
				{
					break;
				}
			}

		}
		//遍历学生列表
		void displayStu()
		{
            Student stu_displayStu;
            cout<<"\t\t--------------------------------------------------------------------------"<<endl;
			cout<<"\t\t";
//			Student::showHeader();
            stu_displayStu.showHeader();
            cout<<"\t\t--------------------------------------------------------------------------"<<endl;
			for(int i=0;i<stuList.size();i++)
			{
				cout<<"\t\t";
				stuList[i].showStuInfo();
			}
			cout<<"\t\t--------------------------------------------------------------------------"<<endl;
		}
		//查询获奖信息
		void displayCp()
		{
            Subject cp;
            cout<<"\t\t--------------------------------------------------------------------------"<<endl;
			cout<<"\t\t";
			cout<<left<<setw(12)<<"学号";
			cout<<left<<setw(10)<<"姓名";
//			Subject::showHeader();
            cp.showHeader();
            cout<<"\t\t--------------------------------------------------------------------------"<<endl;
			for(int i=0;i<stuList.size();i++)
			{
				for(int j=0;j<stuList[i].cps.size();j++)
				{
					cout<<"\t\t";
					cout<<left<<setw(12)<<stuList[i].stuNum;
					cout<<left<<setw(10)<<stuList[i].stuName;
					stuList[i].cps[j].showCpInfo();
				}
			}
			cout<<"\t\t--------------------------------------------------------------------------"<<endl;
		}

		//显示信息列表
		void displayList()
		{
            system("clear");
			cout<<"\t\t**********************欢迎来到显示信息列表功能*********************"<<endl;
			cout<<"\t\t表1  学生基本信息一栏表"<<endl;
			this->displayStu();
			cout<<"\n\t\t表2  学生成绩信息一栏表"<<endl;
			this->displayCp();
			cout<<"\t\t";
            cout<<"\t\tPlease any key to continue...";
            cin.ignore();
            cin.get();
        }
		
		//将学生列表按学好升序排列
		static bool cmpNum(const Student& s1,Student& s2)
		{
			return s1.stuNum<s2.stuNum;
		}

		//将学生列表按平均分降序排列，平均分相同的再按照学号升序排列
		static bool cmpscore(const Student& s1,Student& s2)
		{
			if(s1.stuNum!=s2.stuNum) return s1.score>s2.score;
			else return s1.stuNum<s2.stuNum;
		}
		
		//统计学生数据
		void statisticList()
		{
			while(true)
			{
				system("clear");
				cout<<"\t\t*************************欢迎来到统计学生数据功能**************************"<<endl;
				string sel="0";
				cout<<"\t\t--------------------"<<endl;
				cout<<"\t\t1 按学号排序"<<endl;
				cout<<"\t\t2 修平均分排序"<<endl;
				cout<<"\t\t3 返回主菜单"<<endl;
				cout<<"\t\t--------------------"<<endl;
				cout<<"\t\t请进行选择【1-3】：";
				cin>>sel;
				while("1"!=sel&&"2"!=sel&&"3"!=sel)
				{
					cout<<"\t\t输入不合法，请重新输入【1-3】:";
					cin>>sel;
				}
				if("1"==sel)
				{
					sort(stuList.begin(),stuList.end(),cmpNum); cout<<"\t\t按学号升序排列如下："<<endl;
					this->displayStu();
					int numMale=0,numFemale=0;
					for(int i=0;i<stuList.size();i++)
					{
						if("男"==stuList[i].gender) numMale++;
						else if("女"==stuList[i].gender) numFemale++;
					}
					cout<<"\t\t一共"<<stuList.size()<<"人，其中男生"<<numMale<<"人，女生"<<numFemale<<"人。"<<endl;
					cout<<"\t\t";
                    cout<<"\t\tPlease any key to continue...";
                    cin.ignore();
                    cin.get();
				}
				else if("2"==sel)
				{
					sort(stuList.begin(),stuList.end(),cmpscore);
					cout<<"\t\t按平均分降序排列如下："<<endl;
					this->displayStu();
					vector<int> z(10);
					double totalscore=0;
					for(int i=0;i<stuList.size();++i)
					{
						totalscore+=stuList[i].score;
						if(0<=stuList[i].score&&stuList[i].score<60) z[0]++;
						else if(60<=stuList[i].score&&stuList[i].score<70) z[1]++;
						else if(70<=stuList[i].score&&stuList[i].score<80) z[2]++;
						else if(80<=stuList[i].score&&stuList[i].score<90) z[3]++;
						else z[4]++;
					}
					cout<<"\t\tscore<60-------------------"<<z[0]<<"人"<<endl;
					cout<<"\t\t60<=score<70---------------"<<z[1]<<"人"<<endl;
					cout<<"\t\t70<=score<80---------------"<<z[2]<<"人"<<endl;
					cout<<"\t\t80<=score<90---------------"<<z[3]<<"人"<<endl;
					cout<<"\t\t90<=score<100--------------"<<z[4]<<"人"<<endl;
					cout<<"\t\t所有学生平均分："<<totalscore/stuList.size()<<endl;
					cout<<"\t\t"<<stuList.back().gradeNum<<"级"<<stuList.back().department<<stuList.back().classNum<<"班---";
					cout<<stuList.back().stuName<<"平均分最低，为"<<stuList.back().score<<"分"<<endl;
					cout<<"\t\t"<<stuList.front().gradeNum<<"级"<<stuList.front().department<<stuList.front().classNum<<"班---";
					cout<<stuList.front().stuName<<"平均分最低，为"<<stuList.front().score<<"分"<<endl;
					cout<<"\t\t";
                    cout<<"\t\tPlease any key to continue...";
                    cin.ignore();
                    cin.get();
				}
				else
				{
					break;
				}
			}
		}

		//清空系统数据
		void clearList()
		{
			while(true)
			{
				string sel="0";
				system("clear");
				cout<<"\t\t**********************欢迎来到清空数据功能*********************"<<endl;
				cout<<"\t\t--------------"<<endl;
				cout<<"\t\t1  确认清空系统数据"<<endl;
				cout<<"\t\t2  返回主菜单"<<endl;
				cout<<"\t\t--------------"<<endl;
				cout<<"\t\t请进行选择【1-2】：";
				cin>>sel;
				while("1"!=sel&&"2"!=sel)
				{
					cout<<"\t\t输入不合法，请重新输入【1-2】：";
					cin>>sel;
				}
				if("1"==sel)
				{
					stuList.clear();    //清空vector所有数据
                   //显示清空过程 
                    cout<<"\t\t清空功能！"<<endl;
					cout<<"\t\t";
					system("kill");
					writeFile();
				}
				else break;
			}
		}
};


int main()
{
	StudentList stuinfo_main;
	stuinfo_main.init();	//读入文件数据初始化
	stuinfo_main.MainMenu();	//打开主菜单
	return  0;
}
