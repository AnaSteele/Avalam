/*
 * Fichier      Partie.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#include <iostream>
#include<fstream>
#include "Partie.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Affichage.h"

using namespace std;

/*
 * Fonction     Partie(int i)
 * Description  Methode constructeur d'une partie
 * Arguments    int i
 * Renvoi       Rien
 */

Partie::Partie(int i){

}

/*
 * Fonction     ~Partie()
 * Description  Methode destructeur d'une partie
 * Arguments    Auncun
 * Renvoi       Rien
 */

Partie::~Partie(){

}

/*
 * Fonction     jouerPartie()
 * Description  Fonction pour jouer une partie
 * Arguments    Auncun
 * Renvoi       int
 */

int Partie::jouerPartie(){
    string name;
    Joueur J1(1,name,0,' ');
    Joueur J2(2,name,0,' ');
    J1.saisieNomJoueur();
    
    cout << "**************************************" << endl;
    cout << "******* CHOIX DE L'ADVERSAIRE ********" << endl;
    cout << "**************************************" << endl;
    cout << "   1 - HUMAIN       2 - ORDINATEUR" << endl;
    cout << "CHOIX >> ";
    int choixAdversaire;
    cin >> choixAdversaire;
    
    switch(choixAdversaire){
        case 1:{
            J2.saisieNomJoueur();
            cout << endl;
            cout << J1.getNom() << " VS " << J2.getNom() << endl;
            break;
        }
                
        case 2:{
            J2.setNom("ORDINATEUR");
            cout << endl;
            cout << J1.getNom() << " VS " << J2.getNom() << endl;
            break;
        }
                    
        default:{
            cout << "ERREUR : LE MENU N'EXISTE PAS" << endl;
            break;
        }
    }
    
    string choixJoueur;
    cout << endl;
    cout << "ENTRER VOTRE PRENOM POUR COMMENCER EN PREMIER >> ";
    cin >> choixJoueur;
    if(choixJoueur==J1.getNom()) tourJoueur=true;
    else if (choixJoueur==J2.getNom()) tourJoueur=false;
    else{
        while(choixJoueur!=J1.getNom() && choixJoueur!=J2.getNom()){
            cout << "ERREUR >> MAUVAIS PRENOM >> ";
            cin >> choixJoueur;
        }
    }
    
    cout << endl;
    cout << "***************************************" << endl;
    cout << "**** CHOIX DE LA COULEUR DES TOURS ****" << endl;
    cout << "***************************************" << endl;
    cout << "       1 - BLEU       2 - ROUGE" << endl;
    if(tourJoueur==true){
        J1.choixCouleurTour();
        cout << J1.getNom() << " A LES TOURS " << J1.getCouleur();
        if(J1.getCouleur()==tourRouge){
            J2.setTour(tourBleu);
            cout << " DONC " << J2.getNom() << " A LES TOURS " << J2.getCouleur() << endl;
        }
        else {
            J2.setTour(tourRouge);
            cout << " DONC " << J2.getNom() << " A LES TOURS " << J2.getCouleur() << endl;
        }
    }
    else {
        J2.choixCouleurTour();
        cout << J2.getNom() << " A LES TOURS " << J2.getCouleur();
        if(J2.getCouleur()==tourRouge){
            J1.setTour(tourBleu);
            cout << " DONC " << J1.getNom() << " A LES TOURS " << J1.getCouleur() << endl;
        }
        else {
            J1.setTour(tourRouge);
            cout << " DONC " << J1.getNom() << " A LES TOURS " << J1.getCouleur() << endl;
        }
    }
    
    cout << endl;
    cout << "***************************************" << endl;
    cout << "**** CHOIX DE LA TAILLE DES TOURS *****" << endl;
    cout << "***************************************" << endl;
    int choixTaille;
    cout << "   1 - TOURS DE 5 PIONS" << endl;
    cout << "   2 - MODIFICATION" << endl;
    cout << "CHOIX >> ";
    cin >> choixTaille;
    switch(choixTaille){
        case 1:{
            compteur=5;
            break;
        }
        case 2:{
            int tours;
            cout << "NOMBRE DE TOURS MAX SUR UNE CASE >> " ;
            cin >> tours;
            compteur=tours;
            break;
        }
            
        default:
            cout << "ERREUR" << endl;
            break;
    }
    
    cout << endl;
    cout << "***************************************" << endl;
    cout << "********** TAILLE DU PLATEAU **********" << endl;
    cout << "***************************************" << endl;
    cout << "   1 - PLATEAU CLASSIQUE (9X9)" << endl;
    cout << "   2 - PLATEAU MODIFIE (.x.)" << endl;
    cout << "CHOIX >> ";
    int choixPlateau;
    cin >> choixPlateau;
    switch(choixPlateau){
        case 1:{
            Plateau p(9,9);
            p.lectureFichier();
            p.afficherPlateau();
            
            do{
                aQuiDeJouer();
                Affichage A;
                A.menuJoueur();
                if(tourJoueur==false) cout << J1.getNom();
                else cout << J2.getNom();
                cout << ", QUE VOULEZ-VOUS FAIRE >> ";
                int choixMenuJoueur=A.lireChoixMenuJoueur();
                switch (choixMenuJoueur) {
                    case 1:{
                        p.setCompteurMax(compteur);
                        p.demandeDeplacement();
                        p.afficherPlateau();
                        cout << "********************************************" << endl;
                        cout << "****************** SCORES ******************" << endl;
                        cout << "********************************************" << endl;
                        cout << J1.getNom() <<  " >> " << /*RED << */ p.scoreJoueur(tourRouge) << /*CANCEL << */ endl;
                        cout << J2.getNom() << " >> " << /*RED << */ p.scoreJoueur(tourBleu) << /*CANCEL << */ endl;
                       
                        break;
                    }
                
                    case 2:{
                        if(tourJoueur==false) tourJoueur=true;
                        else tourJoueur=false;
                        cout << "PAUSE";
                        int c;
                        while((c=getchar())!='\n' && c!=EOF);
                        getchar();
                        break;
                    }
                
                    case 3:{
                        cout << "QUITTER LA PARTIE" << endl;
                        quitter=true;
                        break;
                    }
                    case 4:{
                        cout <<"sauvegarde" << endl;
                        ofstream fichier;
                        fichier.open("/Users/Admin/Desktop/Avalam/Avalam/maPremiereSauvegarde.txt", ios::out); //ouverture en ecriture
                        if(fichier.bad()) return 1;
                        fichier << J1.getNom() << endl;
                        fichier <<endl;
                        fichier.close();
                        break;
                    }
                
                    default:{
                        cout << "ERREUR : LE MENU CHOISI N'EXISTE PAS" << endl;
                        if(tourJoueur==false) tourJoueur=true;
                        else tourJoueur=false;
                        A.lireChoixMenuJeu();
                        break;
                    }
                }
                 p.testSiFinPartie();
                if(p.victoire()==true){
                    quitter=true; 
                }
            }while(quitter!=true );
               break;
        }
            
        case 2:{
            int l, c;
            cout << "TAILLE DU PLATEAU >> " ;
            cout << "lignes >> ";
            cin >> l;
            cout << "colonnes >> ";
            cin >> c;
            Plateau p(l,c);
            p.afficherPlateau();
            break;
        }
            
        default:
            break;
    }
    return 0;
}

/*
 * Fonction     aQuiDeJouer()
 * Description  Fonction qui gère la main des joueurs
 * Arguments    Auncun
 * Renvoi       bool
 */

bool Partie::aQuiDeJouer(){
    if(tourJoueur==true) tourJoueur=false;
    else tourJoueur=true;
    return tourJoueur;
}

/*void Partie::sauvegarde(){
    ofstream fichier;
    fichier.open("/Users/Admin/Desktop/Avalam/Avalam/maPremiereSauvegarde.txt", ios::out); //ouverture en ecriture
    if(fichier.bad()) return 1;
    fichier << J1.getNom()
}*/



