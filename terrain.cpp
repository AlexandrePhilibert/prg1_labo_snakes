// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            : Représente le terrain sur lequel se trouvent les serpents et les pommes
// Modifications  : NIL
// Remarque(s)    : Le système de coordonnée débute en haut à gauche en (0,0).
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <vector>

#include "fenetre.h"
#include "terrain.h"
#include "coordonnee.h"
#include "serpent.h"
#include "pomme.h"

using namespace std;

Terrain::Terrain(vector<Serpent> &serpents, vector<Pomme>& pommes, int largeur, int hauteur) : largeur(largeur),
                                                                                               hauteur(hauteur),
                                                                                               pommes(pommes),
                                                                                               serpents(serpents) {}
Direction Terrain::directionVersPomme(const Serpent& serpent) {
   Direction direction;
   Pomme& pomme = pommes[(size_t) serpent.getId() - 1];
   // Calcul la distance en x et y entre la tête du serpent et la pomme
   Coordonnee distance = serpent.tete() - pomme.getCoordonnee();
   // Calcul la distance absolue en x et y entre la tête du serpent et la pomme
   Coordonnee distanceAbsolue = distance.abs();

   if (distanceAbsolue.getX() > distanceAbsolue.getY()) {
      if (distance.getX() < 0) {
         direction = Direction::EST;
      } else {
         direction =  Direction::OUEST;
      }
   } else {
      if (distance.getY() < 0) {
         direction = Direction::SUD;
      } else {
         direction =  Direction::NORD;
      }
   }

   return direction;
}

class TeteSurSerpent {
public:
   TeteSurSerpent(Serpent& serpent): serpent(serpent) {}

   bool operator()(const Serpent& serpent) {
      if (serpent == this->serpent) {
         return false;
      }

      vector<Coordonnee>::const_iterator it = find(serpent.corps.begin(), serpent.corps.end(), this->serpent.tete());
      return it != serpent.corps.end();
   }
private:
   Serpent& serpent;
};

void Terrain::prochainTour() {
   for (vector<Serpent>::iterator serpent = serpents.begin(); serpent != serpents.end(); ++serpent) {
      Direction direction = directionVersPomme(*serpent);
      serpent->deplacer(direction);

      if (serpent->tete() == pommes[(size_t) serpent->getId() - 1].getCoordonnee()) {
         serpent->mange(pommes[(size_t) serpent->getId() - 1]);
         pommes[(size_t) serpent->getId() - 1] = Pomme(Coordonnee::random(largeur - 1, hauteur - 1));
      }

      // Combats tête sur tête
      vector<Serpent>::iterator it = find_if(serpents.begin(), serpents.end(), TeteSurSerpent(*serpent));
      if (it != serpents.end()) {
         if (it->tete() == serpent->tete()) {
            ResultatCombat resultat = serpent->combat(*it);

            cout << resultat.gagnant << " killed " << resultat.perdant << endl;

            serpent = serpents.erase(remove(serpents.begin(), serpents.end(), resultat.perdant), serpents.end());
            --serpent;
         } else { // La tête du serpent est sur le corps d'un autre serpent
            serpent->mord(*it);
         }
      }
   }
}

const Fenetre& operator<<(const Fenetre& fenetre, const Terrain& terrain) {
   // Affiche l'arrière-plan du terrain en blanc
   SDL_SetRenderDrawColor(fenetre.getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
   SDL_RenderClear(fenetre.getRenderer());

   for (const Pomme& pomme : terrain.pommes) {
      fenetre << pomme;
   }

   for (const Serpent& serpent : terrain.serpents) {
      fenetre << serpent;
   }

   // Effectue le rendu sur la fenêtre
   SDL_RenderPresent(fenetre.getRenderer());

   return fenetre;
}