#ifndef GPA_H
#define GPA_H
#include"EnterInfo.h"
class Gpa
{
private:
    int id;
    char name1[20];
    float GPA;
    char filename1[20]="GPA.dat";
    Color c;
public:
    Gpa();
    ~Gpa();
    void setGPA(map<int,EnterInfo>&m);//����ѧ������
    void show_by_GPA();//������������ʾ
    void modify_GPA();//�޸�ѧ������
    void delGpa();//ɾ��ѧ������
    void del_Gpa(int i);//ʵ��ɾ��
    int get_id();
    float get_GPA();
    char* get_name1();
};
#endif