# Uebung 2

## Aufgabe 1

### a

Aufgabe 1 ist eigentlich sehr straightforward. Es hat eigenlich nur zwei größere Fehlerquellen:
- Konstruktor von Shape nicht im Konstruktor von Shape aufgerufen
- Size soll die 1/2\*Kantenlänge sein (Aufgabenstellung lesen!)

### b

Die *b* ist etwas komplexer, vielleicht hilft folgendes Bild zu dem Pythagoras Tipp:
![](pics/pythagoras.png?raw=true)

### c

Hier müssen wir eigentlich nur die Formeln in Programmiersprache umsetzen und ein paar linien ziehen :)

## Aufgabe 2

Wir orientieren uns an unserer Sinus Lösug aus Übung 1 (das animierte Quadrat).
Damit wir unsere Shapes nun aber auch richtig animieren können und nicht in einen "unterloop" verschwinden (was schlecht ist), müssen wir es etwas anders gestalten.
Die Idee: anstatt eine Variable hochzuwählen, nehmen wir etwas das Kontinuierlich, natürlich hochzählt, **die Zeit!**
Was muss man also tun?
- Zeit auslesen
- Zeit in Sinus Funktion rein füttern
- Shape mit Ergebnis der Sinus Funktion Analog zu Übung 1 animieren

Ist das richtig umgesetzt, kann mit dieser Methode auch mehrere Shapes gleichzeitig animieren.
Wer richtig motiviert ist, kann auch noch ein offset rein programmieren :)

## Aufgabe 3

Hier müssen wir eigentlich "nur" unsere Skills aus den vorherigen Aufgaben umsetzen.
Um ans Ziel zu kommen müssen wir sowieso erstmal eine Methode schreiben, die ein invertiertes Gleichschenkliges Dreieck zeichnet.
Als nächstes müssen wir uns überlegen die Mittelpunkte unserer Dreiecke liegen und wie wir vom jeweiligen "Mutterdreieck" zum Kind kommen.
Haben wir das erledigt müssen wir nur noch die Rekursive Funktion implementieren und eine kleine Funktion schreiben,
die aus den Koordinaten unserer Dreiecke Farbwerte macht!