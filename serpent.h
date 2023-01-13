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

class ResultatCombat;

class Serpent {
   friend const Fenetre& operator<<(const Fenetre& fenetre, const Serpent& serpent);
   friend std::ostream& operator<<(std::ostream&os, const Serpent& serpent);
   friend class TeteSurSerpent;
public:
   explicit Serpent(const Coordonnee& coordonneeTete, size_t taille = 10);

   bool operator==(const Serpent& serpent) const;
   bool operator!=(const Serpent& serpent) const;

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

   /**
    * Permet de récupérer la longueur du serpent (le nombre d'éléments dont est composé son corps)
    *
    * @return
    */
   size_t longueur() const;

   /**
    * Permet de savoir quel serpent est perdant lorsque ils s'affrontent tête-à-tête.
    *
    * @param serpent
    * @return
    */
   ResultatCombat combat(Serpent& serpent);

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

   const Coordonnee& tete() const;

private:

   static int prochainId;

   /**
    * Le pourcentage de croissance lorsqu'un serpent tue un autre serpent
    */
   static const double POURCENTAGE_CROISSANCE_SERPENT_TUE;

   /**
    * Le pourcentage de croissance lorsqu'un serpent mord un autre serpent
    */
   static const double POURCENTAGE_CROISSANCE_SERPENT_MORDU;

   int id;

   /**
    * Le corps du serpent comprends la tête (premier élément du vecteur)
    */
   std::vector<Coordonnee> corps;

   /**
    * Permet de récupérer la coordonnée de la queue du serpent
    *
    * #throws NIL
    * @return La coordonne de la queue du serpent
    */
   Coordonnee& queue();

   /**
    * Permet de redéfinir la taille du serpent, lorsque sa taille grandit, les coordonnées des nouveaux bouts sont
    * égales aux coordonnée de la queue.
    *
    * @param longeur
    */
   void redimensionner(size_t longeur);
};


class ResultatCombat {
public:
   ResultatCombat(const Serpent& gagnant, const Serpent& perdant): gagnant(gagnant), perdant(perdant) {};

   const Serpent& gagnant;
   const Serpent& perdant;
};

std::ostream& operator<<(std::ostream&os, const Serpent& serpent);

const Fenetre& operator<<(const Fenetre& fenetre, const Serpent& serpent);
#endif //PRG1_LABO_SNAKES_SERPENT_H
