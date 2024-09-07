#include <iostream>
#include <ncurses.h>
#include <curses.h>     //linux下图形界面库头文件

//try to do ncurses library
int main()
{
    initscr();  //ncurses 界面的初始化函数
    printw("This is curses window\n");  //在ncurses下进行printf
    getch();    //等待用户输入,如果没有这句话，程序就推出了，看不到运行结果，也就看不到上面的语句
    endwin();   //程序推出，调用改函数来恢复shell终端的显示，如果没有这句话，shell终端是乱码
    return 0;
}
