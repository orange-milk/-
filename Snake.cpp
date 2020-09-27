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
	std::cout << "���������߿�ʼ�ƶ�";
	this->speed = speed;
	while (1){//��ʼ���ߣ�ʹ���������᲻�������ڽ���
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
	char ch = 0;//�����������
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
		//�ڶ�Ӧ�����¸��ķ���
		if (ch == UP&&position != DOWN) { position = ch; }
		else if (ch == DOWN&&position != UP) { position = ch; }
		else if (ch == LEFT&&position != RIGHT) { position = ch; }
		else if (ch == RIGHT&&position != LEFT) { position = ch; }
	}
}

void Snake::Move_Snake()//��������ʳ���������ƶ�״��
{
	Sleep(speed);
	Point snake_back = Snake_Body[0];
	int x = Snake_Body.back().Get_x(), y = Snake_Body.back().Get_y();//��ȡ��ͷ������
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
	Snake_Body[0].ClearPoint();//������β
	for (int i = 0; i < Snake_Body.size() - 1; i++) {//������ͷ��ڵ�����
		Snake_Body[i] = Snake_Body[i + 1];
	}
	Snake_Body.back().Change_xy(x, y);//������ͷ����
	Snake_Body.back().DrawCircle();//��������ͷ
}


int Snake::Cease_Snake()//ͣ���ߵ��˶�
{
	int i = 30001;
	//ͨ��i�ж�ѡ��λ�ã�����ѡ�񲻻�����̫��Σ�����ȡһ���ϴ��м�ֵȻ����Ĥ�����ȽϷ���
	tool.SetTextColor(PURPLE);
	tool.SetCursorPosition(42, 27);//2
	std::cout << "���¿�ʼ";
	tool.SetCursorPosition(42, 29);//0
	std::cout << "�˳���Ϸ";
	tool.SetCursorPosition(42,25);//1,Ĭ��ѡ�������Ϸ
	tool.SetTextBackColor();
	std::cout << "������Ϸ";
	char ch;//ch���ڻ�ȡ��������
	bool on = false;//on�ж��Ƿ��»س�
	while (!on) {
		ch = _getch();
		if (ch == UP || ch == DOWN || ch == 13)
		{
			if (ch == 13) {//�ж��Ƿ�ѡ��
				on = true;
			}
			tool.SetTextColor(PURPLE);
			if (i % 3 == 1) {//��ԭ֮ǰѡ��
				tool.SetCursorPosition(42, 25);
				std::cout << "������Ϸ";
			}
			else if (i % 3 == 2) {
				tool.SetCursorPosition(42, 27);
				std::cout << "���¿�ʼ";
			}
			else {
				tool.SetCursorPosition(42, 29);
				std::cout << "�˳���Ϸ";
			}
			if (ch == UP) {
				i--;
			}
			else if (ch == DOWN) {
				i++;
			}
			if (i % 3 == 1) {//����ѡ��ѡ�����ɫ
				tool.SetCursorPosition(42, 25);
				tool.SetTextBackColor();
				std::cout << "������Ϸ";
			}
			else if (i % 3 == 2) {
				tool.SetCursorPosition(42, 27);
				tool.SetTextBackColor();
				std::cout << "���¿�ʼ";
			}
			else {
				tool.SetCursorPosition(42, 29);
				tool.SetTextBackColor();
				std::cout << "�˳���Ϸ";
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
	tool.SetTextColor(GREEN);//���÷���������ɫ
	tool.SetCursorPosition(46, 10);
	std::cout << std::setw(2) << (Snake_Body.size() - 3) * 10;
	tool.SetTextColor(YELLOW);//�Ļ����������ɫ
	Sleep(speed);
	Point snake_back = Snake_Body[0];
	int x = Snake_Body.back().Get_x(), y = Snake_Body.back().Get_y();//��ȡ��ͷ������
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
	if (food.Get_x() == x&&food.Get_y() == y) {//�Ӵ���ʳ���������ƶ���������
		Point point(x, y);
		Snake_Body.push_back(point);
		point.DrawCircle();
		return true;//����true��Ϊ�ɹ����󳤶�
	}
	//δ�Ӵ���ʳ���������ƶ���������
	Snake_Body[0].ClearPoint();//������β
	for (int i = 0; i < Snake_Body.size() - 1; i++) {//������ͷ��ڵ�����
		Snake_Body[i] = Snake_Body[i + 1];
	}
	Snake_Body.back().Change_xy(x, y);//������ͷ����
	Snake_Body.back().DrawCircle();//��������ͷ
	if (!On_Snake()) {
		tool.SetCursorPosition(13, 15);
		std::cout << "��զ���ˣ��㻹��";
		tool.SetCursorPosition(22, 15);
		std::cout << "s��˼����";
		for (int i = 0; i < 4; i++) {
			tool.SetCursorPosition(21, 15);
			std::cout << 3 - i;
			Sleep(1000);
		}
		Snake_Life = false;
	}
	return false;
}


bool Snake::On_Snake()//�ж��ߵ��ƶ��Ƿ����
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




