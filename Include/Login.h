#ifndef LONGIN_H
#define LOGIN_H
#include"string.h"
#include<map>
#include<string.h>
#include"Gpa.h"
#include"StuManager.h"
#include"EnterInfo.h"
using namespace std;
struct StuN_K
{
    int id;
    char key[20];
};
class Login
{
    private:
        const char maUserN[20]="admin";//����Ա�˺�
        char managerKey[20];//����Ա����
        map<int,EnterInfo>stu;//map������ȡѧ����Ϣ
        char filename[20]="File.dat";//ѧ����Ϣ�����ļ�
        Manager v;//�������
        Gpa f;//GPA��������
        StuManager sMa;//ѧ������
        Color c;
    public:
        Login();
        void stuSever(int i);//ѧ������ʵ��
        void managerSever();//����Ա����ʵ��
        void add_stu_userName(int id1,int id2);//���ѧ���û���
        bool studentLogin(int userName,char* key);//ѧ����¼
        bool managerLogin(char* userName,char* key);//����Ա��¼
        bool modifyStuKey(int id,char* key);//�޸�ѧ������
        bool ensureKey(char* a);//�������ǿ��
        ~Login();
};
#endif