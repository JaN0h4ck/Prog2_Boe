#pragma once
#include "Shape.h"
#include <iostream>

class Square :
    public Shape
{
public:
    Square(int red, int green, int blue);

    void prepare(ViewPortGL& vp, int centerX, int centerY, int size);
};

