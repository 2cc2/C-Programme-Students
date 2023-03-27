#ifndef MANAGER_H
#define MANAGER_H
#include<fstream>
#include"EnterInfo.h"
#include<map>
using namespace std;
class Manager
{
    protected:
    char filename[20]="File.dat";
    Color c;
    public:
        Manager();
        void showMenu();//��ʾ�˵�
        void run_Modify(map<int,EnterInfo>&stu);
        void modifyStuKey();//�޸�ѧ������
        void addStuInfo(map<int,EnterInfo>&m);//����ѧ����Ϣ
        void delStuInfo(map<int,EnterInfo>&m);//ɾ��ѧ����Ϣ
        void modifyEx(map<int,EnterInfo>&stu1);//�޸�ѧ������
        void modifyEnterInfo(map<int,EnterInfo>&stu1);//�޸�ѧ��������Ϣ
        void modifyStuInfo(map<int,EnterInfo>&m);//�޸�ѧ����Ϣ
        void findStuInfo(map<int,EnterInfo>&m);//����ѧ����Ϣ
        void showStuInfo(map<int ,EnterInfo>&m);//չʾѧ����Ϣ
        void show_by_entersco(map<int ,EnterInfo>&m);//��ѧ���߿�����������ʾ
        void distribute_userName();//����ѧ���˺�
        int bool_userName(map<int,EnterInfo>&stu1);//�ж�������ȷ��
        void saveStuInfo(map<int,EnterInfo>&m,const char* filename);//������Ϣ
        void readInfo(map<int,EnterInfo>&m,const char* filename);//��ȡ��Ϣ
        ~Manager();
};
#endif