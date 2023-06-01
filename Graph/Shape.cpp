#include "Shape.h"
void Shape::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    painter.translate(_offset);
    for (int i = 0; i < judge._pointItems[_whichLayer].size(); i++) {
        _pointItems[_whichLayer][i].draw(painter);
    }
    for (int i = 0; i < _lineItems[_whichLayer].size(); i++) {
        _lineItems[_whichLayer][i].draw(painter);
    }
    for (int i = 0; i < _rectItems[_whichLayer].size(); i++) {
        _rectItems[_whichLayer][i].draw(painter);
    }
    for (int i = 0; i < _polygonItems[_whichLayer].size(); i++) {
        _polygonItems[_whichLayer][i].draw(painter);
    }
    for (int i = 0; i < _sectorItems[_whichLayer].size(); i++) {
        _lineItems[_whichLayer][i].draw(painter);
    }
    for (int i = 0; i < _ellipseItems[_whichLayer].size(); i++) {
        _ellipseItems[_whichLayer][i].draw(painter);
    }
    if (__p.size() != 0 && _isDraw) {
        switch (_drawMode)
        {
        case POINT:
            break;
        case LINE:
            painter.setPen(_penColor);
            painter.setBrush(_brushColor);
            painter.drawLine(__p[0], __p[1]);
            break;
        case POLYGON: {
            painter.setPen(_penColor);
            painter.setBrush(_brushColor);
            QVector<QPoint> ___p = __p;
            ___p.push_back(___p.first());
            painter.drawPolygon(___p);
            break; }
        case RECT:
            painter.setPen(_penColor);
            painter.setBrush(_brushColor);
            painter.drawRect(QRect(__p[0], __p[1]));
            break;
        case ELLIPSE:
            painter.setPen(_penColor);
            painter.setBrush(_brushColor);
            painter.drawEllipse(QRect(__p[0], __p[1]));
            break;
        case SECTOR:
            break;
        }
    }
    if (__p.size() != 0 && _interact && _interactMode == REGION) {
        QPen p = Qt::black;
        QVector<qreal> dashes;
        qreal space = 3;
        dashes << 5 << space << 5 << space;
        p.setDashPattern(dashes);
        painter.setPen(p);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(QRect(QPoint(__p[0]), QSize((__p[1] - __p[0]).x(), (__p[1] - __p[0]).y())));
    }
    painter.translate(-_offset);
    painter.end();
}