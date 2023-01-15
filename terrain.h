// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
      // But            : Représente le terrain sur lequel se trouvent les serpents et les pommes
      // Modifications  : NIL
      // Remarque(s)    : Le système de coordonnée débute en haut à gauche en (0,0).
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_TERRAIN_H
#define PRG1_LABO_SNAKES_TERRAIN_H

#include <sstream>
#include <vector>

#include "serpent.h"
#include "pomme.h"

class Terrain {
   friend const Fenetre& operator<<(const Fenetre& fenetre, const Terrain& terrain);
public:
   explicit Terrain(std::vector<Serpent>& serpents, std::vector<Pomme>& pomme , int largeur = 50, int hauteur = 50);

   void prochainTour();

private:

   const int largeur;
   const int hauteur;

   // TODO: Est-ce qu'il ne serait pas mieux de faire un std::pair<Serpent, Pomme>,
   // cela permettrai de lier un serpent à une pomme de manière plus formelle.
   std::vector<Pomme>& pommes;
   std::vector<Serpent>& serpents;

   /**
    * Donne la direction dans laquelle le serpent doit se diriger pour atteindre sa pomme.
    *
    * @param serpent Le serpent en question
    * @return une direction (NORD, EST, SUD, OUEST)
    */
   Direction directionVersPomme(const Serpent& serpent);

};

const Fenetre& operator<<(const Fenetre& fenetre, const Terrain& terrain);

#endif //PRG1_LABO_SNAKES_TERRAIN_H
