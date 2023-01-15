// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            : Représente le terrain sur lequel se trouvent les serpents et les pommes
// Modifications  : NIL
// Remarque(s)    : Le système de coordonnée débute en haut à gauche en (0,0).
//                  Chaque serpent se voit attribué une pomme, l'index de la pomme dans le vecteur corresponds à l'index
//                  du serpent (par ex. serpents en index 4, pomme en index 4).
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
   explicit Terrain(std::vector<Serpent>& serpents, std::vector<Pomme>& pommes, int largeur = 50, int hauteur = 50);

   void prochainTour();

private:
   const int largeur;
   const int hauteur;

   std::vector<Pomme>& pommes;
   std::vector<Serpent>& serpents;

   /**
    * Donne la direction dans laquelle le serpent doit se diriger pour atteindre sa pomme.
    *
    * @param serpent Le serpent en question
    * @return une direction (NORD, EST, SUD, OUEST)
    */
   Direction directionVersPomme(const Serpent& serpent, const Pomme& pomme) const;

};

const Fenetre& operator<<(const Fenetre& fenetre, const Terrain& terrain);

#endif //PRG1_LABO_SNAKES_TERRAIN_H
