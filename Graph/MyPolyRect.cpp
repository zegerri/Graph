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

// ���㳤��
double MyPolyRect::compute_length(int pos)
{
    double result = 0.0;
    auto ps = m_lines.begin() + pos; // ��ȡָ��λ�õ��߶�
    for (auto p = ps->begin(); p != (ps->end() - 1); p++)
        result += sqrt(pow(abs(p->point.x() - (p + 1)->point.x()), 2) + pow(abs(p->point.y() - (p + 1)->point.y()), 2)); // �����߶���ÿ����֮��ľ��벢�ۼ�
    result += sqrt(pow(abs(ps->begin()->point.x() - ps->rbegin()->point.x()), 2) + pow(abs(ps->begin()->point.y() - ps->rbegin()->point.y()), 2)); // �����߶εĵ�һ���������һ����֮��ľ���
    result += sqrt(pow(abs(ps->rbegin()->point.x() - ps->rbegin()[1].point.x()), 2) + pow(abs(ps->rbegin()->point.y() - ps->rbegin()[1].point.y()), 2)); // ������ε����һ���ߵĳ���
    return result;
}

//�������
double MyPolyRect::compute_Area(int pos)
{
    auto ps = m_lines.begin() + pos; // ��ȡָ��λ�õ��߶�
    auto topLeft = ps->front().point;
    auto bottomRight = ps->back().point;
    double width = abs(bottomRight.x() - topLeft.x());
    double height = abs(bottomRight.y() - topLeft.y());
    return width * height; // ֱ�ӷ��س��Ϳ�ĳ˻�
}
//void myFunction()
//{
//    MyPolyRect rc;
//    rc.AddRectangle(QPoint(0, 0), QPoint(5, 5)); // ���һ������
//    double length = rc.compute_length(0); // �����һ�����ε��ܳ�
//    double area = rc.compute_Area(0); // �����һ�����ε����
//}
