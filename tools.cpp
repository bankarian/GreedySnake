#include <iostream>
#include "tools.h"
using namespace std;
namespace bankarian
{
void Move(int x ,int y)//finish 
{
	COORD c;//����ṹ����� windows API�еĽṹ�壬����̨��Ļ����
	c.X = x;
	c.Y = y;

	HANDLE handle;//����һ�����
	handle = GetStdHandle(STD_OUTPUT_HANDLE);//�������豸�ľ�����൱��ÿ���̨��һ���ӿ� 
	SetConsoleCursorPosition(handle,c);//��λ������ƹ��
}
void Color(int a)//����ǰ����ɫ  �ٶ�ţƤ 
{
	HANDLE  hand;//���þ�� 
	hand = GetStdHandle(STD_OUTPUT_HANDLE);//�������豸�ľ�����ӿڣ� 
	SetConsoleTextAttribute(hand, a); //����������� 
}
}
