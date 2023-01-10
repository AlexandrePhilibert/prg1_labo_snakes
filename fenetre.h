// -----------------------------------------------------------------------------------------------
// Fichier        : fenetre.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-10
// But            : Représentation d'une fenêtre SDL
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_FENETRE_H
#define PRG1_LABO_SNAKES_FENETRE_H

#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

using namespace std;

class Fenetre {
public:
   Fenetre(const char nom[], int largeur = 50, int hauteur = 50, int echelle = 10);

   ~Fenetre();

   void afficher();

private:
   SDL_Window*   window   = nullptr;
   SDL_Renderer* renderer = nullptr;

   int largeur;
   int hauteur;
};

#endif //PRG1_LABO_SNAKES_FENETRE_H
