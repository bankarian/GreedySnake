#include <iostream>
#include <Windows.h>
using namespace std;
#ifndef TOOLS_H
#define TOOLS_H
namespace bankarian
{
void Move(int ,int);
struct Pos//λ�ýṹ�� 
{
	int _x;
	int _y;
	Pos(int x = 20, int y = 40) :_x(x), _y(y) {}
};	
void Color(int a);
}
#endif
