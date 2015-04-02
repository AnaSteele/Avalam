/*
 *  Fichier     Menu.cpp
 *  Dossier     Mini-projet "Avalam"
 *  Auteur      Marine Taliercio
 *  Date        Date de début du projet
 *
 *  On gere les menus du jeu
 */

#include <iostream>
#include "Menu.h"
#include "Plateau.h"
//#include "Joueur.h"
using namespace std;

/*
 *  Fonction        Menu::menuAvalam()
 *  Description     Affichage du menu principal du jeu
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

void Menu::menuAvalam(){
    cout << "********************************************" << endl;
    cout << "****************** AVALAM ******************" << endl;
    cout << "********************************************" << endl;
    cout << "           1- JOUEUR vs JOUEUR" << endl;
    cout << "           2- JOUEUR vs ORDINATEUR" << endl;
    cout << "           3- REGLES DU JEU" << endl;
    cout << "           4- PARAMETRES" << endl;
    cout << "           5- A PROPOS" << endl;
    cout << "           0- QUITTER" << endl;
}

/*
 *  Fonction        Plateau::lancerPartie()
 *  Description     Methode qui gere toutes les fonctions du jeu
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

void Menu :: lancerPartie(){
    
    menuAvalam();

    cout << endl;
    cout << "Veuillez choisir votre menu >>> ";
    cin >> choixMenu ;
    cout << endl;
    
    switch (choixMenu)
    {
        case 1:{
            bool gagner=false;
            typeJoueur='h';
            cout << "QUE LA PARTIE COMMENCE !" << endl << endl;
            Plateau pl;
            pl.prenomsJoueurs(typeJoueur);
            pl.joueEnPremier();
            pl.aQuiDeJouer();
            pl.initialiser();
            pl.afficher();
            do{
                pl.aQuiDeJouer();
                pl.lancerMenuJoueur();
                pl.afficher();
            }while(gagner!=true);
            break;
        }
            
        case 2:{
            cout << "********************************************" << endl;
            cout << "*********** JOUEUR vs ORDINATEUR ***********" << endl;
            cout << "********************************************" << endl;
            typeJoueur='o';
            cout << "* PARTIE NON DEVELOPPEE *" << endl << endl;
        }
            
        case 3:{
            reglesDuJeu();
            char revenirMenuPrincipal;
            while(revenirMenuPrincipal!='o' || revenirMenuPrincipal!='O' || revenirMenuPrincipal!='n' || revenirMenuPrincipal!='N'){
                cout << "Voulez vous revenir au Menu Principal ? (O-N) >> ";
                cin >> revenirMenuPrincipal;
                cout << endl;
                if (revenirMenuPrincipal=='o' || revenirMenuPrincipal=='O') lancerPartie();
                else if (revenirMenuPrincipal=='n' || revenirMenuPrincipal=='N') reglesDuJeu();
                else cout << "ERREUR" << endl;
            }
            break;
        }
            
        case 4:{
            parametres();
            break;
        }
            
        case 5:{
            aPropos();
            char revenirMenuPrincipal;
            while(revenirMenuPrincipal!='o' || revenirMenuPrincipal!='O' || revenirMenuPrincipal!='n' || revenirMenuPrincipal!='N'){
                cout << "Voulez vous revenir au Menu Principal ? (O-N) >> ";
                cin >> revenirMenuPrincipal;
                cout << endl;
                if (revenirMenuPrincipal=='o' || revenirMenuPrincipal=='O') lancerPartie();
                else if (revenirMenuPrincipal=='n' || revenirMenuPrincipal=='N') aPropos();
                else cout << "ERREUR" << endl;
            }            break;
        }
            
        case 0:{
            cout << "* QUITTER LE JEU *" << endl;
            quitter();
            break;
        }
            
        default:{
            cout << "ERREUR >> LE MENU QUE VOUS AVEZ CHOISI N'EXISTE PAS " << endl;
            lancerPartie();
            break;
        }
    }
}

void Menu::aPropos(){
    cout << "********************************************" << endl;
    cout << "***************** A PROPOS *****************" << endl;
    cout << "********************************************" << endl;
    cout << "       Réalisé par Marine Taliercio" << endl;
    cout << "             L2 CERI Avignon" << endl;
    cout << "                 TD2 - TP3" << endl;
    cout << endl;
}

void Menu::parametres(){
    cout << "********************************************" << endl;
    cout << "**************** PARAMETRES ****************" << endl;
    cout << "********************************************" << endl;
    cout << "           1 - CHNAGER LA FORME DU PLATEAU" << endl;
    cout << "           2 - CHANGER LA TAILLE DU PLATEAU" << endl;
    cout << "           3 - CHANGER LES PIONS DES JOUEURS" << endl;
    cout << "           0 - REVENIR AU MENU PRINCIPAL" << endl << endl;
    
    int choixParametres=0;
    cout << "Veuillez choisir votre menu >>> ";
    cin >> choixParametres;
    switch (choixParametres) {
        case 1:
            cout << "* CHANGER LA FORME DU PLATEAU *" << endl;
            break;
            
        case 2:
            cout << "* CHANGER LA TAILLE DU PLATEAU *" << endl;
            break;
            
        case 3:
            cout << "* CHANGER LES PIONS DES JOUEURS *" << endl;
            //changerPionsJoueurs();
            break;
            
        case 0:
            lancerPartie();
            break;
            
        default:
            cout << "ERREUR >> LE MENU QUE VOUS AVEZ CHOISI N'EXISTE PAS" << endl;
            parametres();
            break;
    }
}

/*void Menu::changerPionsJoueurs(){
    char reponse;
    do{
        cout << "Voulez vous changer les pions? (O-N) >> ";
        cin >> reponse;
        if(reponse=='o' || reponse=='O') {
            char pion;
            char tabPions[]={'X','@','&','$','*','O'};
            do{
                cout << prenom1 <<", choisi ton pion  >>> ";
                cin>> pion;
                if(tabPions[pion]) cout << prenom1 << ", votre pion est " << pion << endl;
                else cout << "le pion que vous voulez n'existe pas" << endl; //voulez vous le creer ???
                
                cout << prenom2 << ", choisi ton pion  >>> ";
                if(tabPions[pion]) cout << prenom2 << ", votre pion est " << pion << endl;
                else cout << "le pion que vous voulez n'existe pas" << endl; //voulez vous le creer ???
            }while(!tabPions[pion]);
        }
        else if (reponse=='n' || reponse=='N') parametres();
        if (reponse != 'o' || reponse!='O' || reponse!='n' || reponse!='N') cout << "je n'ai pas compris votre reponse ";
    }while (reponse != 'o' || reponse!='O' || reponse!='n' || reponse!='N');
}*/


