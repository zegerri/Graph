#pragma once
#include "MyPolygon.h"
class MyPolyRect :public MyPolygon
{
public:
	void AddRectangle(QPoint topLeft, QPoint bottomRight);
	// 计算长度
	double compute_length(int pos)override;
	//计算面积
	double compute_Area(int pos)override;

};

