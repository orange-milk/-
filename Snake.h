#pragma once
#ifndef __SNAKE__
#define __SNAKE__
class Snake
{
public:
	Tool tool;
	bool Snake_Life = true;
	int speed = 0;//��¼���˶��ٶȣ�����Ϸ�Ѷ�
	char position = 0;//��¼���˶��ķ���
	std::vector<Point>Snake_Body;//��¼����������,�������ȽϷ��㽻������
	Snake();
	Snake(int speed);
	~Snake();
	void Move_Snake();//������ʳ���������ƶ�
	bool Move_Snake(Food food);//������ʳ���������ƶ� 
	int Cease_Snake();//ͣ���ߵ��˶�
	bool On_Snake();//�ж��ߵ��ƶ��Ƿ����
	void ChangePosition();//�������˶�����
};
#endif
