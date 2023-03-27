#ifndef MANAGER_H
#define MANAGER_H
#include<fstream>
#include"EnterInfo.h"
#include<map>
using namespace std;
class Manager
{
    protected:
    char filename[20]="File.dat";
    Color c;
    public:
        Manager();
        void showMenu();//显示菜单
        void run_Modify(map<int,EnterInfo>&stu);
        void modifyStuKey();//修改学生密码
        void addStuInfo(map<int,EnterInfo>&m);//创建学生信息
        void delStuInfo(map<int,EnterInfo>&m);//删除学生信息
        void modifyEx(map<int,EnterInfo>&stu1);//修改学生经历
        void modifyEnterInfo(map<int,EnterInfo>&stu1);//修改学生基本信息
        void modifyStuInfo(map<int,EnterInfo>&m);//修改学生信息
        void findStuInfo(map<int,EnterInfo>&m);//查找学生信息
        void showStuInfo(map<int ,EnterInfo>&m);//展示学生信息
        void show_by_entersco(map<int ,EnterInfo>&m);//按学生高考分数排序显示
        void distribute_userName();//分配学生账号
        int bool_userName(map<int,EnterInfo>&stu1);//判断输入正确性
        void saveStuInfo(map<int,EnterInfo>&m,const char* filename);//保存信息
        void readInfo(map<int,EnterInfo>&m,const char* filename);//读取信息
        ~Manager();
};
#endif