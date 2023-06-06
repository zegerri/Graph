#include "MyPolyEllipse.h"
//重写加点
void MyPolyEllipse::Add(std::vector<nPoint>& points)
{
    nPoint center_point;
    // 计算椭圆中心点的坐标，即长轴两端点的中点和短轴两端点的中点的中点
    center_point.point = points[0].point; // 将第一个点作为中心点
    std::vector<nPoint> ellipse_points;
    // 将中心点和长轴两端点、短轴两端点添加到vector中，按顺序保存
    ellipse_points.push_back(center_point); // 第一个点为中心点
    ellipse_points.push_back(points[1]);    // 第二个点为短轴的顶点
    ellipse_points.push_back(points[2]);    // 第三个点为长轴的顶点
    // 将vector保存到m_lines中
    m_lines.push_back(ellipse_points);
}
// 计算长度
double MyPolyEllipse::compute_length(int pos) 
{
    double result = 0.0;
    // 获取椭圆的所有端点
    auto ps = m_lines.begin() + pos;
    // 计算长轴与短轴的长度
    double a = sqrt(pow(abs(ps->at(1).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(1).point.y() - ps->at(0).point.y()), 2));
    double b = sqrt(pow(abs(ps->at(2).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(2).point.y() - ps->at(0).point.y()), 2));
    // 使用椭圆周长的近似公式计算周长
    result = PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    return result;
}
//计算面积
double MyPolyEllipse::compute_Area(int pos)
{
    // 获取椭圆的所有端点
    auto ps = m_lines.begin() + pos;
    // 计算长轴与短轴的长度
    double a = sqrt(pow(abs(ps->at(1).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(1).point.y() - ps->at(0).point.y()), 2));
    double b = sqrt(pow(abs(ps->at(2).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(2).point.y() - ps->at(0).point.y()), 2));
    // 计算椭圆面积
    double area = PI * a * b;
    return area;
}
