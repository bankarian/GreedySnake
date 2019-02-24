#pragma once
#include <iostream>
using namespace std;
#ifndef SNAKE_H
#define SNAKE_H
#include <ctime>
#include <string>
#include <vector>//ʸ��������������
#include "tools.h" //  Move() POS�ṹ�� 
namespace bankarian
{ 	
class Snake
{
	private:
		vector<Pos> _array; //���� ��������
		int **_map; //��ά���鹹����ε�ͼ
		size_t  _hor; //��ͼ ��  size_t���� ����unsigned int ����һ��д�����������±�ķ�Χ 
		size_t _ver; //��ͼ ��    
		Pos _food;  //ʳ��λ�� �������� 
		int _dir; 	// ��ͷ���� 
		int _score; 
		int _speed;
		
	public://��������  finish 
		Snake(int hor=30,int ver=30,int score=0):_hor(hor),_ver(ver),_score(score)
		{ 	
			_array.reserve(sizeof(Pos)*300);//Ԥ��ռ䣬��ֹ������ʧЧ 
			_speed=0;
			_map=new int*[_hor];//��_hor�� 
			for(size_t i=0;i<_hor;i++)
			{
				_map[i]=new int [_ver];//��_ver�� 
			}	
		} 
		~Snake()  
		{//�ͷŶ�̬�ڴ� 
			for(size_t i=0;i<_hor;i++)
				delete []_map[i];
			delete []_map;
		}
	public: //��Ϸ�������� 
		void InitMap();//��ʼ��ͼ finish
		void PrintMap();//��ӡ��ͼ finish
		void BodyAfter();	//�ƶ� 
		void HeadGo();	//
		bool JudgeAlive(); //�ж��Ƿ�lose finish
		void PrintArray();//��ӡ�� 
		void ClearArray();
		void SetFood();  //����ʳ��  finish
		void Play(); //��ʼ�ƶ� ����ʳ���� 
};
}
#endif
