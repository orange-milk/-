#pragma once
#include "Tool.h"
#include<conio.h>
class SelectInterface :
	public Tool
{
public:
	SelectInterface();
	~SelectInterface();
	int SelectDegree();
	void Text_xy(int Position);
};

