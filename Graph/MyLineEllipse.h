#pragma once
#include "MyLine.h"
class MyLineEllipse : public MyLine
{
public:
    //��д�ӵ�
    void Add(std::vector<nPoint>& points) override;
    // ���㳤��
    double compute_length(int pos)override;
};

