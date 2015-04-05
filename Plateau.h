/*
 *  Fichier     Plateau.h
 *  Dossier     Mini-projet "Avalam"
 *  Auteur     
 *  Date        Date de début du projet
 *
 *  Cette classe nous sert a gerer le plateau du jeu
 */

#ifndef __avalam_test_22__Plateau__
#define __avalam_test_22__Plateau__

#include        <stdio.h>
#include        <iostream>
#include        <string>
#include        <ncurses.h>
#include        <vector>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define CANCEL  "\033[00m"


using namespace std;

const char      pionRouge   = 'R';
const char      pionJaune   = 'J';
const int       caseVide    = ' ';

const char      joueurHumain    = 'h';
const char      joueurOrdi      = 'o';

struct CoordonneesCase{
    int         ligne;
    int         colonne;
};

inline bool operator==(CoordonneesCase const& c1, CoordonneesCase const& c2){
    return c1.ligne==c2.ligne && c1.colonne==c2.colonne;
}

inline bool operator!=(CoordonneesCase const& c1, CoordonneesCase const& c2){
    return !(c1==c2);
}

inline bool operator<(CoordonneesCase const& c1, CoordonneesCase const& c2){
    return c1.ligne+c1.colonne < c2.ligne+c2.colonne;
}

inline bool operator>(CoordonneesCase const& c1, CoordonneesCase const& c2){
    return !(c1<c2) && c1!=c2;
}


class Plateau{
    
public:
    
    // Constructeur et Destructeur
    Plateau();
    ~Plateau();
    
    // Autres methodes
    void        initialiser();
    void        afficher();
    int         scoreJoueurs(char _couleur);
    int         testSiFinDePartie(char _couleur, char _typeJoueur);
    void        mettrePartieNulle();
    void        joueurHumain();
    void        effectuerDeplacement(char _lacouleur,CoordonneesCase _Depart, CoordonneesCase _Arrivee);

    // Autres Methodes
    void        prenomsJoueurs(char _typeJoueur);
    bool        aQuiDeJouer();
    void        joueEnPremier();
    void        menuJoueur();
    void        lancerMenuJoueur();
    int         quitter();
    void        tabCoupJoue();
    void        deplacementPossible();
    void        testBasGauche();
    void        testHautGauche();
    void        testBasDroite();
    void        testHautDroite();
    void        chercherCoordonneesTour();
    void        choixPrenomsJoueurs();
    
    
private:
    
    char**      _plateau;
    char        _typeJoueur;
    
    int         _colonnes;
    int         _lignes;
    int         _partieNulle;
    int         _nbrLignes ;
    int         _nbrColonnes ;
    int         _couleur;
    
    bool        _tourJoueur;
    bool        _deplacement; 
    
    string      _prenom1;
    string      _prenom2;
    
    CoordonneesCase     _Depart;
    CoordonneesCase     _Arrivee;
    
    vector<CoordonneesCase>     _tab;
    vector<CoordonneesCase>     _coordonneesEntrees;
    vector<CoordonneesCase>     _vectorDeCoordConnues;
};


#endif
