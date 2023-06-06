#include "MyPolySector.h"
//重写加点
void MyPolySector::Add(std::vector<nPoint>& points)
{
    if (points.size() != 3) {
        // 如果传入的点的数量不为3，则不添加
        return;
    }

    // 添加圆心点
    m_lines.push_back({ points[0] });

    // 计算弧线上的点
    QPoint center = points[0].point;
    QPoint start = points[1].point;
    QPoint end = points[2].point;
    int startAngle = atan2(start.y() - center.y(), start.x() - center.x()) * 180 / PI;
    int endAngle = atan2(end.y() - center.y(), end.x() - center.x()) * 180 / PI;
    if (endAngle < startAngle) {
        endAngle += 360;
    }
}
// 计算长度
double MyPolySector::compute_length(int pos)
{
    double result = 0.0;

    if (m_lines.size() <= pos) {
        // 如果 pos 超出了 m_lines 的索引范围，则返回 0
        return result;
    }

    auto ps = m_lines.begin() + pos;
    if (ps->size() < 3) {
        // 如果 m_lines[pos] 的大小小于3，则不是扇形，返回 0
        return result;
    }

    // 计算扇形的圆弧长度
    QPoint center = ps->begin()->point;
    QPoint start = (ps->begin() + 1)->point;
    QPoint end = (ps->begin() + 2)->point;
    int startAngle = atan2(start.y() - center.y(), start.x() - center.x()) * 180 / PI;
    int endAngle = atan2(end.y() - center.y(), end.x() - center.x()) * 180 / PI;
    if (endAngle < startAngle) {
        endAngle += 360;
    }
    double radius = sqrt(pow(center.x() - start.x(), 2) + pow(center.y() - start.y(), 2));
    result = 2 * PI * radius * (endAngle - startAngle) / 360;

    // 计算扇形的线段长度
    for (auto p = ps->begin() + 2; p != ps->end(); p++) {
        result += sqrt(pow(abs(p->point.x() - (p - 1)->point.x()), 2) + pow(abs(p->point.y() - (p - 1)->point.y()), 2));
    }

    return result;
}
//计算面积
double MyPolySector::compute_Area(int pos)
{
    double area = 0.0;

    if (m_lines.size() <= pos) {
        // 如果 pos 超出了 m_lines 的索引范围，则返回 0
        return area;
    }

    auto ps = m_lines.begin() + pos;
    if (ps->size() < 3) {
        // 如果 m_lines[pos] 的大小小于3，则不是扇形，返回 0
        return area;
    }

    // 计算扇形的圆心角和半径
    QPoint center = ps->begin()->point;
    QPoint start = (ps->begin() + 1)->point;
    QPoint end = (ps->begin() + 2)->point;
    double radius = sqrt(pow(center.x() - start.x(), 2) + pow(center.y() - start.y(), 2));
    double startAngle = atan2(start.y() - center.y(), start.x() - center.x());
    double endAngle = atan2(end.y() - center.y(), end.x() - center.x());
    double angle = endAngle - startAngle;
    if (angle < 0) {
        angle += 2 * PI;
    }

    // 计算扇形的面积
    area = 0.5 * radius * radius * angle;

    return area;
}