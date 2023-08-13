#include "ViewPortGL.h"
#include "Square.h"
#include "Disk.h"
#include "EquilateralTriangle.h"
#include "PulsatingAnimation.h"

constexpr auto VIEWPORT_SIZE_X = 1000;
constexpr auto VIEWPORT_SIZE_Y = 1000;
constexpr float PI = 3.141f;
constexpr float alpha = PI / 6.0f;

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

void ShapeAndAnimationTest() {
	ViewPortGL vp = ViewPortGL("All Shapes Test", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
	bool shouldClose = false;

	EquilateralTriangle yellowTriangle = EquilateralTriangle(0, 255, 255);
	Disk redDisk = Disk(255, 0, 0);
	Square blueSquare = Square(0, 0, 255);
	EquilateralTriangle greenTriangle = EquilateralTriangle(0, 255, 00);

	PulsatingAnimation anim = PulsatingAnimation(100, 700, 50, 150);

	while (!shouldClose) {
		shouldClose = vp.windowShouldClose();
		vp.clearViewPort();

		yellowTriangle.prepare(vp, 700, 700, 35);
		redDisk.prepare(vp, 499, 499, 50);
		blueSquare.prepare(vp, 40, 40, 15);

		anim.animate(vp, greenTriangle);

		vp.sendLines();
		vp.sendTriangles();

		vp.swapBuffers();
	}
}

void DrawSierpinski(ViewPortGL& vp, int centerX, int centerY, int size, int maxIter) {
	if (maxIter > 0) {
		maxIter--;
		EquilateralTriangle(255, 0, 0).prepareFaceDown(vp, centerX, centerY, size);

		int halfSize = size / 2;
		float u = (float)size * sin(alpha);
		float v = (float)size * cos(alpha);
		DrawSierpinski(vp, centerX - v, centerY + u, halfSize, maxIter);
		DrawSierpinski(vp, centerX + v, centerY + u, halfSize, maxIter);
		DrawSierpinski(vp, centerX, centerY - (halfSize + u), halfSize, maxIter);
	}
	else
		return;
}

void Sierpinski() {
	ViewPortGL vp = ViewPortGL("Sierpinski", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
	bool shouldClose = false;
	
	while (!shouldClose) {
		shouldClose = vp.windowShouldClose();
		vp.clearViewPort();

		DrawSierpinski(vp, VIEWPORT_SIZE_X / 2, VIEWPORT_SIZE_Y / 2 + VIEWPORT_SIZE_Y /2 /2, VIEWPORT_SIZE_X / 2 / 2, 6);
		vp.sendLines();

		vp.swapBuffers();
	}
}


int main() {
	//SquareTest();
	//DiskTest();
	//TriangleTest();
	//TestingAllShapes();
	//ShapeAndAnimationTest();
	Sierpinski();
	return 0;
}