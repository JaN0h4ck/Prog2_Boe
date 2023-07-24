#include "ViewPortGL.h"
#include <windows.h>
#include <math.h>
#include <iostream>

constexpr int VIEWPORT_SIZE_X = 1000;
constexpr int VIEWPORT_SIZE_Y = 1000;
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

#pragma region Aufgabe2

//Aufgabe 2
/*
Vorgehensweise:
- Ecken für das Quadrat ermitteln (hier bereits im Vorfeld passiert)
- Vier Linien von den Ecken aus setzen
*/
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

#pragma endregion

#pragma region Aufgabe3
/* Diese Variante von Aufgabe 3 ist etwas leichter zum "drauf kommen", aber bereits etwas unübersichtlich und nicht so schön
* da nur linear interpoliert wird
* Vorgehenheise:
* - Pivot Punkt des Quadrats verschieben, bis es in der Mitte ist
* - Gleichzeitig die Kantenlänge des Quadrates verringen
* - Ab der Mitte umgekehrt
*/
void animateBlock() {
    if (VIEWPORT_SIZE_X != VIEWPORT_SIZE_Y) {
        std::cerr << "Fehler! Der Viewport ist nicht quadratisch" << std::endl;
        return;
    }
        

    ViewPortGL vp = ViewPortGL("OpenGL Animated Block", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
    bool isRunning = true;
    bool isShrinking = false;
    int cornerY = 0;
    int cornerX = 0;
    int width = VIEWPORT_SIZE_X;

    while (isRunning) {
        isRunning = !vp.windowShouldClose();
        // Ansosten wird das Ergebnis aus dem letzten Frame nicht gelöscht und alles ist Lila
        vp.clearViewPort();

        if (isShrinking && cornerX < 499) {
            cornerX++;
            cornerY++;
            width -= 2; //Die Breite des Quadrats muss immer um 2 Schritte geändert werden, da wir den Urpsrung um je 1 in X UND Y ändern
        }
        else if (!isShrinking && cornerX >= 0) {
            cornerX--;
            cornerY--;
            width += 2;
        }
        else
            isShrinking = !isShrinking;

        vp.prepareBlock(cornerX, cornerY, width, width, 100, 0, 100);
        vp.sendTriangles();
        
        vp.swapBuffers();
    }
}

/* Anstatt linear zu Interpolieren können wir auch eine Sinus/Kosinus Funktion verwenden, um eine sauberere Animation zu erhalten.
* Vorgehensweise:
* - Maximalwert des Pivotpunktes und der Kantenlänge mit der Kosinusfunktion multiplizieren
* - Damit es sich "bewegt", der Kosinusfunktion einen Wert geben, der über Zeit steigt (oder sinkt, ist ja eigentlich egal)
* 
* Im LoeVo wird Kosinus verwendet, da diese Funktion für den Wert 0 den Wert 1 annimmt
*/
void animateBlockCosine() {
    if (VIEWPORT_SIZE_X != VIEWPORT_SIZE_Y) {
        std::cerr << "Fehler! Der Viewport ist nicht quadratisch" << std::endl;
        return;
    }

    ViewPortGL vp = ViewPortGL("OpenGL Animated Block", VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y);
    bool isRunning = true;

    // Wir geben die Maximalwerte an, da wir mit 0 schlecht interpolieren können
    int cornerY = 499;
    int cornerX = 499;
    int width = VIEWPORT_SIZE_X;

    double elapsedTime = 0;

    while (isRunning) {
        isRunning = !vp.windowShouldClose();
        vp.clearViewPort();

        double elapsedTimeRad = elapsedTime * PI / 180.0; //Die cos() funktion nimmt streng genommen nur radian Werte

        double factorCos = cos(elapsedTimeRad) * .5 + .5; // Das Ergebnis soll im Wertebereich [0, 1] liegen
        double factorNegCos = 1.0 - factorCos; // Die Kantenlänge "wächst" gegensätzlich zum Pivotpunkt
        elapsedTime += 0.1;


        vp.prepareBlock(cornerX * factorCos, cornerY * factorCos, width * factorNegCos, width * factorNegCos, 100, 0, 100);
        vp.sendTriangles();

        vp.swapBuffers();
    }
}

#pragma endregion

int main() {
    //test();
    //drawSquare();
    //animateBlock();
    animateBlockCosine();
    return 0;
}


