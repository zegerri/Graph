#pragma once
#include "MyPolygon.h"
class MyPolySector :public MyPolygon
{
public:
    //��д�ӵ�
    void Add(std::vector<nPoint>& points) override;
    // ���㳤��
    double compute_length(int pos)override;
    //�������
    double compute_Area(int pos)override;

private:
    int m_startAngle;
    int m_spanAngle;
};

