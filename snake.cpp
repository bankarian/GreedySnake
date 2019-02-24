#include <iostream>		//有时会有卡顿 
using namespace std;
#include "snake.h"
#define wa 9  //方便设置颜色 
#define pl 7
#define sn 14
#define fo 4
namespace bankarian
{
enum {U,R,D,L};//枚举类型 up right down left
void Snake::InitMap() //finish
{	
//cout<<"InitMap"<<endl;
	size_t i=0,j=0;
	for(i=1;i<_hor;i++){//中间空白的移动部分 
		for(j=1;j<_ver;j++){
			_map[i][j]=0;
		}
	}
	for(i=0;i<_hor;i++){//初始竖墙 
		_map[i][0]=1;
		_map[i][_ver-1]=1;
	}
	for(j=0;j<_ver;j++){
		_map[0][j]=1;
		_map[_hor-1][j]=1;
	}
} 
void Snake::PrintMap() //打印墙  finish
{
	size_t i=0,j=0;
	for(i=0;i<_hor;i++){
		for(j=0;j<_ver;j++){
			if(_map[i][j]==0)
			{ Color(pl);
				cout<<"■";
			} 
			else if(_map[i][j]==1) {
				Color(wa);
				cout<<"□";
			}

		}
		cout<<endl;	//(～￣▽￣)～ 	记得换行呀哥哥 
	}
	//打印初始蛇 
	Pos body(4,4);//初始蛇的坐标；
	_array.push_back(body);//构建第一个蛇身
	Move(body._x,body._y);//光标移动到蛇身处
	Color(sn);
	cout<<"◆"; //蛇身用o构建
	_dir=5; //初始蛇头方向为空  
}
void Snake::SetFood() //finish
{
	int x=0;
	int y=0;  //食物的坐标
	while(_map[x][y]!=0) //只在空位产生 
	{
		srand((unsigned)time(NULL));//系统定时/计数器的值作为随机种子
		while(x==0)//行要从第2个坐标开始 
		{
			x=rand()%_hor;		
		}
		while(y<2){//列要从第3个坐标开始 
			y=(2*rand())%_ver;
		} 		
	} 
	Move(y,x);
	Color(fo);
	cout<<"★";
	_food._x=y;
	_food._y=x;//存储此时食物的坐标 
}
bool Snake::JudgeAlive() // finish
{
	if(_array[0]._x>1&&_array[0]._x<(2*_ver-2)&&_array[0]._y>0&&_array[0]._y<_hor-1)//未撞墙 
	{
		for(size_t i=1;i<_array.size();i++)//判断是否与自己相撞 
		{
			if ((_array[i]._x==_array[0]._x)
				&&(_array[i]._y==_array[0]._y))
			{ 
				cout<<"Hit Youself !";
				return false;
			}
		} 
		return true;
	}
	else{
		cout<<"Hit the Wall !";
		return false;
	} 
}
void Snake::HeadGo() //Wait for Judge 
{
	switch (_dir) //方向 
	{
		case U:{//up 
			BodyAfter();
			_array[0]._y-=1; 
			break;
		}
		case D:{//down
			BodyAfter();
			_array[0]._y+=1;
			break;
		}
		case L:{//left
			BodyAfter();
			_array[0]._x-=2;
			break;
		}
		case R:{//right
			BodyAfter();
			_array[0]._x+=2;
			break;
		}
	}

}
void Snake::BodyAfter() //身体移动本质后一节覆盖前一节 Wait for Judge 
{
	for(size_t i=_array.size()-1;i>0;i--)//注意要从后往前！！  不然相当于挤成一坨~ 
	{										//这个bug找了好久（T^T） 
		_array[i]._x = _array[i - 1]._x;
		_array[i]._y = _array[i - 1]._y;
	} 
}
void Snake::ClearArray()
{
	size_t i=0;
	for(i=0;i<_array.size();i++)
	{		
		Move(_array[i]._x,_array[i]._y);
		Color(pl); 
		cout<<"■";//覆盖 
	}
}
void Snake::PrintArray() //先将原本的抹去，打印后来的 finish
{
	ClearArray();
	HeadGo();
	if(JudgeAlive())
	{
		for(size_t i=0;i<_array.size();i++)
		{
			Move(_array[i]._x,_array[i]._y);
			Color(sn);
			cout<<"◆";//打印出蛇 
		}
	}
	else{
		Move(62,8);
		cout<< "GAME OVER!(￣▽￣)~*"<<endl;
		Sleep(800);
		exit(1); 
	}
}
void Snake::Play()
{
	InitMap();
	PrintMap();
	SetFood();
	Move(62,2);
	Color(15);
	cout<<"上下左右键开始游戏" ; 
	Move(62,4);
	cout<<"Score :"<<_score;
	Move(62,5);
	cout<<"Speed :"<<_speed;
	int time=200; //移动间隔时间 
	while(1)
	{
		if(GetAsyncKeyState(VK_UP)&&_dir!=U)//windows.h 中的一个函数，判断键盘是否按下 
		{
			_dir=U;
		}
		else if(GetAsyncKeyState(VK_DOWN)&&_dir!=D)
		{
			_dir=D;
		} 
		else if(GetAsyncKeyState(VK_LEFT)&&_dir!=L)
		{
			_dir=L;
		}
		else if(GetAsyncKeyState(VK_RIGHT)&&_dir!=R)
		{
			_dir=R;
		}
		try{//检查是否正常增长 
			if(_array[0]._x==_food._x&&_array[0]._y==_food._y)//吃食 
			{
				Pos temp=_array.back();
				int len=_array.size();
				_array.push_back(temp);
					if(len==_array.size()) throw temp;
				time-=10;//速度增加 
				SetFood();
					
				_score+=10;
				Move(62,4);
				cout<<"Score :"<<_score;	
				_speed+=1;;
				Move(62,5);
				cout<<"Speed :"<<_speed;	
			} 
		}
		catch (...){
			cout<<"push_back erro"<<endl;  
		}
		PrintArray(); 
		Sleep(time);
	}
} 


}
