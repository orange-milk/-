#include "stdafx.h"
#include "Snake.h"
#include"conio.h"
#include<iomanip>
enum Position_Key { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };
Snake::Snake()
{
	
}

Snake::Snake(int speed)
{
	tool.SetTextColor(YELLOW);
	for (int i = 0; i < 3; i++) {
		Point point;
		point.Change_xy(20, 20-i);
		Snake_Body.push_back(point);
		Snake_Body[i].DrawCircle();
		point.~Point();
	}
	tool.SetCursorPosition(16, 17);
	std::cout << "按上左右蛇开始移动";
	this->speed = speed;
	while (1){//初始化蛇，使得蛇以三结不动保持在界面
		if (_kbhit()) {
			position = _getch();
			if (position == UP || position == LEFT || position == RIGHT ) {
				tool.SetCursorPosition(16, 17);
				std::cout << "                  ";
				break;
			}
		}
	}	
}

Snake::~Snake()
{
}

void Snake::ChangePosition()
{
	char ch = 0;//检测输入数据
	if (_kbhit()) {
		ch = _getch();
		if (ch == -32) {
			ch = _getch();
		}
		if (ch == 27)//ESC
		{
			int i = Cease_Snake();
			if (i == 1) {} 
			else {
				Snake_Life = false;
			}
		}
		//在对应条件下更改方向
		if (ch == UP&&position != DOWN) { position = ch; }
		else if (ch == DOWN&&position != UP) { position = ch; }
		else if (ch == LEFT&&position != RIGHT) { position = ch; }
		else if (ch == RIGHT&&position != LEFT) { position = ch; }
	}
}

void Snake::Move_Snake()//测试在无食物条件蛇移动状况
{
	Sleep(speed);
	Point snake_back = Snake_Body[0];
	int x = Snake_Body.back().Get_x(), y = Snake_Body.back().Get_y();//获取蛇头的坐标
	switch (position)
	{
		case UP:
			y = y - 1;
			break;
		case DOWN:
			y = y + 1;
			break;
		case RIGHT:
			x = x + 1;
			break;
		case LEFT:
			x = x - 1;
			break;
		default:
			break;
	}
	Snake_Body[0].ClearPoint();//消除蛇尾
	for (int i = 0; i < Snake_Body.size() - 1; i++) {//更新蛇头外节点坐标
		Snake_Body[i] = Snake_Body[i + 1];
	}
	Snake_Body.back().Change_xy(x, y);//更新蛇头坐标
	Snake_Body.back().DrawCircle();//绘制新蛇头
}


int Snake::Cease_Snake()//停下蛇的运动
{
	int i = 30001;
	//通过i判断选中位置，由于选择不会上下太多次，所以取一个较大中间值然后求膜运算会比较方便
	tool.SetTextColor(PURPLE);
	tool.SetCursorPosition(42, 27);//2
	std::cout << "重新开始";
	tool.SetCursorPosition(42, 29);//0
	std::cout << "退出游戏";
	tool.SetCursorPosition(42,25);//1,默认选择继续游戏
	tool.SetTextBackColor();
	std::cout << "继续游戏";
	char ch;//ch用于获取键盘输入
	bool on = false;//on判断是否按下回车
	while (!on) {
		ch = _getch();
		if (ch == UP || ch == DOWN || ch == 13)
		{
			if (ch == 13) {//判断是否选中
				on = true;
			}
			tool.SetTextColor(PURPLE);
			if (i % 3 == 1) {//还原之前选项
				tool.SetCursorPosition(42, 25);
				std::cout << "继续游戏";
			}
			else if (i % 3 == 2) {
				tool.SetCursorPosition(42, 27);
				std::cout << "重新开始";
			}
			else {
				tool.SetCursorPosition(42, 29);
				std::cout << "退出游戏";
			}
			if (ch == UP) {
				i--;
			}
			else if (ch == DOWN) {
				i++;
			}
			if (i % 3 == 1) {//更改选中选中项背景色
				tool.SetCursorPosition(42, 25);
				tool.SetTextBackColor();
				std::cout << "继续游戏";
			}
			else if (i % 3 == 2) {
				tool.SetCursorPosition(42, 27);
				tool.SetTextBackColor();
				std::cout << "重新开始";
			}
			else {
				tool.SetCursorPosition(42, 29);
				tool.SetTextBackColor();
				std::cout << "退出游戏";
			}
		}
	}
	if (i % 3 == 0) {
		exit(0);
	}
	tool.SetTextColor(BLUE);
	tool.SetCursorPosition(42, 25);
	std::cout << "        ";
	tool.SetCursorPosition(42, 27);
	std::cout << "        ";
	tool.SetCursorPosition(42, 29);
	std::cout << "        ";
	return i % 3;
}


bool Snake::Move_Snake(Food food)
{
	tool.SetTextColor(GREEN);//设置分数字体颜色
	tool.SetCursorPosition(46, 10);
	std::cout << std::setw(2) << (Snake_Body.size() - 3) * 10;
	tool.SetTextColor(YELLOW);//改回蛇身体的颜色
	Sleep(speed);
	Point snake_back = Snake_Body[0];
	int x = Snake_Body.back().Get_x(), y = Snake_Body.back().Get_y();//获取蛇头的坐标
	switch (position)
	{
	case UP:
		y = y - 1;
		break;
	case DOWN:
		y = y + 1;
		break;
	case RIGHT:
		x = x + 1;
		break;
	case LEFT:
		x = x - 1;
		break;
	default:
		break;
	}
	if (food.Get_x() == x&&food.Get_y() == y) {//接触到食物条件下移动后绘制情况
		Point point(x, y);
		Snake_Body.push_back(point);
		point.DrawCircle();
		return true;//返回true则为成功增大长度
	}
	//未接触到食物条件下移动后绘制情况
	Snake_Body[0].ClearPoint();//消除蛇尾
	for (int i = 0; i < Snake_Body.size() - 1; i++) {//更新蛇头外节点坐标
		Snake_Body[i] = Snake_Body[i + 1];
	}
	Snake_Body.back().Change_xy(x, y);//更新蛇头坐标
	Snake_Body.back().DrawCircle();//绘制新蛇头
	if (!On_Snake()) {
		tool.SetCursorPosition(13, 15);
		std::cout << "蛇咋死了？你还有";
		tool.SetCursorPosition(22, 15);
		std::cout << "s反思过程";
		for (int i = 0; i < 4; i++) {
			tool.SetCursorPosition(21, 15);
			std::cout << 3 - i;
			Sleep(1000);
		}
		Snake_Life = false;
	}
	return false;
}


bool Snake::On_Snake()//判断蛇的移动是否合理
{
	int x = Snake_Body.back().Get_x(), y = Snake_Body.back().Get_y();
	for (int i = 0; i < Snake_Body.size() - 1; i++) {
		if (x == Snake_Body[i].Get_x ()&&y == Snake_Body[i].Get_y())  {
			return false;
		}
	}
	if (x == 0 || y == 0 || x == 39 || y == 39) {
		return false;
	}
	return true;
}




