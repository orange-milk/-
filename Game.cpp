#include "stdafx.h"
#include"time.h"
#include "Game.h"
#include"Tool.h"
#include"StartInterface.h"
#include"SelectInterface.h"
#include "Point.h"
#include"Map.h"
#include"Food.h"
#include"Snake.h"
#include<iostream>
enum Position_Key { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };
Game::Game()
{
	srand((unsigned)time(NULL));
	Rand_Num = rand();
}


Game::~Game()
{
}


bool Game::PlayGname()
{
	Tool tool;
	tool.HideCursor();
	tool.SetWindowSize();
	StartInterface StartInterface;
	StartInterface.TheEnd();
	SelectInterface SelectInterface;
	int i = SelectInterface.SelectDegree();
	system("cls");
	Map map(i);
	Snake snake(i);
	std::vector<Food>food_vector;
	Food food(Create_Rand() % 37 + 1, Create_Rand() % 37 + 1);
	food_vector.push_back(food);
	while (!food_vector.back().On_Food(snake.Snake_Body)) {//�ж�ʳ���Ƿ����
		food_vector.pop_back();
		Food food(Create_Rand() % 37 + 1, Create_Rand() % 37 + 1);
		food_vector.push_back(food);
		food.~Food();
	}
	food.~Food();
	food_vector.back().DrawFood();
	snake.Move_Snake();
	while (1) {
		snake.ChangePosition();
		if (snake.Snake_Life == false) {//��ESC���ѡ������ж�
			return 1;//����1��ʼ��һ��
		}
		if (snake.Move_Snake(food_vector.back()) == true)  {
			while (!food_vector.back().On_Food(snake.Snake_Body)) {//�ж�ʳ���Ƿ����
				food_vector.pop_back();
				Food food(Create_Rand() % 37 + 1, Create_Rand() % 37 + 1);
				food_vector.push_back(food);
				food.~Food();
			}
			food_vector.back().DrawFood();
		}
		if (snake.Snake_Life == false) {//����������ж�
			system("cls");
			tool.SetTextColor(BLUE);
			tool.SetCursorPosition(23, 10); 
			std::cout << "Game Over";
			tool.SetCursorPosition(21, 12);
			std::cout << "���ź�������߲�����";
			tool.SetCursorPosition(20, 14);
			std::cout << "������յ÷�Ϊ��";
			tool.SetCursorPosition(31, 14);
			std::cout << (snake.Snake_Body.size()-3)*10;
			tool.SetCursorPosition(22, 16);
			std::cout << "�Ƿ�����һ��";
			tool.SetCursorPosition(28, 20);
			std::cout << "�ҶԲ��������ߣ���������";
			tool.SetCursorPosition(13, 20);
			tool.SetTextBackColor();
			std::cout << "��Ϸͦ�ã�������������";
			char ch = 0;//ch��ȡ����
			int i = 100000;//�ж�λ��
			while (ch != 13) {
				ch = _getch();
				if (ch == LEFT || ch == RIGHT) {
					if (i % 2 == 0) {
						tool.SetTextColor(BLUE);
						tool.SetCursorPosition(13, 20);
						std::cout << "��Ϸͦ�ã�������������";
					}
					else {
						tool.SetTextColor(BLUE);
						tool.SetCursorPosition(28, 20);
						std::cout << "�ҶԲ��������ߣ���������";
					}
					if (ch == LEFT) {
						i--;
					}
					else if (ch == RIGHT) {
						i++;
					}
					if (i % 2 == 0) {
						tool.SetTextBackColor();
						tool.SetCursorPosition(13, 20);
						std::cout << "��Ϸͦ�ã�������������";
					}
					else {
						tool.SetTextBackColor();
						tool.SetCursorPosition(28, 20);
						std::cout << "�ҶԲ��������ߣ���������";
					}
				}
			}
			if (i % 2 == 0) {
				return 1;
			}
			else {
				exit(0);
			}
		}
	}
	while (1);
	return 0;
}


int Game::Create_Rand()
{
	return Rand_Num = (7393 * Rand_Num + 5939) % 1000000000;
}
