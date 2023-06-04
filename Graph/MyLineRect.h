#pragma once
#include "MyLine.h"
class MyLineRect :public MyLine
{
public:
	void AddRectangle(QPoint topLeft, QPoint bottomRight);

	//重写绘制
	//void Draw(QPainter& painter, QPoint&) override;
	// 
	//计算长度
	//double compute_length(int pos);

};

