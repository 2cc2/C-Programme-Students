#include<iostream>
#include"Login.h"
#include<fstream>
using namespace std;
Login::Login()//初始化管理员密码
{
    char key[20]="happyNUAA70th";
    strcpy(managerKey,key);
}
Login::~Login(){}
void Login::add_stu_userName(int id1,int id2)//实现学生账户分配函数
{
    fstream loginFile("login.dat",ios::app|ios::out|ios::binary);
    if(loginFile.fail())
    {
        c.RED();
        cout<<"打开文件失败"<<endl;
    }
    c.GREEN();
    cout<<"打开文件成功！"<<endl;
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
bool Login::studentLogin(int userName,char* key)//学生登录
{
    
    bool b=false;
    fstream file("login.dat",ios::in|ios::binary);
    if(!file)
    {
        c.RED();
        cout<<"打开文件失败"<<endl;
    }
    StuN_K stu;
    while(!file.eof())//循环遍历查找后输出
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
bool Login::managerLogin(char* userName,char* key)//管理员登录
{
    bool b=false;
    if(strcmp(userName,maUserN)==0)
    {
        if(strcmp(key,managerKey)==0)
            b=true;
    }
    return b;
}
bool Login::modifyStuKey(int id,char* key)//学生账户修改密码实现
{
    bool b=false;
    char newkey[20];
   fstream file("login.dat",ios::in|ios::out|ios::binary);
    if(!file)
    {
        c.RED();
        cout<<"打开文件失败"<<endl;
        exit(0);
    }
    c.GREEN();
    cout<<"打开文件成功"<<endl;
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
        cout<<"账号输入错误"<<endl;
        return b;
    }
    for(int i=3;i;i--)
    if(strcmp(key,stu.key)!=0)
    {
        c.RED();
        cout<<"密码错误，您共有三次机会"<<endl;
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
        cout<<"请输入您要修改的密码"<<endl;
        cin>>newkey;
        b2=ensureKey(newkey);
    }
    strcpy(stu.key,newkey);
    file.seekp(-sizeof(stu),ios::cur);
    file.write((char*)&stu,sizeof(stu));
    file.close();
    return b;
}
bool B(char* a,int n)//判断是否有大写字母
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
bool S(char* a,int n)//判断是否有小写字母
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
bool N(char* a,int n)//判断是否有数字
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
bool Login::ensureKey(char* a)//密码强度检验函数
{
    bool b=false;
    int n;
	n=strlen(a);
	if(n<6)
    {
        c.RED();
	    cout<<"输入口令少于6位"<<endl;
    }
    else if(!B(a,n))
	{
		cout<<"口令中至少需包含一个大写字母"<<endl;
	} 
	else if(!S(a,n))
	{
		cout<<"口令中至少需包含一个小写字母。"<<endl;
	}
	else if(!N(a,n))
	{
		cout<<"口令中至少需包含一个数字。"<<endl;
	}
    else
    {
        c.GREEN();
        cout<<"密码强度:强"<<endl;
        b=true;
    }
    c.BLACK();//初始颜色回调
    return b;
}
void Login::stuSever(int i)//学生服务接口函数
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
            cout<<"谢谢使用";
            Sleep(1000);
            exit(0);
            break;
        default:
            c.RED();
            cout<<"输入选项不符"<<endl;
            Sleep(1000);
            system("cls");
            break;
        }
    }
}
void Login::managerSever()//管理员服务接口函数
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
                cout<<"谢谢使用！！";
                Sleep(1000);
                exit(0);
                break;
            default:
                c.RED();
                cout<<"请输入正确的操作选项"<<endl;
                Sleep(1000);
                system("cls");
                break;
        }
    }
}