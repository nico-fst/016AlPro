#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Druckt einen Text aus
void drucke_text(const std::string& text);

// Druckt eine Ganzzahl aus
void drucke_ganzzahl(int ganzzahl);

// Druckt eine Kommazahl aus
void drucke_kommazahl(double gleitkommazahl);

// Liest einen Text von der Konsole ein
std::string lies_text();

// Liest eine Ganzzahl von der Konsole ein
int lies_ganzzahl();

// Liest eine Gleitkommazahl von der Konsole ein
double lies_gleitkommazahl();


double sinus(double x) {
    // drucke_text("Zu sinussende Kommazahl: ");
    // double x = lies_gleitkommazahl();

    double sinus = 0;  // berechnet Sinus als Taylorentwicklung
    double summand = x;  // akt. Summand der Taylorentwicklung
    double zähler_helfer = 1;  // hilft beim Berechnen Nenners
    double klein = 1e-8;  // sehr kleine Zahl

    while (summand > klein || -summand > klein) { // solange |summand| > klein
        sinus += summand;
        summand = -(summand*x*x) / ((zähler_helfer + 1) * (zähler_helfer + 2));
        zähler_helfer += 2;
    }
    return sinus;
}

// Def.: https://de.wikipedia.org/wiki/Sinus_und_Kosinus
double kosinus(double x) {  // sinus(x-1) wäre auch möglich
    // drucke_text("Zu kosinussende Kommazahl: ");
    // double x = lies_gleitkommazahl();

    double kosinus = 0;
    double summand = 1; // fängt bei x^0 statt bei x^1 an
    double zähler_helfer = 0;  // fängt bei 0! statt 1! an
    double klein = 1e-8;

    while (summand > klein || -summand > klein) { 
        kosinus += summand;
        summand = -(summand*x*x) / ((zähler_helfer + 1) * (zähler_helfer + 2));
        zähler_helfer += 2;
    }
    return kosinus;
}

// Def.: https://www.mathebibel.de/tangensfunktion
double tangens(double x) {
    return (sinus(x) / cos(x));  // LAMBDA???
}

// Def.: https://de.wikipedia.org/wiki/Tangens_und_Kotangens#Beziehung_zu_Taylorreihen
double kotangens(double x) {
    return (cos(x) / sinus(x));
}

double wurzel(double x) {
    double t = x;
    double klein = 1e-8;

    while (t*t - x > klein) {  // "noch weit weg von Wurzel x", oder stattdessen t*t > x, Weil mehr fancy
        t = 0.5 * (t + x/t);
    }
    return t;
}

// ÜBERLADEN

double sinus(double x, double klein) {
    // drucke_text("Zu sinussende Kommazahl: ");
    // double x = lies_gleitkommazahl();

    double sinus = 0;  // berechnet Sinus als Taylorentwicklung
    double summand = x;  // akt. Summand der Taylorentwicklung
    double zähler_helfer = 1;  // hilft beim Berechnen Nenners
    // nicht mehr nötig: s. Übergabeparameter

    while (summand > klein || -summand > klein) { // solange |summand| > klein
        sinus += summand;
        summand = -(summand*x*x) / ((zähler_helfer + 1) * (zähler_helfer + 2));
        zähler_helfer += 2;
    }
    return sinus;
}

// Def.: https://de.wikipedia.org/wiki/Sinus_und_Kosinus
double kosinus(double x, double klein) {  // sinus(x-1) wäre auch möglich
    // drucke_text("Zu kosinussende Kommazahl: ");
    // double x = lies_gleitkommazahl();

    double kosinus = 0;
    double summand = 1; // fängt bei x^0 statt bei x^1 an
    double zähler_helfer = 0;  // fängt bei 0! statt 1! an
    // nicht mehr nötig: s. Übergabeparameter

    while (summand > klein || -summand > klein) { 
        kosinus += summand;
        summand = -(summand*x*x) / ((zähler_helfer + 1) * (zähler_helfer + 2));
        zähler_helfer += 2;
    }
    return kosinus;
}

// Def.: https://www.mathebibel.de/tangensfunktion
double tangens(double x, double klein) {
    return (sinus(x, klein) / kosinus(x, klein));  // LAMBDA???
}

// Def.: https://de.wikipedia.org/wiki/Tangens_und_Kotangens#Beziehung_zu_Taylorreihen
double kotangens(double x, double klein) {
    return (kosinus(x, klein) / sinus(x, klein));
}

double wurzel(double x, double klein) {
    double t = x;
    // klein s. Übergabeparameter

    while (t*t - x > klein) {  // "noch weit weg von Wurzel x", oder stattdessen t*t > x, Weil mehr fancy
        t = 0.5 * (t + x/t);
    }
    return t;
}



int main() {
    drucke_text("Zu sinussende und kosinussende und tangensisse und kotangense Zahl:");
    double x = lies_gleitkommazahl();
    drucke_text("Toleranzwert festlegen");
    double klein = lies_gleitkommazahl();

    std::cout << "Normale Funktionen liefern:" << std::endl;
    drucke_kommazahl(sinus(x));
    drucke_kommazahl(kosinus(x));
    drucke_kommazahl(tangens(x));
    drucke_kommazahl(kotangens(x));
    std::cout << std::endl;

    std::cout << "Überladene Funktionen mit Toleranz ca. " << std::to_string(klein) << " liefern:" << std::endl;
    drucke_kommazahl(sinus(x, klein));
    drucke_kommazahl(kosinus(x, klein));
    drucke_kommazahl(tangens(x, klein));
    drucke_kommazahl(kotangens(x, klein));


    // drucke_text("Zahl, deren Wurzel bestimmt werden soll:");
    // double x = lies_gleitkommazahl();
    // drucke_text("Näherungsweise bestimmte Wurzel:");
    // drucke_kommazahl(wurzel(x));
}

/************************************/
/*                                  */
/*   MAGIE   MAGIE   MAGIE  MAGIE   */
/*                                  */
/************************************/

void drucke_text(const std::string& text) {
  std::cout << text << std::endl;
}

void drucke_ganzzahl(int ganzzahl) {
  std::cout << std::to_string(ganzzahl) << std::endl;
}

void drucke_kommazahl(double gleitkommazahl) {
  std::cout << std::to_string(gleitkommazahl) << std::endl;
}

std::string lies_text() {
  std::string text;
  std::cin >> text;
  return text;
}

int lies_ganzzahl() {
  std::string text;
  std::cin >> text;
  int ganzzahl = 0;
  try {
    ganzzahl = std::stoi(text);
  } catch (const std::invalid_argument& e) {
    ganzzahl = -1000;
  }
  return ganzzahl;
}

double lies_gleitkommazahl() {
  std::string text;
  std::cin >> text;
  double lies_gleitkommazahl = 0.0;
  try {
    lies_gleitkommazahl = std::stod(text);
  } catch (const std::invalid_argument& e) {
    lies_gleitkommazahl = NAN; // See https://en.cppreference.com/w/cpp/numeric/math/NAN
  }
  return lies_gleitkommazahl;
}
