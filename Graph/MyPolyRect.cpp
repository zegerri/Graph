#include "MyPolyRect.h"
void MyPolyRect::AddRectangle(QPoint topLeft, QPoint bottomRight)
{
    std::vector<nPoint> points;
    points.push_back({ topLeft });
    points.push_back({ QPoint(bottomRight.x(), topLeft.y()) });
    points.push_back({ bottomRight });
    points.push_back({ QPoint(topLeft.x(), bottomRight.y()) });
    Add(points);
}

// 计算长度
double MyPolyRect::compute_length(int pos)
{
    double result = 0.0;
    auto ps = m_lines.begin() + pos; // 获取指定位置的线段
    for (auto p = ps->begin(); p != (ps->end() - 1); p++)
        result += sqrt(pow(abs(p->point.x() - (p + 1)->point.x()), 2) + pow(abs(p->point.y() - (p + 1)->point.y()), 2)); // 计算线段中每个点之间的距离并累加
    result += sqrt(pow(abs(ps->begin()->point.x() - ps->rbegin()->point.x()), 2) + pow(abs(ps->begin()->point.y() - ps->rbegin()->point.y()), 2)); // 计算线段的第一个点与最后一个点之间的距离
    result += sqrt(pow(abs(ps->rbegin()->point.x() - ps->rbegin()[1].point.x()), 2) + pow(abs(ps->rbegin()->point.y() - ps->rbegin()[1].point.y()), 2)); // 计算矩形的最后一条边的长度
    return result;
}

//计算面积
double MyPolyRect::compute_Area(int pos)
{
    auto ps = m_lines.begin() + pos; // 获取指定位置的线段
    auto topLeft = ps->front().point;
    auto bottomRight = ps->back().point;
    double width = abs(bottomRight.x() - topLeft.x());
    double height = abs(bottomRight.y() - topLeft.y());
    return width * height; // 直接返回长和宽的乘积
}
//void myFunction()
//{
//    MyPolyRect rc;
//    rc.AddRectangle(QPoint(0, 0), QPoint(5, 5)); // 添加一个矩形
//    double length = rc.compute_length(0); // 计算第一个矩形的周长
//    double area = rc.compute_Area(0); // 计算第一个矩形的面积
//}
