#pragma once
#include "MyLine.h"
class MyLineSector : public MyLine
{
public:
    //重写加点
    void Add(std::vector<nPoint>& points) override;
    // 计算长度
    double compute_length(int pos)override;

private:
    int m_startAngle;
    int m_spanAngle;
};

