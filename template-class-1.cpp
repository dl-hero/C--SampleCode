#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack
{
	private:
		vector<T> elems;	//元素
	public:
		void push(T const&);	//入栈
		void pop();		//出栈
		T top() const;		//返回栈顶元素
		bool empty() const{	//如果为空，则返回真
			return elems.empty();
		}
};

template <class T>
void Stack<T>::pop()
{
	if(elems.empty())
	{
		throw out_of_range("Stack<>::pop():empty stack");
	}
	//删除最后一个元素
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if(elems.empty())
	{
		throw out_of_range("Stack<>::pop():empty stack");
	}
	//返回最后一个元素的副本
	return elems.back();
}

int main()
{
	try{
		Stack<int>	intStack;	//int的类型栈
		Stack<string>	stringStack;	//string类型的栈
		
		//操作int的类型栈
		intStack.push(7);
		cout<<intStack.top()<<endl;

		//操作string类型的栈
		stringStack.push("Hello");
		cout<<stringStack.top()<<std::endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const& ex){
		cerr<<"Exception: "<<ex.what()<<endl;
		return -1;
	}
}



