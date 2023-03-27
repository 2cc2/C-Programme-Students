#include"Color.h"
Color::Color(){}
Color::~Color(){}
void Color::RED()//红字----错误提示
{
     WORD wColor =((15 & 0x0F)<<4)+(4 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::GREEN()//绿色————正确操作
{
     WORD wColor =((15 & 0x0F)<<4)+(2 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::BLACK()//黑色----菜单
{
     WORD wColor =((15 & 0x0F)<<4)+(0 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::BLUE()//提示操作
{
     WORD wColor =((15 & 0x0F)<<4)+(1 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void Color::PURPLE()//功能提示
{
     WORD wColor =((15 & 0x0F)<<4)+(5 & 0x0f);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}