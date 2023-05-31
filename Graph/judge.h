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
    int fileModel=1;   //文件模式 1 - 3
    int model=1;       //1创建  2选择
    int lineSize=1;
    int fontSize=1;
    int r = 180 * 16;
    QColor _penColor = Qt::black;
    QColor _brushColor = Qt::white;    //绘制属性
    QString shapeName = "矩形";       //当前的图形

    //数据部分
    QVector < QVector<MyPoint>>_pointItems;//点
    QVector<QVector<MyLine>> _lineItems;//线
    QVector < QVector<MyRectangle> >_rectItems;//矩形
    QVector < QVector<MyPolygon>> _polygonItems;//多边形
    QVector < QVector< MySector>>_sectorItems;//扇形
    QVector < QVector<MyEllipse>>_ellipseItems;//圆
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

