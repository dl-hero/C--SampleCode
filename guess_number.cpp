#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	
	int a=time(NULL);
	
	srand(time(NULL));	//生成随机数种子
	/*如果获取m~n之间随机数，那么rand()&(n-m+1)+m*/
	int number=rand()%100+1;	//生成1到100之间的随机数
	int guess=0;
	int attempts=0;

//	cout<<"time(0)："<<time(NULL)<<srand(time(0))<<"  rand():"<<rand()<<"  number:"<<number<<endl;
	cout<<"  rand():"<<rand()<<"  number:"<<number<<endl;
	cout<<"a:"<<a<<endl;

	cout<<"欢迎来到猜数字游戏！"<<endl;
	cout<<"我已经想好了一个1到100之间的数字，你能猜到它是什么吗？"<<endl;

	while(guess != number)
	{
		cout<<"请输入你的猜测："<<endl;
		cin>>guess;
		attempts++;

		if(guess<number)
		{
			cout<<"太小了，请再试一次"<<endl;
		}
		else if(guess>number)
		{
			cout<<"太大了，请再试一次"<<endl;	
		}
		else
		{
			cout<<"恭喜你，你猜对了！你一共猜了"<<attempts<<"次！再见！"<<endl;
		}
	}
	
	return 0;
}

