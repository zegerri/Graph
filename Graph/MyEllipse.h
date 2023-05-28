#pragma once // ��ֹͷ�ļ��ظ�����
#include "Head.h" // ��������ͷ�ļ�

class MyEllipse : public QRect // MyEllipse ��̳��� QRect ��
{
public:
	MyEllipse() {}; // Ĭ�Ϲ��캯��
	MyEllipse(QRect r, QPen p, QBrush b) : QRect(r) { pen = p; brush = b; }; // ���������캯��
    double area() { return PI * width() * height() / 4; }; // ������Բ������ķ���
    double length() { // ������Բ���ܳ��ķ���
        return 2 * PI * (width() < height() ? width() : height()) / 2 + 4 * ((width() > height() ? width() : height()) / 2 - (width() < height() ? width() : height()) / 2);
    }

    void draw(QPainter& painter) { // ������Բ�εķ���
        painter.setPen(pen); // ���û�����ɫ��������ʽ
        painter.setBrush(brush); // ���������ɫ����ʽ
        painter.translate(rotatePoint); // ƽ������ϵ����ת��
        painter.rotate(angle); //��ת����ϵ
        painter.scale(scale, scale); // ��������ϵ
        painter.translate(-rotatePoint); // ƽ������ϵ��ԭ��
        painter.drawEllipse(*this); // ������Բ��
        painter.translate(rotatePoint); // �ٴ�ƽ������ϵ����ת��
        painter.scale(1 / scale, 1 / scale); // �ָ�����ϵ���ű���
        painter.rotate(-angle); // �ָ�����ϵ��ת�Ƕ�
        painter.translate(-rotatePoint); // ƽ������ϵ��ԭ��
    }

    QPen pen; // ��Բ�α߿򻭱�
    double angle = 0; // ��Բ����ת�Ƕ�
    QPoint rotatePoint = QPoint((x() + width()) / 2, (y() + height()) / 2); // ��ת�����꣬Ĭ��Ϊ��Բ�����ĵ�
    QBrush brush; // ��Բ����仭ˢ
    double scale = 1; // ��Բ�����ű���
};