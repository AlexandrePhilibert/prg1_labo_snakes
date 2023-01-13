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

class Fenetre {
public:
   /**
    *
    * @param nom     nom de la fenêtre affichée par le système d'exploitation
    * @param largeur largeur de la fenêtre
    * @param hauteur hauteur de la fenêtre
    * @param echelle echelle à laquelle est rendue un pixel
    */
   Fenetre(const char nom[], int largeur = 50, int hauteur = 50, int echelle = 10);

   ~Fenetre();

   bool getVeutQuitter() const;

   SDL_Renderer* getRenderer() const;

   /**
    * Gère les évènements de la fenêtre tel que la fermeture de la fenêtre
    */
   void gererEvenements();

private:
   SDL_Window*   window   = nullptr;
   SDL_Renderer* renderer = nullptr;

   bool veutQuitter = false;
};

#endif //PRG1_LABO_SNAKES_FENETRE_H
