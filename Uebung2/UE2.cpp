#include "ViewPortGL.h"
#include "Square.h"

constexpr auto VIEWPORT_SIZE_X = 1000;
constexpr auto VIEWPORT_SIZE_Y = 1000;

void SquareTest() {
	ViewPortGL vp = ViewPortGL("SquareTest", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
	bool isRunning = true;
	Square redSquare = Square(255, 0, 0);
	Square greenSquare = Square(0, 255, 0);
	Square blueSquare = Square(0, 0, 255);
	while (isRunning) {
		isRunning = !vp.windowShouldClose();
		vp.clearViewPort();

		redSquare.prepare(vp, 10, 10, 5);
		greenSquare.prepare(vp, 400, 700, 50);
		blueSquare.prepare(vp, 800, 300, 100);

		vp.sendTriangles();

		vp.swapBuffers();
	}
}

int main() {
	SquareTest();
	return 0;
}