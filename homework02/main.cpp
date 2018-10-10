#include <QCoreApplication>
#include<QDebug>

/* when I want to generate the pretty same paragraph into the following function,
QtCreator kept warning: make a template delcaration before '&'. I guss it comes from QList--a complic type*/
//int searchprint(QList & list, QList & tlist)
//{
//    int j;
//    for(int i=0;i<list.size();i++)
//    {
//        for(j=0;j<list.size();j++)
//            if(list.at(i)==tlist.at(1).at(j)) break;
//        qDebug()<<tlist.at(0).at(j)<<'\t'<<tlist.at(1).at(j)<<'\t'
//                  <<tlist.at(2).at(j)<<'\t'<<tlist.at(3).at(j)<<'\t';
//    }
//    return 0;
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int j;
    //use QList to store students' score
    QList<QString> namelist,studentnumber,course1score,course2score;
    studentnumber<< "1403130209" << "1403140101" << "1403140102" << "1403140103" ;
    namelist<<"鲁智深"<<"林冲"<<"宋江"<<"武松";
    course1score<<"80"<<"82"<<"76"<<"88";
    course2score<<"72"<<"76"<<"85"<<"80";
    // generate all QLists to totallist
    QList< QList<QString> > totallist;
    totallist<<studentnumber<<namelist<<course1score<<course2score;
    //打印原始成绩单
    qDebug("原始成绩单:");
    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";
    for(int i=0;i<studentnumber.size();i++)
        qDebug()<<studentnumber.at(i)<<"\t"<<namelist.at(i)<<"\t"
               <<course1score.at(i)<<"\t"<<course2score.at(i);
    //基于姓名排序
    //首先姓名list排序,然后查找打印
    std::sort(namelist.begin(),namelist.end(),std::greater<QString>());
    qDebug("\n姓名排序成绩单:");
    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";
    for(int i=0;i<namelist.size();i++)
    {
        for(j=0;j<namelist.size();j++)
            if(namelist.at(i)==totallist.at(1).at(j)) break;
        qDebug()<<totallist.at(0).at(j)<<'\t'<<totallist.at(1).at(j)<<'\t'
                  <<totallist.at(2).at(j)<<'\t'<<totallist.at(3).at(j)<<'\t';
    }
    //基于课程1成绩排序
    std::sort(course1score.begin(),course1score.end(),std::greater<QString>());
    qDebug("\n课程1成绩排序成绩单:");
    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";
    for(int i=0;i<course1score.size();i++)
    {
        for(j=0;j<course1score.size();j++)
            if(course1score.at(i)==totallist.at(2).at(j)) break;
        qDebug()<<totallist.at(0).at(j)<<'\t'<<totallist.at(1).at(j)<<'\t'
                  <<totallist.at(2).at(j)<<'\t'<<totallist.at(3).at(j)<<'\t';
    }
    //基于课程2成绩排序
    std::sort(course2score.begin(),course2score.end(),std::greater<QString>());
    qDebug("\n课程2成绩排序成绩单:");
    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";
    for(int i=0;i<course2score.size();i++)
    {
        for(j=0;j<course2score.size();j++)
            if(course2score.at(i)==totallist.at(3).at(j)) break;
        qDebug()<<totallist.at(0).at(j)<<'\t'<<totallist.at(1).at(j)<<'\t'
                  <<totallist.at(2).at(j)<<'\t'<<totallist.at(3).at(j)<<'\t';
    }

    return a.exec();
}