void Menu::reglesDuJeu(){
    cout << "*********************************************" << endl;
    cout << "*************** REGLES DU JEU ***************" << endl;
    cout << "*********************************************" << endl;
    cout << "BUT DU JEU" << endl;
    cout << "Possèder un maximum de tours dont le pion supérieur est de la couleur choisie." << endl;
    cout << "Une tour est constituée de 1 à 5 pions. Jamais plus." << endl << endl;
    
    cout << "REGLES DU JEU" << endl;
    cout << "Chaque joueur choisit sa couleur et chaque joueur a le droit de jouer avec tous les pions, y compris ceux de l'adversaire." << endl << endl;
    
    cout << "DEPLACEMENTS" << endl;
    cout << "A tour de rôle, chaque joueur effectue un seul deplacement à partir de n'importe quel pion ou pile de pions. Chacun est donc libre de jouer où bon lui semble. Un deplacement consiste à empiler le ou les pions sur un emplacement directement voisin (diagonale=ok) déjà occupé par un ou plusieurs pions (jamais sur un trou vide). " << endl;
    cout << "-> Chaque coup joué équivaut donc à libérer un emplacement"  << endl;
    cout << "-> Il est interdit de passer au-dessus d'un trou vide" << endl;
    cout << "On deplace obligatoirement tous les pions situés sur un emplacement(de 1 à 4. Une tour de 5 pions ne se deplace pas)" << endl;
    cout << "Une pile de pions de peut qu'augmenter, jamais diminuer. Un pion ou une tour, isolés de tous les côtés, ne pourront donc plus bouger ni chnager de propriétaire" << endl << endl;
    
    cout << "FIN DE LA PARTIE" << endl;
    cout << "La partie se poursuit tant qu'on peut effectuer des empilements. le jeu se termine lorsque plus aucun deplacement n'est possbile. Le plateau n'est donc plus constitué que de tours ou de pions isolés. Seul le dernier étage compte."<< endl;
    cout << "-> Le vainqueur est le joueur totalisant le plus grand nombre de pions isolés ou de sommets de tous de sa couleur." << endl;
    cout << "-> Qu'une tout compte 1,2... ou 5 pions, elle vaut toujours un point. "<< endl;
    cout <<"En cas d'égalité, c'est celui qui a le plus de tours de 5 pions (avec le pion de sa couleur au sommet) qui a gagné." << endl << endl;
}

int Menu::quitter(){
    exit(1);
}




