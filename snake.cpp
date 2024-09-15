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
        SnakeGame(int width,int height):width(width),height(height),score(0),gamevoer(false)
        {
            srand(time(nullptr));
            initscr();  //初始化屏幕
            keypad(stdsrc,true);    //启用键盘输入
            noecho();   //关闭回显
            nodelay(stdsrc,true);   //非阻塞模式
            curs_set(0);    //隐藏光标
            getmaxyx(stdsrc,max_y,max_x);
            window=newwin(height,width,(max_y-height)/2,(max_x-width)/2);
            box(window,0,0);    //绘制窗口边框
            refresh();
            wrefresh(window);
            generateFood();
            snake.push_back(make_pair(height/2,width/2));       //初始化贪吃蛇位置
            drawSnake();
        }

        ~SnakeGame()
        {
            delwin(window);
            endwin();
        }

        void run()
        {
           //循环游戏
           while(!gameover)
           {
                int ch=getch();
                handleInput(ch);
                moveSnake();
                checkCollision();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
           }
           showGameOver();
        }

    private:
        
}


