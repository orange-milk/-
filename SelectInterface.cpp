#include "stdafx.h"
#include "SelectInterface.h"

void SelectInterface::Text_xy(int Position)//����ѡ��ʱ����text
{
	if (Position == 0) {
		SetCursorPosition(40, 26);
		std::cout << "��ģʽ";
	}
	else if (Position == 1) {
		SetCursorPosition(40, 28);
		std::cout << "��ͨģʽ";
	}
	else if (Position == 2) {
		SetCursorPosition(40, 30);
		std::cout << "����ģʽ";
	}
	else if (Position == 3) {
		SetCursorPosition(40, 32);
		std::cout << "����ģʽ";
	}
	else if (Position == 4) {
		SetCursorPosition(40, 34);
		std::cout << "�˳���Ϸ";
	}
}

SelectInterface::SelectInterface()
{
	//����ѡ�����
	SetCursorPosition(5,25);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(5,26);
	std::cout << "(���¼�ѡ��,�س�ȷ��)"; 
	for (int i = 0; i < 5; i++) {
		Text_xy(i);
	}
}


SelectInterface::~SelectInterface()
{
}


int SelectInterface::SelectDegree()
{
	char select;//select�����ȡ��������
	int i = 0;//i������ѡ������һ��
	SetTextBackColor();
	Text_xy(i);
	bool on = true;//on�������Ƿ�ѡ��
	while (on) {
		select = _getch();
		if (select == 72) {//��ʵ��Ӧ����ĸҲ���ԣ����档����
			//����
			SetTextColor(GREEN);
			Text_xy(i);
			if (i == 0) {
				i = 4;
			}
			else {
				i--;
			}
		}
		else if (select ==80 ) {//��ʵ��Ӧ����ĸҲ���ԣ����档����
			//����
			SetTextColor(GREEN);
			Text_xy(i);
			if (i == 4) {
				i = 0;
			}
			else {
				i++;
			}
		}
		else if (select == 13) {
			//ѡ��13Ϊ�س���Ӧ��ֵ
			if (i == 4) { exit(0); }
			switch (i)
			{
			case 0:
				return 135;
			case 1:
				return 100;
			case 2:
				return 60;
			case 3:
				return 30;
			default:
				break;
			}
		}
		else {
			//����������Ч
			continue;
		}
		SetTextBackColor();
		Text_xy(i);
	}
	return 0;
}
