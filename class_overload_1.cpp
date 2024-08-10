#include <iostream>

using namespace std;

//加号运算符重载
class xiMeng
{
	public:
		int M_A;
		int M-B;

		//通过成员函数运算符重载
		/* xiMeng operator + (xiMeng& p)
		{
			xiMeng temp;
			temp.M_A=this->M_A+p.M_A;
			temp.M_B=this->M_B+p.M_B;
			return temp;
		}*/
};

//通过全局函数运算符重载
xiMeng operator + (xiMeng& p1,xiMeng& p2)
{
	xiMeng temp;

}
