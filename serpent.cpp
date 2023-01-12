// -----------------------------------------------------------------------------------------------
// Fichier        : serpent.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            :
//
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <vector>

#include "serpent.h"

using namespace std;

int Serpent::prochainId = 1;

Serpent::Serpent(const Coordonnee& coordonneeTete, size_t taille) {
   // Assigne un identifiant au serpent
   id = Serpent::prochainId;
   prochainId++;

   // Place le serpent dans le trou (toutes les parties de son corps se trouvent au même endroit)
   corps = vector<Coordonnee>(taille, coordonneeTete);
}

int Serpent::getId() const {
   return id;
}

void Serpent::mange(const Pomme& pomme) {
   corps.resize(corps.size() + (size_t) pomme.getValeur(), queue());
}

void Serpent::deplacer(Direction direction) {
   // Déplace le corps du serpent
   for(size_t i = this->corps.size() - 1; i > 0; --i){
      corps[i] = corps[i+1];
   }

   // Déplace la tête du serpent
   tete() = tete() + direction;
}

Coordonnee& Serpent::tete() {
   return corps[0];
}

Coordonnee& Serpent::queue() {
   return corps[corps.size() - 1];
}

const Fenetre& operator<<(const Fenetre& fenetre, const Serpent& serpent) {
   SDL_SetRenderDrawColor(fenetre.getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);

   for(Coordonnee coordonnee : serpent.corps){
      SDL_RenderDrawPoint(fenetre.getRenderer(), coordonnee.getX(), coordonnee.getY());
   }
}