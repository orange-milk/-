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
	while (!food_vector.back().On_Food(snake.Snake_Body)) {//判断食物是否合理
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
		if (snake.Snake_Life == false) {//对ESC后的选择进行判断
			return 1;//返回1开始下一次
		}
		if (snake.Move_Snake(food_vector.back()) == true)  {
			while (!food_vector.back().On_Food(snake.Snake_Body)) {//判断食物是否合理
				food_vector.pop_back();
				Food food(Create_Rand() % 37 + 1, Create_Rand() % 37 + 1);
				food_vector.push_back(food);
				food.~Food();
			}
			food_vector.back().DrawFood();
		}
		if (snake.Snake_Life == false) {//对蛇死后的判断
			system("cls");
			tool.SetTextColor(BLUE);
			tool.SetCursorPosition(23, 10); 
			std::cout << "Game Over";
			tool.SetCursorPosition(21, 12);
			std::cout << "很遗憾，你的蛇不见了";
			tool.SetCursorPosition(20, 14);
			std::cout << "你的最终得分为：";
			tool.SetCursorPosition(31, 14);
			std::cout << (snake.Snake_Body.size()-3)*10;
			tool.SetCursorPosition(22, 16);
			std::cout << "是否再来一局";
			tool.SetCursorPosition(28, 20);
			std::cout << "我对不起这条蛇，算了算了";
			tool.SetCursorPosition(13, 20);
			tool.SetTextBackColor();
			std::cout << "游戏挺好，再来体验体验";
			char ch = 0;//ch获取输入
			int i = 100000;//判断位置
			while (ch != 13) {
				ch = _getch();
				if (ch == LEFT || ch == RIGHT) {
					if (i % 2 == 0) {
						tool.SetTextColor(BLUE);
						tool.SetCursorPosition(13, 20);
						std::cout << "游戏挺好，再来体验体验";
					}
					else {
						tool.SetTextColor(BLUE);
						tool.SetCursorPosition(28, 20);
						std::cout << "我对不起这条蛇，算了算了";
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
						std::cout << "游戏挺好，再来体验体验";
					}
					else {
						tool.SetTextBackColor();
						tool.SetCursorPosition(28, 20);
						std::cout << "我对不起这条蛇，算了算了";
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
