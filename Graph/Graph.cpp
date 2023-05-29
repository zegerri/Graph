#include "Graph.h"

Graph::Graph(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    _penColor = Qt::black;
    _brushColor = Qt::white;
    _height = 900; _width = 1500; _offset = QPoint(0, 0);
    _isDraw = false; _isPixmap = false;  _isGraphic = false;  _interact = false; _isPress = false;
    _drawMode = -1; _pixmapMode = -1; _graphicMode = -1; _interactMode = -1; _whichLayer = 0;
    _pointItems.push_back(QVector<MyPoint>{});
    _lineItems.push_back(QVector<MyLine>{});
    _rectItems.push_back(QVector<MyRectangle>{});
    _polygonItems.push_back(QVector<MyPolygon>{});
    _sectorItems.push_back(QVector<MySector>{});
    _ellipseItems.push_back(QVector<MyEllipse>{});
    setFixedSize(_width, _height);
}

Graph::~Graph()
{}
