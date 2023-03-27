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
        Date start;//起始时间
        Date end;//结束时间
        char schoolName[30];//学校名
        char stuPosition[13];//担任职务
        char headTeacher[20];//班主任（证明人）
        char PhoneNum[15];//班主任联系电话
}; 
class EnterInfo
{
    protected:
        char name[20];//姓名
        int age;//年龄
        char gender[3];//学生性别
		char nation[15];//学生的民族
		Date birthday;//学生出生日期
        char nativePlace[30];//籍贯
        char politicalStatus[6];//政治面貌
        char enterScore[4];//入学成绩
		int id;//学号
		char department[30]; //学生系别
		char major[30];//学生专业
        EduEx ex[4];
        Color c;
    public:
        EnterInfo();
        EnterInfo(int id);//带参构造
        EnterInfo(int id,char* name);
        ~EnterInfo();
        void show_enterinfo();//展示学生基本信息
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
        friend ostream& operator<<(ostream& out, EnterInfo& obj);//重载运算符
        void set_exp(EduEx* e);//设置学生教育经历
        EduEx* get_exp();
        void show_exp(int i);//展示学生学生经历
        void stay_info(EnterInfo& obj);
};  
#endif