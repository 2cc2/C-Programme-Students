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
void Manager::showMenu()//显示管理员菜单
{
    cout<<"欢迎使用学生学籍管理系统："<<endl;
    cout<<"可执行操作："<<endl;
    cout<<"1、添加学生信息"<<endl;
    cout<<"2、设置学生绩点"<<endl;
    cout<<"3、修改学生绩点"<<endl;
    cout<<"4、修改学生信息"<<endl;
    cout<<"5、查找学生信息"<<endl;
    cout<<"6、删除学生信息"<<endl;
    cout<<"7、单独删除学生绩点信息"<<endl;
    cout<<"8、显示所有学生的信息"<<endl;
    cout<<"9、分配学生账号"<<endl;
    cout<<"10、按高考成绩降序显示"<<endl;
    cout<<"11、按GPA降序显示"<<endl;
    cout<<"0、退出系统"<<endl;
    cout<<"\n";
    cout<<"请输入您要进行的操作";
}
void Manager::modifyStuKey()//修改学生密码调用函数
{
    LoginMenu lm;
    lm.modifyStuKey();
}
bool mycmp(pair<int,EnterInfo> &stu,pair<int,EnterInfo> &stu1)//自定义排序
{
    if(strcmp(stu.second.get_entSco(),stu1.second.get_entSco())>0)
        return true;
    return false;
}
void Manager::show_by_entersco(map<int ,EnterInfo>&m)//排序按高考分数降序输出
{
    c.PURPLE();
    cout<<"---------当前显示(高考分数降序)-----------"<<endl;
    c.BLACK();
    if(m.empty())
    {
        readInfo(m,filename);
    }
    vector<pair<int,EnterInfo>> stu(m.begin(),m.end());
    sort(stu.begin(),stu.end(),mycmp);
    c.BLACK();
    cout<<"-----------------------------------------------------------------------------------------------------------\n";
    cout<<"|  排名  |    id   |"<<"  姓名  |"<<" 年龄 |"<<" 性别 |"<<" 民族   |"<<"    出生日期    |"<<"     籍贯       |"<<" 入学成绩 |"<<"   专业   |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n";
    for(int i=0;i<stu.size();i++)
    {
        cout<<"-----------------------------------------------------------------------------------------------------------\n";
        cout<<"|   "<<i+1<<"   |";
        stu[i].second.show_enterinfo();
        cout<<"-----------------------------------------------------------------------------------------------------------\n";

    }
    c.GREEN();
    cout<<"-------显示完毕-------"<<endl;
    c.BLACK();
    system("pause");
    system("cls");
}
void Manager::showStuInfo(map<int,EnterInfo>&stu1)//展示学生基本信息
{
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    c.PURPLE();
    cout<<"----- 学生基本信息-------"<<endl;
    c.BLACK();
    cout<<"---------------------------------------------------------------------------------------------------\n";
    cout<<"|    id   |"<<"  姓名  |"<<" 年龄 |"<<" 性别 |"<<" 民族   |"<<"    出生日期    |"<<"     籍贯       |"<<" 入学成绩 |"<<"   专业   |"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------\n";
    map<int,EnterInfo>::iterator it;
    for(it=stu1.begin();it!=stu1.end();it++)
    {
        cout<<"---------------------------------------------------------------------------------------------------\n";
        it->second.show_enterinfo();
        cout<<"---------------------------------------------------------------------------------------------------\n";
    }
    c.GREEN();
    cout<<"以上为全部学生信息"<<endl;
    system("pause");
    system("cls");
}
bool bool_id(char *id,map<int,EnterInfo>&stu1)//学号正确性检验
{
    bool b=false;
    int l,id2;
    l=strlen(id);
    if(l!=9)
        {    
            cout<<"输入学号应为九位"<<endl;
            return b;
        }
    for(int i=0;i<9;i++)
    {
        if(id[i]>'9'||id[i]<'0')
            {
                cout<<"学号中不应有字母"<<endl;
                return b;
            }
    }
    convert_int(id);
    if(stu1.find(id2)!=stu1.end())
    {
       cout<<"学号输入重复"<<endl;
        return b;
    }
    return true;
}
int Manager::bool_userName(map<int,EnterInfo>&stu)//学生id检验
{   
    char id[15],ch;
    cin>>id;
    if(convert_int(id)==0)
    return 0;
     while(!bool_id(id,stu))
    {
        c.RED();
        cout<<"请核对后再输入，谢谢。"<<endl;
        c.BLACK();
        cout<<"是否要继续输入学号(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            cout<<"-----输入结束------"<<endl;
            return 0;
        }
        cout<<"请输入学生学号(0可退出):"<<endl;
        cin>>id;
    }
    int id2;
    id2=convert_int(id);
    return id2;
}
void Manager::addStuInfo(map<int,EnterInfo>&stu1)//添加学生信息
{
    c.RED();
    bool b;
    b=read(stu1,filename);
    if(!b)
    cout<<"初始文件为空,需要录入信息"<<endl;
    c.PURPLE();
    cout<<"------添加学生信息------"<<endl;
    c.BLACK();
    int id1;
    char ch;
    while(true)
    {
        cout<<"请输入要添加的学生学号(输入0可退出):"<<endl;
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
                cout<<"输入学号重复"<<endl;
                cout<<"请新输入"<<endl;
                c.BLACK();
            }
            else
            break;
        }
        EnterInfo stu(id1);
        stu1.insert(make_pair(stu.get_id(),stu));
        c.BLACK();
        cout<<"是否要继续添加一个学生(y/n):"<<endl;
        cin>>ch;
        if(ch=='n'||ch=='N')
        {
            c.GREEN();
            cout<<"-----录入完毕----"<<endl;
            break; 
        }
    }
    c.BLACK();
    saveStuInfo(stu1,filename);
    system("pause");
    system("cls");
}
void Manager::findStuInfo(map<int,EnterInfo>&stu1)//查找学生
{
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    c.PURPLE();
    cout<<"------查询学生信息--------"<<endl;
    c.BLACK();
    int id2,f=0;
    EnterInfo stu;
        cout<<"请输入你要查询的学生学号(输入0可退出):"<<endl;
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
            cout<<"|    id   |"<<"  姓名  |"<<"年龄 |"<<"性别|"<<"   民族   |"<<"  出生日期  |"<<"        籍贯       |"<<"   入学成绩   |"<<"  专业  |"<<endl;
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
            cout<<"查无此人"<<endl;
        }
    c.BLACK();
    system("pause");
    system("cls");
}
void Manager::delStuInfo(map<int,EnterInfo>&stu1)//删除学生
{
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    c.PURPLE();
    cout<<"---------删除操作---------"<<endl;
    c.BLACK();
    int id;
    char ch;
    readInfo(stu1,filename);
    map<int,EnterInfo>::iterator it;
    while(true)
    {    
        c.BLACK();
        cout<<"请输入你要删除的学生的id(输入0可退出):"<<endl;
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
            cout<<"删除成功"<<endl;
            saveStuInfo(stu1,filename);
            c.BLACK();
            cout<<"是否同步删除学生绩点信息(y/n):"<<endl;
            cin>>ch;
            if(ch=='n'||ch=='N')
            {
                cout<<"学生绩点信息将被保留，若要删除可单独再删除"<<endl;
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
            cout<<"查无此人"<<endl;
        }
        c.BLACK();
        cout<<"还要删除学生吗(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"--------删除操作结束---------"<<endl;
            c.BLACK();
            break;
        }
    }
    system("pause");
    system("cls");
}
void Manager::run_Modify(map<int,EnterInfo>&stu)//修改实现函数
{
    c.PURPLE();
    cout<<"———————修改学生信息————————"<<endl;
    if(stu.empty())
    {
        readInfo(stu,filename);
    }
    int choice;
    c.BLACK();
    while(true)
    {
        cout<<"请选择您要修改的内容："<<endl;
        cout<<"1.学生基本信息"<<endl;
        cout<<"2.学生教育信息"<<endl;
        cout<<"3.修改全部学生信息"<<endl;
        cout<<"0.放弃修改"<<endl;
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
            cout<<"请等待退出";
            Sleep(1000);
            system("cls");
            return;
        }
        else
        c.RED();
        cout<<"输入选项错误"<<endl;
        char ch;
        c.BLACK();
        cout<<"是否继续修改其他信息(y/n):"<<endl;
        cin>>ch;
        if(ch=='n'||ch=='N')
        {
            c.GREEN();
            cout<<"-----结束修改-----"<<endl;
            break;
        }
    }
    system("pause");
    system("cls");
}
void Manager::modifyStuInfo(map<int,EnterInfo>&stu1)//修改学生函数
{
    c.PURPLE();
    cout<<"------修改学生全部信息--------"<<endl;
    c.BLACK();
    int idx,id;
    char ch,name[20];
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    while(true)
    {
        cout<<"请输入要修改的学生id(输入0可退出):"<<endl;
        idx=bool_userName(stu1);
        if(idx==0)
        {
            system("pause");
            system("cls");
            return;
        }
        cout<<"请输入要修改的信息："<<endl;
        cout<<"请输入修改后的id:"<<endl;
        id=bool_userName(stu1);
        EnterInfo stu(id);
        map<int,EnterInfo>::iterator it;
        it=stu1.find(idx);
        if(it!=stu1.end())
        {
            it->second=stu;
            c.GREEN();
            cout<<"修改成功"<<endl;
        }
        else
        {
            c.RED();
            cout<<"查无此人"<<endl;
        }
        c.BLACK();
        cout<<"是否要继续修改(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"-----修改结束------"<<endl;
            c.BLACK();
            break;
        }
    }
    saveStuInfo(stu1,filename);
}
void Manager::modifyEnterInfo(map<int,EnterInfo>&stu1)//修改学生基本信息
{
    c.PURPLE();
    cout<<"------修改学生基本信息--------"<<endl;
    c.BLACK();
    int idx,id;
    char ch,name[20];
    if(stu1.empty())
    {
        readInfo(stu1,filename);
    }
    while(true)
    {
        cout<<"请输入要修改的学生id(输入0可退出):"<<endl;
        idx=bool_userName(stu1);
        if(idx==0)
            {
                system("pause");
                system("cls");
                return;
            }
        cout<<"请输入要修改的信息："<<endl;
        cout<<"请输入修改后的id:"<<endl;
        id=bool_userName(stu1);
        cout<<"请输入修改的学生姓名："<<endl;
        cin>>name;
        EnterInfo stu(id,name);
        map<int,EnterInfo>::iterator it;
        it=stu1.find(idx);
        if(it!=stu1.end())
        {
            stu.set_exp(it->second.get_exp());
            it->second=stu;
            c.GREEN();
            cout<<"修改成功"<<endl;
        }
        else
        {
            c.RED();
            cout<<"查无此人"<<endl;
        }
        c.BLACK();
        cout<<"是否要继续修改(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"-----修改结束------"<<endl;
            c.BLACK();
            break;
        }
    }
    saveStuInfo(stu1,filename);
}
void Manager::modifyEx(map<int,EnterInfo>&stu1)//修改教育信息
{
    c.PURPLE();
    cout<<"------修改学生教育信息--------"<<endl;
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
        cout<<"请输入要修改的学生id(输入0可退出)"<<endl;
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
            cout<<"请选择您要修改的内容："<<endl;
            cout<<"1.该生小学学习经历信息\n";
            cout<<"2.该生初中学习经历信息\n";
            cout<<"3.该生高中学习经历信息\n";
            cout<<"4.该生大学学习经历信息\n";
            cin>>choice;
            c.PURPLE();
            switch(choice)
                {
                    case 1:
                    cout<<"您要修改的是该生小学的信息："<<endl;
                    break;
                    case 2:
                    cout<<"您要修改的是该生初中的信息："<<endl;
                    break;
                    case 3:
                    cout<<"您要修改的是该生高中的信息："<<endl;
                    break;
                    case 4:
                    cout<<"您要修改的是该生大学的信息："<<endl;
                    break;
                    default:
                    cout<<"输入选项有误"<<endl;
                    continue;
                }
            c.BLACK();
            cout<<"原有信息为："<<endl;
            EduEx* e;
            stu.set_exp(it->second.get_exp());//保留exp
            stu.show_exp(choice-1);//显示原有信息
            stu.stay_info(it->second);//保留原有基本信息
            stu.set_experience(choice-1);
            it->second=stu;
            saveStuInfo(stu1,filename);
            c.GREEN();
            cout<<"修改完成"<<endl;
         }
        else
         {
             c.RED();
             cout<<"查无此人"<<endl;
         }
         c.BLACK();
         cout<<"是否要继续修改(y/n):"<<endl;
         cin>>ch;
         if(ch=='N'||ch=='n')
         {
            c.GREEN();
            cout<<"-----修改结束------"<<endl;
            break;
         }
        }
        c.BLACK();
        cout<<"是否要继续修改其它学生(y/n):"<<endl;
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            c.GREEN();
            cout<<"-----修改结束------"<<endl;
            break;
        }
    }
}
bool save(map<int,EnterInfo>&m,const char* filename)//判断保存函数
{
    bool b=true;
    fstream savef(filename,ios::out|ios::binary);
    if(savef.fail())
    {
        cout<<"打开保存文件失败"<<endl;
        b=false;
        exit(0); 
    }
    cout<<"打开文件成功！"<<endl;
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
void Manager::saveStuInfo(map<int,EnterInfo>&m1,const char* filename)//保存函数
{
    if(m1.begin()==m1.end())
    {
        c.RED();
        cout<<"还没有任何学生信息，无法保存"<<endl;
    }
    else
    {
        bool b=save(m1,filename);
        if(b)
        {
            c.GREEN();
            cout<<"保存成功"<<endl;
        }
        else
        {
            c.RED();
            cout<<"保存失败"<<endl;
        }
    }
    c.BLACK();
}
bool read(map<int,EnterInfo>&m,const char* filename)//判断读取函数
{
    bool b=true;
    m.clear();
    fstream readf(filename,ios::in|ios::binary);
    if(readf.fail())
    {
        cout<<"打开文件失败！"<<endl;
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
void Manager::readInfo(map<int ,EnterInfo>&m1,const char* filename)//读取文件信息
{
    bool b=read(m1,filename);
    if(b)
    {
        c.GREEN();
        cout<<"读取成功"<<endl;
    }
    else
    {
        c.RED();
        cout<<"读取失败"<<endl;
        c.BLACK();
    }
}
int bool_id1(char* id);
void Manager::distribute_userName()//给学生分配账号
{
    c.PURPLE();
    cout<<"管理员您好,请输入您要分配的学生学号区间:"<<endl;
    c.BLACK();
    int id1,id2;
    char id3[15],id4[15];
    while(true)
    {
    cout<<"初始学号："<<endl;
    cin>>id3;
    if(bool_id1(id3))
        break;
    }
    id1=convert_int(id3);
    while(true)
    {
    cout<<"终止学号："<<endl;
    cin>>id4;
    if(bool_id1(id4))
        break;
    }
    id2=convert_int(id4);
    Login l;
    l.add_stu_userName(id1,id2);
    c.GREEN();
    cout<<"-------分配完毕-------"<<endl;
    c.BLACK();
}