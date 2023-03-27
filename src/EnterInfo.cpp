#include"EnterInfo.h"
#include<iostream>
#include<iomanip>
using namespace std;
EnterInfo::EnterInfo()//初始学号为-1
{
    id=-1;
}
EnterInfo::~EnterInfo(){}
bool bool_int(char* n)//判断数字中是否含有字符
{
    bool b=true;
    for(int i=0;i<strlen(n);i++)
        {
            if(n[i]<'0'||n[i]>'9')
            b=false;
        }
    return b;
}
int convert_int(char* n)//char*转换为int
{
    int a,m,num;
        a=0;
        m=1;
       for(int i=strlen(n)-1;i>=0;i--)
        {
            num=n[i]-'0';
            a+=num*m;
            m*=10;
        }
    return a;
}
EnterInfo::EnterInfo(int id)//带参构造
{
    this->id=id;
    cout<<"姓名:";
    cin>>name;
    char age1[5]="a";
    while(!bool_int(age1))
    {
        cout<<"年龄:";
        cin>>age1;
    }
    age=convert_int(age1);
    cout<<"性别:";
    cin>>gender;
    cout<<"民族:";
    cin>>nation;
    cout<<"出生日期:";
    cin>>birthday;
    cout<<"籍贯:";
    cin>>nativePlace;
    cout<<"政治面貌:";
    cin>>politicalStatus;
    char sco[4];
    while(true)
    {   
        cout<<"入学成绩：";
        cin>>sco;
        if(bool_int(sco))
        {   
            strcpy(enterScore,sco);
            break;
        }
        else
        {
            c.RED();
            cout<<"请输入正确的分数"<<endl;
        }
   }
    cout<<"学生专业：";
    cin>>department;
    cout<<"请编辑学生的教育经历："<<endl;
    cout<<"——————————————小学——————————————————————"<<endl;
    set_experience(0);
    cout<<"————————————————初中————————————————————"<<endl;
    set_experience(1);
    cout<<"—————————————————高中—————————————————————"<<endl;
    set_experience(2);
    cout<<"——————————————————大学—————————————————————"<<endl;
    set_experience(3);
    c.GREEN();
    cout<<"-------------基本信息录入成功------------"<<endl;
    c.BLACK();
}
EnterInfo::EnterInfo(int id,char* name)//带参重载构造
{
    this->id=id;
    strcpy(this->name,name);
    char age1[5]="a";
    while(!bool_int(age1))
    {
        cout<<"年龄:";
        cin>>age1;
    }
    age=convert_int(age1);
    cout<<"性别:";
    cin>>gender;
    cout<<"民族:";
    cin>>nation;
    cout<<"出生日期:";
    cin>>birthday;
    cout<<"籍贯:";
    cin>>nativePlace;
    cout<<"政治面貌:";
    cin>>politicalStatus;
    char sco[4];
    while(true)
    {   
        cout<<"入学成绩：";
        cin>>sco;
        if(bool_int(sco))
        {   
            strcpy(enterScore,sco);
            break;
        }
        else
        {
            c.RED();
            cout<<"请输入正确的分数"<<endl;
            c.BLACK();
        }
   }
    cout<<"学生专业：";
    cin>>department;
}
void EnterInfo::set_name(char* name1)
   {
       strcpy(name,name1);
   }
char* EnterInfo::get_name()
    {
        return name;
    }
void EnterInfo::set_age(int age1)
    {
        age=age1;
    }
int EnterInfo::get_age()
    {
        return age;
    }
void EnterInfo::set_gender(char* gen)
    {
        strcpy(gender,gen);
    }
char* EnterInfo::get_gender()
    {
        return gender;
    }
void EnterInfo::set_nation(char* nat)
    {
        strcpy(nation,nat);
    }
char* EnterInfo::get_nation()
    {
        return nation;
    }
void EnterInfo::set_birthday(Date bir)
    {
        birthday=bir;
    }
Date EnterInfo::get_birthday()
    {
        return birthday;
    }
void EnterInfo::set_natPlace(char* natpl)
    {
        strcpy(nativePlace,natpl);
    }
char* EnterInfo::get_natPlace()
    {
        return nativePlace;
    }
void EnterInfo::set_plotStatus(char* polst)
    {
        strcpy(politicalStatus,polst);
    }
char* EnterInfo::get_polStatus()
    {
        return politicalStatus;
    }
void EnterInfo::set_entSco(char* sco)
    {
        strcpy(enterScore,sco);
    }
char* EnterInfo::get_entSco()
    {
        return enterScore;
    }
void EnterInfo::set_id(int n)
    {
        id=n;
    }
int EnterInfo::get_id()
    {
        return id;
    }
void EnterInfo::set_department(char* dep)
    {
        strcpy(department,dep);
    }
char* EnterInfo::get_department()
    {
        return department;
    }
