#pragma once
#ifndef _TOOLS__HH
#define _TOOLS__HH
#include"windows.h"
#include "stdafx.h"
enum COLORS {//ʹ��ʹ����ɫ����ֱ��
	RED = 4,YELLOW =  6,GREEN =  2,CYAN =  3,BLUE =  1,
	PURPLE =  5,WHITE =  7,BLACK = 8 ,
};
class Tool
{
public:
	Tool();
	virtual ~Tool();
	void HideCursor();//���ع���»���
	void SetWindowSize();//�趨����Ĵ�С
	void SetCursorPosition(const int x, const int y);//�ڶ�Ӧλ�����ù��λ��
	void SetTextColor(int color);//�趨�������ɫ
	void SetTextBackColor();//�趨�����Ӧ����ɫ(��ѡ��ʱ���ı���ɫʹ��ѡ��������ֱ��)
	void RenewBack();
};


#endif