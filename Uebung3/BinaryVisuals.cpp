#include "BinaryVisuals.h"
#include <limits.h>

void BinaryVisuals::prepareBit(ViewPortGL& vp, int xk, int yk, int width, int height, bool isOne) {
	if (isOne) {
		vp.prepareBlock(xk, yk, width, height, 255, 255, 255);
	}
	else {
		vp.prepareLine(xk, yk, xk + width, yk, 255, 255, 255);
		vp.prepareLine(xk, yk + height, xk + width, yk + height, 255, 255, 255);
		vp.prepareLine(xk, yk, xk, yk + height, 255, 255, 255);
		vp.prepareLine(xk + width, yk, xk + width, yk + height, 255, 255, 255);
	}
}

void BinaryVisuals::prepareRepresentation(ViewPortGL& vp, unsigned char value, int xk, int yk, int width, int height) {
	int xSpace = (vp.getXSize() - xk) / CHAR_BIT - 10;
}