void EnterInfo::set_major(char* m)
    {
        strcpy(major,m);
    }
char* EnterInfo::get_major()
    {
        return major;
    }
void EnterInfo::show_enterinfo()//展示基本信息
{
    cout<<"|"<<setw(9)<<get_id();
    cout<<"|"<<setw(8)<<get_name();
    cout<<"| "<<setw(4)<<get_age();
    cout<<" | "<<setw(4)<<get_gender();
    cout<<" |"<<setw(8)<<get_nation();
    cout<<"|"<<setw(8)<<get_birthday();
    cout<<"|"<<setw(16)<<get_natPlace();
    cout<<"|"<<setw(10)<<get_entSco();
    cout<<"|"<<setw(10)<<get_department();
    cout<<"|"<<endl;
}
void EnterInfo::set_experience(int i)//设置指定教育信息
{
    c.BLACK();
    cout<<"--------------------------------------------------"<<endl;
    cout<<"入学时间："<<endl;
    cin>>ex[i].start;
    cout<<"毕业时间："<<endl;
    cin>>ex[i].end;
    cout<<"学校名称："<<endl;
    cin>>ex[i].schoolName;
    cout<<"担任职务："<<endl;
    cin>>ex[i].stuPosition;
    cout<<"班主任姓名："<<endl;
    cin>>ex[i].headTeacher;
    cout<<"班主任联系电话："<<endl;
    char num[15];
    cin>>num;
    set_PhoneNum(num,i);
    cout<<"--------------------------------------------------"<<endl;  
}
void EnterInfo::set_PhoneNum(char* p,int i)//设置电话号
    {
        int l;
        char tele[15];
        while(true)
        {
            l=strlen(p);
            if(l==11)
            {
                strcpy(ex[i].PhoneNum,p);
                break;
            }       
            else
            {
                c.RED();
                cout<<"输入电话号码有误,应为11位数字。"<<endl;
                c.BLACK();
                cout<<"请重新输入班主任电话号："<<endl;
                cin>>tele;
                strcpy(p,tele);
            }
        }
    }
ostream& operator<<(ostream& out, EnterInfo& obj)//重载运算符
{
    for(int i=0;i<4;i++)
    {
        switch(i)
        {
            case 0:
            cout<<"——————————小学——————————"<<endl;
            break;
            case 1:
            cout<<"——————————初中——————————"<<endl;
            break;
            case 2:
            cout<<"——————————高中——————————"<<endl;
            break;
            case 3:
            cout<<"——————————大学——————————"<<endl;
            break;
        }
        cout<<"入学时间：";
        out<<obj.ex[i].start<<endl;
        out<<"毕业时间：";
        out<<obj.ex[i].end<<endl;
        out<<"学校名称：";
        out<<obj.ex[i].schoolName<<endl;
        out<<"担任职务：";
        out<<obj.ex[i].stuPosition<<endl;
        out<<"班主任姓名：";
        out<<obj.ex[i].headTeacher<<endl;
        cout<<"班主任联系电话：";
        out<<obj.ex[i].PhoneNum<<endl;
    }
    return out;
}
void EnterInfo::set_exp(EduEx* e)//设置单独的学生教育信息
{
    ex[0]=e[0];
    ex[1]=e[1];
    ex[2]=e[2];
    ex[3]=e[3];
}
EduEx* EnterInfo::get_exp()
{
    return ex;
}
void EnterInfo::show_exp(int i)//展示学生特定教育信息
{
    c.PURPLE();
    switch(i)
    {
        case 0:
        cout<<"小学————————————————————"<<endl;
        break;
        case 1:
        cout<<"初中——————————————————————————"<<endl;
        break;
        case 2:
        cout<<"高中——————————————————————————"<<endl;
        break;
        case 3:
        cout<<"大学——————————————————————————"<<endl;
        break;
    }
    c.BLUE();
    cout<<"入学时间：";
    cout<<ex[i].start<<endl;
    cout<<"毕业时间：";
    cout<<ex[i].end<<endl;
    cout<<"学校名称：";
    cout<<ex[i].schoolName<<endl;
    cout<<"担任职务：";
    cout<<ex[i].stuPosition<<endl;
    cout<<"班主任姓名：";
    cout<<ex[i].headTeacher<<endl;
    cout<<"班主任联系电话：";
    cout<<ex[i].PhoneNum<<endl;
    cout<<"————————————————————————————————————"<<endl;
    c.BLACK();
}
void EnterInfo::stay_info(EnterInfo& p)//保留基本信息
{
    this->id=p.get_id();
    strcpy(this->name,p.get_name());
    this->age=p.get_age();
    strcpy(this->gender,p.get_gender());
    this->birthday=p.get_birthday();
    strcpy(this->nation,p.get_nation());
    strcpy(this->nativePlace,p.get_natPlace());
    strcpy(this->enterScore,p.get_entSco());
    strcpy(this->department,p.get_department());
}