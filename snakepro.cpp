/********************Change History****************************************/
/*1.add game menu funciotn                            2024-9-22     JinNuo*/
/*2.add color for game                                2024-9-22     JinNuo*/
/*3.modfiy snake head and body                        2024-9-30     JinNuo*/
/*4.add HEROES COUNT                                  2024-10-01    JinNuo*/
/**************************************************************************/
#include <iostream>
#include <ncurses.h>    //ncurses library
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <fstream>

using namespace std;

//定义方向 限定作用域的枚举类，Direction与UP/DOWN/LEFT/RIGHT作用域相同，相当于等价定义 UP=0,DOWN=1,LEFT=2,RIGHT=3
enum class Direction {UP,DOWN,LEFT,RIGHT};

//定义获得分数的类
class Scoredef
{
    public:
        string name;
        int score;
        string date_time;
 
        Scoredef():name("test"),score(0),date_time("2000-1-1/00:00:00") {}
        ~Scoredef(){}
};

class SnakeGame
{
    public:
        //构造函数，初始化 width和height是通过参数初始化，score和gameover默认值初始化
        SnakeGame(int width,int height):width(width),height(height),score(0),gameover(false),menuover(false),gamelevel(500)
        {
            srand(time(nullptr));   //设置随机种子，nullptr:即空指针（null point）也可直接改为NULL或0
            readfile();
        }
        //析构函数，推出时关闭
        ~SnakeGame()
        {
            writefile();
            delwin(window);
            endwin();
        }
        //初始化窗口
        void initwindow()
        {
            initscr();  //初始化屏幕,默认窗口为stdscr
            keypad(stdscr,true);    //激活功能键和小键盘的输入,允许getch()函数获取功能键和小键盘
            noecho();   //关闭回显,或者叫禁止输入字符显示到现在屏幕上
            curs_set(false);    //隐藏光标
            getmaxyx(stdscr,max_y,max_x);   //获取窗口大小的函数,当前屏幕的行数(max_y)和列数(max_x)
            window=newwin(height,width,(max_y-height)/2,(max_x-width)/2);   //定义新窗口，参数（高，宽，窗口左上y坐标，窗口左上x坐标）,并且返回指向窗口的结构体指针
            box(window,0,0);    //绘制窗口边框，0,0是字符默认的行列起始位置
            refresh();
            wrefresh(window); 
 
           //将窗口背景设定为黑色
            //确认终端是否支持颜色显示
            if(false==has_colors())
            {
                mvprintw(height/2,(width-38)/2,"Your teminal does not support color!!!");
                getch();
                delwin(window);
                endwin();
           }
            start_color();  //开启颜色功能
            init_pair(1,COLOR_GREEN,COLOR_GREEN);     //初始化颜色对，背景为绿色
            init_pair(2,COLOR_RED,COLOR_GREEN);     //初始化为红字绿背,食物颜色
            init_pair(3,COLOR_BLACK,COLOR_GREEN);     //初始化为黑字绿背,Menu颜色
            init_pair(4,COLOR_BLUE,COLOR_GREEN);       //初始化蓝字绿背，snake身颜色
            init_pair(5,COLOR_YELLOW,COLOR_GREEN);     //初始化为黄字绿背,snake头颜色
            init_pair(6,COLOR_RED,COLOR_CYAN);          //初始化为红字青背，当前分数高亮显示
            wbkgd(window,COLOR_PAIR(1));    //设置窗口背景颜色

       }

       //初始化食物和snake位置
        void initfood()
        {
            generateFood();
            snake.clear(); //清除snake的原有坐标数据
            snake.push_back(make_pair(height/2,width/2));       //初始化贪吃蛇位置(窗口中心位置), make_pair直接生成pair对象
            drawSnake();
        }

        //游戏菜单
        void menu()
        {
            werase(window);
            wattron(window,COLOR_PAIR(3));  //开始打印颜色
            mvwaddstr(window,(height-5)/2,(width-40)/2,"Welcome to Play Game!!!");
            mvwaddstr(window,(height-3)/2,(width-40)/2,"Please selece game level:");
            mvwaddstr(window,(height-1)/2,(width-40)/2,"1. easy   2. Middle   3.High    4. exit");
            wattroff(window,COLOR_PAIR(3));  //开始打印颜色
            refresh();
            wrefresh(window);

            int ch=getch();
            gameover=false;

            switch(ch)
            {
                case '1':
                    gamelevel=500;
                    break;
                case '2':
                    gamelevel=260;
                    break;
                case '3':
                    gamelevel=100;
                    break;
                default:
                    menuover=true;
                    gameover=true;
                    break;
            }
            werase(window);     //清楚指定窗口中的内容
            refresh();  //将stdscr缓冲区中的数据显示在屏幕上
            wrefresh(window);
        }

