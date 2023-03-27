#include<iostream>
using namespace std;
#include"Date.h"
Date::Date(int year,int month,int day)//Date类构造函数
{
    year=-1;
    month=-1;
    day=-1;
}
bool Date::judgeInput(int year,int month,int day)//输入正确性检验
{
    if(year<=0 || month<=0||month>12 || day<=0||day>get_dayOfMonth(year,month))
        return false;
    else
        return true;
}
bool Date::Y_N_leapYear(int y)//判断是否为润年
{
    if(y%4==0&&y%100!=0||y%400==0)
    return true;
    else
    return false;
}
int Date::get_dayOfMonth(int y,int m)//得到指定年的月的最大值
{
    int days[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                    {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    return days[Y_N_leapYear(y)][m];
}
void Date::setDate(int year,int month,int day)//设置日期
{
        while(true)
    {
        if(judgeInput(year,month,day))
        {
            this->year=year;
            this->month=month;
            this->day=day;
            break;
        }
        else
        {
            c.RED();
            cout<<"输入日期有误，请重新输入！"<<endl;
            c.BLACK();
            cout<<"年：";
            cin>>year;
            cout<<"月：";
            cin>>month;
            cout<<"日：";
            cin>>day;
        }
    }
}
istream& operator >>(istream& in,Date &obj)//重载>>
{
    int year1,month1,day1;
    cout<<endl;
    cout<<"年：";
    in>>year1;
    cout<<"月:";
    in>>month1;
    cout<<"日:";
    in>>day1;
    obj.setDate(year1,month1,day1);
    return in;
}
ostream &operator <<(ostream& out,const Date &obj)//重载<<
{
    cout<<obj.year<<"年"<<obj.month<<"月"<<obj.day<<"日";
    return out;
}
void Date::operator=(const Date &obj)//重载=
{
        year=obj.year;
        month=obj.month;
        day=obj.day;
 }
 Date::~Date(){}