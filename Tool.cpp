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
	GetConsoleCursorInfo(handle, &Cursorinfo);//获取光标消息
	Cursorinfo.bVisible = false;//隐藏控制台光标
	SetConsoleCursorInfo(handle,&Cursorinfo);//设置控制台光标状态
}


void Tool::SetWindowSize()//wide为长，high为高  设定显示界面大小
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	HWND hWnd = GetConsoleWindow(); //获得cmd窗口句柄
	//RECT rc;
	//GetWindowRect(hWnd, &rc); //获得cmd窗口对应矩形
							  //改变cmd窗口风格
	SetWindowLongPtr(hWnd,GWL_STYLE, //设置使得控制台界面大小无法更改避免图形出错
		GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	//因为风格涉及到边框改变，必须调用SetWindowPos，否则无效果
	//SetWindowPos(hWnd,NULL,rc.left,rc.top,rc.right - rc.left, rc.bottom - rc.top,NULL);
	SetConsoleTitle(_T("贪吃蛇游戏"));
	system("mode con cols=110 lines=40");
}


void Tool::SetCursorPosition(const int x, const int y)//控制光标的位置
{
	COORD position;
	position.X = 2*x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	//GetStdHandle()返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄。
}


void Tool::SetTextColor(int color)//设定字体颜色
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
