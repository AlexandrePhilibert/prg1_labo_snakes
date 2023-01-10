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
   for (Coordonnee& coordonnee : coordonneesDeDepart) {
      pommes.push_back(Pomme(coordonnee));
   }
};