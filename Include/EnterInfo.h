#ifndef ENTERINFO_H
#define ENTERINFO_H
#include<string.h>
#include<iostream>
#include<map>
#include"Date.h"
#include"Color.h"
using namespace std;
int convert_int(char* n);
struct EduEx
{
        Date start;//��ʼʱ��
        Date end;//����ʱ��
        char schoolName[30];//ѧУ��
        char stuPosition[13];//����ְ��
        char headTeacher[20];//�����Σ�֤���ˣ�
        char PhoneNum[15];//��������ϵ�绰
}; 
class EnterInfo
{
    protected:
        char name[20];//����
        int age;//����
        char gender[3];//ѧ���Ա�
		char nation[15];//ѧ��������
		Date birthday;//ѧ����������
        char nativePlace[30];//����
        char politicalStatus[6];//������ò
        char enterScore[4];//��ѧ�ɼ�
		int id;//ѧ��
		char department[30]; //ѧ��ϵ��
		char major[30];//ѧ��רҵ
        EduEx ex[4];
        Color c;
    public:
        EnterInfo();
        EnterInfo(int id);//���ι���
        EnterInfo(int id,char* name);
        ~EnterInfo();
        void show_enterinfo();//չʾѧ��������Ϣ
        void set_name(char* name1);
        char* get_name();
        void set_age(int age1);
        int  get_age();
        void set_gender(char* gen);
        char* get_gender();
        void set_nation(char* nat);
        char* get_nation();
        void set_birthday(Date bir);
        Date get_birthday();
        void set_natPlace(char* natpl);
        char* get_natPlace();
        void set_plotStatus(char* polst);
        char* get_polStatus();
        void set_entSco(char* sco);
        char* get_entSco();
        void set_id(int n);
        int get_id();
        void set_department(char* dep);
        char* get_department();
        void set_major(char* m);
        char* get_major();
        void set_experience(int i);
        void set_PhoneNum(char* p,int i);
        friend ostream& operator<<(ostream& out, EnterInfo& obj);//���������
        void set_exp(EduEx* e);//����ѧ����������
        EduEx* get_exp();
        void show_exp(int i);//չʾѧ��ѧ������
        void stay_info(EnterInfo& obj);
};  
#endif