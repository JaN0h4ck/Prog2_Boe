#include "BinaryVisuals.h"

constexpr auto VIEWPORT_SIZE_X = 1000;
constexpr auto VIEWPORT_SIZE_Y = 1000;

void BitTest() {
	ViewPortGL vp = ViewPortGL("Bit Test", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
	bool shouldClose = false;
	BinaryVisuals myBit = BinaryVisuals();

	while (!shouldClose) {
		shouldClose = vp.windowShouldClose();

		myBit.prepareBit(vp, 499, 499, 200, 300, 1);
		myBit.prepareBit(vp, 699, 699, 200, 300, 0);

		vp.sendLines();
		vp.sendTriangles();

		vp.swapBuffers();
	}
}

int main() {
	BitTest();

	return 0;
}