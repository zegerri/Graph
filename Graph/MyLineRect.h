#pragma once
#include "MyLine.h"
class MyLineRect :public MyLine
{
public:
	void AddRectangle(QPoint topLeft, QPoint bottomRight);

};

