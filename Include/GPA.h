#ifndef GPA_H
#define GPA_H
#include"EnterInfo.h"
class Gpa
{
private:
    int id;
    char name1[20];
    float GPA;
    char filename1[20]="GPA.dat";
    Color c;
public:
    Gpa();
    ~Gpa();
    void setGPA(map<int,EnterInfo>&m);//设置学生绩点
    void show_by_GPA();//按绩点排序显示
    void modify_GPA();//修改学生绩点
    void delGpa();//删除学生绩点
    void del_Gpa(int i);//实现删除
    int get_id();
    float get_GPA();
    char* get_name1();
};
#endif