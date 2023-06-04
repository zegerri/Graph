#pragma once
#include"Head.h"
#include"MyLine.h"

class MyPolygon : public MyLine
{

public:

	//��д����
	void Draw(QPainter& painter, QPoint&) override;
	//���㳤��
	double compute_length(int pos);
	//�������
	double compute_Area(int pos);
	//�����ٽ���
	int find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points) override;

public:
	//����
	bool write(QFile&) const;	//���麯��

};

//// MyPolygon�࣬�̳���QPolygon�࣬��ʾ��άƽ���ϵ�һ�������
//class MyPolygon
//{
//public:
//    MyPolygon() {};   // Ĭ�Ϲ��캯��
//    MyPolygon(QPolygon p, QPen pe, QBrush b){ pen = pe; brush = b; setR(); }   // �������Ĺ��캯�������ڳ�ʼ��MyPolygon����ĳ�Ա����pen��brush��rotatePoint
//    void setR() {   // �������ε���ת����
//        QRect r = poly.boundingRect();   // ��ȡ��������ε���С����
//        rotatePoint = QPoint((r.x() + r.width()) / 2, (r.y() + r.height()) / 2);   // ����ת��������Ϊ��С���ε����ĵ�
//    }
//    double area() {   // �������ε����
//        int point_num = poly.size();
//        if (point_num < 3) return 0.0;
//        double s = 0;
//        for (int i = 0; i < point_num; ++i) {
//            s += poly.at(i).x() * poly.at((i + 1) % point_num).y() - poly.at(i).y() * poly.at((i + 1) % point_num).x();   // ��������ÿ�������γɵ����������֮��
//        }
//        return fabs(s / 2.0);   // ���ض���ε������ʹ��fabs()������ȡ����ֵ
//    }
//    double length() {   // �������ε��ܳ�
//        double distance = 0;
//        for (int i = 0; i < poly.size(); i++) {
//            if (i == poly.size() - 1) {
//                distance += sqrt(pow(poly.at(i).x() - poly.at(0).x(), 2) + pow(poly.at(i).y() - poly.at(0).y(), 2));   // �����������һ���ߺ͵�һ����֮��ľ���
//            }
//            else distance += sqrt(pow(poly.at(i).x() - poly.at(i + 1).x(), 2) + pow(poly.at(i).y() - poly.at(i + 1).y(), 2));   // ������������������֮��ľ���
//        }
//        return distance;
//    }
//    void draw(QPainter& painter) {   // ����MyPolygon����ʾ�Ķ����
//        painter.setPen(pen);   // ���û���
//        painter.setBrush(brush);   // ���û�ˢ
//        painter.translate(rotatePoint);   // ƽ������ϵ��ʹ��ת����ΪrotatePoint
//        painter.rotate(angle);   // ��ת����ϵ����ת�Ƕ�Ϊangle
//        painter.scale(scale, scale);   // ��������ϵ�����ű���Ϊscale
//        painter.translate(-rotatePoint);   // ƽ������ϵ��ʹ��ת���Ļص�ԭ����λ��
//
//        painter.translate(rotatePoint);   // ƽ������ϵ��ʹ��ת����ΪrotatePoint
//        painter.scale(1 / scale, 1 / scale);   // ��������ϵ�����ű���Ϊ1/scale
//        painter.rotate(-angle);   // ��ת����ϵ����ת�Ƕ�Ϊ-angle
//        painter.translate(-rotatePoint);   // ƽ������ϵ��ʹ��ת���Ļص�ԭ����λ��
//    }
//    QPen pen;   // ���ʣ����ڻ��ƶ����
//    double angle = 0;   // ��ת�Ƕȣ����ڶԶ���ν�����ת
//    QPoint rotatePoint = QPoint(0, 0);   // ��ת���ģ�����ָ������ε���ת����
//    QBrush brush;   // ��ˢ�����ڻ��ƶ����
//    double scale = 1;   // ���ű��������ڶԶ���ν�������
//    QPolygon poly;
//};