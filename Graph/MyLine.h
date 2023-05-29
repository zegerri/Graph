#pragma once
#include"Head.h"

// MyLine�࣬�̳���QLine�࣬��ʾ��άƽ���ϵ�һ���߶�
class MyLine :public QLine
{
public:
    MyLine() {};   // Ĭ�Ϲ��캯��
    MyLine(QLine l, QPen p, QBrush b) :QLine(l) { pen = p; brush = b; }  // �������Ĺ��캯�������ڳ�ʼ��MyLine����ĳ�Ա����pen��brush
    bool in(QPoint p) {   // �жϵ�p�Ƿ���MyLine����ʾ���߶���
        double x3 = p.x();
        double y3 = p.y();
        double x1 = p1().x();
        double x2 = p2().x();
        double y1 = p1().y();
        double y2 = p2().y();
        // �жϵ�p�Ƿ����߶ε�x��y�ķ�Χ�ڣ���ΧΪ10��������ڣ�������p���߶εľ��룬�������С��5�����ж��õ����߶���
        if (x3 <= ((x1 > x2 ? x1 : x2) + 10) && x3 >= ((x1 < x2 ? x1 : x2) - 10) && y3 <= ((y1 > y2 ? y1 : y2) + 10) && y3 >= ((y1 < y2 ? y1 : y2) - 10)) {
            double a = y1 - y2;
            double b = x2 - x1;
            double c = y1 * (x1 - x2) - x1 * (y1 - y2);
            double distance = abs((a * x3 + b * y3 + c)) / sqrt(a * a + b * b);
            if (distance < 5) return true;
            else return false;
        }
        else return false;
    }
    void draw(QPainter& painter) {   // ����MyLine����ʾ���߶�
        painter.setPen(pen);   // ���û���
        painter.setBrush(brush);   // ���û�ˢ
        painter.translate(rotatePoint);   // ƽ������ϵ��ʹ��ת����ΪrotatePoint
        painter.rotate(angle);   // ��ת����ϵ����ת�Ƕ�Ϊangle
        painter.scale(scale, scale);   // ��������ϵ�����ű���Ϊscale
        painter.translate(-rotatePoint);   // ƽ������ϵ��ʹ��ת���Ļص�ԭ����λ��
        painter.drawLine(*this);   // �����߶�
        painter.translate(rotatePoint);   // ƽ������ϵ��ʹ��ת����ΪrotatePoint
        painter.scale(1 / scale, 1 / scale);   // ��������ϵ�����ű���Ϊ1/scale
        painter.rotate(-angle);   // ��ת����ϵ����ת�Ƕ�Ϊ-angle
        painter.translate(-rotatePoint);   // ƽ������ϵ��ʹ��ת���Ļص�ԭ����λ��
    }
    double length() {   // ����MyLine����ʾ���߶εĳ���
        return sqrt((p1() - p2()).x() * (p1() - p2()).x() + (p1() - p2()).y() * (p1() - p2()).y());
    }
    QPen pen;   // ���ʣ����ڻ����߶�
    double angle = 0;   // ��ת�Ƕȣ����ڶ��߶ν�����ת
    QPoint rotatePoint = (p1() + p2()) / 2;   // ��ת���ģ�����ָ���߶ε���ת����
    QBrush brush;   // ��ˢ�����ڻ����߶�
    double scale = 1;   // ���ű��������ڶ��߶ν�������
};