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
    Date(int year,int month,int day);//���캯��
    void  setDate(int y,int m,int d); //���ú���
    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}
    bool judgeInput(int year,int month,int day);//�ж�����
    bool Y_N_leapYear(int y);// �ж��Ƿ�Ϊ����
    int get_dayOfMonth(int y,int m);//��ò�ͬ����·ݵ�����
    friend istream &operator >>(istream&in,Date &obj);//���������
    friend ostream &operator <<(ostream& out,const Date &obj);
    void operator=(const Date &obj);
    ~Date();
};
#endif