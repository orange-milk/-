// ̰���߾�ϸ��.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"Game.h"
#include"stdafx.h"
int main()
{
	bool on_game = true;//�����Ϸ�Ƿ��˳�
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

