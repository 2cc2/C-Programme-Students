#include<iostream>
#include<conio.h>
#include"LoginMenu.h"
#include"Manager.h"
using namespace std;
LoginMenu::LoginMenu(){}
LoginMenu::~LoginMenu(){}
void LoginMenu::showLogin()//��ʾ��¼ѡ��
{
    system("color F0");
    system("title ���������޵е�ѧ������ϵͳ");
    cout<<"--------------------------------------------"<<endl;
    cout<<"------------��ӭʹ��ѧ������ϵͳ------------"<<endl;
    cout<<"             1.ѧ���˵�¼                   "<<endl;
    cout<<"             2.����Ա��¼                   "<<endl;
    cout<<"             3.����ѡ���¼��ʽ             "<<endl;
    cout<<"             0.�˳���¼                     "<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"��ѡ�����ĵ�¼��ʽ:...                        "<<endl;
}
int LoginMenu::student_login()//ѧ����¼
{
    int userName,i=0;
    char key[20],ch;
    cout<<"ѧ���˵�½�����룺"<<endl;
    Login student;
    bool b;
    while(true)
    {
        cout<<"�˺ţ�"<<endl;
        cin>>userName;
        cout<<"���룺"<<endl;
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
                cout<<"��¼��";
                cout<<'['<<(i*4)<<"%]";
                for(int j=1;j<=i;j++)
                {
                    cout<<"��";
                }
                for(int j = i + 1; j <= 25; j ++) 
                {
                    cout<<"��";
                }
                }
            system("cls");
            cout<<"\n\n";
            cout<<"\n��¼�ɹ�";
            cout<<"[100%]";
            cout<<"��ӭʹ��!!>>";
            Sleep(500);
            system("cls");
            student.stuSever(userName);
        }
        else
        {
            c.RED();
            cout<<"�˺Ż��������!"<<endl;
            c.BLACK();
            cout<<"�Ƿ�Ҫ������¼��ʽ(y��n):"<<endl;
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
int LoginMenu::manager_login()//����Ա��¼
{
    char userName[20],key[20],ch;
    int i=0;
    cout<<"����Ա��½�����룺"<<endl;
    Login ma;
    bool b;
    while(true)
    {
        cout<<"�˺ţ�"<<endl;
        cin>>userName;
        cout<<"���룺"<<endl;
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
            cout<<"\n��¼��...";
            for(int i=0;i<=100;i++)
            {
                cout.width(3);
                c.GREEN();
                cout<<i<<"%";
                Sleep(50);
                cout<<"\b\b\b\b";
            }
            cout<<"\n\n";
            cout<<"\n��¼�ɹ�"<<endl;
            cout<<"��ӭʹ��!!>>";
            Sleep(500);
            system("cls");
            ma.managerSever();//���ӹ���Ա�˵�
        }
        else
        {
            c.RED();
            cout<<"\n��¼ʧ��,�����˺ź�����"<<endl;
            c.BLACK();
            cout<<"�Ƿ�Ҫ������¼��ʽ(y��n):"<<endl;
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
void LoginMenu::modifyStuKey()//�޸�ѧ������
{
    c.BLACK();
    int id;
    char skey[20];
    cout<<"�������˺ţ�"<<endl;
    cin>>id;
    cout<<"������ԭ���룺"<<endl;
    cin>>skey;
    Login ma;
    bool b ;
    b=ma.modifyStuKey(id,skey);
    if(b)
    {
        c.GREEN();
        cout<<"���ѳɹ��޸�����"<<endl;
    }
    else
    {
        c.RED();
        cout<<"�޸�ʧ�ܣ�"<<endl;
    }
}