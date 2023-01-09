

// -----------------------------------------------------------------------------------------------
// Fichier        : saisie.h
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            : Fonctions responsables de la saisie utilisateur et la
// 					  vérification de celle-ci, ainsi que la gestion du flux, des
// 					  éventuelles erreurs et la fin du programme.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_SNAKES_SAISIE_H
#define PRG1_LABO_SNAKES_SAISIE_H

#include <string>

/**
 *  Affiche un message de bienvenue et vérifie si la saisie utilisateur est comprise
 *  entre min et max. Retourne la valeur saisie par l'utilisateur si celle-ci
 *  est correcte, autrement affiche un message d'erreur.
 *
 *  Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/40f1ef41f8f2ee1d8c1a1c7fc1cc562b88e620c8/04_Fonctions/04_nbreJoursMois.cpp#L45
 */
int saisie(const std::string& msgInvite,
           const std::string& msgErreur,
           int min,
           int max);

#endif //PRG1_LABO_SNAKES_SAISIE_H
