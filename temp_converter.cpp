#include <iostream>
using namespace std;

int main()
{
    int choice;
    double temperature;

    while(1)
    {
        cout<<"Welcome to Temperature Converter!"<<endl;
        cout<<"choose an option:"<<endl;
        cout<<"1. Convert Celsius to Fahrenheit"<<endl;
        cout<<"2. Convert Fahrenheit to Celsius"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice (1 or 2 or 3):"<<endl;

        if(!(cin>>choice)) {
            cerr<<"Error:Invaild input. Please enter a number (1 or 2)."<<endl;
            cin.clear();    //clear input error flag
            cin.ignore();    //ignore last char in buffer
        }

        if ((1==choice)||(2==choice))
        {
            cout<<"Enter your temperature value:";

            if(!(cin>>temperature))
            {
                cerr<<"Error:Invaild temperature value. Please enter a number."<<endl;
                cin.clear();    //clear input error flag
                cin.ignore();    //ignore last char in buffer
           }

            switch(choice)
            {
                case 1: //转换摄氏度到华氏度
                    cout<<"Temperature in Fahrenheit: "<<(temperature*9/5)+32<<endl;
                    break;
//                    return 0;
                case 2: //转换华氏度到摄氏度
                    cout<<"Temperature in Celsius: "<<(temperature-32)*5/9<<endl;
                    break;
//                    return 0;
            }
        }
        else if (3==choice)
        {
            cout<<"See you next!!!"<<endl;
            return 0;
        }
        else
        {
            cout<<"Invalid choice. Please enter 1 ro 2."<<endl;
        }
    }

    return 0;
}

