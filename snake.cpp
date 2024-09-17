#include <iostream>
#include <ncurses.h>    //ncurses library
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace std;

//定义方向
enum class Direction {UP,DOWN,LEFT,RIGHT};

class SnakeGame
{
    public:
        //构造函数，初始化
        SnakeGame(int width,int height):width(width),height(height),score(0),gameover(false)
        {
            srand(time(nullptr));
            initscr();  //初始化屏幕
            keypad(stdscr,true);    //启用键盘输入
            noecho();   //关闭回显
            nodelay(stdscr,true);   //非阻塞模式
            curs_set(0);    //隐藏光标
            getmaxyx(stdscr,max_y,max_x);
            window=newwin(height,width,(max_y-height)/2,(max_x-width)/2);
            box(window,0,0);    //绘制窗口边框
            refresh();
            wrefresh(window);
            generateFood();
            snake.push_back(make_pair(height/2,width/2));       //初始化贪吃蛇位置
            drawSnake();
        }
        //析构函数，推出时关闭
        ~SnakeGame()
        {
            delwin(window);
            endwin();
        }
        //运行游戏
        void run()
        {
           //循环游戏
           while(!gameover)
           {
                int ch=getch();
                handleInput(ch);
                moveSnake();
                checkCollision();
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
           }
           showGameOver();
        }

    private:
       int width,height;
       int score;
       bool gameover;
       int max_x,max_y;
       WINDOW *window;
       vector<pair<int,int>> snake;
       pair<int,int> food;
       Direction direction=Direction::RIGHT;

       //随机产生一个食物
       void generateFood()
       {
            do
            {
                food.first=rand()%(height-2)+1;
                food.second=rand()%(width-2)+1;
            }
            while(isSnakeCell(food.first,food.second));
            mvwaddch(window,food.first,food.second,'@');
            refresh();
            wrefresh(window); 
       }

       //描述保存在内存中的蛇
       void drawSnake()
       {
           for(const auto& cell:snake)
           {
                mvwaddch(window,cell.first,cell.second,'#');
           }
           refresh();
           wrefresh(window);
       }

       //蛇移动
       void moveSnake()
       {
            pair<int,int> head=snake.front();
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
            snake.insert(snake.begin(),newHead);
            mvwaddch(window,newHead.first,newHead.second,'#');
            refresh();  //将stdscr中变动部分显示到屏幕上
            wrefresh(window);   //刷新window窗口
        
            if(newHead!=food)
            {
                mvwaddch(window,snake.back().first,snake.back().second,' ');
                snake.pop_back();
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
            for(size_t i=1;i<snake.size();i++)
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
            clear();        //清屏幕
            string gameOverText="Game Over!";
//            mvprintw(max_y/2,(max_x-gameOverText.length())/2,gameOverText.c_str());     //在指定位置打印,c_srt()返回字符串首地址
            string scoreText="Score: "+to_string(score);    //to_string(xxx)将括号内数字转换称字符串
//            mvprintw(max_y/2+1,(max_x-scoreText.length())/2,scoreText.c_str());
            refresh();  //将stdscr缓冲区中的数据显示在屏幕上
            getch();    //读取一个字符

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
};

int main()
{
    SnakeGame game(40,20);
    game.run();
    return 0;
}

