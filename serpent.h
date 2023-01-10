// -----------------------------------------------------------------------------------------------
// Fichier        : serpent.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            :
//
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_SERPENT_H
#define PRG1_LABO_SNAKES_SERPENT_H

#include "cible.h"

class Serpent {
public:
   Serpent(int x, int y);

   void deplacer();

   // Référence ou non ?
   Cible cible;

   // Getters
   int getPosX(){
      return posX;
   }
   int getPosY(){
      return posY;
   }


private:
   // A voir si on change
   int posX;
   int posY;

};
#endif //PRG1_LABO_SNAKES_SERPENT_H
