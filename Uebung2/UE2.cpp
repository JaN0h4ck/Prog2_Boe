#include "ViewPortGL.h"
#include "Square.h"
#include "Disk.h"
#include "EquilateralTriangle.h"
#include "PulsatingAnimation.h"

constexpr auto VIEWPORT_SIZE_X = 1000;
constexpr auto VIEWPORT_SIZE_Y = 1000;
constexpr float PI = 3.141f;
constexpr float alpha = PI / 6.0f;

#pragma region TesterFunctions
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
#pragma endregion

#pragma region Aufgabe_3
/// <summary>
/// Calculates a corressponding color based on the shapes position in the viewport
/// </summary>
void calculateColors(int centerX, int centerY, int& red, int& green) {
	red = 255 - ((centerX * 255) / (VIEWPORT_SIZE_X - 1));
	green = 255 - ((centerY * 255) / (VIEWPORT_SIZE_Y - 1));
}

/// <summary>
/// A recursive Function prepares a Sierpinski Triangle
/// </summary>
/// <param name="size"> The distance between the center and the corners </param>
/// <param name="maxIter"> The maximum amount of Iterations to come after the current one</param>
void PrepareSierpinski(ViewPortGL& vp, int centerX, int centerY, int size, int maxIter) {
	if (maxIter > 0) {
		maxIter--;
		int red = 0, green = 0;
		calculateColors(centerX, centerY, red, green);
		EquilateralTriangle(red, green, 0).prepareFaceDown(vp, centerX, centerY, size);

		int halfSize = size / 2;
		float u = (float)size * sin(alpha);
		float v = (float)size * cos(alpha);
		PrepareSierpinski(vp, centerX - v, centerY + u, halfSize, maxIter);
		PrepareSierpinski(vp, centerX + v, centerY + u, halfSize, maxIter);
		PrepareSierpinski(vp, centerX, centerY - (halfSize + u), halfSize, maxIter);
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

		PrepareSierpinski(vp, VIEWPORT_SIZE_X / 2, VIEWPORT_SIZE_Y / 2 + VIEWPORT_SIZE_Y /2 /2, VIEWPORT_SIZE_X / 2 / 2, 6);
		vp.sendLines();

		vp.swapBuffers();
	}
}
#pragma endregion

int main() {
	//SquareTest();
	//DiskTest();
	//TriangleTest();
	//TestingAllShapes();
	//ShapeAndAnimationTest();
	Sierpinski();
	return 0;
}