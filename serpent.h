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

#include "coordonnee.h"

class Serpent {
public:
   explicit Serpent(const Coordonnee& coordonneeTete, size_t taille = 10);

   /**
    * Déplace la tête du serpent dans la direction donnée, déplace également
    * le reste de son corps.
    *
    * @param direction
    */
   void deplacer(Direction direction);

   int getId() const;

private:

   static int prochainId;

   int id;

   /**
    * Le corps du serpent comprends la tête (premier élément du vecteur)
    */
   std::vector<Coordonnee> corps;

   Coordonnee& tete();

};
#endif //PRG1_LABO_SNAKES_SERPENT_H
