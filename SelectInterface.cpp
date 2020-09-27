#include "stdafx.h"
#include "SelectInterface.h"

void SelectInterface::Text_xy(int Position)//方便选择时更新text
{
	if (Position == 0) {
		SetCursorPosition(40, 26);
		std::cout << "简单模式";
	}
	else if (Position == 1) {
		SetCursorPosition(40, 28);
		std::cout << "普通模式";
	}
	else if (Position == 2) {
		SetCursorPosition(40, 30);
		std::cout << "困难模式";
	}
	else if (Position == 3) {
		SetCursorPosition(40, 32);
		std::cout << "炼狱模式";
	}
	else if (Position == 4) {
		SetCursorPosition(40, 34);
		std::cout << "退出游戏";
	}
}

SelectInterface::SelectInterface()
{
	//构建选择界面
	SetCursorPosition(5,25);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(5,26);
	std::cout << "(上下键选择,回车确认)"; 
	for (int i = 0; i < 5; i++) {
		Text_xy(i);
	}
}


SelectInterface::~SelectInterface()
{
}


int SelectInterface::SelectDegree()
{
	char select;//select负责获取键盘数据
	int i = 0;//i负责监控选择了哪一个
	SetTextBackColor();
	Text_xy(i);
	bool on = true;//on负责监控是否选中
	while (on) {
		select = _getch();
		if (select == 72) {//其实对应的字母也可以，神奇。。。
			//上移
			SetTextColor(GREEN);
			Text_xy(i);
			if (i == 0) {
				i = 4;
			}
			else {
				i--;
			}
		}
		else if (select ==80 ) {//其实对应的字母也可以，神奇。。。
			//下移
			SetTextColor(GREEN);
			Text_xy(i);
			if (i == 4) {
				i = 0;
			}
			else {
				i++;
			}
		}
		else if (select == 13) {
			//选中13为回车对应码值
			if (i == 4) { exit(0); }
			switch (i)
			{
			case 0:
				return 135;
			case 1:
				return 100;
			case 2:
				return 60;
			case 3:
				return 30;
			default:
				break;
			}
		}
		else {
			//其他输入无效
			continue;
		}
		SetTextBackColor();
		Text_xy(i);
	}
	return 0;
}
