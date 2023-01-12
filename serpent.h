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
#include "pomme.h"

class Serpent {
   friend const Fenetre& operator<<(const Fenetre& fenetre, const Serpent& serpent);
public:
   explicit Serpent(const Coordonnee& coordonneeTete, size_t taille = 10);

   /**
    * Déplace la tête du serpent dans la direction donnée, déplace également
    * le reste de son corps.
    *
    * @param direction
    */
   void deplacer(Direction direction);

   /**
    * Ajoute la longueur de la valeur de la pomme au serpent.
    *
    * @param pomme
    */
   void mange(const Pomme& pomme);

   /**
    *
    * @param serpent
    */
   void mord(Serpent& serpent);

   int getId() const;

   /**
    * Permet de récupérer la coordonnée de la tête du serpent
    *
    * TODO: Référence mutable, donc peut être modifiée depuis l'extérieur
    *
    * @throws NIL
    * @return La coordonne de la tête du serpent
    */
   Coordonnee& tete();

private:

   static int prochainId;

   int id;

   /**
    * Le corps du serpent comprends la tête (premier élément du vecteur)
    */
   std::vector<Coordonnee> corps;

   /**
    * Premet de récupérer la coordonnée de la queue du serpent
    *
    * #throws NIL
    * @return La coordonne de la queue du serpent
    */
   Coordonnee& queue();

};

const Fenetre& operator<<(const Fenetre& fenetre, const Serpent& serpent);
#endif //PRG1_LABO_SNAKES_SERPENT_H
