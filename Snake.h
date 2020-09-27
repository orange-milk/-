#pragma once
#ifndef __SNAKE__
#define __SNAKE__
class Snake
{
public:
	Tool tool;
	bool Snake_Life = true;
	int speed = 0;//记录蛇运动速度，即游戏难度
	char position = 0;//记录蛇运动的方向
	std::vector<Point>Snake_Body;//记录蛇身体数据,用容器比较方便交换坐标
	Snake();
	Snake(int speed);
	~Snake();
	void Move_Snake();//蛇在无食物条件下移动
	bool Move_Snake(Food food);//蛇在有食物条件下移动 
	int Cease_Snake();//停下蛇的运动
	bool On_Snake();//判断蛇的移动是否合理
	void ChangePosition();//更改蛇运动方向
};
#endif
