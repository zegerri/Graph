#pragma once
#include "MyPolygon.h"
class MyPolyEllipse :public MyPolygon
{
    //重写加点
    void Add(std::vector<nPoint>& points) override;
    // 计算长度
    double compute_length(int pos)override;
    //计算面积
    double compute_Area(int pos)override;
};

