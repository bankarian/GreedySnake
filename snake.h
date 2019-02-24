#pragma once
#include <iostream>
using namespace std;
#ifndef SNAKE_H
#define SNAKE_H
#include <ctime>
#include <string>
#include <vector>//矢量容器构建蛇身
#include "tools.h" //  Move() POS结构体 
namespace bankarian
{ 	
class Snake
{
	private:
		vector<Pos> _array; //蛇身 坐标类型
		int **_map; //二维数组构造矩形地图
		size_t  _hor; //地图 行  size_t类型 就是unsigned int 的另一种写法，扩大了下标的范围 
		size_t _ver; //地图 列    
		Pos _food;  //食物位置 坐标类型 
		int _dir; 	// 蛇头方向 
		int _score; 
		int _speed;
		
	public://析构构造  finish 
		Snake(int hor=30,int ver=30,int score=0):_hor(hor),_ver(ver),_score(score)
		{ 	
			_array.reserve(sizeof(Pos)*300);//预存空间，防止迭代器失效 
			_speed=0;
			_map=new int*[_hor];//创_hor行 
			for(size_t i=0;i<_hor;i++)
			{
				_map[i]=new int [_ver];//创_ver列 
			}	
		} 
		~Snake()  
		{//释放动态内存 
			for(size_t i=0;i<_hor;i++)
				delete []_map[i];
			delete []_map;
		}
	public: //游戏操作函数 
		void InitMap();//初始地图 finish
		void PrintMap();//打印地图 finish
		void BodyAfter();	//移动 
		void HeadGo();	//
		bool JudgeAlive(); //判断是否lose finish
		void PrintArray();//打印蛇 
		void ClearArray();
		void SetFood();  //产生食物  finish
		void Play(); //开始移动 并吃食增长 
};
}
#endif
