// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-16
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
   /**
    * Créé un terrain avec des serpents et des pommes d'une largeur et hauteur donnée
    *
    * @param nombreSerpents Le nombre de serpents qui sera présent sur le terrain
    * @param largeur La largeur du terrain
    * @param hauteur La hauteur du terrain
    * @throws NIL
    */
   explicit Terrain(int nombreSerpents, int largeur = 50, int hauteur = 50);

   /**
    * Permet de récupérer le nombre de serpents présents sur le terrain
    *
    * @throws NIL
    * @return le nombre de serpents présent sur le terrain
    */
   int getNombreSerpents() const;

   /**
    * Effectue le prochain tour de jeu sur le terrain :
    * - Déplace les serpents
    * - Fait manger les pommes aux serpents si leur tête ce trouve sur la pomme
    * - Effectue les combats de serpents si nécessaire
    *
    * @throws NIL
    * @return void
    */
   void prochainTour();

private:
   /**
    * La largeur du terrain
    */
   const int largeur;
   /**
    * La hauteur du terrain
    */
   const int hauteur;

   std::vector<Pomme> pommes;
   std::vector<Serpent> serpents;

   /**
    * Effectue le type de combat de serpentAttaquant requis (tête sur tête, ou tête sur corps).
    *
    * @param serpentAttaquant Le serpent qui attaque l'autre
    * @param serpentVictime Le serpent victime de l'attaque
    * @param indexSerpentAttaquant L'index du serpentAttaquant qui attaque l'autre serpentAttaquant
    * @throws NIL
    * @return void
    */
   void combat(Serpent& serpentAttaquant, Serpent& serpentVictime, size_t& indexSerpentAttaquant);

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
