#include <iostream>		//��ʱ���п��� 
using namespace std;
#include "snake.h"
#define wa 9  //����������ɫ 
#define pl 7
#define sn 14
#define fo 4
namespace bankarian
{
enum {U,R,D,L};//ö������ up right down left
void Snake::InitMap() //finish
{	
//cout<<"InitMap"<<endl;
	size_t i=0,j=0;
	for(i=1;i<_hor;i++){//�м�հ׵��ƶ����� 
		for(j=1;j<_ver;j++){
			_map[i][j]=0;
		}
	}
	for(i=0;i<_hor;i++){//��ʼ��ǽ 
		_map[i][0]=1;
		_map[i][_ver-1]=1;
	}
	for(j=0;j<_ver;j++){
		_map[0][j]=1;
		_map[_hor-1][j]=1;
	}
} 
void Snake::PrintMap() //��ӡǽ  finish
{
	size_t i=0,j=0;
	for(i=0;i<_hor;i++){
		for(j=0;j<_ver;j++){
			if(_map[i][j]==0)
			{ Color(pl);
				cout<<"��";
			} 
			else if(_map[i][j]==1) {
				Color(wa);
				cout<<"��";
			}

		}
		cout<<endl;	//(��������)�� 	�ǵû���ѽ��� 
	}
	//��ӡ��ʼ�� 
	Pos body(4,4);//��ʼ�ߵ����ꣻ
	_array.push_back(body);//������һ������
	Move(body._x,body._y);//����ƶ�������
	Color(sn);
	cout<<"��"; //������o����
	_dir=5; //��ʼ��ͷ����Ϊ��  
}
void Snake::SetFood() //finish
{
	int x=0;
	int y=0;  //ʳ�������
	while(_map[x][y]!=0) //ֻ�ڿ�λ���� 
	{
		srand((unsigned)time(NULL));//ϵͳ��ʱ/��������ֵ��Ϊ�������
		while(x==0)//��Ҫ�ӵ�2�����꿪ʼ 
		{
			x=rand()%_hor;		
		}
		while(y<2){//��Ҫ�ӵ�3�����꿪ʼ 
			y=(2*rand())%_ver;
		} 		
	} 
	Move(y,x);
	Color(fo);
	cout<<"��";
	_food._x=y;
	_food._y=x;//�洢��ʱʳ������� 
}
bool Snake::JudgeAlive() // finish
{
	if(_array[0]._x>1&&_array[0]._x<(2*_ver-2)&&_array[0]._y>0&&_array[0]._y<_hor-1)//δײǽ 
	{
		for(size_t i=1;i<_array.size();i++)//�ж��Ƿ����Լ���ײ 
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
	switch (_dir) //���� 
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
void Snake::BodyAfter() //�����ƶ����ʺ�һ�ڸ���ǰһ�� Wait for Judge 
{
	for(size_t i=_array.size()-1;i>0;i--)//ע��Ҫ�Ӻ���ǰ����  ��Ȼ�൱�ڼ���һ��~ 
	{										//���bug���˺þã�T^T�� 
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
		cout<<"��";//���� 
	}
}
void Snake::PrintArray() //�Ƚ�ԭ����Ĩȥ����ӡ������ finish
{
	ClearArray();
	HeadGo();
	if(JudgeAlive())
	{
		for(size_t i=0;i<_array.size();i++)
		{
			Move(_array[i]._x,_array[i]._y);
			Color(sn);
			cout<<"��";//��ӡ���� 
		}
	}
	else{
		Move(62,8);
		cout<< "GAME OVER!(������)~*"<<endl;
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
	cout<<"�������Ҽ���ʼ��Ϸ" ; 
	Move(62,4);
	cout<<"Score :"<<_score;
	Move(62,5);
	cout<<"Speed :"<<_speed;
	int time=200; //�ƶ����ʱ�� 
	while(1)
	{
		if(GetAsyncKeyState(VK_UP)&&_dir!=U)//windows.h �е�һ���������жϼ����Ƿ��� 
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
		try{//����Ƿ��������� 
			if(_array[0]._x==_food._x&&_array[0]._y==_food._y)//��ʳ 
			{
				Pos temp=_array.back();
				int len=_array.size();
				_array.push_back(temp);
					if(len==_array.size()) throw temp;
				time-=10;//�ٶ����� 
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
