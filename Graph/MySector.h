#pragma once
#include"Head.h"
#include"Shape.h"

class MySector
{
public:
	MySector(QPoint p_, double angle_, double r1_, double r2_) { p = p_; angle = angle_; }
	double area;
	double length;
	QPoint p;
	double angle;
	double r1, r2;
	QPen pen;
	QBrush brush;
	double scale = 1;
};