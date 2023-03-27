#ifndef STUMANAGER_H
#define STUMANAGER_H
#include"Manager.h"
#include"GPA.h"
class StuManager:public Manager 
{
private:
public:
    StuManager();
    void showStuMenu();//显示学生菜单
    void addSelf(int i,map<int,EnterInfo>&stu1);//添加自己的信息
    void showSelf(int i,map<int,EnterInfo>&stu1);//查看自己的信息
    void findGPA(int i);//查看学生绩点信息
    ~StuManager();
};
#endif