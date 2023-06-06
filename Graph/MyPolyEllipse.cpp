#include "MyPolyEllipse.h"
//��д�ӵ�
void MyPolyEllipse::Add(std::vector<nPoint>& points)
{
    nPoint center_point;
    // ������Բ���ĵ�����꣬���������˵���е�Ͷ������˵���е���е�
    center_point.point = points[0].point; // ����һ������Ϊ���ĵ�
    std::vector<nPoint> ellipse_points;
    // �����ĵ�ͳ������˵㡢�������˵���ӵ�vector�У���˳�򱣴�
    ellipse_points.push_back(center_point); // ��һ����Ϊ���ĵ�
    ellipse_points.push_back(points[1]);    // �ڶ�����Ϊ����Ķ���
    ellipse_points.push_back(points[2]);    // ��������Ϊ����Ķ���
    // ��vector���浽m_lines��
    m_lines.push_back(ellipse_points);
}
// ���㳤��
double MyPolyEllipse::compute_length(int pos) 
{
    double result = 0.0;
    // ��ȡ��Բ�����ж˵�
    auto ps = m_lines.begin() + pos;
    // ���㳤�������ĳ���
    double a = sqrt(pow(abs(ps->at(1).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(1).point.y() - ps->at(0).point.y()), 2));
    double b = sqrt(pow(abs(ps->at(2).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(2).point.y() - ps->at(0).point.y()), 2));
    // ʹ����Բ�ܳ��Ľ��ƹ�ʽ�����ܳ�
    result = PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    return result;
}
//�������
double MyPolyEllipse::compute_Area(int pos)
{
    // ��ȡ��Բ�����ж˵�
    auto ps = m_lines.begin() + pos;
    // ���㳤�������ĳ���
    double a = sqrt(pow(abs(ps->at(1).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(1).point.y() - ps->at(0).point.y()), 2));
    double b = sqrt(pow(abs(ps->at(2).point.x() - ps->at(0).point.x()), 2) + pow(abs(ps->at(2).point.y() - ps->at(0).point.y()), 2));
    // ������Բ���
    double area = PI * a * b;
    return area;
}
