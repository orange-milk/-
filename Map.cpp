#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	tool.SetTextColor(BLUE);
	system("cls");
	/*for (int i = 0; i < 40; i++) {//ֱ��ȫ����ʾ
		if (i == 0 || i == 39) {
			for (int j = 0; j < 40; j++) {
				std::cout << "��";
			}
		}
		else {
			for (int j = 0; j < 40; j++) {
				if (j == 0 || j == 39) {
					std::cout << "��";
				}
				else {
					std::cout << "  ";
				}
			}
		}
		if (i != 39) { std::cout << std::endl; }
	}*/
	for (int i = 0; i < 40; i++) {//������ڵ���ʾ
		tool.SetCursorPosition(0, i);
		std::cout << "��";
		tool.SetCursorPosition(i, 0);
		std::cout << "��";
		Sleep(30);
	}
	for (int i = 0; i < 40; i++) {
		tool.SetCursorPosition(i, 39);
		std::cout << "��";
		tool.SetCursorPosition(39, i);
		std::cout << "��";
		Sleep(30);
	}
}


Map::~Map()
{
}


Map::Map(int i)
{
	tool.SetTextColor(BLUE);
	system("cls");
	for (int i = 0; i < 40; i++) {//������ڵ���ʾ
		tool.SetCursorPosition(0, i);
		std::cout << "��";
		tool.SetCursorPosition(i, 0);
		std::cout << "��";
		Sleep(30);
	}
	for (int i = 0; i < 40; i++) {
		tool.SetCursorPosition(i, 39);
		std::cout << "��";
		tool.SetCursorPosition(39, i);
		std::cout << "��";
		Sleep(30);
	}
	tool.SetTextColor(GREEN);
	tool.SetCursorPosition(43,0);
	std::cout << "Greedy   Snake";
	tool.SetCursorPosition(44, 2);
	std::cout << "̰������Ϸ";
	tool.SetCursorPosition(40, 4);
	std::cout << "��Ϸ�Ѷȣ�";
	switch (i)
	{
	case 135:
		tool.SetCursorPosition(45, 6);
		std::cout << "��ģʽ";
		break;
	case 100:
		tool.SetCursorPosition(45, 6);
		std::cout << "��ͨģʽ";
		break;
	case 60:
		tool.SetCursorPosition(45, 6);
		std::cout << "����ģʽ";
		break;
	case 30:
		tool.SetCursorPosition(45, 6);
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	tool.SetCursorPosition(40, 8);
	std::cout << "�÷֣�";//�������λ�ã�45,10��
	tool.SetCursorPosition(45, 14);
	std::cout << "������ƶ�";
	tool.SetCursorPosition(45, 16);
	std::cout << "ESC������ͣ";
}
