#include "stdafx.h"
#include "Point.h"


Point::Point()
	: x(0)
	, y(0)
{
}


Point::~Point()
{
}


int Point::Get_x()
{
	return this->x;
}


int Point::Get_y()
{
	return this->y;
}


void Point::Change_xy(int x,int y)
{
	this->x = x;
	this->y = y;
}



Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}


void Point::DrawCircle()
{
	tool.SetCursorPosition(x,y);
	std::cout << "●";
}


void Point::DrawSquare()
{
	tool.SetCursorPosition(x, y);
	std::cout << "■";
}


void Point::DrawStar()
{
	tool.SetCursorPosition(x, y);
	std::cout << "★";
}



void Point::DrawSpecial()//游戏地图出现后再进行构建
{
	
}


void Point::ClearPoint()
{
	tool.SetCursorPosition(x, y);
	std::cout << "  ";
}
