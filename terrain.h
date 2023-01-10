// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_TERRAIN_H
#define PRG1_LABO_SNAKES_TERRAIN_H

#include "serpent.h"
#include "pomme.h"

class Terrain {
public:
   explicit Terrain(int nombreSerpents = 0, int largeur = 50, int hauteur = 50);

   void prochainTour();

private:

   const int largeur;
   const int hauteur;

   // TODO: Est-ce qu'il ne serait pas mieux de faire un std::pair<Serpent, Pomme>,
   // cela permettrai de lier un serpent à une pomme de manière plus formelle.
   std::vector<Pomme> pommes;
   std::vector<Serpent> serpents;


   void deplacer(Serpent& serpent);

};

#endif //PRG1_LABO_SNAKES_TERRAIN_H
