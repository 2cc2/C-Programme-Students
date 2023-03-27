#ifndef DATE_H
#define DATE_H
#include<iostream>
#include"Color.h"
using namespace std;
class Date
{
    private:
    int year,month,day;
    Color c;
    public:
    Date(){}
    Date(int year,int month,int day);//构造函数
    void  setDate(int y,int m,int d); //设置函数
    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}
    bool judgeInput(int year,int month,int day);//判断输入
    bool Y_N_leapYear(int y);// 判断是否为闰年
    int get_dayOfMonth(int y,int m);//获得不同年的月份的天数
    friend istream &operator >>(istream&in,Date &obj);//重载运算符
    friend ostream &operator <<(ostream& out,const Date &obj);
    void operator=(const Date &obj);
    ~Date();
};
#endif