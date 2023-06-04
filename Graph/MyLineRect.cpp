#include "MyLineRect.h"

void MyLineRect::AddRectangle(QPoint topLeft, QPoint bottomRight) {
    std::vector<nPoint> points;
    points.push_back({ topLeft });
    points.push_back({ QPoint(bottomRight.x(), topLeft.y()) });
    points.push_back({ bottomRight });
    points.push_back({ QPoint(topLeft.x(), bottomRight.y()) });
    points.push_back({ topLeft });
    Add(points);
}