        //运行游戏
        void run()
        {
            initwindow();
            while(!menuover)
            {
                menu();
                initfood();
                nodelay(stdscr,true);   //非阻塞模式,多线程并发输入，使程序不用一直在getch()等待用户输入


                //循环游戏
               while(!gameover)
               {
                    int ch=getch();
                    handleInput(ch);
                    moveSnake();
                    checkCollision();
                    std::this_thread::sleep_for(std::chrono::milliseconds(gamelevel));
              }
               showGameOver();
            }
       }

    private:
       int width,height;    //窗口的宽和高
       int score;
       bool gameover;
       bool menuover;
       int gamelevel;
       int max_x,max_y;
       WINDOW *window;  //定义新窗口
       vector<pair<int,int>> snake;     //定义snake的位置数组
       vector<Scoredef> scorelist;      //定义获取分数的结构;
       pair<int,int> food;  //定义食物的位置
       Direction direction=Direction::RIGHT;    //初始化：sanke往右移动

       //随机产生一个食物
       void generateFood()
       {
           chtype foodstr;  //定义带属性的字符串

            do
            {   //rand()
                food.first=rand()%(height-2)+1;     //获取食物的x位置，范围1~(height-2),也就是范围[m,n]是rand()%(n-m+1)+m
                food.second=rand()%(width-2)+1;     //获取食物的y位置, 范围1~(width-2)
            }
            while(isSnakeCell(food.first,food.second));
            //设置食物的颜色和状态

            foodstr='@'|COLOR_PAIR(2)|A_BOLD;
            mvwaddchstr(window,food.first,food.second,&foodstr);    //打印食物的位置，带颜色属性
            refresh();
            wrefresh(window); 
       }

       //描述保存在内存中的蛇
       void drawSnake()
       {
            //便利snake容器中每个节点，并且打印屏幕
           for(const auto& cell:snake)      //范围for循环用和引用传递(const auto& e:a) 通过e循环遍历容器a中的元素，而且不会修改a中的内容
           {
               mvwaddch(window,cell.first,cell.second,'#'|COLOR_PAIR(5));
           }
           refresh();
           wrefresh(window);
       }

       //蛇移动
       void moveSnake()
       {
            pair<int,int> head=snake.front();   //pair[first,second]是模板类，存储两个值的有序对,snake.front():snake vector中第一个元素赋值给head
            pair<int,int> newHead=head;
        
            switch(direction)
            {
                case Direction::UP:
                    newHead.first--;
                    break;
                case Direction::DOWN:
                    newHead.first++;
                    break;
                case Direction::LEFT:
                    newHead.second--;
                    break;
                case Direction::RIGHT:
                    newHead.second++;
                    break;
            }
            snake.insert(snake.begin(),newHead);    //在第一个元素插入newhead，其他元素依次后移。如果刚开始时，当前的snake变成两个节点
            mvwaddch(window,newHead.first,newHead.second,'#'|COLOR_PAIR(5));    //定义蛇头符号
            refresh();  //将stdscr中变动部分显示到屏幕上
            wrefresh(window);   //刷新window窗口
            mvwaddch(window,head.first,head.second,'*'|COLOR_PAIR(4));      //定义蛇身符号
            refresh();  //将stdscr中变动部分显示到屏幕上
            wrefresh(window);   //刷新window窗口
        
            if(newHead!=food)
            {
                mvwaddch(window,snake.back().first,snake.back().second,' '|COLOR_PAIR(1));
                snake.pop_back();   //删除snake容器的最后一个元素
            }
            else
            {
                score++;
                generateFood();
            }
       }

       //获取键盘输入的上下左右按键
       void handleInput(int ch)
       {
            switch(ch)
            {
                case KEY_UP:
                    if(Direction::DOWN!=direction)
                    {
                        direction=Direction::UP;
                    }
                    break;
                case KEY_DOWN:
                    if(Direction::UP!=direction)
                    {
                        direction=Direction::DOWN;
                    }
                    break;
                case KEY_LEFT:
                    if(Direction::RIGHT!=direction)
                    {
                        direction=Direction::LEFT;
                    }
                    break;
                case KEY_RIGHT:
                    if(Direction::LEFT!=direction)
                    {
                        direction=Direction::RIGHT;
                    }
                    break;
            }
       }

       void checkCollision()
       {
            pair<int,int> head=snake.front();

            //检查是否碰墙
            if(0==head.first||(height-1)==head.first||0==head.second||(width-1)==head.second)
            {
                gameover=true;
                return;
            }

            //检查是否撞到自己身体
            for(size_t i=1;i<snake.size();i++)  //size_t：表示无符号整数类型，通常用于内存分配，数组索引和对象大小
            {
                if(snake[i]==head)  //头与身相碰
                {
                    gameover=true;
                    return;
                }
            }
       }

