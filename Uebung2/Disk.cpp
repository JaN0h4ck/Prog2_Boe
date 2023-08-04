#include "Disk.h"

Disk::Disk(int red, int green, int blue) : Shape(red, green, blue) {}

void Disk::prepare(ViewPortGL& vp, int centerX, int centerY, int size) {
	int radius = size;

	int PunktlinksX = centerX - radius;
	int PunktlinksY = centerY;

	int PunktrechtsX = centerX + radius;
	int PunktrechtsY = centerY;

	vp.prepareLine(PunktlinksX, PunktlinksY, PunktrechtsX, PunktrechtsY, 100, 200, 50);

	for (size_t hoehe = 1; hoehe <= radius; hoehe++)
	{
		int gesuchtelaenge = pow(radius, 2) - pow(hoehe, 2); //a^2 = c^2 - b^2
		int gesuchtelaengesqr = sqrt(gesuchtelaenge);

		int gesuchterPunktlinksX = centerX - gesuchtelaengesqr;

		int gesuchterPunktrechtsX = centerX + gesuchtelaengesqr;

		vp.prepareLine(gesuchterPunktlinksX, centerY - hoehe, gesuchterPunktrechtsX, centerY - hoehe, 100, 200, 50);

		vp.prepareLine(gesuchterPunktlinksX, centerY + hoehe, gesuchterPunktrechtsX, centerY + hoehe, 100, 200, 50);
	}
}