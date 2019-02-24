#include <iostream>
#include "snake.h"
#include "intershow.h"
using namespace std;
using namespace bankarian;

int main(int argc, char** argv) 
{
	Inter _snake;
	_snake.InterShow();
	_snake.PrintTopic();
	Color(14);
	Move(18,16);
	cout<<"Created By bankarian, HNU.";
	Move(18,18);
	cout<<"按任意键开始游戏 ... (￣▽￣)~*"; 
	cin.ignore();
	system("CLS");
	for(int i=3;i>0;i--)
	{
		cout<<i;
		Sleep(1000);
		system("CLS");
	}
	Snake snake;
	snake.Play();
	return 0;
}
