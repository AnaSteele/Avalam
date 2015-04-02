/*
 *  Fichier     Menu.h
 *  Dossier     Mini-projet "Avalam"
 *  Auteur      Marine Taliercio
 *  Date        Date de début du projet
 *
 *  On gere les menus du jeu
 */

#ifndef __avalam_test_22__aff__
#define __avalam_test_22__aff__

#include <stdio.h>
#include <iostream>
using namespace std;

class Menu
{
private:
    int choixMenu;
    char typeJoueur;
    bool _tourJoueur;
    char prenom1[15];//="Joueur1";
    char prenom2[15];//="Joueur2";
    
public:
    void menuAvalam();
    void affichageMenuJoueur();
    void lancerPartie();
    void parametres();
    void changerPionsJoueurs();
    void reglesDuJeu();
    void aPropos();
    int quitter(); 
};

#endif /* defined(__avalam_test_22__aff__) */
