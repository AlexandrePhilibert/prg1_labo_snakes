#ifndef PRG1_LABO_SNAKES_FENETRE_H
#define PRG1_LABO_SNAKES_FENETRE_H

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Fenetre {
public:
   Fenetre(const char nom[], int largeur = 50, int hauteur = 50, int echelle = 10) : largeur(largeur), hauteur(hauteur) {
      SDL_Init(SDL_INIT_VIDEO);
      SDL_CreateWindowAndRenderer(largeur  * echelle,
                                  hauteur * echelle,
                                  SDL_WINDOW_SHOWN,
                                  &window, &renderer);

      if (window == nullptr or renderer == nullptr) {
         cout << "SDL not ready ... quitting" << endl;
         exit(EXIT_FAILURE);
      }

      SDL_SetWindowTitle(window, nom);
      SDL_RenderSetScale(renderer, (float) echelle, (float) echelle);
   };

   void afficher() {
      const int      STEP           =  1;
      bool           appIsRunning   = true;
      // point to show
      SDL_Point point;
      point.x = largeur  / 2;
      point.y = hauteur / 2;

      //--------------------------------------------------------------------------
      // main loop
      //--------------------------------------------------------------------------
      while (appIsRunning) {

         // Events management
         SDL_Event event;
         while (SDL_PollEvent(&event)) {

            switch (event.type) {
               case SDL_QUIT     :  appIsRunning = false;
                  break;

                  // keyboard API for key pressed
               case SDL_KEYDOWN  :
                  switch (event.key.keysym.scancode) {

                     case SDL_SCANCODE_W     :
                     case SDL_SCANCODE_UP    :  point.y -= STEP;
                        break;
                     case SDL_SCANCODE_A     :
                     case SDL_SCANCODE_LEFT  :  point.x -= STEP;
                        break;
                     case SDL_SCANCODE_S     :
                     case SDL_SCANCODE_DOWN  :  point.y += STEP;
                        break;
                     case SDL_SCANCODE_D     :
                     case SDL_SCANCODE_RIGHT :  point.x += STEP;
                        break;
                        // other "unknown" cases
                     default:                   break;
                  } // switch event.key.keysym.scancode

            } // switch event.type

         } // while PollEvent

         //-----------------------------------------------------------------------
         // bounderies
         //-----------------------------------------------------------------------
         // right boundary
         if (point.x >= largeur)
            point.x = largeur - 1;

         // left boundary
         if (point.x < 0)
            point.x = 0;

         // bottom boundary
         if (point.y >= hauteur)
            point.y = hauteur - 1;

         // upper boundary
         if (point.y < 0)
            point.y = 0;

         //-----------------------------------------------------------------------
         // draw the point
         //-----------------------------------------------------------------------
         SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
         SDL_RenderClear(renderer);

         SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
         SDL_RenderDrawPoint(renderer, point.x, point.y);
         SDL_RenderPresent(renderer);

      } // app running
   }

   ~Fenetre() {
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
   }

private:
   SDL_Window*    window         = nullptr;
   SDL_Renderer*  renderer       = nullptr;

   int largeur;
   int hauteur;

};

#endif //PRG1_LABO_SNAKES_FENETRE_H
