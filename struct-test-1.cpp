#include <iostream>
#include <cstring>

using namespace std;

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	unsigned int book_id;
};

int main()
{
	Books book1;
	Books book2;

	strcpy(book1.title,"C++ 教程");
	strcpy(book1.author,"jinnuo");
	strcpy(book1.subject,"编程语言");
	book1.book_id=12345;

	strcpy(book2.title,"python 教程");
	strcpy(book2.author,"jinnuo");
	strcpy(book2.subject,"上层语言");
	book1.book_id=12346;

	cout<<"第一本书标题："<<book1.title<<endl;
	cout<<"第一本书作者："<<book1.author<<endl;
	cout<<"第一本书类目："<<book1.subject<<endl;
	cout<<"第一本书 ID ："<<book1.book_id<<endl;
	
	cout<<"第二本书标题："<<book1.title<<endl;
	cout<<"第二本书作者："<<book1.author<<endl;
	cout<<"第二本书类目："<<book1.subject<<endl;
	cout<<"第二本书 ID ："<<book1.book_id<<endl;
	
	return 0;
}
