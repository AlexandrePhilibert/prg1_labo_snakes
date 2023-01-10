// -----------------------------------------------------------------------------------------------
// Fichier        : coordonnee.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-10
// But            : Représentation d'un point sur un plan x et y.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

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
      Coordonnee position = Coordonnee::random(xMax, yMax);

      if (find(debut, fin, position) == fin) {
         *it = position;
      }
   }
}

Coordonnee Coordonnee::random(int xMax, int yMax) {
   return Coordonnee(::random(0, xMax), ::random(0, yMax));
}

// -----------------------------------------------------------------------------------------------
// region Opérateurs
// -----------------------------------------------------------------------------------------------

Coordonnee Coordonnee::operator+(Direction direction) const {
   int x = this->x;
   int y = this->y;

   switch (direction) {
      case Direction::HAUT:
         y--;
         break;
      case Direction::DROITE:
         x++;
         break;
      case Direction::BAS:
         y++;
         break;
      case Direction::GAUCHE:
         x--;
         break;
   }

   return Coordonnee(x, y);
}

Coordonnee operator+(Direction direction, const Coordonnee& position) {
   return position + direction;
}


bool Coordonnee::operator==(const Coordonnee &position) const {
   return position.x == x && position.y == y;
}

Direction& operator++(Direction& direction) {
   direction = (Direction) ((int) direction + 1);
   return direction;
}

// -----------------------------------------------------------------------------------------------
// endregion Opérateurs
// -----------------------------------------------------------------------------------------------