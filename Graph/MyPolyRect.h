#pragma once
#include "MyPolygon.h"
class MyPolyRect :public MyPolygon
{
public:
	void AddRectangle(QPoint topLeft, QPoint bottomRight);
	// ���㳤��
	double compute_length(int pos)override;
	//�������
	double compute_Area(int pos)override;

};

