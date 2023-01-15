// -----------------------------------------------------------------------------------------------
// Fichier        : pomme.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-10
// But            : Réprésente des pommes pouvant être mangé par des serpents, leur
//                  permettant de changer de taille.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_POMME_H
#define PRG1_LABO_SNAKES_POMME_H

#include "coordonnee.h"
#include "fenetre.h"

class Pomme {
   friend const Fenetre& operator<<(const Fenetre& fenetre, const Pomme& pomme);
public:
   Pomme(const Coordonnee& coordonnee);

   int getValeur() const;

   const Coordonnee& getCoordonnee() const;

   int valeur;
   Coordonnee coordonnee;

   static int VALEUR_MIN;
   static int VALEUR_MAX;
};

const Fenetre& operator<<(const Fenetre& fenetre, const Pomme& pomme);

#endif //PRG1_LABO_SNAKES_POMME_H
