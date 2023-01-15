// -----------------------------------------------------------------------------------------------
// Fichier        : serpent.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-10
// But            : Représentation d'un point sur un plan x et y.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_COORDONNEE_H
#define PRG1_LABO_SNAKES_COORDONNEE_H

#include <vector>

enum class Direction { NORD, SUD, OUEST, EST };

class Coordonnee {
public:
   explicit Coordonnee(int x = 0, int y = 0);

   int getX() const;
   int getY() const;

   /**
    * Permet de récupérer les coordonnées absolues
    *
    * @return
    */
   Coordonnee abs() const;

   /**
    * Génère une coordonnée aléatoire entre 0 et la position maximum passée en paramètre.
    *
    * @param xMax   La coordonnée x maximum
    * @param yMax   La coordonnée y maximum
    * @throws NIL
    * @return       La position créer aléatoirement
    */
   static Coordonnee random(int xMax, int yMax);

   /**
    * Remplis de l'itérateur de début jusqu'à l'itérateur de fin un vecteur avec des coordonnées uniques.
    *
    * @param debut  L'itérateur de début du vecteur
    * @param fin    L'itérateur de fin du vecteur
    * @param xMax   La position x maximum que prendra la position
    * @param yMax   La position y maximum que prendra la position
    * @throws NIL
    * @return void
    */
   static void unique(std::vector<Coordonnee>::iterator debut, std::vector<Coordonnee>::iterator fin, int xMax, int yMax);

   bool operator==(const Coordonnee& position) const;
   Coordonnee operator+(Direction direction) const;
   Coordonnee operator-(const Coordonnee& coordonnee) const;

private:
   int x;
   int y;
};

Coordonnee operator+(Direction direction, const Coordonnee& position);
Direction& operator++(Direction& direction);

#endif //PRG1_LABO_SNAKES_COORDONNEE_H
