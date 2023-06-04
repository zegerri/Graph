#pragma once
#include"Head.h"
#include"MyLine.h"

class MyPolygon : public MyLine
{

public:

	//重写绘制
	void Draw(QPainter& painter, QPoint&) override;
	//计算长度
	double compute_length(int pos);
	//计算面积
	double compute_Area(int pos);
	//查找临近点
	int find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points) override;

public:
	//保存
	bool write(QFile&) const;	//纯虚函数

};

//// MyPolygon类，继承自QPolygon类，表示二维平面上的一个多边形
//class MyPolygon
//{
//public:
//    MyPolygon() {};   // 默认构造函数
//    MyPolygon(QPolygon p, QPen pe, QBrush b){ pen = pe; brush = b; setR(); }   // 带参数的构造函数，用于初始化MyPolygon对象的成员变量pen、brush和rotatePoint
//    void setR() {   // 计算多边形的旋转中心
//        QRect r = poly.boundingRect();   // 获取包含多边形的最小矩形
//        rotatePoint = QPoint((r.x() + r.width()) / 2, (r.y() + r.height()) / 2);   // 将旋转中心设置为最小矩形的中心点
//    }
//    double area() {   // 计算多边形的面积
//        int point_num = poly.size();
//        if (point_num < 3) return 0.0;
//        double s = 0;
//        for (int i = 0; i < point_num; ++i) {
//            s += poly.at(i).x() * poly.at((i + 1) % point_num).y() - poly.at(i).y() * poly.at((i + 1) % point_num).x();   // 计算多边形每条边所形成的三角形面积之和
//        }
//        return fabs(s / 2.0);   // 返回多边形的面积，使用fabs()函数获取绝对值
//    }
//    double length() {   // 计算多边形的周长
//        double distance = 0;
//        for (int i = 0; i < poly.size(); i++) {
//            if (i == poly.size() - 1) {
//                distance += sqrt(pow(poly.at(i).x() - poly.at(0).x(), 2) + pow(poly.at(i).y() - poly.at(0).y(), 2));   // 计算多边形最后一条边和第一条边之间的距离
//            }
//            else distance += sqrt(pow(poly.at(i).x() - poly.at(i + 1).x(), 2) + pow(poly.at(i).y() - poly.at(i + 1).y(), 2));   // 计算多边形相邻两条边之间的距离
//        }
//        return distance;
//    }
//    void draw(QPainter& painter) {   // 绘制MyPolygon所表示的多边形
//        painter.setPen(pen);   // 设置画笔
//        painter.setBrush(brush);   // 设置画刷
//        painter.translate(rotatePoint);   // 平移坐标系，使旋转中心为rotatePoint
//        painter.rotate(angle);   // 旋转坐标系，旋转角度为angle
//        painter.scale(scale, scale);   // 缩放坐标系，缩放比例为scale
//        painter.translate(-rotatePoint);   // 平移坐标系，使旋转中心回到原来的位置
//
//        painter.translate(rotatePoint);   // 平移坐标系，使旋转中心为rotatePoint
//        painter.scale(1 / scale, 1 / scale);   // 缩放坐标系，缩放比例为1/scale
//        painter.rotate(-angle);   // 旋转坐标系，旋转角度为-angle
//        painter.translate(-rotatePoint);   // 平移坐标系，使旋转中心回到原来的位置
//    }
//    QPen pen;   // 画笔，用于绘制多边形
//    double angle = 0;   // 旋转角度，用于对多边形进行旋转
//    QPoint rotatePoint = QPoint(0, 0);   // 旋转中心，用于指定多边形的旋转中心
//    QBrush brush;   // 画刷，用于绘制多边形
//    double scale = 1;   // 缩放比例，用于对多边形进行缩放
//    QPolygon poly;
//};