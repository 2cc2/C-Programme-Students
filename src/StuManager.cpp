#include"StuManager.h"
#include<vector>
#include<algorithm>
#include<iomanip>
StuManager::StuManager(){}
StuManager::~StuManager(){}
bool mycmp(Gpa &stu,Gpa &stu1);//�Զ�������
void  StuManager::showStuMenu()
    {
        cout<<"��ӭʹ��ѧ��ѧ������ϵͳ��"<<endl;
        cout<<"��ִ�в�����"<<endl;
        cout<<"1��¼�������Ϣ"<<endl;
        cout<<"2���鿴������Ϣ"<<endl;
        cout<<"3���鿴����ѧ�ڼ��㼰����"<<endl;
        cout<<"4���޸�����"<<endl;
        cout<<"0���˳�ϵͳ"<<endl;
        cout<<"��������Ҫ���еĲ���";
    }
void StuManager::addSelf(int i,map<int,EnterInfo>&stu1)
    {
        c.PURPLE();
        cout<<"����������������������¼�������Ϣ������������������������";
        readInfo(stu1,filename);
        map<int,EnterInfo>::iterator it;
        it=stu1.find(i);
        if(it!=stu1.end())
            {
                c.RED();
                cout<<"��Ϣ��¼��"<<endl;
            }
        else
            {
                EnterInfo stu(i);
                stu1.insert(make_pair(stu.get_id(),stu));
                saveStuInfo(stu1,filename);
                c.GREEN();
                cout<<"-------¼��ɹ�--------"<<endl;
            }
        system("pause");
        system("cls");
        c.BLACK();
    }
void StuManager::showSelf(int i,map<int,EnterInfo>&stu1)
    {

            Manager::readInfo(stu1,filename);
            map<int,EnterInfo>::iterator it;
            it =stu1.find(i);
            EnterInfo stu;
            if(it!=stu1.end())
                {
                    c.BLACK();
                    cout<<"---------------------------------------------------------------------------------------------------\n";
                    cout<<"|    id   |"<<"  ����  |"<<"���� |"<<"�Ա�|"<<"   ����   |"<<"  ��������  |"<<"        ����       |"<<"   ��ѧ�ɼ�   |"<<"  רҵ  |"<<endl;
                    cout<<"---------------------------------------------------------------------------------------------------\n";
                    it->second.show_enterinfo();
                    cout<<"---------------------------------------------------------------------------------------------------\n";
                }
            else
                {
                    c.RED();
                    cout<<"���޴���"<<endl;
                }
        system("pause");
        system("cls");       
    }
void StuManager::findGPA(int i)//�鿴ѧ��������Ϣ
    {
    
        fstream gpaFile("GPA.dat",ios::in|ios::binary);
        Gpa Info;
        vector<Gpa> gpa;
        while(!gpaFile.eof())
            {
                gpaFile.read((char*)&Info,sizeof(Info));   
                if(gpaFile.fail())
                break;
                gpa.push_back(Info);    
            }
        sort(gpa.begin(),gpa.end(),mycmp);
        vector<Gpa>::iterator it;
        int k=0;
        cout<<"--------------------------------------\n";
        cout<<"|  ����  |    id   |"<<"  ����  |"<<"   GPA  |"<<endl;
        for(it=gpa.begin();it!=gpa.end();it++,k++)
            {   
                if(it->get_id()==i)
                    {
                        cout<<"--------------------------------------\n";
                        cout<<"|   "<<k+1<<"     ";
                        cout<<"|"<<setw(8)<<it->get_id();
                        cout<<"|"<<setw(8)<<it->get_name1();
                        cout<<"|"<<setw(8)<<it->get_GPA()<<"|"<<endl;
                        cout<<"--------------------------------------\n";
                        break;   
                    }
                else
                    {
                        c.RED();
                        cout<<"δ�ҵ������Ϣ"<<endl;
                    }
            }
        c.GREEN();
        cout<<"-------չʾ���-------"<<endl;   
        gpaFile.close();
        system("pause");
        system("cls");
    }