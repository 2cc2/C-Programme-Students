#ifndef LOGINMENU_H 
#define LOGINMENU_H
#include<map>
#include<iostream>
#include"string.h"
#include"Login.h"
using namespace std;
class LoginMenu
{
    private:
    Color c;
    public:
        LoginMenu();
        void showLogin();//显示登录菜单
        int student_login();//学生登录
        int manager_login();//管理登录
        void modifyStuKey();//修改学生密码
        ~LoginMenu();
};
#endif