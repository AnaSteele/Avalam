/*
 * Fichier      Case.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

/*
 * Inclusions
 */

#include "Case.h"

Case::Case(){
    
}

Case::~Case(){
    
}

Case::Case(int l, int c, char t, int cpt){
    ligne=l;
    colonne=c;
    tour=t;
    compteur=cpt;
}

char Case::getTour(){
    return tour;
}

int Case::getLigne(){
    return ligne;
}

int Case::getColonne(){
    return colonne;
}

int Case::getCompteur(){
    return compteur;
}








