#include<iostream>
#include<conio.h>
#include"LoginMenu.h"
#include"Manager.h"
using namespace std;
LoginMenu::LoginMenu(){}
LoginMenu::~LoginMenu(){}
void LoginMenu::showLogin()//显示登录选项
{
    system("color F0");
    system("title 这是宇宙无敌的学籍管理系统");
    cout<<"--------------------------------------------"<<endl;
    cout<<"------------欢迎使用学生管理系统------------"<<endl;
    cout<<"             1.学生端登录                   "<<endl;
    cout<<"             2.管理员登录                   "<<endl;
    cout<<"             3.重新选择登录方式             "<<endl;
    cout<<"             0.退出登录                     "<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"请选择您的登录方式:...                        "<<endl;
}
int LoginMenu::student_login()//学生登录
{
    int userName,i=0;
    char key[20],ch;
    cout<<"学生端登陆请输入："<<endl;
    Login student;
    bool b;
    while(true)
    {
        cout<<"账号："<<endl;
        cin>>userName;
        cout<<"密码："<<endl;
        while((ch=getch())!=13)
        {
            if(ch==8)
            {
                if(i>0)
                {
                    key[i--]='\0';
                    putch(8);
                    putch(' ');
                    putch(8);
                }
                else
                {
                    putch(7);
                }
            }
            else
            {
                c.GREEN();
                putch('*');
                key[i]=ch;
                i++;
            }
        }
        key[i]='\0';
        b=student.studentLogin(userName,key);
        if(b)
        {
            cout<<endl;
            c.GREEN();
            for(int i=0;i<=25;i++)
            {
                system("cls");
                cout<<"登录中";
                cout<<'['<<(i*4)<<"%]";
                for(int j=1;j<=i;j++)
                {
                    cout<<"■";
                }
                for(int j = i + 1; j <= 25; j ++) 
                {
                    cout<<"□";
                }
                }
            system("cls");
            cout<<"\n\n";
            cout<<"\n登录成功";
            cout<<"[100%]";
            cout<<"欢迎使用!!>>";
            Sleep(500);
            system("cls");
            student.stuSever(userName);
        }
        else
        {
            c.RED();
            cout<<"账号或密码错误!"<<endl;
            c.BLACK();
            cout<<"是否要更换登录方式(y或n):"<<endl;
            char choice;
            c.GREEN();
            cin>>choice;
            if(choice=='Y'||choice=='y')
                return 3;
                else
                return 1;
        }
    }
    return 0;
}
int LoginMenu::manager_login()//管理员登录
{
    char userName[20],key[20],ch;
    int i=0;
    cout<<"管理员登陆请输入："<<endl;
    Login ma;
    bool b;
    while(true)
    {
        cout<<"账号："<<endl;
        cin>>userName;
        cout<<"密码："<<endl;
        while((ch=getch())!=13)
        {
            if(ch==8)
            {
                if(i>0)
                {
                    key[i--]='\0';
                    putch(8);
                    putch(' ');
                    putch(8);
                }
                else
                {
                    putch(7);
                }
            }
            else
            {
                c.GREEN();
                putch('*');
                key[i]=ch;
                i++;
            }
        }
        key[i]='\0';
        b=ma.managerLogin(userName,key);
        if(b)
        {
            c.BLACK();
            cout<<"\n登录中...";
            for(int i=0;i<=100;i++)
            {
                cout.width(3);
                c.GREEN();
                cout<<i<<"%";
                Sleep(50);
                cout<<"\b\b\b\b";
            }
            cout<<"\n\n";
            cout<<"\n登录成功"<<endl;
            cout<<"欢迎使用!!>>";
            Sleep(500);
            system("cls");
            ma.managerSever();//链接管理员菜单
        }
        else
        {
            c.RED();
            cout<<"\n登录失败,请检查账号和密码"<<endl;
            c.BLACK();
            cout<<"是否要更换登录方式(y或n):"<<endl;
            char choice;
            c.GREEN();
            cin>>choice;
            if(choice=='Y'||choice=='y')
                return 3;
            else
                return 2;
        }
    }   
    return 0;
}
void LoginMenu::modifyStuKey()//修改学生密码
{
    c.BLACK();
    int id;
    char skey[20];
    cout<<"请输入账号："<<endl;
    cin>>id;
    cout<<"请输入原密码："<<endl;
    cin>>skey;
    Login ma;
    bool b ;
    b=ma.modifyStuKey(id,skey);
    if(b)
    {
        c.GREEN();
        cout<<"您已成功修改密码"<<endl;
    }
    else
    {
        c.RED();
        cout<<"修改失败！"<<endl;
    }
}