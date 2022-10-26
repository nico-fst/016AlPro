// Zur Blatt 02 Aufgabe 02

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


void ablauf_diagram_1(){  //TODO
  double x = lies_gleitkommazahl();  // oder falls x als :in: \mathbb{N} gewünscht: lies_ganzzahl();
  x *= x;  // quadrieren
  drucke_kommazahl(x);
}

/* modulo 2 */
void ablauf_diagram_2(){  //TODO
  double x = lies_gleitkommazahl();

  while (!(x <= 1)) {  // oder: while (x > 1) => solange x größer 1:
    x -= 2;  // x um 2 verringern
  }
  drucke_kommazahl(x);
}

void programm_1() {  //TODO
  int x = lies_ganzzahl();
  int y = x;

  y += 17;
  y *= 3;
  y %= 2;  // Modulo 2, Rest bei Divion mit 2
  drucke_ganzzahl(y);
}


void programm_2() {  //TODO
  std::string text = "Das Modul Algorithmen und Programmierung ist so konzipert, dass die Konzepte und Metho-\
diken der objektorientierten Programmierung im Vordergrund stehen. Die hier vorgestellte\
Programmiersprache C++ nimmt die Rolle einer Beispielprogrammiersprache ein, in der die\
diskutierten Konzepte (meist mehr, selten weniger) nachvollziehbar und effizient umgesetzt\
sind. Das Modul soll so verstanden werden, dass es den Teilnehmer:innen im Anschluss an\
dieses Modul leicht fällt andere, objektorientierte Programmiersprachen zu erlernen. Hier soll\
man sich nur noch die Frage stellen: Wie setzten andere Programmiersprachen die wesentli-\
chen Konzepte um und was gibt es bei der Sprachsyntax zu beachten?";

  // Zählervariable i erst in for-Loop deklariert/gebraucht
  int s = 0;

  for (int i = 0; i < text.length(); i++) {
    if (text[i] == '.' || text[i] == '?' || text[i] == '!')  // oder statt || "or"
      s++;  // '.', '?' und '!'  in s zählen
    i += 1;  // opt. auch mit while-loop möglich
  }

  drucke_ganzzahl(s);
}


void programm_3() {  //TODO
  std::vector<int> zahlen = {42, 69, 420, 99, -444, 9014};

  // Zählervariable i erst in for-Loop deklariert/gebraucht
  double s = 0;
  int n = zahlen.size();
  drucke_ganzzahl(n);

  for (int i = 0; i <= n; i++) {
    s += zahlen[i];
  }  // opt. auch mit while-Schleife möglich

  drucke_kommazahl(s/(n+1));
}


void programm_4() {
  //TODO
  double x = lies_gleitkommazahl();
  double t = x;

  t *= t;  // quadrieren
  t *= x;  // quadrieren, da t == x wahr
  t *= t;
  t *= t;
  t *= x;
  t *= t;
  t *= x;
  t *= t;
  t *= t;
  t *= x;
  t *= t;  // nun t^218

  drucke_kommazahl(t);
}


int main() {
  // ablauf_diagram_1();
  // ablauf_diagram_2();
  // programm_1();
  // programm_2();
  // programm_3();
  programm_4();
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
