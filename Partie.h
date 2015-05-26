/*
 * Fichier      Partie.h
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#ifndef __Avalam__Partie__
#define __Avalam__Partie__

#include "Joueur.h"

class Partie{
private:
    bool tourJoueur;
    bool quitter;
    
    int compteur;
    
public:
    Partie(int i);
    ~Partie();

    int jouerPartie();
    
    void affichageScoreJoueur(Joueur J1, Joueur J2);
    
    bool aQuiDeJouer();
};

#endif
