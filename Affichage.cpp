/*
 * Fichier      Affichage.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#include <iostream>
#include <limits>
#include "Affichage.h"

using namespace std;

/*
 * Fonction     menuJoueur()
 * Description  Affichage du menu pour les joueurs
 * Arguments    Aucun
 * Renvoi       Rien
 */

void Affichage::menuJoueur(){
    cout << endl;
    cout << "*************************************" << endl;
    cout << "************ MENU PLAYER ************" << endl;
    cout << "*************************************" << endl;
    cout << "   1 - DEPLACER UN PION" << endl;
    cout << "   2 - FAIRE UNE PAUSE" << endl;
    cout << "   3 - QUITTER LA PARTIE" << endl;
    cout << "   4 - sauvegarde" << endl; 
}

/*
 * Fonction     lireChoixMenuJoueur()
 * Description  Fonction qui test la saisie pour le menu des joueurs
 * Arguments    Aucun
 * Renvoi       int choixMenuJoueur
 */

int Affichage::lireChoixMenuJoueur(){
    while(!(cin>>choixMenuJoueur)&&(choixMenuJoueur<=1 || choixMenuJoueur>=3)){
        if(cin.eof()) return 0;
        else if(cin.fail()){
            cout << "ERREUR : SAISIE INCORRECTE >> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else cout << "ERREUR : LE MENU N'EXISTE PAS >> ";
    }
    return choixMenuJoueur;
}

/*
 * Fonction     menuJeu()
 * Description  Affichage du menu principal
 * Arguments    Aucun
 * Renvoi       Rien
 */

void Affichage::menuJeu(){
    cout << endl;
    cout << "**************************************" << endl;
    cout << "*************** AVALAM ***************" << endl;
    cout << "**************************************" << endl;
    cout << "   1 - LANCER UNE PARTIE" << endl;
    cout << "   2 - REGLES DU JEU" << endl;
    cout << "   3 - A PROPOS" << endl;
    cout << "   4 - QUITTER" << endl;
    cout << "CHOIX >> ";
}

/*
 * Fonction     lireChoixMenuJeu()
 * Description  Fonction qui test la saisie pour le menu principal
 * Arguments    Aucun
 * Renvoi       int choixMenu
 */

int Affichage::lireChoixMenuJeu(){
    while(!(cin>>choixMenu) && (choixMenu<=0 || choixMenu>=4)){
        if(cin.eof()) return 0;
        else if(cin.fail()){
            cout << "ERREUR : SAISIE INCORRECTE >> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else cout << "ERREUR : LE MENU N'EXISTE PAS >> ";
    }
    return choixMenu;
    return 0; 
}

/*
 * Fonction     aPropos()
 * Description  Fonction qui affiche qui à créer le programme
 * Arguments	Aucun
 * Renvoie      Aucun
 */

void Affichage::aPropos(){
    cout << "**************************************" << endl;
    cout << "************** A PROPOS **************" << endl;
    cout << "**************************************" << endl;
    cout << "     Réalisé par Marine Taliercio" << endl;
    cout << "           L2 CERI Avignon" << endl;
    cout << "               TD2 - TP3" << endl;
    cout << endl;
}

/*
 * Fonction 	reglesDuJeu()
 * Description  Fonction qui affiche les regles du jeu
 * Arguments    Aucun
 * Renvoie      Aucun
 */

void Affichage::reglesDuJeu(){
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

/*
 * Fonction     quitterLeJeu()
 * Description  Fonction qui quitte le jeu
 * Arguments    Aucun
 * Renvoie      int
 */

int Affichage::quitterLeJeu(){
    exit(1);
}



