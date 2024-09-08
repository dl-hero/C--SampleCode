#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Task
{
    public:
        string name;
        bool isCompleted;

        Task(const string& name):name(name),isCompleted(false){}
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
            if(index>=0 && index<tasks.size())
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
            if(index >=0 && index<tasks.size())
            {
                tasks.erase(tasks.begin()+index);
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
        int TasksStatus() const
        {
            if(tasks.size()){
                return 1;
            }
            else 
            {
                return 0;
            }
        }
        void readfile()
        {
            ifstream infile;    //open file by read mode
            int index=0;
            Task temptask("test");

            infile.open("tasks.dat",ios::in);
            if(!infile)
            {
                cout<<"reading data is error, please confirm database!!!"<<endl;
                return;
            }
            else
            {
                infile>>index;
                for(int i=0;i<index;i++)
                {
                    infile>>temptask.name>>temptask.isCompleted;
                }
                tasks.push_back(temptask);
            }
            infile.close();
        }
        void writefile()
        {
            ofstream outfile;   //open file by write mode
            outfile.open("tasks.dat",ios::out);
            
            if(!outfile)
            {
                cout<<endl;
                cout<<"writing data is error, please confirm database!!!"<<endl;
                return;
            }
            else
            {
                outfile<<tasks.size()<<endl;
                for(int i=0;i<tasks.size();i++)
                {
                    outfile<<tasks[i].name<<" "<<tasks[i].isCompleted<<endl;
                }
            }
            outfile.close();
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

        int choice=6;
        todolist.readfile();
        cin>>choice;

        switch(choice)
        {
            case 1:     //add task
                {
                string taskName;
                cout<<"Enter the task name:";
                cin.ignore();
                getline(cin,taskName);
                todolist.addTask(taskName);
                break;
                }
            case 2:     //mark as complete
                {
                int index;
                cout<<"Enter the task index to mark as complete:";
                cin>>index;
                todolist.markAsComplete(index);
                break;
                }
            case 3:     //remove task;
                {
                int index;
                cout<<"Enter the task index to remove:";
                cin>>index;
                todolist.removeTask(index);
                break;
                }
            case 4:     //display tasks
                {
                int temprtn;

                temprtn=todolist.TasksStatus();
                if(0==temprtn)
                {
                    cout<<"\n No Task, please add new task!\n";
                    break;
                }
                cout<<"\nYour Task:\n";
                todolist.displayTasks();
                break;
                }
            case 5:     //exit
               todolist.writefile();
                return 0;
            default:
                cout<<endl;
                cout<<"invalid choice. Please input number for your select again.\n"<<endl;
                //clear input buffer
                cin.clear();
                cin.ignore();
                break;
        }
    }

    return 0;
}

