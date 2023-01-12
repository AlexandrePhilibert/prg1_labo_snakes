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

   //Enlever duplication code
   vector<Coordonnee> coordonneesDeDepartSerpent = vector<Coordonnee>((size_t) nombreSerpents);
   Coordonnee::unique(coordonneesDeDepartSerpent.begin(), coordonneesDeDepartSerpent.end(), largeur - 1, hauteur - 1);

   // Création des serpents et attributions des coordonnées de départ uniques
   serpents = vector<Serpent>();
   serpents.reserve((size_t) nombreSerpents);
   for(const Coordonnee& coordonnee : coordonneesDeDepartSerpent){
      serpents.push_back(Serpent(coordonnee));
   }
};


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