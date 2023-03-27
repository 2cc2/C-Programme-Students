#ifndef LONGIN_H
#define LOGIN_H
#include"string.h"
#include<map>
#include<string.h>
#include"Gpa.h"
#include"StuManager.h"
#include"EnterInfo.h"
using namespace std;
struct StuN_K
{
    int id;
    char key[20];
};
class Login
{
    private:
        const char maUserN[20]="admin";//管理员账号
        char managerKey[20];//管理员密码
        map<int,EnterInfo>stu;//map容器存取学生信息
        char filename[20]="File.dat";//学生信息保存文件
        Manager v;//管理对象
        Gpa f;//GPA操作对象
        StuManager sMa;//学生管理
        Color c;
    public:
        Login();
        void stuSever(int i);//学生服务实现
        void managerSever();//管理员服务实现
        void add_stu_userName(int id1,int id2);//添加学生用户名
        bool studentLogin(int userName,char* key);//学生登录
        bool managerLogin(char* userName,char* key);//管理员登录
        bool modifyStuKey(int id,char* key);//修改学生密码
        bool ensureKey(char* a);//检查密码强度
        ~Login();
};
#endif