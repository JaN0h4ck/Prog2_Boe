#include "Square.h"

Square::Square(int red, int green, int blue): Shape(red, green, blue) {}

/// <summary>
/// Prepares the Square
/// </summary>
/// <param name="vp"></param>
/// <param name="centerX"></param>
/// <param name="centerY"></param>
/// <param name="size">Half of the length of the square</param>
void Square::prepare(ViewPortGL& vp, int centerX, int centerY, int size) {
	vp.prepareBlock(centerX - size, centerY - size, 2 * size, 2 * size, red, green, blue);
}