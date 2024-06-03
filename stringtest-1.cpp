#include <iostream>
#include <string>
using namespace std;

int main()
{
	string http="www.jinnuo.com";

	cout << http.length()<<endl;

	http.append("/Home");
	cout << http << endl;

	int pos = http.find("/Home");
	cout << pos << endl;
	/* when search nothing,return -1*/
	if (pos < http.length())
	{
	
		http.replace(pos,2,"A");
	}
	cout << http << endl;

	int first = http.find_first_of(".");
	int last = http.find_last_of(".");
	cout<<http.substr(first+1,last-first-1)<<endl;

	return 0;
}
