#pragma once
#include "MyLine.h"
class MyLineEllipse : public MyLine
{
public:
    //重写加点
    void Add(std::vector<nPoint>& points) override;
    // 计算长度
    double compute_length(int pos)override;
};

