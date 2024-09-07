#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task
{
    public:
        std::string name;
        bool isCompleted;

        Task(const std::string& name):name(name),isCompleted(false){}
};

class TodoList
{
    private:
        vector<Task> tasks;

    public:
        void addTask(const string& taskName)
        {
            tasks.push_back(Task(taskName));
        }
        void markAsComplete(int index)
        {
            if(index>=0 && index<task.size())
            {
                tasks[index].isCompleted=true;
            }
            else
            {
                cout <<"invalid task index."<<endl;
            }
        }
        void removeTask(int index)
        {
            if(index >=0 && index<task.size())
            {
                tasks.earse(tasks.begin()+index);
            }
            else
            {
                cout<<"invalid task index."<<endl;
            }
        }
        void displayTasks() const
        {
            for (size_t i=0;i<tasks.size();++i)
            {
                cout<<"["<<(tasks[i].isCompleted?"x":" ")<<"]"<<tasks[i].name<<endl;
            }
        }
};

int main()
{
    TodoList todolist;

    while(true)
    {
        cout<<"\n--- To-Do List Manager ---\n";
        cout<<"1. Add Task\n";
        cout<<"2. Mark as Comlete\n";
        cout<<"3. Remove Task\n";
        cout<<"4. Display Tasks\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice:";

        int choice;
    }

    return 0;
}

