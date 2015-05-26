/*
 * Fichier      Jeu.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#include <iostream>
#include "Jeu.h"
#include "Partie.h"
#include "Affichage.h"

using namespace std; 

/*
 * Fonction     Jeu()
 * Description  Methode constructeur d'un jeu
 * Arguments    Auncun
 * Renvoi       Rien
 */

Jeu::Jeu(){
    
}

/*
 * Fonction     Jeu()
 * Description  Methode destructeur d'un jeu
 * Arguments    Auncun
 * Renvoi       Rien
 */

Jeu::~Jeu(){
    
}

/*
 * Fonction     lancer()
 * Description  Fonction qui lance le jeu Avalam
 * Arguments    Auncun
 * Renvoi       Rien
 */

void Jeu::lancer(){
    Affichage A;
    A.menuJeu();
    int choixMenu=A.lireChoixMenuJeu();
    switch(choixMenu){
        case 1:{
            int continuer=0;
            while(continuer==0){
                Partie P(1);
                continuer=P.jouerPartie();
                cout << "VOULEZ VOUS QUITTER LE JEU ?" << endl;
                cout << "  0 - NON       1 - OUI" << endl;
                cin>>continuer;
            }
            break;
        }
            
        case 2:{
            A.reglesDuJeu();
            char revenirMenuPrincipal;
            while(revenirMenuPrincipal!='o' || revenirMenuPrincipal!='O' || revenirMenuPrincipal!='n' || revenirMenuPrincipal!='N'){
                cout << "REVENIR AU MENU PRINCIPAL ? (O-N) >> ";
                cin >> revenirMenuPrincipal;
                cout << endl;
                if (revenirMenuPrincipal=='o' || revenirMenuPrincipal=='O') lancer();
                else if (revenirMenuPrincipal=='n' || revenirMenuPrincipal=='N') A.reglesDuJeu();
                else cout << "ERREUR" << endl;
            }
            break;
        }
            
        case 3:{
            A.aPropos();
            char revenirMenuPrincipal;
            while(revenirMenuPrincipal!='o' || revenirMenuPrincipal!='O' || revenirMenuPrincipal!='n' || revenirMenuPrincipal!='N'){
                cout << "REVENIR AU MENU PRINCIPAL ? (O-N) >> ";
                cin >> revenirMenuPrincipal;
                cout << endl;
                if (revenirMenuPrincipal=='o' || revenirMenuPrincipal=='O') lancer();
                else if (revenirMenuPrincipal=='n' || revenirMenuPrincipal=='N') A.aPropos();
                else cout << "ERREUR" << endl;
            }
            break;
        }
            
        case 4:{
            cout << endl;
            cout << "AUREVOIR" << endl;
            A.quitterLeJeu();
            break;
        }
            
        default:{
            cout << "ERREUR : LE MENU N'EXISTE PAS" << endl;
            lancer();
            break;
        }
    }
}
