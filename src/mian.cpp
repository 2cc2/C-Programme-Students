#include<iostream>
#include"LoginMenu.h"
#include"Color.h"
#include<map>
#include<string.h>
using namespace std;
using namespace std;
int main()
{
    Color c;
    system("color F0");
    system("DATE /t");
    system("TIME /t");
    LoginMenu LM;
    LM.showLogin();
    int choice;
    cin>>choice;
    while(true)
    {
        if(choice==1)
        {
            c.BLACK();
            choice=LM.student_login();
        }
        else if(choice==2)
        {
            c.BLACK();
            choice=LM.manager_login();
        }
        else if(choice==3)
        {
            c.BLACK();
            cout<<"������ѡ���¼��ʽ��ѡ���˳���¼"<<endl;
            cin>>choice;            
        }
        else if(choice==0)
        {
            c.RED();
            cout<<"�˳���¼"<<endl;
            Sleep(1000);
            exit(0);
        }
        else
        {
            c.RED();
            cout<<"�������ѡ������,������ѡ��"<<endl;
            c.GREEN();
            cin>>choice; 
        }
    }
    return 0;
}