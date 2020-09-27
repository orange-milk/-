#pragma once
class Food:
	public Point
{
private:
	int x;
	int y;
public:
	Tool tool;
	Food();
	Food(int x,int y);
	~Food();
	void DrawFood();
	bool On_Food(std::vector<Point>Snake_Body);
	bool On_Food();
	void ClearFood();
	int Get_x();
	int Get_y();
};

