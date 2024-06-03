#include <iostream>
#include <vector>
using namespace std;

class Obj
{
	static int i,j;
public:
	void f() const{cout<<i++<<endl;}
	void g() const{cout<<j++<<endl;}
};

//define staric number
int Obj::i=10;
int Obj::j=12;

//为上面的类实现一个容器
class ObjContainer
{
	vector<Obj*> a;
public:
	void add(Obj* obj)
	{
		a.push_back(obj);
	}
	friend class SmartPointer;
};

//实现只能指针，用于访问Obj类成员
class SmartPointer
{
	ObjContainer oc;
	int index;
public:
	SmartPointer(ObjContainer& objc)
	{
		oc=objc;
		index=0;
	}
	//返回值表示列表结束
	bool operator++()	//前缀版本
	{
		if(index>=oc.a.size()-1) return false;
		if(oc.a[index]==0) return false;
		return true;
	}
	bool operator++(int)	//后缀版本
	{
		return operator++();
	}
	//重载运算符->
	Obj* operator->() const
	{
		if(!oc.a[index])
		{
			cout<<"Zero value";
			return (Obj*)0;
		}
		return oc.a[index];
	}
};

int main()
{
	const int SZ=10;
	Obj o[SZ];
	ObjContainer oc;

	for(int i=0;i<SZ;i++)
	{
		oc.add(&o[i]);
	}
	SmartPointer sp(oc);	//创建一个迭代器
	do {
		sp->f();	//只能指针调用
		sp->g();
	}
       	while(sp++);
	
	return 0;
}


