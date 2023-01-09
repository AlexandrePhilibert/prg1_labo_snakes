// -----------------------------------------------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <cstdlib>

#include "fenetre.h"

using namespace std;

int main() {
   const char nomFenetre[] = "PRG1 Labo Snakes";

   Fenetre fenetre = Fenetre(nomFenetre, 80, 50, 10);
   fenetre.afficher();

   return EXIT_SUCCESS;
}
