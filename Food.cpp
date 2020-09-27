#include "stdafx.h"
#include "Food.h"
#include"time.h"
Point point;
Food::Food()
{
}

Food::Food(int x,int y)
{
	this->x = x;
	this->y = y;
}

Food::~Food()
{
}



void Food::DrawFood()
{
	Point point(x, y);
	tool.SetTextColor(YELLOW);
	point.DrawStar();
	point.~Point();
}


bool Food::On_Food(std::vector<Point>Snake_Body)
{
	//�ж�������������ʳ��λ�õĺ�����,�����򷵻�true
	for (int i = 0; i < Snake_Body.size() ; i++) {
		if (x == Snake_Body[i].Get_x() && y == Snake_Body[i].Get_y()) {
			return false;
		}
	}
	if (x <= 0 || y <= 0 || x >= 39 || y >= 39) {
		return false;
	}
	return true;
}

bool Food::On_Food()
{
	//�ж�������������ʳ��λ�õĺ�����,�����򷵻�true
	if (x <= 0 || y <= 0 || x >= 39 || y >= 39) {
		return false;
	}
	return true;
}


void Food::ClearFood()
{
	Point point(x, y);
	point.ClearPoint();
	point.~Point();
}


int Food::Get_x()
{
	return x;
}



int Food::Get_y()
{
	return y;
}
