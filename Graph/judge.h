#pragma once
#include"Head.h"
#include"MyEllipse.h"
#include"MyLine.h"
#include"MyPoint.h"
#include"MyPolygon.h"
#include"MySector.h"
#include"MyRectangle.h"

class Judge
{
public:
    int fileModel=1;   //�ļ�ģʽ 1 - 3
    int model=1;       //1����  2ѡ��
    int lineSize=1;
    int fontSize=1;
    int r = 180 * 16;
    QColor _penColor = Qt::black;
    QColor _brushColor = Qt::white;    //��������
    QString shapeName = "����";       //��ǰ��ͼ��

    //���ݲ���
    QVector < QVector<MyPoint>>_pointItems;//��
    QVector<QVector<MyLine>> _lineItems;//��
    QVector < QVector<MyRectangle> >_rectItems;//����
    QVector < QVector<MyPolygon>> _polygonItems;//�����
    QVector < QVector< MySector>>_sectorItems;//����
    QVector < QVector<MyEllipse>>_ellipseItems;//Բ
    QVector<QPoint>__p;
    QVector<int> _sltLine;
    QVector <int> _sltRect; 
    QVector <int> _sltPolygon; 
    QVector <int> _sltEllipse; 
    QVector < int> _sltPoint;
    Judge()
    {
        _pointItems.push_back(QVector<MyPoint>{});
        _lineItems.push_back(QVector<MyLine>{});
        _rectItems.push_back(QVector<MyRectangle>{});
        _polygonItems.push_back(QVector<MyPolygon>{});
        _sectorItems.push_back(QVector<MySector>{});
        _ellipseItems.push_back(QVector<MyEllipse>{});
    }
   
};

