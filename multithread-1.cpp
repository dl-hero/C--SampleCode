#include <iostream>
#include <pthread.h>	//must a head file

using namespace std;

#define NUM_THREADS 5

//线程的运行函数
void* say_Hello(void* args)
{
	cout<<"Hello Runoob!"<<endl;
	return 0;
}

int main()
{
	//定义线程使用的ID，多个变量使用数组
	pthread_t tids[NUM_THREADS];
	for(int i=0;i<NUM_THREADS;++i)
	{
		//参数依次是：创建线程ID,线程参数，调用的函数，传入的函数参数
		int ret=pthread_create(&tids[i],NULL,say_Hello,NULL);
		if(ret!=0)
		{
			cout<<"pthread_create error:error_code="<<ret<<endl;
		}
	}
	//等各线程推出后，进程才结束，否则强制结束了进程，线程可能还没有反应过来
	pthread_exit(NULL);

	return 0;
}
