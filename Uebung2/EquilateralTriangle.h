#pragma once
#include "Shape.h"
#include <math.h>
#include <iostream>
class EquilateralTriangle :
    public Shape
{
public:
    EquilateralTriangle(int red, int green, int blue);

    void prepare(ViewPortGL& vp, int centerX, int centerY, int size);
};

