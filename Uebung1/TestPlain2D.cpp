
#include "ViewPortGL.h"

void test() {
    ViewPortGL vp = ViewPortGL("OpenGL Plain Test", 1000, 1000);
    bool isRunning = true;
    while (isRunning) {
        isRunning = !vp.windowShouldClose();

        vp.prepareTriangle(0, 999, 999, 999, 500, 0, 200, 0, 0, 0, 0, 200, 0, 200, 0);
        vp.sendTriangles();

        vp.swapBuffers();
    }
}

void drawSquare() {
    ViewPortGL vp = ViewPortGL("OpenGL Square", 1000, 1000);
    bool isRunning = true;
    while (isRunning) {
        isRunning = !vp.windowShouldClose();

        vp.prepareLine(299, 299, 699, 299, 255, 255, 255);
        vp.prepareLine(299, 299, 299, 699, 255, 255, 255);
        vp.prepareLine(699, 299, 699, 699, 255, 255, 255);
        vp.prepareLine(299, 699, 699, 699, 255, 255, 255);
        vp.sendLines();

        vp.swapBuffers();
    }
}

int main() {
    //test();
    drawSquare();
    return 0;
}


