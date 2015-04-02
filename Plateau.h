/*
 *  Fichier     Plateau.h
 *  Dossier     Mini-projet "Avalam"
 *  Auteur      Marine Taliercio
 *  Date        Date de début du projet
 *
 *  Cette classe nous sert a gerer le plateau du jeu
 */

#ifndef __avalam_test_22__Plateau__
#define __avalam_test_22__Plateau__

#include <stdio.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CANCEL "\033[00m"
#include <vector>

using namespace std;

const char pionRouge = 'R';
const char pionJaune = 'J';
const int caseVide = ' ';

const char joueurHumain = 'h';
const char joueurOrdi = 'o';

struct CoordonneesCase{
    int ligne;
    int colonne;
};





class Plateau{
public:
    
    // Constructeur et Destructeur
    Plateau();
    ~Plateau();
    
    // Autres methodes
    void initialiser2();
    void initialiser();
    void afficher();
    int scoreJoueurs(char couleur);
    int testSiFinDePartie(char couleur, char typeJoueur);
    void mettrePartieNulle();
    void joueurHumain();
    int testSiDeplacementPossible(CoordonneesCase Depart, CoordonneesCase Arrivee);
    bool effectuerDeplacement(char lacouleur,CoordonneesCase Depart, CoordonneesCase Arrivee);
    bool estUneTour();

    // Autres Methodes
    void prenomsJoueurs(char typeJoueur);
    bool aQuiDeJouer();
    void joueEnPremier();
    void menuJoueur();
    void lancerMenuJoueur();
    void jouer();
    void testLire();
    void testEcrire();
    int quitter();
    void testEcrire2();
    void comparer();
    bool testLire2();
   // bool comparer;
    void tabCoupJoue();
    //bool operator==(CoordonneesCase const& c1, CoordonneesCase const& c2);
    //bool operator!=(CoordonneesCase const& c1, CoordonneesCase const& c2);
    void deplacementPossible();
    void testBasGauche();
    void testHautGauche();
    void testBasDroite();
    void testHautDroite();
    void chercherCoordonneesTour(); 
    
    
private:
    char** plateau;
    int partieNulle;
    int _nbrLignes ;
    int _nbrColonnes ;
    bool _tourJoueur;
    int couleur;
    int _nbrPionsAEmpiler;
    
    char prenom1[15];//="Joueur1";
    char prenom2[15];//="Joueur2";
    int colonnes, lignes;
    
    CoordonneesCase Depart;
    CoordonneesCase Arrivee;
    int cpt;
    vector<CoordonneesCase> tab;
};


#endif /* defined(__avalam_test_22__Plateau__) */
