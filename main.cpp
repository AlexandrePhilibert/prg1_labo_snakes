// -----------------------------------------------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <cstdlib>
#include <thread>
#include <iostream>
#include <random>
#include <vector>
#include <limits>

#include "fenetre.h"
#include "saisie.h"
#include "terrain.h"
#include "pomme.h"
#include "serpent.h"

#include "SDL.h" // Include aussi dans le main autrement problème avec windows

using namespace std;

//Argument pour SDL et windows
int main (int argc, char *args[]) {
   const string MSG_SAISIE_LARGEUR = "largeur"; // Message de saisie de la largeur du terrain
   const string MSG_SAISIE_HAUTEUR = "hauteur"; // Message de saisie de la hauteur du terrain
   const string MSG_SAISIE_NOMBRE_SERPENTS = "nbre snakes";  // Message de saisie du nombre de serpents
   const string MSG_ERREUR = "/!\\ erreur de saisie ..."; // Message d'erreur (hors interval)
   const int LARGEUR_TERRAIN_MIN = 50; // La largeur de terrain minimum
   const int LARGEUR_TERRAIN_MAX = 1200; // La largeur de terrain maximum
   const int HAUTEUR_TERRAIN_MIN = 50; // La hauteur de terrain minimum
   const int HAUTEUR_TERRAIN_MAX = 800; // La hauteur de terrain maximum
   const int NOMBRE_SERPENTS_MIN = 2; // Le nombre de serpents minimum
   const int NOMBRE_SERPENTS_MAX = 1000; // Le nombre de serpents maximum
   const char* nomFenetre = "PRG1 Labo Snakes Groupe G"; // Le nom de la fenêtre
   const int ECHELLE_FENETRE = 4; // L'échelle de la fenêtre (1 pixel * échelle)
   const chrono::duration TEMPS_ENTRE_TOUR = 16ms;

   // TODO: Description du programme
   cout << "ce programme..." << endl << endl;

   // Saisie de la largeur du terrain
   int largeurTerrain = saisie(MSG_SAISIE_LARGEUR, MSG_ERREUR, LARGEUR_TERRAIN_MIN, LARGEUR_TERRAIN_MAX);
   // Saisie de la hauteur du terrain
   int hauteurTerrain = saisie(MSG_SAISIE_HAUTEUR, MSG_ERREUR, HAUTEUR_TERRAIN_MIN, HAUTEUR_TERRAIN_MAX);
   // Saisie du nombre de serpents
   int nombreSerpents = saisie(MSG_SAISIE_NOMBRE_SERPENTS, MSG_ERREUR, NOMBRE_SERPENTS_MIN, NOMBRE_SERPENTS_MAX);

   cout << endl;

   vector<Coordonnee> coordonnees = vector<Coordonnee>((size_t) nombreSerpents * 2);
   Coordonnee::unique(coordonnees.begin(), coordonnees.end(), largeurTerrain - 1, hauteurTerrain - 1);

   vector<Serpent> serpents = vector<Serpent>();
   serpents.reserve((size_t) nombreSerpents);
   vector<Pomme> pommes = vector<Pomme>();
   pommes.reserve((size_t) nombreSerpents);

   for (vector<Coordonnee>::const_iterator coordonnee = coordonnees.begin(); coordonnee != coordonnees.end(); ) {
      serpents.emplace_back(*coordonnee);
      ++coordonnee;
      pommes.emplace_back(*coordonnee);
      ++coordonnee;
   }

   Terrain terrain = Terrain(serpents, pommes, largeurTerrain, hauteurTerrain);
   Fenetre fenetre = Fenetre(nomFenetre, largeurTerrain, hauteurTerrain, ECHELLE_FENETRE);

   while(!fenetre.getVeutQuitter() && serpents.size() > 1) {
      fenetre << terrain;

      // Effectue les déplacements et les combats de serpents
      terrain.prochainTour();

      this_thread::sleep_for(TEMPS_ENTRE_TOUR);

      // Gère les événements liés à la fenêtre (fermeture de la fenêtre par ex.)
      fenetre.gererEvenements();
   }

   fenetre.quitter();

   cout << endl << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}
