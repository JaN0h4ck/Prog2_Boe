#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(int red, int green, int blue) : Shape(red, green, blue) {}

void EquilateralTriangle::prepare(ViewPortGL& vp, int centerX, int centerY, int size)
{
	const float PI = 3.141;
	const float alpha = PI / 6.0f;

	for (int i = 0; i < size; i++) {
		float u = (float)(size - i) * sin(alpha);
		float v = (float)(size - i) * cos(alpha);
		vp.prepareLine(centerX - v, centerY + u, centerX + v, centerY + u, red, green, blue);
		vp.prepareLine(centerX - v, centerY + u, centerX, centerY - (size - i), red, green, blue);
		vp.prepareLine(centerX + v, centerY + u, centerX, centerY - (size - 1), red, green, blue);
	}
}
