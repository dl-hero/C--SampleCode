
//定义贪吃蛇节点结构体
struct Snake
{
    int hang;   //行
    int lie;    //列
    struct Snake *next; //下一个节点

};

struct Snake *head=NULL;    //定义蛇尾（链表头）
struct Snake *tail=NULL;    //定义蛇头（链表尾）
