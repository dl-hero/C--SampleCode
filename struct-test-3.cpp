#include <iostream>
#include <cstring>

using namespace std;

void printbook(struct Books *book);

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

	printbook(&book1);
	printbook(&book2);

	return 0;
}


void printbook(struct Books *book)
{
	cout<<"书标题："<<book->title<<endl;
	cout<<"书作者："<<book->author<<endl;
	cout<<"书类目："<<book->subject<<endl;
	cout<<" 书ID ："<<book->book_id<<endl;
	
}


