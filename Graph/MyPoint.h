#pragma once
#include"Head.h"
class MyPoint :public QPoint, public Shape
{
public:
	MyPoint(QPoint p, QPen pe, QBrush b) :QPoint(p) { pen = pe; brush = b; };
	MyPoint() {};
	void draw(QPainter& painter) {
		painter.setPen(pen);
		painter.setBrush(brush);
		painter.drawPoint(*this);
	}
	QPen pen;
	QBrush brush;
	double scale = 1;
};