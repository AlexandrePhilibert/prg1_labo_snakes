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
#include "fenetre.h"

int Pomme::VALEUR_MIN = 1;
int Pomme::VALEUR_MAX = 10;

Pomme::Pomme(const Coordonnee& coordonnee):  coordonnee(coordonnee) {
   valeur = random(VALEUR_MIN, VALEUR_MAX);
};

int Pomme::getValeur() const {
   return valeur;
}

const Fenetre& operator<<(const Fenetre& fenetre, const Pomme& pomme) {
   SDL_SetRenderDrawColor(fenetre.getRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
   SDL_RenderDrawPoint(fenetre.getRenderer(), pomme.coordonnee.getX(), pomme.coordonnee.getY());
}