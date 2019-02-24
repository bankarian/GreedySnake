#include <iostream>
#include "tools.h"
using namespace std;
namespace bankarian
{
void Move(int x ,int y)//finish 
{
	COORD c;//定义结构体变量 windows API中的结构体，控制台屏幕坐标
	c.X = x;
	c.Y = y;

	HANDLE handle;//定义一个句柄
	handle = GetStdHandle(STD_OUTPUT_HANDLE);//获得输出设备的句柄，相当获得控制台的一个接口 
	SetConsoleCursorPosition(handle,c);//定位句柄控制光标
}
void Color(int a)//控制前景颜色  百度牛皮 
{
	HANDLE  hand;//设置句柄 
	hand = GetStdHandle(STD_OUTPUT_HANDLE);//获得输出设备的句柄（接口） 
	SetConsoleTextAttribute(hand, a); //控制输出文字 
}
}
