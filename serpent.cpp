// -----------------------------------------------------------------------------------------------
// Fichier        : serpent.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            :Représente un serpent pouvant se déplacer, manger des pommes, mordre d'autres
//                 serpents ainsi que grandir de taille
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <vector>

#include "serpent.h"
#include "annexe.h"

using namespace std;

int Serpent::prochainId = 1;

const double Serpent::POURCENTAGE_CROISSANCE_SERPENT_TUE = 0.6;

const double Serpent::POURCENTAGE_CROISSANCE_SERPENT_MORDU = 0.4;

Serpent::Serpent(const Coordonnee& coordonneeTete, size_t taille): id(Serpent::prochainId) {
   // Incrémente l'id qui sera attribué au prochain serpent
   prochainId++;

   // Place le serpent dans le trou (toutes les parties de son corps se trouvent au même endroit)
   corps = vector<Coordonnee>(taille, coordonneeTete);
}

int Serpent::getId() const {
   return id;
}

size_t Serpent::longueur() const {
   return corps.size();
}

ResultatCombat Serpent::combat(Serpent& serpent) {
   Serpent& vainqueur = longueur() > serpent.longueur() ? *this : serpent;

   // Dans le cas ou les serpents font la même longueure
   if(longueur() == serpent.longueur()){
      vainqueur = random(0, 1) ? *this : serpent; // Sélécitonne aléatoirement un gagnant
   }

   Serpent& perdant = *this == vainqueur ? serpent : *this;

   vainqueur.redimensionner(perdant.corps.size() + (size_t) ((double) perdant.longueur() * POURCENTAGE_CROISSANCE_SERPENT_TUE));
   return { vainqueur, perdant };
}

void Serpent::mange(const Pomme& pomme) {
   // Lorsqu'un serpent mange une pomme, son corps s'agrandit de la valeur de la pomme, les
   // nouveaux bouts de son corps se trouvent tous sur la position de sa queue.
   redimensionner(corps.size() + (size_t) pomme.getValeur());
}

void Serpent::mord(Serpent& serpent) {
   vector<Coordonnee>::iterator it = find(serpent.corps.begin(), serpent.corps.end(), tete());

   // Ajoute les 40% de la longueur coupée
   redimensionner(corps.size() + (size_t) ((double) distance(it, serpent.corps.end()) * POURCENTAGE_CROISSANCE_SERPENT_MORDU));

   serpent.corps.erase(it, serpent.corps.end());
}

void Serpent::redimensionner(size_t longueur) {
   corps.resize(longueur, queue());
}

void Serpent::deplacer(Direction direction) {
   // Déplace le corps du serpent
   for(size_t i = corps.size() - 1; i > 0; --i){
      corps[i] = corps[i-1];
   }

   // Déplace la tête du serpent
   tete() = tete() + direction;
}

Coordonnee& Serpent::tete() {
   return corps[0];
}

const Coordonnee& Serpent::tete() const {
   return corps[0];
}

Coordonnee& Serpent::queue() {
   return corps[corps.size() - 1];
}

const Fenetre& operator<<(const Fenetre& fenetre, const Serpent& serpent) {
   SDL_SetRenderDrawColor(fenetre.getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);

   // Effectue le rendu de chaque bout du corps du serpent
   for(const Coordonnee& coordonnee : serpent.corps) {
      SDL_RenderDrawPoint(fenetre.getRenderer(), coordonnee.getX(), coordonnee.getY());
   }

   return fenetre;
}

bool Serpent::operator==(const Serpent &serpent) const {
   return this->id == serpent.id;
}

bool Serpent::operator!=(const Serpent &serpent) const {
   return !(*this == serpent);
}

std::ostream& operator<<(ostream &os, const Serpent& serpent) {
   os << serpent.id;

   return os;
}

Serpent &Serpent::operator=(const Serpent& serpent) {
   if (this != &serpent) {
      this->corps = serpent.corps;
      (int&) this->id = serpent.id;
   }

   return *this;
}
