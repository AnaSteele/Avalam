/*
 * Fichier      Plateau.h
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */


#ifndef __Avalam__Plateau__
#define __Avalam__Plateau__

#include "Case.h"
#include "Joueur.h"

class Plateau{
private:
    Case** plateau;
    
    Case Depart;
    Case Arrivee;
    
    unsigned int nombreDeLignes;
    unsigned int nombreDeColonnes;
    
    char couleur;
    
    int compteurMax;
    int ligne;
    int colonne; 
    
    bool diagonaleBasDroite;
    bool diagonaleBasGauche;
    bool diagonaleHautDroite;
    bool diagonaleHautGauche;
    bool haut;
    bool droite;
    bool gauche;
    bool bas;
    bool tourPleine;
    bool tourNonPleine;
    bool finPartie;
    bool victoirePartie;
    bool test;
    
    
public:
    Plateau();
    Plateau(unsigned int lignes, unsigned int colonnes);
    ~Plateau();
    
    void lectureFichier();
    void afficherPlateau();
    void demandeDeplacement();
    void deplacementPossible();
    void effectuerDeplacement(char couleur,Case Depart, Case Arrivee);
    void setCompteurMax(unsigned int  cptMax);
    
    bool testDepart();
    bool testArrivee();
    bool testDiagonaleBasDroite();
    bool testDiagonaleBasGauche();
    bool testDiagonaleHautGauche();
    bool testDiagonaleHautDroite();
    bool testBas();
    bool testHaut();
    bool testDroite();
    bool testGauche();
    bool estUneTourNonPleine(unsigned int ligne, unsigned int colonne);
    bool estUneTourPleine(unsigned int ligne, unsigned int colonne);
    bool testSiFinPartie();
    bool victoire();
    
    int scoreJoueur(char couleur);
    int getCompteurMax();
};

#endif 
