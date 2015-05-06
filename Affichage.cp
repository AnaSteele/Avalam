

#include <iostream>
#include "Affichage.h"

using namespace std;

/*
 * Fonction     menuPlayer()
 * Description  Affichage du menu pour les players
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
}

/*
 * Fonction     menuGame()
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
    cout << "   3 - PARAMETRES" << endl;
    cout << "   4 - A PROPOS" << endl;
    cout << "   5 - QUITTER" << endl;
}

int Affichage::lireChoixMenuJeu(){
    cout << "choisir ";
    while(!(cin>>choixMenu) && (choixMenu<=0 || choixMenu>=5)){
        if(cin.eof()) return 0;
        else if(cin.fail()){
            cout << "saisie incorrecte, choisir ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else cout << "n'existe pas, choisir ";
        cout << endl;
    }
    return choixMenu;
}

/*
 * Fonction	Menu::aPropos()
 * Description  Fonction qui affiche qui à créer le programme
 * Arguments	Aucun
 * Renvoie      Aucun
 */

void Affichage::aPropos(){
    cout << "********************************************" << endl;
    cout << "***************** A PROPOS *****************" << endl;
    cout << "********************************************" << endl;
    cout << "       Réalisé par " << endl;
    cout << "             " << endl;
    cout << "                " << endl;
    cout << endl;
}

/*
 * Fonction	Menu::lireChoixMenuParametres
 * Description	Fonction qui verifie si le menu entrer est bien un int
 * Arguments	Aucun
 * Renvoie	bool
 */

/*
 bool Menu::lireChoixMenuParametres(){
 cout << endl;
 cout << "VEUILLEZ CHOISIR VOTRE MENU >> ";
 while(!(cin>>choixParametres) && (choixParametres<=0 || choixParametres>=3)){
 if(cin.eof()) return false;
 else if(cin.fail()) {
 cout << "SAISIE INCORRECTE, RECOMMENCEZ >> ";
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 }
 else cout << "LE MENU N'EXISTE PAS, RECOMMENCEZ >> ";
 cout << endl;
 }
 return true;
 }
 */

/*
 * Fonction	Menu::parametresDuJeu()
 * Description  Fonction qui affiche les différents paramètres possibles
 * Arguments    Aucun
 * Renvoie      Aucun
 */

void Affichage::parametresDuJeu(){
    cout << "********************************************" << endl;
    cout << "**************** PARAMETRES ****************" << endl;
    cout << "********************************************" << endl;
    cout << "           1 - CHANGER LA FORME DU PLATEAU" << endl;
    cout << "           2 - CHANGER LA TAILLE DU PLATEAU" << endl;
    cout << "           3 - CHANGER LES PIONS DES JOUEURS" << endl;
    cout << "           0 - REVENIR AU MENU PRINCIPAL" << endl << endl;
    
    cout << "VEUILLEZ CHOISIR VOTRE MENU >> ";
    cin >> choixParametres;
    //  lireChoixMenuParametres();
    cout << endl;
    switch (choixParametres){
        case 1:
            cout << "* CHANGER LA FORME DU PLATEAU *" << endl;
            cout << "* PARTIE NON DEVELOPPEE *" << endl << endl;
            parametresDuJeu();
            break;
            
        case 2:
            cout << "* CHANGER LA TAILLE DU PLATEAU *" << endl;
            cout << "* PARTIE NON DEVELOPPEE *" << endl << endl;
            parametresDuJeu();
            break;
            
        case 3:
            cout << "* CHANGER LES PIONS DES JOUEURS *" << endl;
            cout << "* PARTIE NON DEVELOPPEE *" << endl << endl;
            parametresDuJeu();
            break;
            
        case 0:
            //lancerPartie();
            break;
            
        default:
            cout << "ERREUR >> LE MENU QUE VOUS AVEZ CHOISI N'EXISTE PAS" << endl;
            parametresDuJeu();
            break;
    }
}

/*
 * Fonction 	Menu::reglesDuJeu()
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
 * Fonction	Menu::quitterLeJeu()
 * Description  Fonction qui quitte le jeu
 * Arguments    Aucun
 * Renvoie      int
 */

int Affichage::quitterLeJeu(){
    return 0; //exit(1); 
}

 

