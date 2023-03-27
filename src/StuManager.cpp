#include"StuManager.h"
#include<vector>
#include<algorithm>
#include<iomanip>
StuManager::StuManager(){}
StuManager::~StuManager(){}
bool mycmp(Gpa &stu,Gpa &stu1);//自定义排序
void  StuManager::showStuMenu()
    {
        cout<<"欢迎使用学生学籍管理系统："<<endl;
        cout<<"可执行操作："<<endl;
        cout<<"1、录入个人信息"<<endl;
        cout<<"2、查看本人信息"<<endl;
        cout<<"3、查看个人学期绩点及排名"<<endl;
        cout<<"4、修改密码"<<endl;
        cout<<"0、退出系统"<<endl;
        cout<<"请输入您要进行的操作";
    }
void StuManager::addSelf(int i,map<int,EnterInfo>&stu1)
    {
        c.PURPLE();
        cout<<"———————————录入个人信息————————————";
        readInfo(stu1,filename);
        map<int,EnterInfo>::iterator it;
        it=stu1.find(i);
        if(it!=stu1.end())
            {
                c.RED();
                cout<<"信息已录入"<<endl;
            }
        else
            {
                EnterInfo stu(i);
                stu1.insert(make_pair(stu.get_id(),stu));
                saveStuInfo(stu1,filename);
                c.GREEN();
                cout<<"-------录入成功--------"<<endl;
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
                    cout<<"|    id   |"<<"  姓名  |"<<"年龄 |"<<"性别|"<<"   民族   |"<<"  出生日期  |"<<"        籍贯       |"<<"   入学成绩   |"<<"  专业  |"<<endl;
                    cout<<"---------------------------------------------------------------------------------------------------\n";
                    it->second.show_enterinfo();
                    cout<<"---------------------------------------------------------------------------------------------------\n";
                }
            else
                {
                    c.RED();
                    cout<<"查无此人"<<endl;
                }
        system("pause");
        system("cls");       
    }
void StuManager::findGPA(int i)//查看学生绩点信息
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
        cout<<"|  排名  |    id   |"<<"  姓名  |"<<"   GPA  |"<<endl;
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
                        cout<<"未找到相关信息"<<endl;
                    }
            }
        c.GREEN();
        cout<<"-------展示完毕-------"<<endl;   
        gpaFile.close();
        system("pause");
        system("cls");
    }