// -----------------------------------------------------------------------------------------------
// Fichier        : fenetre.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-16
// But            : Représentation d'une fenêtre SDL
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream>

#include "fenetre.h"

using namespace std;

Fenetre::Fenetre(const char* nom, int largeur, int hauteur, int echelle) {
   SDL_Init(SDL_INIT_VIDEO);
   SDL_CreateWindowAndRenderer(largeur  * echelle,
                               hauteur * echelle,
                               SDL_WINDOW_SHOWN,
                               &window, &renderer);

   if (window == nullptr || renderer == nullptr) {
      cout << "Une erreur est survenue à la création de la fenêtre" << endl;
      exit(EXIT_FAILURE);
   }

   SDL_SetWindowTitle(window, nom);
   SDL_RenderSetScale(renderer, (float) echelle, (float) echelle);
};

void Fenetre::gererEvenements() {
   SDL_Event event;
   while (SDL_PollEvent(&event)) {
      switch (event.type) {
         case SDL_QUIT:
            veutQuitter = true;
            break;
         default: break;
      }
   }
}

bool Fenetre::getVeutQuitter() const {
   return veutQuitter;
}

SDL_Renderer *Fenetre::getRenderer() const {
   return renderer;
}

void Fenetre::quitter() {
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}
