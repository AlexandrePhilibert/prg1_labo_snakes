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
#include <iostream>

#include "fenetre.h"
#include "terrain.h"
#include "coordonnee.h"
#include "serpent.h"
#include "pomme.h"

using namespace std;

Terrain::Terrain(int nombreSerpents, int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
   // Génération de points d'apparition aléatoires et uniques pour les serpents et les pommes
   vector<Coordonnee> coordonnees = vector<Coordonnee>((size_t) nombreSerpents * 2);
   Coordonnee::unique(coordonnees.begin(), coordonnees.end(), largeur - 1, hauteur - 1);

   serpents = vector<Serpent>();
   serpents.reserve((size_t) nombreSerpents);
   pommes = vector<Pomme>();
   pommes.reserve((size_t) nombreSerpents);

   // Création des serpents et des pommes aux points d'apparitions
   for (vector<Coordonnee>::const_iterator coordonnee = coordonnees.begin(); coordonnee != coordonnees.end(); ) {
      serpents.push_back(Serpent(*coordonnee));
      ++coordonnee;
      pommes.push_back(Pomme(*coordonnee));
      ++coordonnee;
   }
}

int Terrain::getNombreSerpents() const {
   return (int) serpents.size();
}

class TeteSurSerpent {
public:
   explicit TeteSurSerpent(const Serpent& serpent): serpent(serpent) {}

   bool operator()(const Serpent& serpent) {
      if (serpent == this->serpent) {
         return false;
      }

      vector<Coordonnee>::const_iterator it = find(serpent.corps.begin(), serpent.corps.end(), this->serpent.tete());
      return it != serpent.corps.end();
   }
private:
   const Serpent& serpent;
};

void Terrain::prochainTour() {
   for (size_t i = 0; i < serpents.size(); ++i) {
      Serpent& serpent = serpents[i];
      Pomme& pomme = pommes[i];

      // Déplace le serpent en direction de la pomme
      Direction direction = directionVersPomme(serpent, pomme);
      serpent.deplacer(direction);

      // Le serpent mange la pomme si sa tête se trouve dessus
      if (serpent.tete() == pomme.getCoordonnee()) {
         serpent.mange(pomme);
         pomme = Pomme(Coordonnee::random(largeur - 1, hauteur - 1));
      }

      vector<Serpent>::iterator autreSerpent = find_if(serpents.begin(), serpents.end(), TeteSurSerpent(serpent));
      // La tête du serpent ne se trouve sur aucun autre serpent, aucun combat ou morsure n'est réalisé.
      if (autreSerpent == serpents.end()) {
         continue;
      }

      // Combat tête sur tête
      if (autreSerpent->tete() == serpent.tete()) {
         ResultatCombat resultat = serpent.combat(*autreSerpent);

         // Affiche le résultat du combat dans la console
         cout << resultat.gagnant << " killed " << resultat.perdant << endl;

         long long indexPerdant = distance(serpents.cbegin(), find(serpents.cbegin(), serpents.cend(), resultat.perdant));

         // Supprime le serpent perdant ainsi que sa pomme
         serpents.erase(serpents.cbegin() + indexPerdant);
         pommes.erase(pommes.cbegin() + indexPerdant);

         // Ayant supprimé un serpent du vecteur, il faut décaler l'index d'itération si le serpent supprimer se
         // trouvait avant l'index actuel dans le vecteur, sinon un serpent va être sauté.
         if ((size_t) indexPerdant < i) {
            --i;
         }
      } else { // La tête du serpent est sur le corps d'un autre serpent
         serpent.mord(*autreSerpent);
      }
   }
}

Direction Terrain::directionVersPomme(const Serpent& serpent, const Pomme& pomme) const {
   // Calcul la distance en x et y entre la tête du serpent et la pomme
   Coordonnee distance = serpent.tete() - pomme.getCoordonnee();
   // Calcul la distance absolue en x et y entre la tête du serpent et la pomme
   Coordonnee distanceAbsolue = distance.abs();

   if (distanceAbsolue.getX() > distanceAbsolue.getY()) {
      if (distance.getX() < 0) {
         return Direction::EST;
      } else {
         return Direction::OUEST;
      }
   } else {
      if (distance.getY() < 0) {
         return Direction::SUD;
      } else {
         return Direction::NORD;
      }
   }
}

// -----------------------------------------------------------------------------------------------
// region Opérateurs
// -----------------------------------------------------------------------------------------------

const Fenetre& operator<<(const Fenetre& fenetre, const Terrain& terrain) {
   // Affiche l'arrière-plan du terrain en blanc
   SDL_SetRenderDrawColor(fenetre.getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
   SDL_RenderClear(fenetre.getRenderer());

   // Affiche les pommes sur la fenêtre
   for (const Pomme& pomme : terrain.pommes) {
      fenetre << pomme;
   }

   // Affiche les serpents sur la fenêtre
   for (const Serpent& serpent : terrain.serpents) {
      fenetre << serpent;
   }

   // Effectue le rendu sur la fenêtre
   SDL_RenderPresent(fenetre.getRenderer());

   return fenetre;
}

// -----------------------------------------------------------------------------------------------
// endregion Opérateurs
// -----------------------------------------------------------------------------------------------