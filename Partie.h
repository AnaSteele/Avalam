
/*
 * Inclusions
 */

#ifndef __Avalam__Partie__
#define __Avalam__Partie__

#include "Joueur.h"
#include "Coup.h"

class Partie{
public:
    
    // Constructeur & Destructeur
    Partie(int i);
    ~Partie();
    
    //
    int jouerPartie();
    void ajoutCoup(Coup c);
    void afficherTabCoups();
    void affichageScoreJoueur(Joueur J1, Joueur J2); 
    
private:
    Coup* tabCoups;
    bool tourJoueur; 
};

#endif
