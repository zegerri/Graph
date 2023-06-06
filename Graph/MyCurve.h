#pragma once
#include "MyLine.h"
class MyCurve : public MyLine
{
public:
    double compute_length(int pos) override;
};

