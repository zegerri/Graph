#pragma once // 防止头文件重复包含
#include "Head.h" // 引用其他头文件

class MyEllipse : public QRect // MyEllipse 类继承自 QRect 类
{
public:
	MyEllipse() {}; // 默认构造函数
	MyEllipse(QRect r, QPen p, QBrush b) : QRect(r) { pen = p; brush = b; }; // 带参数构造函数
    double area() { return PI * width() * height() / 4; }; // 计算椭圆形面积的方法
    double length() { // 计算椭圆形周长的方法
        return 2 * PI * (width() < height() ? width() : height()) / 2 + 4 * ((width() > height() ? width() : height()) / 2 - (width() < height() ? width() : height()) / 2);
    }

    void draw(QPainter& painter) { // 绘制椭圆形的方法
        painter.setPen(pen); // 设置画笔颜色和线条样式
        painter.setBrush(brush); // 设置填充颜色和样式
        painter.translate(rotatePoint); // 平移坐标系到旋转点
        painter.rotate(angle); //旋转坐标系
        painter.scale(scale, scale); // 缩放坐标系
        painter.translate(-rotatePoint); // 平移坐标系回原点
        painter.drawEllipse(*this); // 绘制椭圆形
        painter.translate(rotatePoint); // 再次平移坐标系到旋转点
        painter.scale(1 / scale, 1 / scale); // 恢复坐标系缩放比例
        painter.rotate(-angle); // 恢复坐标系旋转角度
        painter.translate(-rotatePoint); // 平移坐标系回原点
    }

    QPen pen; // 椭圆形边框画笔
    double angle = 0; // 椭圆形旋转角度
    QPoint rotatePoint = QPoint((x() + width()) / 2, (y() + height()) / 2); // 旋转点坐标，默认为椭圆形中心点
    QBrush brush; // 椭圆形填充画刷
    double scale = 1; // 椭圆形缩放比例
};