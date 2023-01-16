// -----------------------------------------------------------------------------------------------
// Fichier        : serpent.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-16
// But            : Représente un serpent pouvant se déplacer, manger des pommes, mordre d'autres
//                  serpents ainsi que grandir de taille
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
   /**
    * Créé un serpent de la taille donnée où chaque partie de son corps sont aux coordonnées de sa tête
    *
    * @param coordonneeTete Les coordonnées initiales de la tête du serpent
    * @param taille La taille initiale du serpent
    * @throws NIL
    */
   explicit Serpent(const Coordonnee& coordonneeTete, size_t taille = 10);

   ~Serpent();

   bool operator==(const Serpent& serpent) const;
   bool operator!=(const Serpent& serpent) const;
   Serpent& operator=(const Serpent& serpent);

   /**
    * Déplace la tête du serpent dans la direction donnée, déplace également
    * le reste de son corps.
    *
    * @throws NIL
    * @param direction
    */
   void deplacer(Direction direction);

   /**
    * Ajoute la longueur de la valeur de la pomme au serpent.
    *
    * @throws NIL
    * @param pomme
    */
   void mange(const Pomme& pomme);

   /**
    *
    * @throws NIL
    * @param serpent
    */
   void mord(Serpent& serpent);

   /**
    * Permet de récupérer la longueur du serpent (le nombre d'éléments dont est composé son corps)
    *
    * @throws NIL
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

   /**
    * Permet de récupérer la coordonnée de la tête du serpent
    *
    * @throws NIL
    * @return La coordonne de la tête du serpent
    */
   Coordonnee& tete();

   /**
    * Permet de récupérer la coordonnée de la tête du serpent
    *
    * @throws NIL
    * @return La coordonne de la tête du serpent
    */
   const Coordonnee& tete() const;

private:

   /**
    * Le prochain id assigné lorsqu'un nouveau serpent est créé
    */
   static int prochainId;

   /**
    * Le pourcentage de croissance lorsqu'un serpent tue un autre serpent
    */
   static const double POURCENTAGE_CROISSANCE_SERPENT_TUE;

   /**
    * Le pourcentage de croissance lorsqu'un serpent mord un autre serpent
    */
   static const double POURCENTAGE_CROISSANCE_SERPENT_MORDU;

   /**
    * L'id du serpent, il est unique et s'incrémente de 1 pour chaque nouveau serpent créé
    */
   const int id;

   /**
    * Le corps du serpent comprends la tête (premier élément du vecteur)
    */
   std::vector<Coordonnee> corps;

   /**
    * Permet de récupérer la coordonnée de la queue du serpent
    *
    * @throws NIL
    * @return La coordonne de la queue du serpent
    */
   const Coordonnee& queue() const;

   /**
    * Permet de redéfinir la taille du serpent, lorsque sa taille grandit, les coordonnées des nouveaux bouts sont
    * égales aux coordonnée de la queue.
    *
    * @throws NIL
    * @param longeur
    */
   void redimensionner(size_t longeur);
};


/**
 * Représente le résultat d'un combat de serpent, avec un gagnant et un perdant
 */
class ResultatCombat {
public:
   ResultatCombat(const Serpent& gagnant, const Serpent& perdant): gagnant(gagnant), perdant(perdant) {};

   const Serpent& gagnant;
   const Serpent& perdant;
};

std::ostream& operator<<(std::ostream&os, const Serpent& serpent);

const Fenetre& operator<<(const Fenetre& fenetre, const Serpent& serpent);

#endif //PRG1_LABO_SNAKES_SERPENT_H
