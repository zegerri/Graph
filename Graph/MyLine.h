#pragma once
#include"Head.h"
#include"MyPoint.h"
#include"Shape.h"

class MyLine :public Shape
{
public:
    MyLine() {};
    ~MyLine() = default;

    //添加点集
    void Add(std::vector<nPoint>& points);
    //删除元素
    void delete_element(int pos) { m_lines.erase(m_lines.begin() + pos); };
    //获取点信息
    nPoint get_nPoint(int pos) { return m_lines.at(pos).at(0); };
    //计算长度
    double compute_length(int pos);
    //清空
    void Clear() { if (!m_lines.empty())m_lines.clear(); };
    //线数目
    int size() { return m_lines.size(); }
    //绘制
    void Draw(QPainter& painter, QPoint&) override;
    //显示所有点
    void Show_Point(QPainter& painter) override;
    //移动
    void Move(int index_i, int index_jj, QPoint& np) override;
    //修改参数
    void set_param(int pos, int x, int y, int width, QColor color)override;
    //查找临近点
    int find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points) override;
    //旋转
    void Rotate(int angle, QPoint& center);
    //缩放
    void Scale(double scale_factor, QPoint& center);
public:
    //保存
    bool write(QFile&) const;	//纯虚函数
protected:
    //将点绕中心点旋转指定角度
    QPoint rotate_point(QPoint point, QPoint center, int angle);
    //将点缩放指定比例
    QPoint scale_point(QPoint point, QPoint center, double scale_factor);
    std::vector<std::vector<nPoint>>	m_lines;
};

//class MyLine :public QLine
//{
//public:
//    MyLine() {};   // 默认构造函数
//    MyLine(QLine l, QPen p, QBrush b) :QLine(l) { pen = p; brush = b; }  // 带参数的构造函数，用于初始化MyLine对象的成员变量pen和brush
//    bool in(QPoint p) {   // 判断点p是否在MyLine所表示的线段上
//        double x3 = p.x();
//        double y3 = p.y();
//        double x1 = p1().x();
//        double x2 = p2().x();
//        double y1 = p1().y();
//        double y2 = p2().y();
//        // 判断点p是否在线段的x和y的范围内（误差范围为10），如果在，则计算点p到线段的距离，如果距离小于5，则判定该点在线段上
//        if (x3 <= ((x1 > x2 ? x1 : x2) + 10) && x3 >= ((x1 < x2 ? x1 : x2) - 10) && y3 <= ((y1 > y2 ? y1 : y2) + 10) && y3 >= ((y1 < y2 ? y1 : y2) - 10)) {
//            double a = y1 - y2;
//            double b = x2 - x1;
//            double c = y1 * (x1 - x2) - x1 * (y1 - y2);
//            double distance = abs((a * x3 + b * y3 + c)) / sqrt(a * a + b * b);
//            if (distance < 5) return true;
//            else return false;
//        }
//        else return false;
//    }
//    void draw(QPainter& painter) {   // 绘制MyLine所表示的线段
//        painter.setPen(pen);   // 设置画笔
//        painter.setBrush(brush);   // 设置画刷
//        painter.translate(rotatePoint);   // 平移坐标系，使旋转中心为rotatePoint
//        painter.rotate(angle);   // 旋转坐标系，旋转角度为angle
//        painter.scale(scale, scale);   // 缩放坐标系，缩放比例为scale
//        painter.translate(-rotatePoint);   // 平移坐标系，使旋转中心回到原来的位置
//        painter.drawLine(*this);   // 绘制线段
//        painter.translate(rotatePoint);   // 平移坐标系，使旋转中心为rotatePoint
//        painter.scale(1 / scale, 1 / scale);   // 缩放坐标系，缩放比例为1/scale
//        painter.rotate(-angle);   // 旋转坐标系，旋转角度为-angle
//        painter.translate(-rotatePoint);   // 平移坐标系，使旋转中心回到原来的位置
//    }
//    double length() {   // 计算MyLine所表示的线段的长度
//        return sqrt((p1() - p2()).x() * (p1() - p2()).x() + (p1() - p2()).y() * (p1() - p2()).y());
//    }
//    QPen pen;   // 画笔，用于绘制线段
//    double angle = 0;   // 旋转角度，用于对线段进行旋转
//    QPoint rotatePoint = (p1() + p2()) / 2;   // 旋转中心，用于指定线段的旋转中心
//    QBrush brush;   // 画刷，用于绘制线段
//    double scale = 1;   // 缩放比例，用于对线段进行缩放
//};