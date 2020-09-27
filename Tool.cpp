#include "stdafx.h"
#include "Tool.h"

Tool::Tool()
{

}


Tool::~Tool()
{
}

void Tool::HideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Cursorinfo;
	GetConsoleCursorInfo(handle, &Cursorinfo);//��ȡ�����Ϣ
	Cursorinfo.bVisible = false;//���ؿ���̨���
	SetConsoleCursorInfo(handle,&Cursorinfo);//���ÿ���̨���״̬
}


void Tool::SetWindowSize()//wideΪ����highΪ��  �趨��ʾ�����С
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	HWND hWnd = GetConsoleWindow(); //���cmd���ھ��
	//RECT rc;
	//GetWindowRect(hWnd, &rc); //���cmd���ڶ�Ӧ����
							  //�ı�cmd���ڷ��
	SetWindowLongPtr(hWnd,GWL_STYLE, //����ʹ�ÿ���̨�����С�޷����ı���ͼ�γ���
		GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	//��Ϊ����漰���߿�ı䣬�������SetWindowPos��������Ч��
	//SetWindowPos(hWnd,NULL,rc.left,rc.top,rc.right - rc.left, rc.bottom - rc.top,NULL);
	SetConsoleTitle(_T("̰������Ϸ"));
	system("mode con cols=110 lines=40");
}


void Tool::SetCursorPosition(const int x, const int y)//���ƹ���λ��
{
	COORD position;
	position.X = 2*x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	//GetStdHandle()���ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ����
}


void Tool::SetTextColor(int color)//�趨������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void Tool::SetTextBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |BACKGROUND_BLUE |BACKGROUND_GREEN |BACKGROUND_RED);
}


void Tool::RenewBack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		 NULL);
}
