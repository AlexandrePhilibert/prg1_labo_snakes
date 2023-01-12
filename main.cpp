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

#include "fenetre.h"
#include "saisie.h"
#include "terrain.h"

#include "SDL.h" // Include aussi dans le main autrement problème avec windows

using namespace std;

//Argument pour SDL et windows
int main (int argc, char *args[]) {
   // Le message de saisie de la largeur du terrain
   const string MSG_SAISIE_LARGEUR = "largeur";
   // Le message de saisie de la hauteur du terrain
   const string MSG_SAISIE_HAUTEUR = "hauteur";
   // Le message de saisie du nombre de serpents
   const string MSG_SAISIE_NOMBRE_SERPENTS = "nbre snakes";
   // Le message d'erreur qui s'affichera lorsque la saisie est hors de l'interval spécifié
   const string MSG_ERREUR = "/!\\ erreur de saisie ...";
   // La largeur de terrain minimum qui pourra être choisi par l'utilisateur
   const int LARGEUR_TERRAIN_MIN = 50;
   // La largeur de terrain maximum qui pourra être choisi par l'utilisateur
   const int LARGEUR_TERRAIN_MAX = 1200;
   // La hauteur de terrain minimum qui pourra être choisi par l'utilisateur
   const int HAUTEUR_TERRAIN_MIN = 50;
   // La hauteur de terrain maximum qui pourra être choisi par l'utilisateur
   const int HAUTEUR_TERRAIN_MAX = 800;
   // Le nombre de serpents minimum qui pourra être choisi par l'utilisateur
   const int NOMBRE_SERPENTS_MIN = 2;
   // Le nombre de serpents maximum qui pourra être choisi par l'utilisateur
   const int NOMBRE_SERPENTS_MAX = 1000;

   const char* nomFenetre = "PRG1 Labo Snakes"; // Le nom de la fenêtre
   // L'échelle de la fenêtre (1 pixel * échelle)
   const int ECHELLE_FENETRE = 4;

   // La largeur du terrain saisie par l'utilisateur
   int largeurTerrain;
   // La hauteur du terrain saisie par l'utilisateur
   int hauteurTerrain;
   // Le nombre de serpents saisi par l'utilisateur
   int nombreSerpents;

   // TODO: Description du programme
   cout << "ce programme..." << endl << endl;

   // Saisie de la largeur du terrain
   largeurTerrain = saisie(MSG_SAISIE_LARGEUR, MSG_ERREUR, LARGEUR_TERRAIN_MIN, LARGEUR_TERRAIN_MAX);
   // Saisie de la hauteur du terrain
   hauteurTerrain = saisie(MSG_SAISIE_HAUTEUR, MSG_ERREUR, HAUTEUR_TERRAIN_MIN, HAUTEUR_TERRAIN_MAX);
   // Saisie du nombre de serpents
   nombreSerpents = saisie(MSG_SAISIE_NOMBRE_SERPENTS, MSG_ERREUR, NOMBRE_SERPENTS_MIN, NOMBRE_SERPENTS_MAX);

   cout << endl;

   Terrain terrain = Terrain(nombreSerpents, largeurTerrain, hauteurTerrain);

   Fenetre fenetre = Fenetre(nomFenetre, largeurTerrain, hauteurTerrain, ECHELLE_FENETRE);

   while(!fenetre.getVeutQuitter()) {
      fenetre << terrain;

      // Effectue les déplacements et les combats de serpents
      terrain.prochainTour();

      this_thread::sleep_for(16.66ms);

      fenetre.gererEvenements();
   }

   return EXIT_SUCCESS;
}
