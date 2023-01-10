// -----------------------------------------------------------------------------------------------
// Fichier        : pomme.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-10
// But            :
//
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include "pomme.h"
#include "annexe.h"

Pomme::Pomme(const Coordonnee& coordonnee):  coordonnee(coordonnee) {
   // TODO: Définir des valeurs statiques sur la classe Pomme pour valeur min et max ?
   valeur = random(1, 10);
};