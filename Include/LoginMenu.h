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
        void showLogin();//��ʾ��¼�˵�
        int student_login();//ѧ����¼
        int manager_login();//�����¼
        void modifyStuKey();//�޸�ѧ������
        ~LoginMenu();
};
#endif