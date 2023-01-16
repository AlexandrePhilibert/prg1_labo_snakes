// -----------------------------------------------------------------------------------------------
// Fichier        : fenetre.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-16
// But            : Représentation d'une fenêtre SDL
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_FENETRE_H
#define PRG1_LABO_SNAKES_FENETRE_H

#include <SDL.h>

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

   /**
    * Permet de savoir si la fenêtre souhaite quitter ou non
    *
    * @throws NIL
    * @return true si la fenêtre souhaite se fermer, false sinon
    */
   bool getVeutQuitter() const;

   /**
    *
    * @throws NIL
    * @return
    */
   SDL_Renderer* getRenderer() const;

   /**
    * Permet de fermer la fenêtre
    */
   void quitter();

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
