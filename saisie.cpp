// -----------------------------------------------------------------------------------------------
// Fichier        : saisie.cpp
// Auteur(s)      : DURGERDIL Noam & PHILIBERT Alexandre
// Date           : 2022-01-09
// But            : Fonctions responsables de toute la saisie utilisateur, gestion
// 					  du flux, répétition ou fin du programme.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream> // cin et cout
#include <iomanip>  // setw
#include <limits>   // numeric_limits
#include <string>

#include "saisie.h"

using namespace std;

const int LARGEUR_MESSAGE_INVITE = 12;

int saisie(const string& msgInvite,
           const string& msgErreur,
           const int min,
           const int max
) {
   int  saisie;
   bool erreur;

   do {
      // saisie et vérification
      cout << left << setw(LARGEUR_MESSAGE_INVITE) << msgInvite << " [" << min << ".." << max << "] : ";

      erreur = !(cin >> saisie) || saisie < min || saisie > max;

      // gestion du flux
      if (erreur) {
         cout << msgErreur << endl;
         cin.clear();
      }

      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while(erreur);

   return saisie;
}