#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void signalHandler(int sigum)
{
	cout<<"Interrupt signal ("<<sigum<<") received.\n";

	//clear and close
	//terminate process
	exit(sigum);
}

int main()
{
	//注册信号 sigint和信号处理程序
	signal(SIGINT,signalHandler);

	while(1)
	{
		cout<<"Going to sleep..."<<endl;
		sleep(1);
	}

	return 0;
}
