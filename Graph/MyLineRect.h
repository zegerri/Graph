#pragma once
#include "MyLine.h"
class MyLineRect :public MyLine
{
public:
	void AddRectangle(QPoint topLeft, QPoint bottomRight);

	//��д����
	//void Draw(QPainter& painter, QPoint&) override;
	// 
	//���㳤��
	//double compute_length(int pos);

};

