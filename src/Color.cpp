#include"Color.h"
Color::Color(){}
Color::~Color(){}
void Color::RED()//����----������ʾ
{
     WORD wColor =((15 & 0x0F)<<4)+(4 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::GREEN()//��ɫ����������ȷ����
{
     WORD wColor =((15 & 0x0F)<<4)+(2 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::BLACK()//��ɫ----�˵�
{
     WORD wColor =((15 & 0x0F)<<4)+(0 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::BLUE()//��ʾ����
{
     WORD wColor =((15 & 0x0F)<<4)+(1 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::PURPLE()//������ʾ
{
     WORD wColor =((15 & 0x0F)<<4)+(5 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}