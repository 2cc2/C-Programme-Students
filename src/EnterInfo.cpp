#include"EnterInfo.h"
#include<iostream>
#include<iomanip>
using namespace std;
EnterInfo::EnterInfo()//��ʼѧ��Ϊ-1
{
    id=-1;
}
EnterInfo::~EnterInfo(){}
bool bool_int(char* n)//�ж��������Ƿ����ַ�
{
    bool b=true;
    for(int i=0;i<strlen(n);i++)
        {
            if(n[i]<'0'||n[i]>'9')
            b=false;
        }
    return b;
}
int convert_int(char* n)//char*ת��Ϊint
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
EnterInfo::EnterInfo(int id)//���ι���
{
    this->id=id;
    cout<<"����:";
    cin>>name;
    char age1[5]="a";
    while(!bool_int(age1))
    {
        cout<<"����:";
        cin>>age1;
    }
    age=convert_int(age1);
    cout<<"�Ա�:";
    cin>>gender;
    cout<<"����:";
    cin>>nation;
    cout<<"��������:";
    cin>>birthday;
    cout<<"����:";
    cin>>nativePlace;
    cout<<"������ò:";
    cin>>politicalStatus;
    char sco[4];
    while(true)
    {   
        cout<<"��ѧ�ɼ���";
        cin>>sco;
        if(bool_int(sco))
        {   
            strcpy(enterScore,sco);
            break;
        }
        else
        {
            c.RED();
            cout<<"��������ȷ�ķ���"<<endl;
        }
   }
    cout<<"ѧ��רҵ��";
    cin>>department;
    cout<<"��༭ѧ���Ľ���������"<<endl;
    cout<<"����������������������������Сѧ��������������������������������������������"<<endl;
    set_experience(0);
    cout<<"�����������������������������������С���������������������������������������"<<endl;
    set_experience(1);
    cout<<"�������������������������������������С�����������������������������������������"<<endl;
    set_experience(2);
    cout<<"��������������������������������������ѧ������������������������������������������"<<endl;
    set_experience(3);
    c.GREEN();
    cout<<"-------------������Ϣ¼��ɹ�------------"<<endl;
    c.BLACK();
}
EnterInfo::EnterInfo(int id,char* name)//�������ع���
{
    this->id=id;
    strcpy(this->name,name);
    char age1[5]="a";
    while(!bool_int(age1))
    {
        cout<<"����:";
        cin>>age1;
    }
    age=convert_int(age1);
    cout<<"�Ա�:";
    cin>>gender;
    cout<<"����:";
    cin>>nation;
    cout<<"��������:";
    cin>>birthday;
    cout<<"����:";
    cin>>nativePlace;
    cout<<"������ò:";
    cin>>politicalStatus;
    char sco[4];
    while(true)
    {   
        cout<<"��ѧ�ɼ���";
        cin>>sco;
        if(bool_int(sco))
        {   
            strcpy(enterScore,sco);
            break;
        }
        else
        {
            c.RED();
            cout<<"��������ȷ�ķ���"<<endl;
            c.BLACK();
        }
   }
    cout<<"ѧ��רҵ��";
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
void EnterInfo::show_enterinfo()//չʾ������Ϣ
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
void EnterInfo::set_experience(int i)//����ָ��������Ϣ
{
    c.BLACK();
    cout<<"--------------------------------------------------"<<endl;
    cout<<"��ѧʱ�䣺"<<endl;
    cin>>ex[i].start;
    cout<<"��ҵʱ�䣺"<<endl;
    cin>>ex[i].end;
    cout<<"ѧУ���ƣ�"<<endl;
    cin>>ex[i].schoolName;
    cout<<"����ְ��"<<endl;
    cin>>ex[i].stuPosition;
    cout<<"������������"<<endl;
    cin>>ex[i].headTeacher;
    cout<<"��������ϵ�绰��"<<endl;
    char num[15];
    cin>>num;
    set_PhoneNum(num,i);
    cout<<"--------------------------------------------------"<<endl;  
}
void EnterInfo::set_PhoneNum(char* p,int i)//���õ绰��
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
                cout<<"����绰��������,ӦΪ11λ���֡�"<<endl;
                c.BLACK();
                cout<<"��������������ε绰�ţ�"<<endl;
                cin>>tele;
                strcpy(p,tele);
            }
        }
    }
ostream& operator<<(ostream& out, EnterInfo& obj)//���������
{
    for(int i=0;i<4;i++)
    {
        switch(i)
        {
            case 0:
            cout<<"��������������������Сѧ��������������������"<<endl;
            break;
            case 1:
            cout<<"�����������������������С�������������������"<<endl;
            break;
            case 2:
            cout<<"�����������������������С�������������������"<<endl;
            break;
            case 3:
            cout<<"����������������������ѧ��������������������"<<endl;
            break;
        }
        cout<<"��ѧʱ�䣺";
        out<<obj.ex[i].start<<endl;
        out<<"��ҵʱ�䣺";
        out<<obj.ex[i].end<<endl;
        out<<"ѧУ���ƣ�";
        out<<obj.ex[i].schoolName<<endl;
        out<<"����ְ��";
        out<<obj.ex[i].stuPosition<<endl;
        out<<"������������";
        out<<obj.ex[i].headTeacher<<endl;
        cout<<"��������ϵ�绰��";
        out<<obj.ex[i].PhoneNum<<endl;
    }
    return out;
}
void EnterInfo::set_exp(EduEx* e)//���õ�����ѧ��������Ϣ
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
void EnterInfo::show_exp(int i)//չʾѧ���ض�������Ϣ
{
    c.PURPLE();
    switch(i)
    {
        case 0:
        cout<<"Сѧ����������������������������������������"<<endl;
        break;
        case 1:
        cout<<"���С���������������������������������������������������"<<endl;
        break;
        case 2:
        cout<<"���С���������������������������������������������������"<<endl;
        break;
        case 3:
        cout<<"��ѧ����������������������������������������������������"<<endl;
        break;
    }
    c.BLUE();
    cout<<"��ѧʱ�䣺";
    cout<<ex[i].start<<endl;
    cout<<"��ҵʱ�䣺";
    cout<<ex[i].end<<endl;
    cout<<"ѧУ���ƣ�";
    cout<<ex[i].schoolName<<endl;
    cout<<"����ְ��";
    cout<<ex[i].stuPosition<<endl;
    cout<<"������������";
    cout<<ex[i].headTeacher<<endl;
    cout<<"��������ϵ�绰��";
    cout<<ex[i].PhoneNum<<endl;
    cout<<"������������������������������������������������������������������������"<<endl;
    c.BLACK();
}
void EnterInfo::stay_info(EnterInfo& p)//����������Ϣ
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