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

#include <iostream>
#include <cstdlib>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

using namespace std;

int main() {
   SDL_Window*    window         = nullptr;
   SDL_Renderer*  renderer       = nullptr;
   bool           appIsRunning   = true;

   const int      WINDOW_WIDTH   = 80;
   const int      WINDOW_HEIGTH  = 50;
   const int      SCALE          = 10;
   const int      STEP           =  1;

   SDL_Init(SDL_INIT_VIDEO);
   SDL_CreateWindowAndRenderer(WINDOW_WIDTH  * SCALE,
                               WINDOW_HEIGTH * SCALE,
                               SDL_WINDOW_SHOWN,
                               &window, &renderer);

   if (window == nullptr or renderer == nullptr) {
      cout << "SDL not ready ... quitting" << endl;
      exit(EXIT_FAILURE);
   }

   SDL_SetWindowTitle(window, "SDL Demo / Moving points");
   SDL_RenderSetScale(renderer, SCALE, SCALE);

   // point to show
   SDL_Point point;
   point.x = WINDOW_WIDTH  / 2;
   point.y = WINDOW_HEIGTH / 2;

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
      if (point.x >= WINDOW_WIDTH)
         point.x = WINDOW_WIDTH - 1;

      // left boundary
      if (point.x < 0)
         point.x = 0;

      // bottom boundary
      if (point.y >= WINDOW_HEIGTH)
         point.y = WINDOW_HEIGTH - 1;

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

   // destroy SDL ressources
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();

   return EXIT_SUCCESS;
}
