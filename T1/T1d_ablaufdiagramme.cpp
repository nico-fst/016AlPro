// Zur Blatt 02 Aufgabe 03

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

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




void nr4_3() {
    drucke_text("Natürliche Zahl gröper gleich 1:");
    int n = lies_ganzzahl();

    drucke_text("+");
    int x = 0;
    while (x != n) {
        drucke_text("-");
        x++;
    }
    drucke_text("+");

    int y = 0;
    while (y != n) {
        drucke_text("");

        drucke_text("|");
        int z = n - 2;
        while(z != n) {
            drucke_text("");
            z++;
        }
        drucke_text("|");

        y++;
    }
    
}

int main() {
  nr4_3();
}


