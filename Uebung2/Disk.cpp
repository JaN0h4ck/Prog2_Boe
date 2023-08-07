#include "Disk.h"

Disk::Disk(int red, int green, int blue) : Shape(red, green, blue) {}

/// <summary>
/// Prepares a Disk
/// </summary>
/// <param name="vp">The Viewport the Disk is supposed to be drawn in</param>
/// <param name="centerX"></param>
/// <param name="centerY"></param>
/// <param name="size">The radius of the disk</param>
void Disk::prepare(ViewPortGL& vp, int centerX, int centerY, int size) {
	// Ein paar Deklarationen hier sind streng genommen nicht nötig, aber gut für die Lesbarkeit :)
	int radius = size;

	int PunktlinksX = centerX - radius;
	int PunktlinksY = centerY;

	int PunktrechtsX = centerX + radius;
	int PunktrechtsY = centerY;

	vp.prepareLine(PunktlinksX, PunktlinksY, PunktrechtsX, PunktrechtsY, red, green, blue);

	// Wir brauchen hier relative Koordinaten zum Ursprung, mit abosuluten Koordinaten wird das nichts
	for (size_t hoehe = 1; hoehe <= radius; hoehe++)
	{
		int gesuchtelaenge = pow(radius, 2) - pow(hoehe, 2); //a^2 = c^2 - b^2
		int gesuchtelaengesqr = sqrt(gesuchtelaenge);

		PunktlinksX = centerX - gesuchtelaengesqr;
		PunktrechtsX = centerX + gesuchtelaengesqr;

		vp.prepareLine(PunktlinksX, centerY - hoehe, PunktrechtsX, centerY - hoehe, red, green, blue);

		vp.prepareLine(PunktlinksX, centerY + hoehe, PunktrechtsX, centerY + hoehe, red, green, blue);
	}
}