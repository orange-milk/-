#pragma once
#ifndef _Point__HH
#define _Point__HH
class Point
{
private:
	int x;
private:
	int y;
public:
	Point();
	Point(int x, int y);
	~Point();
	Tool tool;
	int Get_x();
	int Get_y();
	void Change_xy(int x, int y);
	void DrawCircle();
	void DrawSquare();
	void DrawStar();
	void DrawSpecial();
	void ClearPoint();
};

#endif