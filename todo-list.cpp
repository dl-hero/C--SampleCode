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
        int number;
        string finishday;
        string taskhead;

        Task(const string& name,const string& finishday,const string& taskhead):name(name),isCompleted(false),number(0),
            finishday(finishday),taskhead(taskhead){}
};

class TodoList
{
    private:
        vector<Task> tasks;

    public:
        void addTask(const string& taskName)
        {
            string day;
            string head;
           
            //please input finish day
            cout<<"\n pleae input the finish day of task(ex.yy-mm-dd):";
//            cin.ignore();
            getline(cin,day);

            //please input task head
            cout<<"\n pleae input the head of task:";
//            cin.ignore();
            getline(cin,head);

            Task temptask(taskName,day,head);
            temptask.number=tasks.size()+1;
//            tasks[tasks.size()-1].number=tasks.size();
            tasks.push_back(temptask);

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
            string result;
            if(index >=0 && index<tasks.size())
            {
                cout<<"Remove task:"<<tasks[index].name<<endl;
                cout<<"Please confirm to remove task, if it is right to Y, if it is not right to N!"<<endl;
                cin>>result;
                if ("Y"==result || "y"==result)
                {
                    cout<<"removing task"<<endl;
                    system("sleep 1");          //wait for 1s 
                    tasks.erase(tasks.begin()+index);
                }
                for(int i=index;i<=tasks.size();i++)
                {
                    tasks[i].number--;
                }
           }
            else
            {
                cout<<"invalid task index and please press any key to countine "<<endl;
                cin.ignore();
                cin.get();
            }
        }
        void displayTasks() const
        {
            for (size_t i=0;i<tasks.size();++i)
            {
                cout<<tasks[i].number<<". "<<"["<<(tasks[i].isCompleted?"x":" ")<<"]"<<tasks[i].name
                    <<" "<<tasks[i].finishday<<" "<<tasks[i].taskhead<<endl;
            }

            //for hold screen
            cout<<"Return to please any key...";
            cin.ignore();
            cin.get();  //wati user to input keyboard
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
            Task temptask("test","test","test");
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
                    infile>>temptask.name>>temptask.isCompleted>>temptask.number>>temptask.finishday>>temptask.taskhead;
                    tasks.push_back(temptask);
                }
           }
            infile.close();
        }
        void writefile()
        {
            ofstream outfile;   //open file by write mode
            outfile.open("tasks.dat",ios::out);     //after context of file is clear, write new context to file
            
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
                    outfile<<tasks[i].name<<" "<<tasks[i].isCompleted<<" "<<tasks[i].number<<" " 
                        <<tasks[i].finishday<<" "<<tasks[i].taskhead<<endl;
                }
            }
            outfile.close();
        }
};

int main()
{
    TodoList todolist;

    todolist.readfile();
    while(true)
    {
        system("clear"); 

        cout<<"\n--- To-Do List Manager ---\n";
        cout<<"1. Add Task\n";
        cout<<"2. Mark as Comlete\n";
        cout<<"3. Remove Task\n";
        cout<<"4. Display Tasks\n";
        cout<<"5. Save Tasks\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice:";

        int choice=6;
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
                todolist.markAsComplete(index-1);
                break;
                }
            case 3:     //remove task;
                {
                int index;
                cout<<"Enter the task index to remove:";
                cin>>index;
                todolist.removeTask(index-1);
                break;
                }
            case 4:     //display tasks
                {
                int temprtn;

                temprtn=todolist.TasksStatus();
                if(0==temprtn)
                {
                    cout<<"\n No Task, please add new task!\n";
                    //hold the screen, and wait user input
//                    cin.ignore();
//                    cin.get();
                    system("sleep 2");
                    break;
                }
                system("clear");
                cout<<"\nYour Task:\n";
                todolist.displayTasks();
                break;
                }
            case 5:
                cout<<"Task is saved!!!"<<endl;
                system("sleep 2");
                todolist.writefile();
                break;
            case 6:     //exit
                todolist.writefile();
                cout<<"Task is saved!!!"<<endl;
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

