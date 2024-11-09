#include <iostream>
#include <sstream>  //字符串流处理的头文件
#include <string>
#include <map>  //提供map容器的头文件
#include <iomanip>  //for cout/cin的格式设定，比如setw等
using namespace std;

int main()
{
    //定义一个字符串常量
    const string mystr="how to study cpp very good";
    //定义一个map类型的容器变量mymap，map容器是STL的标准容器，map<key-value pairs>,其中每个key值都是唯一的
    map<string,int> mymap;

    //定义字符串流ss，并且初始化为mystr常量的内容;
    stringstream ss(mystr);
    //定义一个word字符串变量
    string word;
    string texttemp;

    cout<<mystr<<endl;
    //每次只能将空前前面的字符串输入到右侧变量中
    ss>>texttemp;   //input "how"
    cout<<texttemp<<endl;
    ss>>texttemp;   //input "to"
    cout<<texttemp<<endl;


    //字符流ss中的字符输入到word字符变量,当遇到空格是停止
    int i=1;
    while(ss>>word)
    {
       //将ss字符流中的字符串输入到mymap容器中
        //map容器插入键值方法，mymap.insert(key1,key2) or mymap[key1]=key2
        cout<<word<<setw(6)<<i<<endl;
         mymap[word]=i++;
//        mymap.insert(pair<string,int>(word,i));
//        i++;
    }

    //iterator是迭代器，按照一定顺序对一个或者多个容器中的元素进行遍历的一种机制
    //定义一个此map容器的迭代器接口it,it实际就是一个容器的指针
    map<string,int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        //map容器中每个元素的first和secod变量
        cout<<it->first<<"->"<<it->second<<endl;
    }

    return 0;
}
