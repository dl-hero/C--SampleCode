#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS	5

void *PrintHello(void *thread)
{
	//对传入的参数进行强制类型转换，由无类型指针转换为int型指针，然后再读取
	int tid=*((int*)thread);
	cout<<"Hello Runoob!线程 ID，"<<tid<<endl;
	pthread_exit(NULL);	
}

int main()
{
	pthread_t threads[NUM_THREADS];	//定义线程的ID变量，多个变量使用数组
	int indexes[NUM_THREADS];//用数组保存i值;
	int rc;
	int i;

	for(i=0;i<NUM_THREADS;i++)
	{
		cout<<"main():创建线程，"<<i<<endl;
		indexes[i]=i;	//现保存i的值
		rc=pthread_create(&threads[i],NULL,PrintHello,(void *)&(indexes[i]));
		if(rc)
		{
			cout<<"error:无法创建线程，"<<rc<<endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);

}
