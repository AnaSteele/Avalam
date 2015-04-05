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

class Menu{

public:
    void        menuAvalam();
    void        lancerPartie();
    void        parametres();
    void        reglesDuJeu();
    void        aPropos();
    bool readChoix(int choix);
    int         quitter();

private:
    int         _choixMenu;
    char        _typeJoueur;
    bool        _tourJoueur;
};

#endif 
