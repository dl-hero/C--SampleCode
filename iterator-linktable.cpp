#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

//定义基类，并且定义了纯虚函数，用于提供接口
template <typename T>
class Iterator {
    public:
        virtual T next()=0;
        virtual bool hasNext()=0;
};

//template <class T>
template <typename T>
class LinkedListIterator:public Iterator<T> {       //定义T类型的Iteratro类向量
    public:
        LinkedListIterator(Node<T>* start) {        //定义T类型的Node结构体向量
            current_=start;
        }
        T next() override {
            T data=current_->data;
            current_=current_->next;
            return data;
        }
        bool hasNext() override {
            return current_!=nullptr;
        }
    private:
        Node<T>* current_;
};

int main() 
{
        Node<int>* head=nullptr;
        for(int i=6;i>=1;i--) {
           Node<int>* newNode=new Node<int>{i,head};
           head=newNode;
        }

        Iterator<int>* iterator=new LinkedListIterator<int>(head);
        while(iterator->hasNext()){
            cout<<iterator->next()<<" ";
        }

        while(nullptr!=head){
            Node<int>* temp=head;
            head=head->next;
            delete temp;
        }

        delete iterator;
        return 0;
}

