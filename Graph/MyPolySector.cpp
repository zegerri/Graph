#include "MyPolySector.h"
//��д�ӵ�
void MyPolySector::Add(std::vector<nPoint>& points)
{
    if (points.size() != 3) {
        // �������ĵ��������Ϊ3�������
        return;
    }

    // ���Բ�ĵ�
    m_lines.push_back({ points[0] });

    // ���㻡���ϵĵ�
    QPoint center = points[0].point;
    QPoint start = points[1].point;
    QPoint end = points[2].point;
    int startAngle = atan2(start.y() - center.y(), start.x() - center.x()) * 180 / PI;
    int endAngle = atan2(end.y() - center.y(), end.x() - center.x()) * 180 / PI;
    if (endAngle < startAngle) {
        endAngle += 360;
    }
}
// ���㳤��
double MyPolySector::compute_length(int pos)
{
    double result = 0.0;

    if (m_lines.size() <= pos) {
        // ��� pos ������ m_lines ��������Χ���򷵻� 0
        return result;
    }

    auto ps = m_lines.begin() + pos;
    if (ps->size() < 3) {
        // ��� m_lines[pos] �Ĵ�СС��3���������Σ����� 0
        return result;
    }

    // �������ε�Բ������
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

    // �������ε��߶γ���
    for (auto p = ps->begin() + 2; p != ps->end(); p++) {
        result += sqrt(pow(abs(p->point.x() - (p - 1)->point.x()), 2) + pow(abs(p->point.y() - (p - 1)->point.y()), 2));
    }

    return result;
}
//�������
double MyPolySector::compute_Area(int pos)
{
    double area = 0.0;

    if (m_lines.size() <= pos) {
        // ��� pos ������ m_lines ��������Χ���򷵻� 0
        return area;
    }

    auto ps = m_lines.begin() + pos;
    if (ps->size() < 3) {
        // ��� m_lines[pos] �Ĵ�СС��3���������Σ����� 0
        return area;
    }

    // �������ε�Բ�ĽǺͰ뾶
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

    // �������ε����
    area = 0.5 * radius * radius * angle;

    return area;
}