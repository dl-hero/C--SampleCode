#include <iostream>
using namespace std;

int count;

extern void func(void);

int main() 
{
	count = 10;
	while (count--) {
		func();
	}
	return 0;
}
