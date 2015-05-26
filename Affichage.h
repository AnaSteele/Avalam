/*
 * Fichier      Affichage.h
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#ifndef __Avalam__Affichage__
#define __Avalam__Affichage__

class Affichage{
private:
    int choixMenu;
    int choixMenuJoueur;

public:
    void menuJoueur();
    void menuJeu();
    void aPropos();
    void reglesDuJeu();
    
    int lireChoixMenuJeu();
    int quitterLeJeu();
    int lireChoixMenuJoueur();
};


#endif 
