#pragma once
#include"Head.h"
#include"MyPoint.h"
#include"Shape.h"

class MyLine :public Shape
{
public:
    MyLine() {};
    ~MyLine() = default;

    //��ӵ㼯
    void Add(std::vector<nPoint>& points);
    //ɾ��Ԫ��
    void delete_element(int pos) { m_lines.erase(m_lines.begin() + pos); };
    //��ȡ����Ϣ
    nPoint get_nPoint(int pos) { return m_lines.at(pos).at(0); };
    //���㳤��
    double compute_length(int pos);
    //���
    void Clear() { if (!m_lines.empty())m_lines.clear(); };
    //����Ŀ
    int size() { return m_lines.size(); }
    //����
    void Draw(QPainter& painter, QPoint&) override;
    //��ʾ���е�
    void Show_Point(QPainter& painter) override;
    //�ƶ�
    void Move(int index_i, int index_jj, QPoint& np) override;
    //�޸Ĳ���
    void set_param(int pos, int x, int y, int width, QColor color)override;
    //�����ٽ���
    int find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points) override;
    //��ת
    void Rotate(int angle, QPoint& center);
    //����
    void Scale(double scale_factor, QPoint& center);
public:
    //����
    bool write(QFile&) const;	//���麯��
protected:
    //���������ĵ���תָ���Ƕ�
    QPoint rotate_point(QPoint point, QPoint center, int angle);
    //��������ָ������
    QPoint scale_point(QPoint point, QPoint center, double scale_factor);
    std::vector<std::vector<nPoint>>	m_lines;
};

//class MyLine :public QLine
//{
//public:
//    MyLine() {};   // Ĭ�Ϲ��캯��
//    MyLine(QLine l, QPen p, QBrush b) :QLine(l) { pen = p; brush = b; }  // �������Ĺ��캯�������ڳ�ʼ��MyLine����ĳ�Ա����pen��brush
//    bool in(QPoint p) {   // �жϵ�p�Ƿ���MyLine����ʾ���߶���
//        double x3 = p.x();
//        double y3 = p.y();
//        double x1 = p1().x();
//        double x2 = p2().x();
//        double y1 = p1().y();
//        double y2 = p2().y();
//        // �жϵ�p�Ƿ����߶ε�x��y�ķ�Χ�ڣ���ΧΪ10��������ڣ�������p���߶εľ��룬�������С��5�����ж��õ����߶���
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
//    void draw(QPainter& painter) {   // ����MyLine����ʾ���߶�
//        painter.setPen(pen);   // ���û���
//        painter.setBrush(brush);   // ���û�ˢ
//        painter.translate(rotatePoint);   // ƽ������ϵ��ʹ��ת����ΪrotatePoint
//        painter.rotate(angle);   // ��ת����ϵ����ת�Ƕ�Ϊangle
//        painter.scale(scale, scale);   // ��������ϵ�����ű���Ϊscale
//        painter.translate(-rotatePoint);   // ƽ������ϵ��ʹ��ת���Ļص�ԭ����λ��
//        painter.drawLine(*this);   // �����߶�
//        painter.translate(rotatePoint);   // ƽ������ϵ��ʹ��ת����ΪrotatePoint
//        painter.scale(1 / scale, 1 / scale);   // ��������ϵ�����ű���Ϊ1/scale
//        painter.rotate(-angle);   // ��ת����ϵ����ת�Ƕ�Ϊ-angle
//        painter.translate(-rotatePoint);   // ƽ������ϵ��ʹ��ת���Ļص�ԭ����λ��
//    }
//    double length() {   // ����MyLine����ʾ���߶εĳ���
//        return sqrt((p1() - p2()).x() * (p1() - p2()).x() + (p1() - p2()).y() * (p1() - p2()).y());
//    }
//    QPen pen;   // ���ʣ����ڻ����߶�
//    double angle = 0;   // ��ת�Ƕȣ����ڶ��߶ν�����ת
//    QPoint rotatePoint = (p1() + p2()) / 2;   // ��ת���ģ�����ָ���߶ε���ת����
//    QBrush brush;   // ��ˢ�����ڻ����߶�
//    double scale = 1;   // ���ű��������ڶ��߶ν�������
//};