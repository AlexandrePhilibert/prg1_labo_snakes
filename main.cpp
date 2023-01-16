// -----------------------------------------------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            : Affiche un terrain dans lequel des serpents se déplacent,
//                  mangent des pommes et se battent entre eux.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <cstdlib>
#include <thread>
#include <iostream>
#include <vector>
#include <limits>

#include "fenetre.h"
#include "saisie.h"
#include "terrain.h"
#include "pomme.h"
#include "serpent.h"

#include "SDL.h" // Include aussi dans le main afin d'éviter des problème avec windows

using namespace std;

int main (int argc, char *argv[]) {
   // Permet d'éviter les warnings de compilation pour variables inutilisées
   (void) argc;
   (void) argv;

   const string MSG_SAISIE_LARGEUR = "largeur";             // Message de saisie de la largeur du terrain
   const string MSG_SAISIE_HAUTEUR = "hauteur";             // Message de saisie de la hauteur du terrain
   const string MSG_SAISIE_NOMBRE_SERPENTS = "nbre snakes"; // Message de saisie du nombre de serpents
   const string MSG_ERREUR = "/!\\ erreur de saisie ...";   // Message d'erreur (hors interval)
   const int LARGEUR_TERRAIN_MIN = 50;                      // La largeur de terrain minimum
   const int LARGEUR_TERRAIN_MAX = 1200;                    // La largeur de terrain maximum
   const int HAUTEUR_TERRAIN_MIN = 50;                      // La hauteur de terrain minimum
   const int HAUTEUR_TERRAIN_MAX = 800;                     // La hauteur de terrain maximum
   const int NOMBRE_SERPENTS_MIN = 2;                       // Le nombre de serpents minimum
   const int NOMBRE_SERPENTS_MAX = 1000;                    // Le nombre de serpents maximum
   const char* NOM_FENETRE = "PRG1 Labo Snakes Groupe G";   // Le nom de la fenêtre
   const int ECHELLE_FENETRE = 4;                           // L'échelle de la fenêtre (1 pixel * échelle)
   const chrono::duration TEMPS_ENTRE_TOUR = 16ms;          // Le temps entre chaque tour sur le terrain

   cout << "ce programme vous permet de créer un terrain sur lequel des serpents vont se déplacer et combattre" << endl << endl;

   // Saisie de la largeur du terrain
   int largeurTerrain = saisie(MSG_SAISIE_LARGEUR, MSG_ERREUR, LARGEUR_TERRAIN_MIN, LARGEUR_TERRAIN_MAX);
   // Saisie de la hauteur du terrain
   int hauteurTerrain = saisie(MSG_SAISIE_HAUTEUR, MSG_ERREUR, HAUTEUR_TERRAIN_MIN, HAUTEUR_TERRAIN_MAX);
   // Saisie du nombre de serpents
   int nombreSerpents = saisie(MSG_SAISIE_NOMBRE_SERPENTS, MSG_ERREUR, NOMBRE_SERPENTS_MIN, NOMBRE_SERPENTS_MAX);

   cout << endl;

   // Création de la fenêtre graphique et du terrain
   Fenetre fenetre = Fenetre(NOM_FENETRE, largeurTerrain, hauteurTerrain, ECHELLE_FENETRE);
   Terrain terrain = Terrain(nombreSerpents, largeurTerrain, hauteurTerrain);

   while(!fenetre.getVeutQuitter() && terrain.getNombreSerpents() > 1) {
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
