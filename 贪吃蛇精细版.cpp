// 贪吃蛇精细版.cpp : 定义控制台应用程序的入口点。
//
#include"Game.h"
#include"stdafx.h"
int main()
{
	bool on_game = true;//检测游戏是否退出
	while (on_game) {
		Tool tool;
		Game game;
		on_game = game.PlayGname();
		game.~Game();
		tool.SetTextColor(BLUE);
		system("cls");
	}
	return 0;
}

