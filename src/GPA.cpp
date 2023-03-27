#include<map>
#include<vector>
#include<algorithm>
#include"Gpa.h"
#include<iomanip>
#include<fstream>
Gpa::~Gpa(){}
Gpa::Gpa(){}//带参构造，参与add函数
bool bool_id1(char *id)//检验学生id
{
    bool b=false;
    int l;
    l=strlen(id);
    if(l!=9)
        {
            cout<<"输入学号应为九位数"<<endl;
            return b;
        }
    for(int i=0;i<9;i++)
    {
        if(id[i]>'9'||id[i]<'0')
            {
                cout<<"学号中不可包含字母"<<endl;
                return b;
            }
    }
    return true;
}
void Gpa::setGPA(map<int,EnterInfo>&m)//设置及修改学生GPA
{
    c.PURPLE();
    cout<<"——————————设置学生绩点————————————"<<endl;
    c.BLACK();
    fstream gpaFile(filename1,ios::app|ios::binary);
    char id2[15],name[20],ch;
    float gpa;
    int id3,f,f2;
    f=f2=0;
    bool b=false;
    Gpa Info;
    while(true)
    {
        while(true)
        {
            c.BLACK();
            cout<<"请输入你要设置的学生学号(输入0退出):"<<endl;
            cin>>id2;
            if(convert_int(id2)==0)
            {
                system("pause");
                system("cls");
                return;
            }
            b=bool_id1(id2);
            cout<<"请输入学生姓名："<<endl;
            cin>>name;
            if(b)
            {
                id3=convert_int(id2);
                break;
            }
        }
        map<int,EnterInfo>::iterator it;
        it=m.find(id3);
        if(it!=m.end()&&strcmp(name,it->second.get_name())==0)
        {
            c.GREEN();
            cout<<"存在该生"<<endl;
            f=1;
        }
        else
        {   
            c.RED();
            cout<<"未查到有相关信息"<<endl;
            continue;
        }
        while(!gpaFile.eof())
        {
            gpaFile.read((char*)&Info,sizeof(Info));
            if(gpaFile.fail())
            {
                f2=1;
                break;
            }
            if(id==Info.id)
            {
                f2=0;
                break;
            }
        }
        gpaFile.close();
        if(f==1&&f2==1)
        {
            Info.id=id3;
            strcpy(Info.name1,name);
            while(true)
            {
                c.BLACK();
                cout<<"请输入学生绩点："<<endl;
                cin>>gpa;
            if(gpa>5.0||gpa<0)
            {
                c.RED();
                cout<<"输入有误(绩点在0.0-5)之间"<<endl;
            }
            else
            {
                Info.GPA=gpa;
                c.GREEN();
                cout<<"-------录入成功--------"<<endl;
                gpaFile.open(filename1,ios::app|ios::binary);
                gpaFile.write((char*)&Info,sizeof(Info));
                break;
            }
            }
        }
        c.BLACK();
        cout<<"是否要继续设置(y/n)"<<endl;
        cin>>ch;
        if(ch=='n'||ch=='N')
         {
            c.GREEN();
            cout<<"------设置完成------"<<endl;
            break;
        }
       }
    c.BLACK();
    gpaFile.close();
    system("pause");
    system("cls");
}
bool mycmp(Gpa &stu,Gpa &stu1)//自定义vector排序规则，按GPA排序
{
     if(stu.get_GPA()>stu1.get_GPA())
         return true;
     return false;
}
void Gpa::show_by_GPA()//按GPA降序输出
{
    c.PURPLE();
    cout<<"-----按学生绩点降序显示-----"<<endl;
    c.BLACK();
    fstream gpaFile(filename1,ios::in|ios::binary);
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
        cout<<"--------------------------------------\n";
        cout<<"|  排名  |    id   |"<<"  姓名  |"<<"   GPA  |"<<endl;
        int i=0;
        for(it=gpa.begin();it!=gpa.end();it++,i++)
        {   
            cout<<"--------------------------------------\n";
            cout<<"|   "<<i+1<<"    |";
            cout<<setw(8)<<it->id;
            cout<<"|"<<setw(8)<<it->name1;
            cout<<"|"<<setw(8)<<it->GPA<<"|"<<endl;
            cout<<"--------------------------------------\n";            
        }
        c.GREEN();
        cout<<"-------展示完毕-------"<<endl;
        c.BLACK();
    gpaFile.close();
    system("pause");
    system("cls");
}
void Gpa::modify_GPA()
{
    c.PURPLE();
    cout<<"——————修改学生绩点———————"<<endl;
    char  name[20],id1[15];
    int id2,f;
    float gpa;
    f=0;
    bool b;
    Gpa Info;
    fstream file(filename1,ios::in|ios::out|ios::binary);
    if(file.fail())
    {
        c.RED();
        cout<<"文件为空，无法修改"<<endl;
        return;
    }
    c.GREEN(); 
    cout<<"打开文件成功"<<endl;
    c.BLACK();
    while(true)
    {
        while(true)
        {
            cout<<"请输入你要设置的学生学号(输入0退出):"<<endl;
            cin>>id1;
            if(convert_int(id1)==0)
            {
                system("pause");
                system("cls");
                return;
            }
            b=bool_id1(id1);
            if(b)
            {
                id2=convert_int(id1);
                break;
            }
        }
        cout<<"请输入学生姓名："<<endl;
        cin>>name;
        while(!file.eof())
        {
            file.read((char*)&Info,sizeof(Info));
            if(file.fail())
            {
               break;
            }
            if(id2==Info.id)
            {
                f=1;
                break;
            }
        }
        if(file.eof()&&f==0)    
             {
                 c.RED();
                 cout<<"查无此人"<<endl;
                 continue;
             }
            c.BLUE();
            cout<<"原有信息如下"<<endl;
            cout<<"ID"<<"\t\t"<<"姓名" <<"\t\t"<<"学生GPA"<<endl;
            cout<<setw(16)<<Info.id;
            cout<<setw(16)<<Info.name1;
            cout<<setw(16)<<Info.GPA<<endl; 
            c.BLACK();   
            cout<<"请输入修改学生绩点:"<<endl;
            cin>>gpa;
        if(gpa>5.0||gpa<0)
           {
            c.RED();
            cout<<"输入有误(绩点在0.0-5)之间"<<endl;
            }
        else
            {
                Info.id=id2;
                strcpy(Info.name1,name);
                Info.GPA=gpa;
                c.GREEN();
                cout<<"设置成功"<<endl;
                file.seekp(-sizeof(Info),ios::cur);
                file.write((char*)&Info,sizeof(Info));
            }
        c.BLACK();
        cout<<"是否要继续设置(y/n)"<<endl;
        char ch;
        cin>>ch;
        if(ch=='n'||ch=='N')
         {
             c.GREEN();
             cout<<"------修改完成------";
            break;
         }
    }
    c.BLACK();
    file.close();
    system("pause");
    system("cls");
}   
void Gpa::delGpa()//删除学生GPA信息
{
    c.PURPLE();
    cout<<"——————删除学生绩点———————"<<endl;
    char  id1[15];
    int id2;
    bool b;
    c.BLACK();
    while(true)
    {
        while(true)
        {
            cout<<"请输入你要删除的学生学号(输入0退出):"<<endl;
            cin>>id1;
            if(convert_int(id1)==0)
            {
                system("pause");
                system("cls");
                return;
            }
            b=bool_id1(id1);
            if(b)
            {
                id2=convert_int(id1);
                break;
            }
        }
        del_Gpa(id2);
        cout<<"是否要继续删除(y/n)"<<endl;
        char ch;
        cin>>ch;
        if(ch=='n'||ch=='N')
        {
            c.GREEN();
            cout<<"------修改完成------";
            break;
        }
    }
    c.BLACK();
    system("pause");
    system("cls");
}
void Gpa::del_Gpa(int id2)//删除实现函数
{
    int f;
    bool b;
    Gpa Info;
    fstream file(filename1,ios::in|ios::binary);
    if(file.fail())
    {
        c.RED();
        cout<<"文件为空"<<endl;
        return;
    }
    c.GREEN(); 
    cout<<"打开文件成功"<<endl;
    vector<Gpa> gpa;
        while(!file.eof())
        {
            file.read((char*)&Info,sizeof(Info));   
            if(file.fail())
            break;
            gpa.push_back(Info);    
        }
        file.close();
        vector<Gpa>::iterator it;
        file.open(filename1,ios::out|ios::binary);
        if(file.fail())
        {
            c.RED();
            cout<<"文件打开失败"<<endl;
            return;
        }
        c.GREEN(); 
        cout<<"打开文件成功"<<endl;
        for(it=gpa.begin();it!=gpa.end();it++)
        {
            if(it->get_id()==id2)
            {
                gpa.erase(it);    
                c.GREEN();
                cout<<"删除成功"<<endl;
                break;
                f=1;
            }
        }
        if(file.eof()&&f==0)    
             {
                 c.RED();
                 cout<<"查无此人"<<endl;
                 return;
             }
        for(it=gpa.begin();it!=gpa.end();it++)
        {
            Info=*it;
            file.write((char*)&Info,sizeof(Info)); 
        }
    file.close();
}
 float Gpa::get_GPA()//返回GPA
 {
     return GPA;
 }
 char* Gpa::get_name1()
 {
     return name1;
 }
 int Gpa::get_id()
{
    return id;
}