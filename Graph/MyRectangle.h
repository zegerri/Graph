#include"Head.h"
class MyRectangle :public QRect
{
public:
	MyRectangle() {};
	MyRectangle(QRect r, QPen p, QBrush b) :QRect(r) { pen = p; brush = b; };
	double area() { return width() * height(); }
	double length() { return height() * 2 + width() * 2; }
	void draw(QPainter& painter) {
		painter.setPen(pen);
		painter.setBrush(brush);
		painter.translate(rotatePoint);
		painter.rotate(angle);
		painter.scale(scale, scale);
		painter.translate(-rotatePoint);
		painter.drawRect(*this);
		painter.translate(rotatePoint);
		painter.scale(1 / scale, 1 / scale);
		painter.rotate(-angle);
		painter.translate(-rotatePoint);
	}
	QPen pen;
	double angle;
	QBrush brush;
	QPoint rotatePoint = QPoint((x() + width()) / 2, (y() + height()) / 2);
	double scale = 1;
};