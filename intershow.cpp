#include <iostream>
#include "intershow.h"
#define red 4 
#define top 14
using namespace std;
namespace bankarian
{
void Inter::ClearSnake()
{
	size_t i=0;
	for(i=0;i<_snake.size();i++)
	{		
		Move(_snake[i]._x,_snake[i]._y);
		cout<<' ';//覆盖 
	}	
}
void Inter::Advance()
{
	for(size_t i=_snake.size()-1;i>0;i--)
	{
		_snake[i]._x=_snake[i-1]._x;
		_snake[i]._y=_snake[i-1]._y;
	}
}
void Inter::PrintSnake()
{
	for(size_t i=0;i<_snake.size();i++)
	{
		Move(_snake[i]._x,_snake[i]._y);
		Color(red);
		cout<<"■";
	}
 } 
void Inter::InterShow()
{  Color(red);
	Pos body(0,5);
	_snake.push_back(body);
	Move(0,5);
	cout<<"■";
	int i=5;
	while(i--)
	{	
		while(_snake[0]._y<9)
		{
			ClearSnake();
			if(_snake.size()<11)
			{
				Pos temp=_snake.back();
				_snake.push_back(temp);
			}
			Advance();
			_snake[0]._x+=2;
			_snake[0]._y++;//头移动 
			PrintSnake();
			Sleep(20);
		}
		while(_snake[0]._y>5)
		{
			ClearSnake();
			if(_snake.size()<13)
			{
				Pos temp=_snake.back();
				_snake.push_back(temp);
			}
			Advance();
			_snake[0]._x+=2;
			_snake[0]._y--;//头移动 
			PrintSnake();
			Sleep(20);
		}		
	}	
	while(_snake.size()>0)
	{		
		ClearSnake();
		_snake.pop_back();
		PrintSnake();
		Sleep(20);
	}		
	Move(0,6);
	cout<<"  ";
}
void Inter::PrintTopic()
{	Color(top);
	size_t i=0;
	int time=30;
	//S
	for(i=0;i<15;i++){
		Move(S[i]._x,S[i]._y);
		cout<<"■";
		Sleep(time);
	}
	//N
	for(i=0;i<19;i++)
	{
		Move(N[i]._x,N[i]._y);
		cout<<"■";
		Sleep(time);
	}
	//A	
	for(i=0;i<16;i++)
	{
		Move(A[i]._x,A[i]._y);
		cout<<"■";
		Sleep(time);
	}
	//K
	for(i=0;i<14;i++)
	{
		Move(K[i]._x,K[i]._y);
		cout<<"■";
		Sleep(time);
	}
	//E 
	for(i=0;i<16;i++)
	{
		Move(E[i]._x,E[i]._y);
		cout<<"■";
		Sleep(time);		
	}
	Move(15,15);
}

	
}
