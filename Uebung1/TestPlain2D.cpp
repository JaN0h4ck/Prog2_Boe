
#include "ViewPortGL.h"
#include <windows.h>
#include <math.h>
#include <iostream>

constexpr auto VIEWPORT_SIZE_X = 1000;
constexpr auto VIEWPORT_SIZE_Y = 1000;
#define PI 3.14159265

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
    ViewPortGL vp = ViewPortGL("OpenGL Square", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
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

void animateBlock() {
    if (VIEWPORT_SIZE_X != VIEWPORT_SIZE_Y)
        return;

    ViewPortGL vp = ViewPortGL("OpenGL Animated Block", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
    bool isRunning = true;
    bool isGrowing = false;
    int cornerY = 0;
    int cornerX = 0;
    int width = VIEWPORT_SIZE_X;

    while (isRunning) {
        isRunning = !vp.windowShouldClose();
        vp.clearViewPort();

        if (isGrowing && cornerX < 499) {
            cornerX++;
            cornerY++;
            width -= 2;
        }
        else if (!isGrowing && cornerX >= 0) {
            cornerX--;
            cornerY--;
            width += 2;
        }
        else
            isGrowing = !isGrowing;

        vp.prepareBlock(cornerX, cornerY, width, width, 100, 0, 100);
        vp.sendTriangles();
        
        vp.swapBuffers();
    }
}

void animateBlockCosine() {
    if (VIEWPORT_SIZE_X != VIEWPORT_SIZE_Y)
        return;

    ViewPortGL vp = ViewPortGL("OpenGL Animated Block", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
    bool isRunning = true;
    int cornerY = 499;
    int cornerX = 499;
    int width = VIEWPORT_SIZE_X;

    double elapsedTime = PI;

    while (isRunning) {
        isRunning = !vp.windowShouldClose();
        vp.clearViewPort();

        double elapsedTimeRad = elapsedTime * PI / 180.0;

        double factorCos = cos(elapsedTimeRad) * .5 + .5;
        double factorNegCos = 1.0 - factorCos;
        elapsedTime += 0.01;


        vp.prepareBlock((double)cornerX * factorCos, (double)cornerY * factorCos, (double)width * factorNegCos, (double)width * factorNegCos, 100, 0, 100);
        vp.sendTriangles();

        vp.swapBuffers();
        
        //Sleep(33);
        //std::cout << (double)cornerX * factorCos << " " << (double)cornerY * factorCos << " " << (double)width* factorNegCos << " " << (double)width* factorNegCos << std::endl;
        std::cout << factorCos << " " << factorNegCos << std::endl;
    }
}

int main() {
    //test();
    //drawSquare();
    //animateBlock();
    animateBlockCosine();
    return 0;
}


