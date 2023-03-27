#include<map>
#include<vector>
#include<algorithm>
#include"Gpa.h"
#include<iomanip>
#include<fstream>
Gpa::~Gpa(){}
Gpa::Gpa(){}//���ι��죬����add����
bool bool_id1(char *id)//����ѧ��id
{
    bool b=false;
    int l;
    l=strlen(id);
    if(l!=9)
        {
            cout<<"����ѧ��ӦΪ��λ��"<<endl;
            return b;
        }
    for(int i=0;i<9;i++)
    {
        if(id[i]>'9'||id[i]<'0')
            {
                cout<<"ѧ���в��ɰ�����ĸ"<<endl;
                return b;
            }
    }
    return true;
}
void Gpa::setGPA(map<int,EnterInfo>&m)//���ü��޸�ѧ��GPA
{
    c.PURPLE();
    cout<<"������������������������ѧ�����㡪����������������������"<<endl;
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
            cout<<"��������Ҫ���õ�ѧ��ѧ��(����0�˳�):"<<endl;
            cin>>id2;
            if(convert_int(id2)==0)
            {
                system("pause");
                system("cls");
                return;
            }
            b=bool_id1(id2);
            cout<<"������ѧ��������"<<endl;
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
            cout<<"���ڸ���"<<endl;
            f=1;
        }
        else
        {   
            c.RED();
            cout<<"δ�鵽�������Ϣ"<<endl;
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
                cout<<"������ѧ�����㣺"<<endl;
                cin>>gpa;
            if(gpa>5.0||gpa<0)
            {
                c.RED();
                cout<<"��������(������0.0-5)֮��"<<endl;
            }
            else
            {
                Info.GPA=gpa;
                c.GREEN();
                cout<<"-------¼��ɹ�--------"<<endl;
                gpaFile.open(filename1,ios::app|ios::binary);
                gpaFile.write((char*)&Info,sizeof(Info));
                break;
            }
            }
        }
        c.BLACK();
        cout<<"�Ƿ�Ҫ��������(y/n)"<<endl;
        cin>>ch;
        if(ch=='n'||ch=='N')
         {
            c.GREEN();
            cout<<"------�������------"<<endl;
            break;
        }
       }
    c.BLACK();
    gpaFile.close();
    system("pause");
    system("cls");
}
bool mycmp(Gpa &stu,Gpa &stu1)//�Զ���vector������򣬰�GPA����
{
     if(stu.get_GPA()>stu1.get_GPA())
         return true;
     return false;
}
void Gpa::show_by_GPA()//��GPA�������
{
    c.PURPLE();
    cout<<"-----��ѧ�����㽵����ʾ-----"<<endl;
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
        cout<<"|  ����  |    id   |"<<"  ����  |"<<"   GPA  |"<<endl;
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
        cout<<"-------չʾ���-------"<<endl;
        c.BLACK();
    gpaFile.close();
    system("pause");
    system("cls");
}
void Gpa::modify_GPA()
{
    c.PURPLE();
    cout<<"�������������޸�ѧ�����㡪������������"<<endl;
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
        cout<<"�ļ�Ϊ�գ��޷��޸�"<<endl;
        return;
    }
    c.GREEN(); 
    cout<<"���ļ��ɹ�"<<endl;
    c.BLACK();
    while(true)
    {
        while(true)
        {
            cout<<"��������Ҫ���õ�ѧ��ѧ��(����0�˳�):"<<endl;
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
        cout<<"������ѧ��������"<<endl;
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
                 cout<<"���޴���"<<endl;
                 continue;
             }
            c.BLUE();
            cout<<"ԭ����Ϣ����"<<endl;
            cout<<"ID"<<"\t\t"<<"����" <<"\t\t"<<"ѧ��GPA"<<endl;
            cout<<setw(16)<<Info.id;
            cout<<setw(16)<<Info.name1;
            cout<<setw(16)<<Info.GPA<<endl; 
            c.BLACK();   
            cout<<"�������޸�ѧ������:"<<endl;
            cin>>gpa;
        if(gpa>5.0||gpa<0)
           {
            c.RED();
            cout<<"��������(������0.0-5)֮��"<<endl;
            }
        else
            {
                Info.id=id2;
                strcpy(Info.name1,name);
                Info.GPA=gpa;
                c.GREEN();
                cout<<"���óɹ�"<<endl;
                file.seekp(-sizeof(Info),ios::cur);
                file.write((char*)&Info,sizeof(Info));
            }
        c.BLACK();
        cout<<"�Ƿ�Ҫ��������(y/n)"<<endl;
        char ch;
        cin>>ch;
        if(ch=='n'||ch=='N')
         {
             c.GREEN();
             cout<<"------�޸����------";
            break;
         }
    }
    c.BLACK();
    file.close();
    system("pause");
    system("cls");
}   
void Gpa::delGpa()//ɾ��ѧ��GPA��Ϣ
{
    c.PURPLE();
    cout<<"������������ɾ��ѧ�����㡪������������"<<endl;
    char  id1[15];
    int id2;
    bool b;
    c.BLACK();
    while(true)
    {
        while(true)
        {
            cout<<"��������Ҫɾ����ѧ��ѧ��(����0�˳�):"<<endl;
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
        cout<<"�Ƿ�Ҫ����ɾ��(y/n)"<<endl;
        char ch;
        cin>>ch;
        if(ch=='n'||ch=='N')
        {
            c.GREEN();
            cout<<"------�޸����------";
            break;
        }
    }
    c.BLACK();
    system("pause");
    system("cls");
}
void Gpa::del_Gpa(int id2)//ɾ��ʵ�ֺ���
{
    int f;
    bool b;
    Gpa Info;
    fstream file(filename1,ios::in|ios::binary);
    if(file.fail())
    {
        c.RED();
        cout<<"�ļ�Ϊ��"<<endl;
        return;
    }
    c.GREEN(); 
    cout<<"���ļ��ɹ�"<<endl;
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
            cout<<"�ļ���ʧ��"<<endl;
            return;
        }
        c.GREEN(); 
        cout<<"���ļ��ɹ�"<<endl;
        for(it=gpa.begin();it!=gpa.end();it++)
        {
            if(it->get_id()==id2)
            {
                gpa.erase(it);    
                c.GREEN();
                cout<<"ɾ���ɹ�"<<endl;
                break;
                f=1;
            }
        }
        if(file.eof()&&f==0)    
             {
                 c.RED();
                 cout<<"���޴���"<<endl;
                 return;
             }
        for(it=gpa.begin();it!=gpa.end();it++)
        {
            Info=*it;
            file.write((char*)&Info,sizeof(Info)); 
        }
    file.close();
}
 float Gpa::get_GPA()//����GPA
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