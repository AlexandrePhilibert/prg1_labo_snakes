// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <vector>
#include <random> // random_device()

#include "fenetre.h"
#include "terrain.h"
#include "coordonnee.h"

using namespace std;

Terrain::Terrain(int nombreSerpents, int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
   vector<Coordonnee> coordonneesDeDepart = vector<Coordonnee>((size_t) nombreSerpents);
   // TODO: Vérifier que les serpents et les pommes ne commencent pas sur la même coordonnée ?
   Coordonnee::unique(coordonneesDeDepart.begin(), coordonneesDeDepart.end(), largeur - 1, hauteur - 1);

   // Création des pommes et attribution des coordonnées de départ uniques
   // TODO: Le code pour les serpents sera le même...
   pommes = vector<Pomme>();
   pommes.reserve((size_t) nombreSerpents);
   for (const Coordonnee& coordonnee : coordonneesDeDepart) {
      pommes.push_back(Pomme(coordonnee));
   }

   // TODO: Enlever duplication code
   vector<Coordonnee> coordonneesDeDepartSerpent = vector<Coordonnee>((size_t) nombreSerpents);
   Coordonnee::unique(coordonneesDeDepartSerpent.begin(), coordonneesDeDepartSerpent.end(), largeur - 1, hauteur - 1);

   // Création des serpents et attributions des coordonnées de départ uniques
   serpents = vector<Serpent>();
   serpents.reserve((size_t) nombreSerpents);
   for(const Coordonnee& coordonnee : coordonneesDeDepartSerpent){
      serpents.push_back(Serpent(coordonnee));
   }
};

Direction Terrain::deplacer(Serpent &serpent) {
   Pomme& pomme = pommes[0];
   Direction direction;

   // TODO: Refactor ça
   if (abs(serpent.tete().getX() - pomme.getCoordonnee().getX()) >
      abs(serpent.tete().getY() - pomme.getCoordonnee().getY())) {
      if (serpent.tete().getX() < pomme.getCoordonnee().getX()) {
         direction = Direction::DROITE;
      } else {
         direction =  Direction::GAUCHE;
      }
   } else {
      if (serpent.tete().getY() < pomme.getCoordonnee().getY()) {
         direction = Direction::BAS;
      } else {
         direction =  Direction::HAUT;
      }
   }

   return direction;
}

void Terrain::prochainTour() {
   // Mélange l'ordre des robots pour une égalité des chances de victoire de chaque robot lors d'un combatsRobots
   shuffle(serpents.begin(), serpents.end(), random_device());

   for (Serpent& serpent : serpents) {
      Direction direction = deplacer(serpent);
      serpent.deplacer(direction);

      if (serpent.tete() == pommes[0].getCoordonnee()) {
         serpent.mange(pommes[0]);
         pommes[0] = Pomme(Coordonnee::random(largeur - 1, hauteur - 1));
      }
   }
}

const Fenetre& operator<<(const Fenetre& fenetre, const Terrain& terrain) {
   // Affiche l'arrière-plan du terrain en blanc
   SDL_SetRenderDrawColor(fenetre.getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
   SDL_RenderClear(fenetre.getRenderer());

   for (const Pomme& pomme : terrain.pommes) {
      // TODO: Ajouter la méthode dessinerPoint sur la classe fenêtre
      fenetre << pomme;
   }

   for (const Serpent& serpent : terrain.serpents) {
      fenetre << serpent;
   }

   // Effectue le rendu sur la fenêtre
   SDL_RenderPresent(fenetre.getRenderer());
}