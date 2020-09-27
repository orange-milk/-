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
	//判断在有蛇条件下食物位置的合理性,合理则返回true
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
	//判断在无蛇条件下食物位置的合理性,合理则返回true
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
