#ifndef STUMANAGER_H
#define STUMANAGER_H
#include"Manager.h"
#include"GPA.h"
class StuManager:public Manager 
{
private:
public:
    StuManager();
    void showStuMenu();//��ʾѧ���˵�
    void addSelf(int i,map<int,EnterInfo>&stu1);//����Լ�����Ϣ
    void showSelf(int i,map<int,EnterInfo>&stu1);//�鿴�Լ�����Ϣ
    void findGPA(int i);//�鿴ѧ��������Ϣ
    ~StuManager();
};
#endif