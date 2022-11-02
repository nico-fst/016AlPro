// Zur Blatt 02 Aufgabe 03

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


void alter_von_alan_turing_erraten() {
  int birthYear = 1912; //
  int currentYear = 2022; //
  int alter = currentYear - birthYear;

  int rateversuche = 0; //
  int guess = -999;
  drucke_text("Wie alt wäre Alan Turing jetzt?");
  while (guess != alter) {  // lieber do while
    drucke_text(""); //
    drucke_text("Deine Schätzung:");
    guess = lies_ganzzahl();
    rateversuche++;

    if (guess > alter)  // theoretisch {} nach if-Statement, aber bei 1 Anweisung vernachlässigbar?
      drucke_text("Nope, Alan turing wäre jetzt jünger.");
    else if (guess < alter)
      drucke_text("Ne, Alan Turing wäre jetzt älter");
    else {  // falls nicht < oder >, kann der guess nur = wie alter sein
      drucke_text("Nice, genau so alt wäre Alan Turing jetzt!");
      printf("(Funfact: Du hast übrigens %i Versuche gebraucht)\n", rateversuche);
    } 
  }
}


int main() {
  alter_von_alan_turing_erraten();
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
