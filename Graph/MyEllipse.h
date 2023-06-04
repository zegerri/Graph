#pragma once // ��ֹͷ�ļ��ظ�����
#include "Head.h" 
#include"Shape.h"

class MyEllipse  // MyEllipse ��̳��� QRect ��
{
public:
	//MyEllipse() {}; // Ĭ�Ϲ��캯��
	MyEllipse(QRect r, QPen p, QBrush b) { pen = p; brush = b; }; // ���������캯��
    double area() { return PI * es.width() * es.height() / 4; }; // ������Բ������ķ���
    double length() { // ������Բ���ܳ��ķ���
        return 2 * PI * (es.width() < es.height() ? es.width() : es.height()) / 2 + 4 * ((es.width() > es.height() ? es.width() : es.height()) / 2 - (es.width() < es.height() ? es.width() : es.height()) / 2);
    }

    void draw(QPainter& painter) { // ������Բ�εķ���
        painter.setPen(pen); // ���û�����ɫ��������ʽ
        painter.setBrush(brush); // ���������ɫ����ʽ
        painter.translate(rotatePoint); // ƽ������ϵ����ת��
        painter.rotate(angle); //��ת����ϵ
        painter.scale(scale, scale); // ��������ϵ
        painter.translate(-rotatePoint); // ƽ������ϵ��ԭ��

        painter.translate(rotatePoint); // �ٴ�ƽ������ϵ����ת��
        painter.scale(1 / scale, 1 / scale); // �ָ�����ϵ���ű���
        painter.rotate(-angle); // �ָ�����ϵ��ת�Ƕ�
        painter.translate(-rotatePoint); // ƽ������ϵ��ԭ��
    }

    QPen pen; // ��Բ�α߿򻭱�
    double angle = 0; // ��Բ����ת�Ƕ�
    QPoint rotatePoint = QPoint((es.x() + es.width()) / 2, (es.y() + es.height()) / 2); // ��ת�����꣬Ĭ��Ϊ��Բ�����ĵ�
    QBrush brush; // ��Բ����仭ˢ
    double scale = 1; // ��Բ�����ű���
    QRect es;
};