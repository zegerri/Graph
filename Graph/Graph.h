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
//    //�ļ�����
//    QAction* openAction;//���ļ�--->֧��shp���Զ���txt�ļ�
//    QAction* saveAction;//�����ļ�--->�Զ���txt�ļ������ݿ�洢�ݶ�
//    void paintEvent(QPaintEvent*);//��д�����¼�
//    //��ɫ�趨
//    QAction* setPenColor;
//    QAction* setBrushColor;
//
//    //�滭����
//    QAction* drawPoint;//����
//    QAction* drawLine;//����
//    QAction* drawRect;//������
//    QAction* drawPolygon;//�������
//    QAction* drawEllipse;//��Բ
//    QAction* drawSector;//������
//
//    //���ݲ���
//    QVector < QVector<MyPoint>>_pointItems;//��
//    QVector<QVector<MyLine>> _lineItems;//��
//    QVector < QVector<MyRectangle> >_rectItems;//����
//    QVector < QVector<MyPolygon>> _polygonItems;//�����
//    QVector < QVector< MySector>>_sectorItems;//����
//    QVector < QVector<MyEllipse>>_ellipseItems;//Բ
//
//    bool _isDraw, _isPixmap, _isGraphic, _interact, _isPress;
//    int _drawMode, _pixmapMode, _graphicMode, _interactMode, _whichLayer;
//    double _height, _width;
//    QPoint _offset;
//    QColor _penColor, _brushColor;
//    QVector<QPoint>__p;
//    QVector<int> _sltLine; QVector < int> _sltRect; QVector < int> _sltPolygon; QVector < int> _sltEllipse; QVector < int> _sltPoint;
};
