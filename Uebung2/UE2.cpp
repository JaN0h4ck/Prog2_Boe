#include "ViewPortGL.h"
#include "Square.h"
#include "Disk.h"
#include "EquilateralTriangle.h"

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

void DiskTest() {
	ViewPortGL vp = ViewPortGL("CircleTest", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
	bool shouldClose = false;
	Disk redDisk = Disk(255, 0, 0);
	while (!shouldClose) {
		shouldClose = vp.windowShouldClose();
		vp.clearViewPort();

		redDisk.prepare(vp, 499, 499, 50);
		vp.sendLines();

		vp.swapBuffers();
	}
}

void TriangleTest() {
	ViewPortGL vp = ViewPortGL("TriangleTest", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
	bool shouldClose = false;
	EquilateralTriangle redTriangle = EquilateralTriangle(255, 0, 0);
	while (!shouldClose) {
		shouldClose = vp.windowShouldClose();
		vp.clearViewPort();

		redTriangle.prepare(vp, 499, 499, 50);
		vp.sendLines();

		vp.swapBuffers();
	}
}

void TestingAllShapes() {
	ViewPortGL vp = ViewPortGL("All Shapes Test", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
	bool shouldClose = false;
	EquilateralTriangle yellowTriangle = EquilateralTriangle(0, 255, 255);
	Disk redDisk = Disk(255, 0, 0);
	Square blueSquare = Square(0, 0, 255);
	EquilateralTriangle greenTriangle = EquilateralTriangle(0, 255, 00);
	while (!shouldClose) {
		shouldClose = vp.windowShouldClose();
		vp.clearViewPort();

		yellowTriangle.prepare(vp, 700, 700, 35);
		redDisk.prepare(vp, 499, 499, 50);
		blueSquare.prepare(vp, 40, 40, 15);
		greenTriangle.prepare(vp, 100, 700, 99);

		vp.sendLines();
		vp.sendTriangles();

		vp.swapBuffers();
	}
}

int main() {
	//SquareTest();
	//DiskTest();
	//TriangleTest();
	TestingAllShapes();
	return 0;
}