       void showGameOver()
       {
            Scoredef scorelastest;
            char temp[10];
            int i=100;
            int j=0;

            //获取当前时间
            time_t now=time(NULL);  //获取当前时间，从1700-1-1开始以秒计数
            struct tm *local_tm=localtime(&now);    //转换为tm结构体,并且将当前时间转换为本地时间
            char buffer[20];
            strftime(buffer,20,"%y-%m-%d/%H:%M:%S",local_tm);   //使用strftime格式化时间


            nodelay(stdscr,false);   //打开阻塞模式,使程序在getch()等待用户输入
            echo();                        //打开回显
            werase(window);     //清楚window窗口内容
            refresh();  //将stdscr缓冲区中的数据显示在屏幕上
            wrefresh(window);
            wattron(window,COLOR_PAIR(3));
            string gameOverText="Game Over!";
            mvwprintw(window,height/4,(width-gameOverText.length())/2,"%s",gameOverText.c_str());     //在指定位置打印,c_srt()返回字符串首地址
            if(false==menuover)
            {
                 string scoreText="Score: "+to_string(score);    //to_string(xxx)将括号内数字转换称字符串
                 mvwprintw(window,height/4+1,(width-scoreText.length())/2,"%s",scoreText.c_str());
                 string inputText="Please input your name:";
                 mvwprintw(window,height/4+3,(width-inputText.length())/2,"%s",inputText.c_str());
                 refresh();  //将stdscr缓冲区中的数据显示在屏幕上
                 wrefresh(window);
                 system("sleep 1");
                 mvwgetstr(window,height/4+3,(width+inputText.length())/2,temp);
                 scorelastest.name=temp;
                 scorelastest.score=score;
                 scorelastest.date_time=buffer;
                 for(i=0;i<scorelist.size();i++)
                 {
                    if(scorelist[i].score<=scorelastest.score)
                    {
                        scorelist.emplace(scorelist.begin()+i,scorelastest);
                        break;
                    }
                 }
           }
           string headText="Ranking     Name           Score     Date/Time";
           mvwprintw(window,height/4+4,(width-headText.length())/4,"%s",headText.c_str());
           for(j=0;j<=5;j++)
           {
                string heroname_text=scorelist[j].name;
                string herodatetime_text=scorelist[j].date_time;
                mvwprintw(window,height/4+j+5,(width-headText.length())/4+3,"%d",j+1);
                mvwprintw(window,height/4+j+5,(width-headText.length())/4+12,"%s",heroname_text.c_str());
                mvwprintw(window,height/4+j+5,(width-headText.length())/4+12+15,"%d",scorelist[j].score);
                mvwprintw(window,height/4+j+5,(width-headText.length())/4+12+15+10,"%s",herodatetime_text.c_str());
           }
            wattroff(window,COLOR_PAIR(3));
            if (i<5)
            {
                wattron(window,COLOR_PAIR(6)); 
                string heroname_text=scorelist[i].name;
                string herodatetime_text=scorelist[i].date_time;
                mvwprintw(window,height/4+i+5,(width-headText.length())/4+3,"%d",i+1);
                mvwprintw(window,height/4+i+5,(width-headText.length())/4+12,"%s",heroname_text.c_str());
                mvwprintw(window,height/4+i+5,(width-headText.length())/4+12+15,"%d",scorelist[i].score);
                mvwprintw(window,height/4+i+5,(width-headText.length())/4+12+15+10,"%s",herodatetime_text.c_str());
                wattroff(window,COLOR_PAIR(6));
            }
            refresh();  //将stdscr缓冲区中的数据显示在屏幕上
            wrefresh(window);
            getch();    //读取一个字符，为了等待用户输入后退出游戏
            noecho();
       }

       bool isSnakeCell(int row,int col)
       {
            for(const auto& cell:snake)
            {
                if(cell.first==row && cell.second==col)
                {
                    return true;
                }
            }
            return false;
       }
       void readfile()
        {
            ifstream infile;    //open file by read mode
            int index=0;
            Scoredef scoretemp;
            infile.open("heroescount.dat",ios::in);
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
                    infile>>scoretemp.name>>scoretemp.score>>scoretemp.date_time;
                    scorelist.push_back(scoretemp);
                }
           }
            infile.close();
        }
        void writefile()
        {
            ofstream outfile;   //open file by write mode
            outfile.open("heroescount.dat",ios::out);     //after context of file is clear, write new context to file
            
            if(!outfile)
            {
                cout<<endl;
                cout<<"writing data is error, please confirm database!!!"<<endl;
                return;
            }
            else
            {
                outfile<<scorelist.size()<<endl;
                for(int i=0;i<scorelist.size();i++)
                {
                    outfile<<" "<<scorelist[i].name<<" "<<scorelist[i].score<<" "<<scorelist[i].date_time<<endl;
                }
            }
            outfile.close();
        }
};

int main()
{
    SnakeGame game(60,20);
    game.run();
    return 0;
}

