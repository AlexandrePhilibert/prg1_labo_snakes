// -----------------------------------------------------------------------------------------------
// Fichier        : pomme.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-10
// But            :
//
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_POMME_H
#define PRG1_LABO_SNAKES_POMME_H

#include "coordonnee.h"

class Pomme {
public:
   Pomme(const Coordonnee& coordonnee);

private:
   int valeur;
   const Coordonnee& coordonnee;
};

#endif //PRG1_LABO_SNAKES_POMME_H
