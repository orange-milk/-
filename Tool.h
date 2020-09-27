#pragma once
#ifndef _TOOLS__HH
#define _TOOLS__HH
#include"windows.h"
#include "stdafx.h"
enum COLORS {//使得使用颜色更加直观
	RED = 4,YELLOW =  6,GREEN =  2,CYAN =  3,BLUE =  1,
	PURPLE =  5,WHITE =  7,BLACK = 8 ,
};
class Tool
{
public:
	Tool();
	virtual ~Tool();
	void HideCursor();//隐藏光标下划线
	void SetWindowSize();//设定界面的大小
	void SetCursorPosition(const int x, const int y);//在对应位置设置光标位置
	void SetTextColor(int color);//设定字体的颜色
	void SetTextBackColor();//设定字体对应背景色(在选择时更改背景色使得选择结果更加直观)
	void RenewBack();
};


#endif