#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Graph.h"
#include"Head.h"
#include"MyEllipse.h"
#include"MyLine.h"
#include"MyPoint.h"
#include"MyPolygon.h"
#include"MySector.h"
#include"MyRectangle.h"

class Graph : public QMainWindow
{
    Q_OBJECT

public:
    Graph(QWidget *parent = nullptr);
    ~Graph();
//public:
//    void saveFile();
//    void readFile();
//    void setLayer();
//    void sltGraphics(QPoint);
//    void sltGraphics(QRect);
private:
    Ui::GraphClass ui;
//    //文件操作
//    QAction* openAction;//打开文件--->支持shp，自定义txt文件
//    QAction* saveAction;//保存文件--->自定义txt文件，数据库存储暂定
//    void paintEvent(QPaintEvent*);//重写画画事件
//    //颜色设定
//    QAction* setPenColor;
//    QAction* setBrushColor;
//
//    //绘画操作
//    QAction* drawPoint;//画点
//    QAction* drawLine;//画线
//    QAction* drawRect;//画矩形
//    QAction* drawPolygon;//画多边形
//    QAction* drawEllipse;//画圆
//    QAction* drawSector;//画扇形
//
//    //数据部分
//    QVector < QVector<MyPoint>>_pointItems;//点
//    QVector<QVector<MyLine>> _lineItems;//线
//    QVector < QVector<MyRectangle> >_rectItems;//矩形
//    QVector < QVector<MyPolygon>> _polygonItems;//多边形
//    QVector < QVector< MySector>>_sectorItems;//扇形
//    QVector < QVector<MyEllipse>>_ellipseItems;//圆
//
//    bool _isDraw, _isPixmap, _isGraphic, _interact, _isPress;
//    int _drawMode, _pixmapMode, _graphicMode, _interactMode, _whichLayer;
//    double _height, _width;
//    QPoint _offset;
//    QColor _penColor, _brushColor;
//    QVector<QPoint>__p;
//    QVector<int> _sltLine; QVector < int> _sltRect; QVector < int> _sltPolygon; QVector < int> _sltEllipse; QVector < int> _sltPoint;
};
