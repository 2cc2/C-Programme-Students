#include<iostream>
using namespace std;
#include"Date.h"
Date::Date(int year,int month,int day)//Date�๹�캯��
{
    year=-1;
    month=-1;
    day=-1;
}
bool Date::judgeInput(int year,int month,int day)//������ȷ�Լ���
{
    if(year<=0 || month<=0||month>12 || day<=0||day>get_dayOfMonth(year,month))
        return false;
    else
        return true;
}
bool Date::Y_N_leapYear(int y)//�ж��Ƿ�Ϊ����
{
    if(y%4==0&&y%100!=0||y%400==0)
    return true;
    else
    return false;
}
int Date::get_dayOfMonth(int y,int m)//�õ�ָ������µ����ֵ
{
    int days[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                    {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    return days[Y_N_leapYear(y)][m];
}
void Date::setDate(int year,int month,int day)//��������
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
            cout<<"���������������������룡"<<endl;
            c.BLACK();
            cout<<"�꣺";
            cin>>year;
            cout<<"�£�";
            cin>>month;
            cout<<"�գ�";
            cin>>day;
        }
    }
}
istream& operator >>(istream& in,Date &obj)//����>>
{
    int year1,month1,day1;
    cout<<endl;
    cout<<"�꣺";
    in>>year1;
    cout<<"��:";
    in>>month1;
    cout<<"��:";
    in>>day1;
    obj.setDate(year1,month1,day1);
    return in;
}
ostream &operator <<(ostream& out,const Date &obj)//����<<
{
    cout<<obj.year<<"��"<<obj.month<<"��"<<obj.day<<"��";
    return out;
}
void Date::operator=(const Date &obj)//����=
{
        year=obj.year;
        month=obj.month;
        day=obj.day;
 }
 Date::~Date(){}