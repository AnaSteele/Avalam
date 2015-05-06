

/*
 * Inclusions
 */

#include <iostream>
#include "Partie.h"
#include "Joueur.h"
#include "Plateau.h"

using namespace std;

Partie::Partie(int i){
    
}

Partie::~Partie(){
    
}

int Partie::jouerPartie(){
    string name;
    Joueur J1(1,name,0);
    Joueur J2(2,name,0);
    J1.saisieNomJoueur();
    
    cout << "**************************************" << endl;
    cout << "******* CHOIX DE L'ADVERSAIRE ********" << endl;
    cout << "**************************************" << endl;
    cout << "   1 - HUMAIN       2 - ORDINATEUR" << endl;
    int choixAdversaire;
    cin >> choixAdversaire;
    switch(choixAdversaire){
        case 1:{
            J2.saisieNomJoueur();
            break;
        }
            
        default:
            break;
    }
    
    string choixJoueur;
    cout << "entrer votre prenom pour commencer en premier >> ";
    cin >> choixJoueur;
    if(choixJoueur==J1.getNom()) tourJoueur=false;
    else if (choixJoueur==J2.getNom()) tourJoueur=true;
    else{
        while(choixJoueur!=J1.getNom() && choixJoueur!=J2.getNom()){
            cout << "mauvais prenom, re saisir >> ";
            cin >> choixJoueur;
        }
    }
    
    Plateau p(9,9);
    p.lectureFichier();
    p.afficherPlateau();
    
    cout << "********************************************" << endl;
    cout << "****************** SCORES ******************" << endl;
    cout << "********************************************" << endl;
    cout << J1.getNom() <<  " >> " << /*RED << */ p.scoreJoueur(pionRouge) << /*CANCEL << */ endl;
    cout << J2.getNom() << " >> " << /*RED << */ p.scoreJoueur(pionBleu) << /*CANCEL << */ endl;

    return 0;
}






