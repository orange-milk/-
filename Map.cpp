#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	tool.SetTextColor(BLUE);
	system("cls");
	/*for (int i = 0; i < 40; i++) {//直接全部显示
		if (i == 0 || i == 39) {
			for (int j = 0; j < 40; j++) {
				std::cout << "■";
			}
		}
		else {
			for (int j = 0; j < 40; j++) {
				if (j == 0 || j == 39) {
					std::cout << "■";
				}
				else {
					std::cout << "  ";
				}
			}
		}
		if (i != 39) { std::cout << std::endl; }
	}*/
	for (int i = 0; i < 40; i++) {//花里胡哨的显示
		tool.SetCursorPosition(0, i);
		std::cout << "■";
		tool.SetCursorPosition(i, 0);
		std::cout << "■";
		Sleep(30);
	}
	for (int i = 0; i < 40; i++) {
		tool.SetCursorPosition(i, 39);
		std::cout << "■";
		tool.SetCursorPosition(39, i);
		std::cout << "■";
		Sleep(30);
	}
}


Map::~Map()
{
}


Map::Map(int i)
{
	tool.SetTextColor(BLUE);
	system("cls");
	for (int i = 0; i < 40; i++) {//花里胡哨的显示
		tool.SetCursorPosition(0, i);
		std::cout << "■";
		tool.SetCursorPosition(i, 0);
		std::cout << "■";
		Sleep(30);
	}
	for (int i = 0; i < 40; i++) {
		tool.SetCursorPosition(i, 39);
		std::cout << "■";
		tool.SetCursorPosition(39, i);
		std::cout << "■";
		Sleep(30);
	}
	tool.SetTextColor(GREEN);
	tool.SetCursorPosition(43,0);
	std::cout << "Greedy   Snake";
	tool.SetCursorPosition(44, 2);
	std::cout << "贪吃蛇游戏";
	tool.SetCursorPosition(40, 4);
	std::cout << "游戏难度：";
	switch (i)
	{
	case 135:
		tool.SetCursorPosition(45, 6);
		std::cout << "简单模式";
		break;
	case 100:
		tool.SetCursorPosition(45, 6);
		std::cout << "普通模式";
		break;
	case 60:
		tool.SetCursorPosition(45, 6);
		std::cout << "困难模式";
		break;
	case 30:
		tool.SetCursorPosition(45, 6);
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	tool.SetCursorPosition(40, 8);
	std::cout << "得分：";//具体分数位置（45,10）
	tool.SetCursorPosition(45, 14);
	std::cout << "方向键移动";
	tool.SetCursorPosition(45, 16);
	std::cout << "ESC界面暂停";
}
