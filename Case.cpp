/*
 * Fichier      Case.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#include "Case.h"
#include <iostream>

using namespace std;

/*
 * Fonction     Case()
 * Description  Methode constructeur d'une case
 * Arguments    Auncun
 * Renvoi       Rien
 */

Case::Case(){
    
}

/*
 * Fonction     Case(unsigned int l, unsigned int c, char t, unsigned int cpt)
 * Description  Methode constructeur d'une case du plateau
 * Arguments    unsigned int l
                unsigned int c
                char t
                unsigned cpt
 * Renvoi       Rien
 */

Case::Case(unsigned int l, unsigned int c, char t, unsigned int cpt){
    ligne=l;
    colonne=c;
    tour=t;
    compteur=cpt;
}

/*
 * Fonction     ~Case()
 * Description  Methode destructeur d'une case
 * Arguments    Auncun
 * Renvoi       Rien
 */

Case::~Case(){
    
}

/*
 * Fonction     getTour()
 * Description  Fonction qui renvoie le caractère(tour) de la case
 * Arguments    Aucun
 * Renvoi       char tour
 */

char Case::getTour(){
    return tour;
}

/*
 * Fonction     setTour(char t)
 * Description  Fonction qui met à jour le caractère(tour) de la case
 * Arguments    char t
 * Renvoi       Rien
 */

void Case::setTour(char t){
    tour=t; 
}

/*
 * Fonction     getLigne()
 * Description  Fonction qui renvoie la ligne de la case
 * Arguments    Aucun
 * Renvoi       int ligne
 */

int Case::getLigne(){
    return ligne;
}

/*
 * Fonction     setLigne(unsigned int l)
 * Description  Fonction qui met à jour la ligne de la case
 * Arguments    unsigned int l
 * Renvoi       Rien
 */

void Case::setLigne(unsigned int  l){
    ligne=l;
}

/*
 * Fonction     getColonne()
 * Description  Fonction qui renvoie la colonne de la case
 * Arguments    Aucun
 * Renvoi       int colonne
 */

int Case::getColonne(){
    return colonne;
}

/*
 * Fonction     setColonne(unsigned int c)
 * Description  Fonction qui met à jour la colonne  de la case
 * Arguments    unsigned int c
 * Renvoi       Rien
 */

void Case::setColonne(unsigned int  c){
    colonne=c;
}

/*
 * Fonction     getCompteur()
 * Description  Fonction qui renvoie le compteur de la case
 * Arguments    Aucun
 * Renvoi       int compteur
 */

int Case::getCompteur(){
    return compteur;
}

/*
 * Fonction     setCompteur(unsigned int cpt)
 * Description  Fonction qui met à jour le compteur de la case
 * Arguments    unsigned int cpt
 * Renvoi       Rien
 */

void Case::setCompteur(unsigned int  cpt){
    compteur=cpt;
}

