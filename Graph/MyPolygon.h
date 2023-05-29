#pragma once
#include"Head.h"

// MyPolygon类，继承自QPolygon类，表示二维平面上的一个多边形
class MyPolygon :public QPolygon
{
public:
    MyPolygon() {};   // 默认构造函数
    MyPolygon(QPolygon p, QPen pe, QBrush b) :QPolygon(p) { pen = pe; brush = b; setR(); }   // 带参数的构造函数，用于初始化MyPolygon对象的成员变量pen、brush和rotatePoint
    void setR() {   // 计算多边形的旋转中心
        QRect r = boundingRect();   // 获取包含多边形的最小矩形
        rotatePoint = QPoint((r.x() + r.width()) / 2, (r.y() + r.height()) / 2);   // 将旋转中心设置为最小矩形的中心点
    }
    double area() {   // 计算多边形的面积
        int point_num = size();
        if (point_num < 3) return 0.0;
        double s = 0;
        for (int i = 0; i < point_num; ++i) {
            s += at(i).x() * at((i + 1) % point_num).y() - at(i).y() * at((i + 1) % point_num).x();   // 计算多边形每条边所形成的三角形面积之和
        }
        return fabs(s / 2.0);   // 返回多边形的面积，使用fabs()函数获取绝对值
    }
    double length() {   // 计算多边形的周长
        double distance = 0;
        for (int i = 0; i < size(); i++) {
            if (i == size() - 1) {
                distance += sqrt(pow(at(i).x() - at(0).x(), 2) + pow(at(i).y() - at(0).y(), 2));   // 计算多边形最后一条边和第一条边之间的距离
            }
            else distance += sqrt(pow(at(i).x() - at(i + 1).x(), 2) + pow(at(i).y() - at(i + 1).y(), 2));   // 计算多边形相邻两条边之间的距离
        }
        return distance;
    }
    void draw(QPainter& painter) {   // 绘制MyPolygon所表示的多边形
        painter.setPen(pen);   // 设置画笔
        painter.setBrush(brush);   // 设置画刷
        painter.translate(rotatePoint);   // 平移坐标系，使旋转中心为rotatePoint
        painter.rotate(angle);   // 旋转坐标系，旋转角度为angle
        painter.scale(scale, scale);   // 缩放坐标系，缩放比例为scale
        painter.translate(-rotatePoint);   // 平移坐标系，使旋转中心回到原来的位置

        painter.drawPolygon(*this);   // 绘制多边形

        painter.translate(rotatePoint);   // 平移坐标系，使旋转中心为rotatePoint
        painter.scale(1 / scale, 1 / scale);   // 缩放坐标系，缩放比例为1/scale
        painter.rotate(-angle);   // 旋转坐标系，旋转角度为-angle
        painter.translate(-rotatePoint);   // 平移坐标系，使旋转中心回到原来的位置
    }
    QPen pen;   // 画笔，用于绘制多边形
    double angle = 0;   // 旋转角度，用于对多边形进行旋转
    QPoint rotatePoint = QPoint(0, 0);   // 旋转中心，用于指定多边形的旋转中心
    QBrush brush;   // 画刷，用于绘制多边形
    double scale = 1;   // 缩放比例，用于对多边形进行缩放
};