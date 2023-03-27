#include<iostream>
#include"Login.h"
#include<fstream>
using namespace std;
Login::Login()//��ʼ������Ա����
{
    char key[20]="happyNUAA70th";
    strcpy(managerKey,key);
}
Login::~Login(){}
void Login::add_stu_userName(int id1,int id2)//ʵ��ѧ���˻����亯��
{
    fstream loginFile("login.dat",ios::app|ios::out|ios::binary);
    if(loginFile.fail())
    {
        c.RED();
        cout<<"���ļ�ʧ��"<<endl;
    }
    c.GREEN();
    cout<<"���ļ��ɹ���"<<endl;
    StuN_K stu;
    char k[20]="123456";
    for(;id1!=(id2+1);id1++)
    {
        stu.id=id1;
        strcpy(stu.key,k);
        loginFile.write((char*)&stu,sizeof(stu));
    }
    loginFile.close();
    managerSever();
    c.BLACK();
}
bool Login::studentLogin(int userName,char* key)//ѧ����¼
{
    
    bool b=false;
    fstream file("login.dat",ios::in|ios::binary);
    if(!file)
    {
        c.RED();
        cout<<"���ļ�ʧ��"<<endl;
    }
    StuN_K stu;
    while(!file.eof())//ѭ���������Һ����
    {
        file.read((char*)&stu,sizeof(stu));
        if(file.fail())
        break;
        if(stu.id==userName&&strcmp(stu.key,key)==0)
        {  
            b=true;
            break;
        }
    }
    file.close();
    return b;
}
bool Login::managerLogin(char* userName,char* key)//����Ա��¼
{
    bool b=false;
    if(strcmp(userName,maUserN)==0)
    {
        if(strcmp(key,managerKey)==0)
            b=true;
    }
    return b;
}
bool Login::modifyStuKey(int id,char* key)//ѧ���˻��޸�����ʵ��
{
    bool b=false;
    char newkey[20];
   fstream file("login.dat",ios::in|ios::out|ios::binary);
    if(!file)
    {
        c.RED();
        cout<<"���ļ�ʧ��"<<endl;
        exit(0);
    }
    c.GREEN();
    cout<<"���ļ��ɹ�"<<endl;
    StuN_K stu;
    int f=0;
     while(!file.eof())
    {
        if(file.fail())
        break;
        file.read((char*)&stu,sizeof(stu));
        if(stu.id==id)
        {
            f=1;
            break;
        }
    }
    if(f!=1)
    {
        c.RED();
        cout<<"�˺��������"<<endl;
        return b;
    }
    for(int i=3;i;i--)
    if(strcmp(key,stu.key)!=0)
    {
        c.RED();
        cout<<"����������������λ���"<<endl;
        cin>>key;
    }
    else
    {
        b=true;
        break;
    }
    bool b2=false;
    while(!b2)
    {
        c.BLACK();
        cout<<"��������Ҫ�޸ĵ�����"<<endl;
        cin>>newkey;
        b2=ensureKey(newkey);
    }
    strcpy(stu.key,newkey);
    file.seekp(-sizeof(stu),ios::cur);
    file.write((char*)&stu,sizeof(stu));
    file.close();
    return b;
}
bool B(char* a,int n)//�ж��Ƿ��д�д��ĸ
{
	bool b=false;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			b=true;
			break;
		}
	}
	return b;
}
bool S(char* a,int n)//�ж��Ƿ���Сд��ĸ
{
	bool b=false;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			b=true;
			break;
		}
	}
	return b;
}
bool N(char* a,int n)//�ж��Ƿ�������
{
	bool b=false;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b=true;
			break;
		}
	}
	return b;
}
bool Login::ensureKey(char* a)//����ǿ�ȼ��麯��
{
    bool b=false;
    int n;
	n=strlen(a);
	if(n<6)
    {
        c.RED();
	    cout<<"�����������6λ"<<endl;
    }
    else if(!B(a,n))
	{
		cout<<"���������������һ����д��ĸ"<<endl;
	} 
	else if(!S(a,n))
	{
		cout<<"���������������һ��Сд��ĸ��"<<endl;
	}
	else if(!N(a,n))
	{
		cout<<"���������������һ�����֡�"<<endl;
	}
    else
    {
        c.GREEN();
        cout<<"����ǿ��:ǿ"<<endl;
        b=true;
    }
    c.BLACK();//��ʼ��ɫ�ص�
    return b;
}
void Login::stuSever(int i)//ѧ������ӿں���
{
    int choice;
    while(true)
    {
        c.BLACK();
        sMa.showStuMenu();
        cin>>choice;
        switch (choice)
        {
        case 1:sMa.addSelf(i,stu);
            break;
        case 2:sMa.showSelf(i,stu);
            break;
        case 3:sMa.findGPA(i);
            break;
        case 4:v.modifyStuKey();
            break;
        case 0:
            c.GREEN();
            cout<<"ллʹ��";
            Sleep(1000);
            exit(0);
            break;
        default:
            c.RED();
            cout<<"����ѡ���"<<endl;
            Sleep(1000);
            system("cls");
            break;
        }
    }
}
void Login::managerSever()//����Ա����ӿں���
{
    int choice;
    while(true)
    {
        c.BLACK();
        v.showMenu();
        cin>>choice;
        switch (choice)
        {
            case 1:v.addStuInfo(stu);
                break;
            case 2:v.readInfo(stu,filename);
                f.setGPA(stu);
                break;
            case 3:f.modify_GPA();
                break;
            case 4:v.run_Modify(stu);
                break;
            case 5:v.findStuInfo(stu);
                break;
            case 6:v.delStuInfo(stu);
                break;
            case 7:f.delGpa();
                break;
            case 8:v.showStuInfo(stu);
                break;
            case 9:v.distribute_userName();
                break;                
            case 10:v.show_by_entersco(stu);
                break;
            case 11:f.show_by_GPA();
                break;
            case 0:
                c.GREEN();
                cout<<"ллʹ�ã���";
                Sleep(1000);
                exit(0);
                break;
            default:
                c.RED();
                cout<<"��������ȷ�Ĳ���ѡ��"<<endl;
                Sleep(1000);
                system("cls");
                break;
        }
    }
}