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
	for (int i = 0; i < Snake_Point.size(); i++) {//�߳���Ϊ��һ�����п���ֱ�ӷ��ڹ��캯����
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
		for (int i = 0; i < size; i++) {//����ÿ���ڵ㣬���Ҹ���λ��
			int x = Snake_Point.front().Get_x(), y = Snake_Point.front().Get_y();
			if (Point_Status[i] == 0) {//�ڵ�������Ӧ���
				if(y-1==17){//��ߵ���ķ���
					Point_Status[i] = 1;
				}
				Snake_Point.front().Change_xy(x + 1, y - 1); 
				if (x + 1 > 54) {
					Snake_Point.pop();//x>54�������ʾ����
					break;
				}
				if (i == 12) { Snake_Point.front().DrawSquare(); }
				Snake_Point.push(Snake_Point.front());
				Snake_Point.pop();//������������
			}
			else if (Point_Status[i] == 1) {//�ڵ��½���Ӧ���
				if(y+1==23){//��͵���ķ���
					Point_Status[i] = 0;
				}
				Snake_Point.front().Change_xy(x + 1, y + 1);
				if (x + 1 > 54) {
					Snake_Point.pop();//x>54�������ʾ����
					break;
				}
				if (i == 12) { Snake_Point.front().DrawSquare(); }
				Snake_Point.push(Snake_Point.front());
				Snake_Point.pop();//������������
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
		Point x = Point(Title_xy[i][0], Title_xy[i][1]);//����Ӧ�ڵ����
		point.push(x);
		x.~Point();
		Title_xy[i][0]--;
	}
	if (time_s-- != 0) {//ɾ��ԭ����
		std::queue<Point>point=Title();//��ȡǰһ��ʱ��ԭ����λ����Ϣ
		while (!point.empty()) {
			point.front().ClearPoint();
			point.pop();
		}
	}
	for (int i = 0; i < point.size(); i++)//���Ʊ���
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
