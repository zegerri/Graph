#pragma once
#include "MyPolygon.h"
class MyPolyEllipse :public MyPolygon
{
    //��д�ӵ�
    void Add(std::vector<nPoint>& points) override;
    // ���㳤��
    double compute_length(int pos)override;
    //�������
    double compute_Area(int pos)override;
};

