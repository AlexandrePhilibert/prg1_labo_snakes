// -----------------------------------------------------------------------------------------------
// Fichier        : annexe.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            : Fonction permettant de générer un nombre aléatoire dans l'interval [min, max]
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <random> // random_device

using namespace std;

// Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/dccd145b3e99101c98de2d9a87ff05db386e2500/04_Fonctions/04_static_srand.cpp#L36
int random (int min, int max) {
   random_device                  rand_dev;
   default_random_engine          generator(rand_dev());
   uniform_int_distribution<int>  distr(min, max);

   // une valeur entre min et max compris
   return distr(generator);
}