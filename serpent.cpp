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

void Serpent::deplacer(Direction direction) {
   // TODO: Déplacer la tête du serpent (fonction tete()) puis faire suivre toutes les parties
   // Déplace le corps du serpent
   for(size_t i = this->corps.size() - 1; i > 0; --i){
      this->corps[i] = this->corps[i+1];
   }

   // Déplace la tête du serpent
   this->tete() = this->tete() + direction;
}

Coordonnee& Serpent::tete(){
   return this->corps[0];
}
