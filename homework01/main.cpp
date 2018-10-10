//详细讲解  https://njuferret.github.io/2018/09/03/cpp_macro_usage/
//题目见文件夹
#include <qDebug>
//定义 i
#define i 0x12345678
//字符串化,嵌套,避免不能展开
#define STR(s)  _STR(s)
#define _STR(s)   #s
//分段8位截取 ,高到低依次为HHI LHI HLO LLO
#define HHI(i32)  ((i32)>>24)
#define LHI(i32)  (((i32)>>16)&0xFF)
#define HLO(i32)  (((i32)&0xFFFF)>>8)
#define LLO(i32)  ((i32)&0xFF)
//取大值
#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )
//取小值
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )


int main(int argc, char *argv[])
{
    int i_new;
    QList<qint8> values;
    qDebug()<<"原始值:"<<STR(i)<<"=="<<i;
    //向values内添加值,见assistant
    values.append(HHI(i));
    values.append(LHI(i));
    values.append(HLO(i));
    values.append(LLO(i));
    //输出截取结果
    qDebug("0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d",
           values.at(0),values.at(0),values.at(1),values.at(1),
           values.at(2),values.at(2),values.at(3),values.at(3));
    //高低8位比较大小
    qDebug("最高8位和次高8位最大值：0x%x(%d)", MAX(values.at(0),values.at(1)),MAX(values.at(0),values.at(1)));
    qDebug("次低8位和最低8位最小值：0x%x(%d)", MIN(values.at(3),values.at(2)),MIN(values.at(2),values.at(3)));
    //重新组合
    i_new=(values.at(2)<<24)+(values.at(0)<<16)+(values.at(3)<<8)+values.at(1);
    qDebug("重新组合后数值：0x%x(%d)",i_new,i_new);
    //std::sort降序排序
    //https://blog.csdn.net/zhangpiu/article/details/50564064
    //https://zh.cppreference.com/w/cpp/algorithm/sort
    qDebug()<<"排序前："<<values;
    std::sort(values.begin(),values.end(),std::greater<qint8>());
    qDebug()<<"排序后："<<values;
}
