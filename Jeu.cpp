
/*
 * Inclusions
 */

#include <iostream>
#include "Jeu.h"
#include "Partie.h"
#include "Affichage.h"

using namespace std; 

Jeu::Jeu(){
    
}

Jeu::~Jeu(){
    
}

void Jeu::lancer(){
    
    /*int continuer=0;
    while(continuer==0){
        Partie P(1);
        continuer=P.jouerPartie();
        cout << "voulez vous continuer ? (0/1)";
        cin>>continuer;
    }*/
    
    
    Affichage A;
    A.menuJeu();
    int choixMenu=A.lireChoixMenuJeu();

        switch(choixMenu){
            
        case 1:{
            int continuer=0;
            while(continuer==0){
                Partie P(1);
                continuer=P.jouerPartie();
                cout << "voulez vous continuer ? (0/1)";
                cin>>continuer;
            }
            break;
        }
            
        case 2:{
            A.reglesDuJeu();
            char revenirMenuPrincipal;
            while(revenirMenuPrincipal!='o' || revenirMenuPrincipal!='O' || revenirMenuPrincipal!='n' || revenirMenuPrincipal!='N'){
                cout << "Voulez vous revenir au Menu Principal ? (O-N) >> ";
                cin >> revenirMenuPrincipal;
                cout << endl;
                if (revenirMenuPrincipal=='o' || revenirMenuPrincipal=='O') lancer();
                else if (revenirMenuPrincipal=='n' || revenirMenuPrincipal=='N') A.reglesDuJeu();
                else cout << "ERREUR" << endl;
            }
            break;
        }
            
        case 3:{
                A.parametresDuJeu();
                break;
            }
            
        case 4:{
            A.aPropos();
            char revenirMenuPrincipal;
            while(revenirMenuPrincipal!='o' || revenirMenuPrincipal!='O' || revenirMenuPrincipal!='n' || revenirMenuPrincipal!='N'){
                cout << "Voulez vous revenir au Menu Principal ? (O-N) >> ";
                cin >> revenirMenuPrincipal;
                cout << endl;
                if (revenirMenuPrincipal=='o' || revenirMenuPrincipal=='O') lancer();
                else if (revenirMenuPrincipal=='n' || revenirMenuPrincipal=='N') A.aPropos();
                else cout << "ERREUR" << endl;
            }
            break;
        }
            
        case 5:{
            cout << "* QUITTER LE JEU *" << endl;
            A.quitterLeJeu();
            break;
        }
            
        default:{
            cout << "ERREUR >> LE MENU QUE VOUS AVEZ CHOISI N'EXISTE PAS " << endl;
            lancer(); 
            break;
        }
    }
    
}
