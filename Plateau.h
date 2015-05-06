#ifndef __Avalam__Plateau__
#define __Avalam__Plateau__

//#include "Case.h"
#include "Joueur.h"

const char pionRouge = 'R';
const char pionBleu= 'B';
const char caseInterdite= 'X';
const char caseVide= ' ';

class Plateau{
public:
    
    // Constructeur & Destructeur
    Plateau();
    Plateau(unsigned int lignes, unsigned int colonnes);
    ~Plateau();
    
    
    //
    void lectureFichier();
    void afficherPlateau();
    int scoreJoueur(char couleur);
    void affichageScoreJoueur(Joueur J1, Joueur J2);
    
private:
    char** plateau;
    unsigned int nombreDeLignes;
    unsigned int nombreDeColonnes;
};

#endif 
