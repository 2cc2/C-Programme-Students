#include"Manager.h"
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include"LoginMenu.h"
using namespace std;
bool read(map<int,EnterInfo>&m,const char* filename);
Manager::Manager(){}
Manager::~Manager(){}
void Manager::showMenu()//��ʾ����Ա�˵�
{
    cout<<"��ӭʹ��ѧ��ѧ������ϵͳ��"<<endl;
    cout<<"��ִ�в�����"<<endl;
    cout<<"1�����ѧ����Ϣ"<<endl;
    cout<<"2������ѧ������"<<endl;
    cout<<"3���޸�ѧ������"<<endl;
    cout<<"4���޸�ѧ����Ϣ"<<endl;
    cout<<"5������ѧ����Ϣ"<<endl;
    cout<<"6��ɾ��ѧ����Ϣ"<<endl;
    cout<<"7������ɾ��ѧ��������Ϣ"<<endl;
    cout<<"8����ʾ����ѧ������Ϣ"<<endl;
    cout<<"9������ѧ���˺�"<<endl;
    cout<<"10�����߿��ɼ�������ʾ"<<endl;
    cout<<"11����GPA������ʾ"<<endl;
    cout<<"0���˳�ϵͳ"<<endl;
    cout<<"\n";
    cout<<"��������Ҫ���еĲ���";
}
void Manager::modifyStuKey()//�޸�ѧ��������ú���
{
    LoginMenu lm;
    lm.modifyStuKey();
}
bool mycmp(pair<int,EnterInfo> &stu,pair<int,EnterInfo> &stu1)//�Զ�������
{
    if(strcmp(stu.second.get_entSco(),stu1.second.get_entSco())>0)
        return true;
    return false;
}
void Manager::show_by_entersco(map<int ,EnterInfo>&m)//���򰴸߿������������
{
    c.PURPLE();
    cout<<"---------��ǰ��ʾ(�߿���������)-----------"<<endl;
    c.BLACK();
    if(m.empty())
    {
        readInfo(m,filename);
    }
    vector<pair<int,EnterInfo>> stu(m.begin(),m.end());
    sort(stu.begin(),stu.end(),mycmp);
    c.BLACK();
    cout<<"-----------------------------------------------------------------------------------------------------------\n";
    cout<<"|  ����  |    id   |"<<"  ����  |"<<" ���� |"<<" �Ա� |"<<" ����   |"<<"    ��������    |"<<"     ����       |"<<" ��ѧ�ɼ� |"<<"   רҵ   |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n";
    for(int i=0;i<stu.size();i++)
    {
        cout<<"-----------------------------------------------------------------------------------------------------------\n";
        cout<<"|   "<<i+1<<"   |";
        stu[i].second.show_enterinfo();
        cout<<"-----------------------------------------------------------------------------------------------------------\n";

    }
    c.GREEN();
    cout<<"-------��ʾ���-------"<<endl;
    c.BLACK();
    system("pause");
    system("cls");
}
void Manager::showStuInfo(map<int,EnterInfo>&stu1)//չʾѧ��������Ϣ
{
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    c.PURPLE();
    cout<<"----- ѧ��������Ϣ-------"<<endl;
    c.BLACK();
    cout<<"---------------------------------------------------------------------------------------------------\n";
    cout<<"|    id   |"<<"  ����  |"<<" ���� |"<<" �Ա� |"<<" ����   |"<<"    ��������    |"<<"     ����       |"<<" ��ѧ�ɼ� |"<<"   רҵ   |"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------\n";
    map<int,EnterInfo>::iterator it;
    for(it=stu1.begin();it!=stu1.end();it++)
    {
        cout<<"---------------------------------------------------------------------------------------------------\n";
        it->second.show_enterinfo();
        cout<<"---------------------------------------------------------------------------------------------------\n";
    }
    c.GREEN();
    cout<<"����Ϊȫ��ѧ����Ϣ"<<endl;
    system("pause");
    system("cls");
}
bool bool_id(char *id,map<int,EnterInfo>&stu1)//ѧ����ȷ�Լ���
{
    bool b=false;
    int l,id2;
    l=strlen(id);
    if(l!=9)
        {    
            cout<<"����ѧ��ӦΪ��λ"<<endl;
            return b;
        }
    for(int i=0;i<9;i++)
    {
        if(id[i]>'9'||id[i]<'0')
            {
                cout<<"ѧ���в�Ӧ����ĸ"<<endl;
                return b;
            }
    }
    convert_int(id);
    if(stu1.find(id2)!=stu1.end())
    {
       cout<<"ѧ�������ظ�"<<endl;
        return b;
    }
    return true;
}
int Manager::bool_userName(map<int,EnterInfo>&stu)//ѧ��id����
{   
    char id[15],ch;
    cin>>id;
    if(convert_int(id)==0)
    return 0;
     while(!bool_id(id,stu))
    {
        c.RED();
        cout<<"��˶Ժ������룬лл��"<<endl;
        c.BLACK();
        cout<<"�Ƿ�Ҫ��������ѧ��(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            cout<<"-----�������------"<<endl;
            return 0;
        }
        cout<<"������ѧ��ѧ��(0���˳�):"<<endl;
        cin>>id;
    }
    int id2;
    id2=convert_int(id);
    return id2;
}
void Manager::addStuInfo(map<int,EnterInfo>&stu1)//���ѧ����Ϣ
{
    c.RED();
    bool b;
    b=read(stu1,filename);
    if(!b)
    cout<<"��ʼ�ļ�Ϊ��,��Ҫ¼����Ϣ"<<endl;
    c.PURPLE();
    cout<<"------���ѧ����Ϣ------"<<endl;
    c.BLACK();
    int id1;
    char ch;
    while(true)
    {
        cout<<"������Ҫ��ӵ�ѧ��ѧ��(����0���˳�):"<<endl;
        while(true)
        {
            id1=bool_userName(stu1);
            if(id1==0)
            {
                system("pause");
                system("cls");
                return;
            }
            map<int,EnterInfo>::iterator it;
            it=stu1.find(id1);
            if(it!=stu1.end()&&!b)
            {
                c.RED();
                cout<<"����ѧ���ظ�"<<endl;
                cout<<"��������"<<endl;
                c.BLACK();
            }
            else
            break;
        }
        EnterInfo stu(id1);
        stu1.insert(make_pair(stu.get_id(),stu));
        c.BLACK();
        cout<<"�Ƿ�Ҫ�������һ��ѧ��(y/n):"<<endl;
        cin>>ch;
        if(ch=='n'||ch=='N')
        {
            c.GREEN();
            cout<<"-----¼�����----"<<endl;
            break; 
        }
    }
    c.BLACK();
    saveStuInfo(stu1,filename);
    system("pause");
    system("cls");
}
void Manager::findStuInfo(map<int,EnterInfo>&stu1)//����ѧ��
{
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    c.PURPLE();
    cout<<"------��ѯѧ����Ϣ--------"<<endl;
    c.BLACK();
    int id2,f=0;
    EnterInfo stu;
        cout<<"��������Ҫ��ѯ��ѧ��ѧ��(����0���˳�):"<<endl;
        id2=bool_userName(stu1);
        if(id2==0)
        {
            system("pause");
            system("cls");
            return;
        }
        map<int,EnterInfo>::iterator it;
          for(it=stu1.begin();it!=stu1.end();it++)
        {
         if(it->second.get_id()==id2)
         {
            stu=it->second;
            cout<<"---------------------------------------------------------------------------------------------------\n";
            cout<<"|    id   |"<<"  ����  |"<<"���� |"<<"�Ա�|"<<"   ����   |"<<"  ��������  |"<<"        ����       |"<<"   ��ѧ�ɼ�   |"<<"  רҵ  |"<<endl;
            cout<<"---------------------------------------------------------------------------------------------------\n";
            it->second.show_enterinfo();      
            cout<<"---------------------------------------------------------------------------------------------------\n";
            cout<<it->second;
            f=1;
         }
        }
         if(f==0)
        {
            c.RED();
            cout<<"���޴���"<<endl;
        }
    c.BLACK();
    system("pause");
    system("cls");
}
void Manager::delStuInfo(map<int,EnterInfo>&stu1)//ɾ��ѧ��
{
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    c.PURPLE();
    cout<<"---------ɾ������---------"<<endl;
    c.BLACK();
    int id;
    char ch;
    readInfo(stu1,filename);
    map<int,EnterInfo>::iterator it;
    while(true)
    {    
        c.BLACK();
        cout<<"��������Ҫɾ����ѧ����id(����0���˳�):"<<endl;
        id=bool_userName(stu1);
        if(id==0)
        {
            system("pause");
            system("cls");
            return;
        }
        it=stu1.find(id);
        if(it!=stu1.end())
        {
            stu1.erase(it);
            c.GREEN();
            cout<<"ɾ���ɹ�"<<endl;
            saveStuInfo(stu1,filename);
            c.BLACK();
            cout<<"�Ƿ�ͬ��ɾ��ѧ��������Ϣ(y/n):"<<endl;
            cin>>ch;
            if(ch=='n'||ch=='N')
            {
                cout<<"ѧ��������Ϣ������������Ҫɾ���ɵ�����ɾ��"<<endl;
            }
            else if(ch=='Y'||ch=='y')
            {
                Gpa p;
                p.del_Gpa(id);
            }
        }
        else
        {
            c.RED();
            cout<<"���޴���"<<endl;
        }
        c.BLACK();
        cout<<"��Ҫɾ��ѧ����(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"--------ɾ����������---------"<<endl;
            c.BLACK();
            break;
        }
    }
    system("pause");
    system("cls");
}
void Manager::run_Modify(map<int,EnterInfo>&stu)//�޸�ʵ�ֺ���
{
    c.PURPLE();
    cout<<"���������������޸�ѧ����Ϣ����������������"<<endl;
    if(stu.empty())
    {
        readInfo(stu,filename);
    }
    int choice;
    c.BLACK();
    while(true)
    {
        cout<<"��ѡ����Ҫ�޸ĵ����ݣ�"<<endl;
        cout<<"1.ѧ��������Ϣ"<<endl;
        cout<<"2.ѧ��������Ϣ"<<endl;
        cout<<"3.�޸�ȫ��ѧ����Ϣ"<<endl;
        cout<<"0.�����޸�"<<endl;
        cin>>choice;
        if(choice==1)
        {
            modifyEnterInfo(stu);
        }
        else if(choice==2)
        {
            modifyEx(stu);
        }
        else if(choice==3)
        {
            modifyStuInfo(stu);
        }
        else if(choice==0)
        {
            cout<<"��ȴ��˳�";
            Sleep(1000);
            system("cls");
            return;
        }
        else
        c.RED();
        cout<<"����ѡ�����"<<endl;
        char ch;
        c.BLACK();
        cout<<"�Ƿ�����޸�������Ϣ(y/n):"<<endl;
        cin>>ch;
        if(ch=='n'||ch=='N')
        {
            c.GREEN();
            cout<<"-----�����޸�-----"<<endl;
            break;
        }
    }
    system("pause");
    system("cls");
}
void Manager::modifyStuInfo(map<int,EnterInfo>&stu1)//�޸�ѧ������
{
    c.PURPLE();
    cout<<"------�޸�ѧ��ȫ����Ϣ--------"<<endl;
    c.BLACK();
    int idx,id;
    char ch,name[20];
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    while(true)
    {
        cout<<"������Ҫ�޸ĵ�ѧ��id(����0���˳�):"<<endl;
        idx=bool_userName(stu1);
        if(idx==0)
        {
            system("pause");
            system("cls");
            return;
        }
        cout<<"������Ҫ�޸ĵ���Ϣ��"<<endl;
        cout<<"�������޸ĺ��id:"<<endl;
        id=bool_userName(stu1);
        EnterInfo stu(id);
        map<int,EnterInfo>::iterator it;
        it=stu1.find(idx);
        if(it!=stu1.end())
        {
            it->second=stu;
            c.GREEN();
            cout<<"�޸ĳɹ�"<<endl;
        }
        else
        {
            c.RED();
            cout<<"���޴���"<<endl;
        }
        c.BLACK();
        cout<<"�Ƿ�Ҫ�����޸�(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"-----�޸Ľ���------"<<endl;
            c.BLACK();
            break;
        }
    }
    saveStuInfo(stu1,filename);
}
void Manager::modifyEnterInfo(map<int,EnterInfo>&stu1)//�޸�ѧ��������Ϣ
{
    c.PURPLE();
    cout<<"------�޸�ѧ��������Ϣ--------"<<endl;
    c.BLACK();
    int idx,id;
    char ch,name[20];
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    while(true)
    {
        cout<<"������Ҫ�޸ĵ�ѧ��id(����0���˳�):"<<endl;
        idx=bool_userName(stu1);
        if(idx==0)
            {
                system("pause");
                system("cls");
                return;
            }
        cout<<"������Ҫ�޸ĵ���Ϣ��"<<endl;
        cout<<"�������޸ĺ��id:"<<endl;
        id=bool_userName(stu1);
        cout<<"�������޸ĵ�ѧ��������"<<endl;
        cin>>name;
        EnterInfo stu(id,name);
        map<int,EnterInfo>::iterator it;
        it=stu1.find(idx);
        if(it!=stu1.end())
        {
            stu.set_exp(it->second.get_exp());
            it->second=stu;
            c.GREEN();
            cout<<"�޸ĳɹ�"<<endl;
        }
        else
        {
            c.RED();
            cout<<"���޴���"<<endl;
        }
        c.BLACK();
        cout<<"�Ƿ�Ҫ�����޸�(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"-----�޸Ľ���------"<<endl;
            c.BLACK();
            break;
        }
    }
    saveStuInfo(stu1,filename);
}
void Manager::modifyEx(map<int,EnterInfo>&stu1)//�޸Ľ�����Ϣ
{
    c.PURPLE();
    cout<<"------�޸�ѧ��������Ϣ--------"<<endl;
    c.BLACK();
    int idx,choice;
    char ch;
    EnterInfo stu;
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    float gpa;
    while(true)
    {
        cout<<"������Ҫ�޸ĵ�ѧ��id(����0���˳�)"<<endl;
        idx=bool_userName(stu1);
        if(idx==0)
            {
                system("pause");
                system("cls");
                return;
            }
        map<int,EnterInfo>::iterator it;
        it=stu1.find(idx);
        while(true)
        {
        if(it!=stu1.end())
        {
            cout<<"��ѡ����Ҫ�޸ĵ����ݣ�"<<endl;
            cout<<"1.����Сѧѧϰ������Ϣ\n";
            cout<<"2.��������ѧϰ������Ϣ\n";
            cout<<"3.��������ѧϰ������Ϣ\n";
            cout<<"4.������ѧѧϰ������Ϣ\n";
            cin>>choice;
            c.PURPLE();
            switch(choice)
                {
                    case 1:
                    cout<<"��Ҫ�޸ĵ��Ǹ���Сѧ����Ϣ��"<<endl;
                    break;
                    case 2:
                    cout<<"��Ҫ�޸ĵ��Ǹ������е���Ϣ��"<<endl;
                    break;
                    case 3:
                    cout<<"��Ҫ�޸ĵ��Ǹ������е���Ϣ��"<<endl;
                    break;
                    case 4:
                    cout<<"��Ҫ�޸ĵ��Ǹ�����ѧ����Ϣ��"<<endl;
                    break;
                    default:
                    cout<<"����ѡ������"<<endl;
                    continue;
                }
            c.BLACK();
            cout<<"ԭ����ϢΪ��"<<endl;
            EduEx* e;
            stu.set_exp(it->second.get_exp());//����exp
            stu.show_exp(choice-1);//��ʾԭ����Ϣ
            stu.stay_info(it->second);//����ԭ�л�����Ϣ
            stu.set_experience(choice-1);
            it->second=stu;
            saveStuInfo(stu1,filename);
            c.GREEN();
            cout<<"�޸����"<<endl;
         }
        else
         {
             c.RED();
             cout<<"���޴���"<<endl;
         }
         c.BLACK();
         cout<<"�Ƿ�Ҫ�����޸�(y/n):"<<endl;
         cin>>ch;
         if(ch=='N'||ch=='n')
         {
            c.GREEN();
            cout<<"-----�޸Ľ���------"<<endl;
            break;
         }
        }
        c.BLACK();
        cout<<"�Ƿ�Ҫ�����޸�����ѧ��(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"-----�޸Ľ���------"<<endl;
            break;
        }
    }
}
bool save(map<int,EnterInfo>&m,const char* filename)//�жϱ��溯��
{
    bool b=true;
    fstream savef(filename,ios::out|ios::binary);
    if(savef.fail())
    {
        cout<<"�򿪱����ļ�ʧ��"<<endl;
        b=false;
        exit(0); 
    }
    cout<<"���ļ��ɹ���"<<endl;
    EnterInfo stu;
    map<int,EnterInfo>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        stu=it->second;
        savef.write((char*)&stu,sizeof(stu));
    }
    savef.close();
    return b;
}
void Manager::saveStuInfo(map<int,EnterInfo>&m1,const char* filename)//���溯��
{
    if(m1.begin()==m1.end())
    {
        c.RED();
        cout<<"��û���κ�ѧ����Ϣ���޷�����"<<endl;
    }
    else
    {
        bool b=save(m1,filename);
        if(b)
        {
            c.GREEN();
            cout<<"����ɹ�"<<endl;
        }
        else
        {
            c.RED();
            cout<<"����ʧ��"<<endl;
        }
    }
    c.BLACK();
}
bool read(map<int,EnterInfo>&m,const char* filename)//�ж϶�ȡ����
{
    bool b=true;
    m.clear();
    fstream readf(filename,ios::in|ios::binary);
    if(readf.fail())
    {
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        b=false;
    }
    EnterInfo stu;
      while(!readf.eof())
    {
        if(readf.fail())
        break;
        readf.read((char*)&stu,sizeof(stu));
        m.insert(make_pair(stu.get_id(),stu));
    }
    readf.close();
    return b;
}
void Manager::readInfo(map<int ,EnterInfo>&m1,const char* filename)//��ȡ�ļ���Ϣ
{
    bool b=read(m1,filename);
    if(b)
    {
        c.GREEN();
        cout<<"��ȡ�ɹ�"<<endl;
    }
    else
    {
        c.RED();
        cout<<"��ȡʧ��"<<endl;
        c.BLACK();
    }
}
int bool_id1(char* id);
void Manager::distribute_userName()//��ѧ�������˺�
{
    c.PURPLE();
    cout<<"����Ա����,��������Ҫ�����ѧ��ѧ������:"<<endl;
    c.BLACK();
    int id1,id2;
    char id3[15],id4[15];
    while(true)
    {
    cout<<"��ʼѧ�ţ�"<<endl;
    cin>>id3;
    if(bool_id1(id3))
        break;
    }
    id1=convert_int(id3);
    while(true)
    {
    cout<<"��ֹѧ�ţ�"<<endl;
    cin>>id4;
    if(bool_id1(id4))
        break;
    }
    id2=convert_int(id4);
    Login l;
    l.add_stu_userName(id1,id2);
    c.GREEN();
    cout<<"-------�������-------"<<endl;
    c.BLACK();
}