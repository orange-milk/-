#include "stdafx.h"
#include "StartInterface.h"

StartInterface::StartInterface()
{
	ChangeTitle_xy();
	for (int i = 0; i < 13; i++) {
		Point x = Point(Snake_xy[i][0], Snake_xy[i][1]);
		Snake_Point.push(x);
		x.~Point();
	}
	tool.SetTextColor(BLUE);
	for (int i = 0; i < Snake_Point.size(); i++) {//蛇出现为第一步所有可以直接放在构造函数中
		Snake_Point.front().DrawSquare();
		Snake_Point.push(Snake_Point.front());
		Snake_Point.pop();
		Sleep(30);
	}
}
 

StartInterface::~StartInterface()
{
}


void StartInterface::Snake()
{
	if (!Snake_Point.empty()) {
		Snake_Point.front().ClearPoint();
		int size = Snake_Point.size();
		for (int i = 0; i < size; i++) {//遍历每个节点，并且更改位置
			int x = Snake_Point.front().Get_x(), y = Snake_Point.front().Get_y();
			if (Point_Status[i] == 0) {//节点上升对应情况
				if(y-1==17){//最高点更改方向
					Point_Status[i] = 1;
				}
				Snake_Point.front().Change_xy(x + 1, y - 1); 
				if (x + 1 > 54) {
					Snake_Point.pop();//x>54会出现显示错误
					break;
				}
				if (i == 12) { Snake_Point.front().DrawSquare(); }
				Snake_Point.push(Snake_Point.front());
				Snake_Point.pop();//遍历整个队列
			}
			else if (Point_Status[i] == 1) {//节点下降对应情况
				if(y+1==23){//最低点更改方向
					Point_Status[i] = 0;
				}
				Snake_Point.front().Change_xy(x + 1, y + 1);
				if (x + 1 > 54) {
					Snake_Point.pop();//x>54会出现显示错误
					break;
				}
				if (i == 12) { Snake_Point.front().DrawSquare(); }
				Snake_Point.push(Snake_Point.front());
				Snake_Point.pop();//遍历整个队列
			}
		}
		Sleep(30);
		Snake();
	}
}

std::queue<Point> StartInterface::Title()
{
	std::queue<Point>point;
	for (int i = 0; i < num_point; i++) {
		if (Title_xy[i][0] < 0) { continue; }
		Point x = Point(Title_xy[i][0], Title_xy[i][1]);//将对应节点入队
		point.push(x);
		x.~Point();
		Title_xy[i][0]--;
	}
	if (time_s-- != 0) {//删除原标题
		std::queue<Point>point=Title();//获取前一个时刻原标题位置信息
		while (!point.empty()) {
			point.front().ClearPoint();
			point.pop();
		}
	}
	for (int i = 0; i < point.size(); i++)//绘制标题
	{
		point.front().DrawSquare();
		point.push(point.front());
		point.pop();
	}
	Sleep(30);
	return point;
}


void StartInterface::ChangeTitle_xy()
{
	for (int i = 0; i < num_point; i++) {
		Title_xy[i][0]+=2;
		Title_xy[i][1]-=3;
	}
}


void StartInterface::TheEnd()
{
	Snake();
	Title();
	tool.SetTextColor(GREEN);
	tool.SetCursorPosition(20, 30);
	std::cout << "Press any key to start" << std::endl;
	tool.SetCursorPosition(20, 31);
	system("pause");
	tool.SetCursorPosition(20, 30);
	std::cout << "                      " << std::endl;
	tool.SetCursorPosition(20, 31);
	std::cout << "                       " << std::endl;
}
