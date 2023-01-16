// -----------------------------------------------------------------------------------------------
// Fichier        : serpent.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-16
// But            : Représentation d'un point sur un plan x et y.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <cstdlib> // abs

#include "coordonnee.h"
#include "annexe.h"

using namespace std;

Coordonnee::Coordonnee(int x, int y): x(x), y(y) {}

int Coordonnee::getX() const {
   return x;
}

int Coordonnee::getY() const {
   return y;
}

void Coordonnee::unique(vector<Coordonnee>::iterator debut, vector<Coordonnee>::iterator fin, int xMax, int yMax) {
   for (vector<Coordonnee>::iterator& it = debut; debut != fin; ++it) {
      Coordonnee coordonnee = Coordonnee::random(xMax, yMax);

      if (find(debut, fin, coordonnee) == fin) {
         *it = coordonnee;
      }
   }
}

Coordonnee Coordonnee::random(int xMax, int yMax) {
   return Coordonnee(::random(0, xMax), ::random(0, yMax));
}

Coordonnee Coordonnee::abs() const {
   return Coordonnee(::abs(x), ::abs(y));
}

// -----------------------------------------------------------------------------------------------
// region Opérateurs
// -----------------------------------------------------------------------------------------------

Coordonnee Coordonnee::operator+(Direction direction) const {
   int x = this->x;
   int y = this->y;

   switch (direction) {
      case Direction::NORD:
         --y;
         break;
      case Direction::EST:
         ++x;
         break;
      case Direction::SUD:
         ++y;
         break;
      case Direction::OUEST:
         --x;
         break;
   }

   return Coordonnee(x, y);
}

Coordonnee operator+(Direction direction, const Coordonnee& coordonnee) {
   return coordonnee + direction;
}

Coordonnee Coordonnee::operator-(const Coordonnee& coordonnee) const {
   return Coordonnee(x - coordonnee.x, y - coordonnee.y);
}

bool Coordonnee::operator==(const Coordonnee &coordonnee) const {
   return x ==  coordonnee.x && y == coordonnee.y;
}

Direction& operator++(Direction& direction) {
   direction = (Direction) ((int) direction + 1);
   return direction;
}

Coordonnee& Coordonnee::operator+=(Direction& direction) {
   return *this = *this + direction;
}

// -----------------------------------------------------------------------------------------------
// endregion Opérateurs
// -----------------------------------------------------------------------------------------------