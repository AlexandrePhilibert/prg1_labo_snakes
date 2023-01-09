// -----------------------------------------------------------------------------------------------
// Fichier        : annexe.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            : Fonction permettant de générer un nombre aléatoire entre un min et un max.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_ANNEXE_H
#define PRG1_LABO_SNAKES_ANNEXE_H

/**
 * @name random
 *
 * Fonction permettant de générer un nombre aléatoire entre un nombre minimal et un nombre maximal
 *
 * @param min valeur minimal que le nombre retourné peut avoir
 * @param max valeur maximal que le nombre retourné peut avoir
 * @return un nombre aléatoire dans l'interval [min, max]
 * @throws NIL
 */
int random(int min, int max);

#endif //PRG1_LABO_SNAKES_ANNEXE_H
