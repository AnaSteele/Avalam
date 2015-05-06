

/*
 * Inclusions
 */

#include "Plateau.h"
#include "Partie.h"
//#include "Joueur.h"
#include <fstream>
#include <iostream>
#include <ncurses.h> // couleurs de pions

using namespace std;

/*
 * Fonction     Plateau()
 * Description  Methode constructeur de la classe
 * Arguments    Aucun
 * Renvoi       Rien
 */

/*Plateau::Plateau(){
    nombreDeLignes=0;
    nombreDeColonnes=0;
    plateau=new char*[nombreDeLignes];
    for(int i=0; i<nombreDeLignes; i++){
        plateau[i]=new char[nombreDeColonnes];
        for(int j=0; j<nombreDeColonnes; j++){
            plateau[i][j]=caseVide;
        }
    }
}*/

Plateau::Plateau(unsigned int lignes, unsigned int colonnes){
    nombreDeLignes=lignes;
    nombreDeColonnes=colonnes;
    plateau=new char*[nombreDeLignes];
    for(int i=0; i<nombreDeLignes; i++){
        plateau[i]=new char[nombreDeColonnes];
        for(int j=0; j<nombreDeColonnes; j++){
            plateau[i][j]=caseVide;
        }
    }
}


/*
 * Fonction     ~Plateau()
 * Decription   Methode destructeur de la classe
 * Arguments    Aucube
 * Renvoi       Rien
 */

Plateau::~Plateau(){
    for(int i=0; i<nombreDeLignes; i++){
        delete [] plateau[i];
    }
    delete [] plateau;
}


/*
 *
 *
 *
 *
 */

void Plateau::lectureFichier(){
    ifstream fichier("avalam.txt", ios::in);
    
    if(!fichier) throw runtime_error("Impossible d'ouvrir le fichier");
    
    for(int i=0; i<nombreDeLignes; i++){
        string line;
        if(!getline(fichier,line)) throw runtime_error("pas assez de lignes dans le fichier");
        if(!(line.size()==nombreDeColonnes)) throw runtime_error("ligne pas de la bonne longueur");
        for(int j=0; j<nombreDeColonnes; j++){
            plateau[i][j]=line[j];
        }
    }
}


/*
 *
 *
 *
 *
 */

void Plateau::afficherPlateau(){
    for(int j=0; j<nombreDeColonnes; j++) cout << "----+";
    cout << "----+" << endl;
    for(int i=0; i<nombreDeLignes; i++){
        //if(i>9) cout << i << "   | ";
        cout << i << "   | ";
        for(int j=0; j<nombreDeColonnes; j++){
            
           if(plateau[i][j]==pionRouge) cout << /* RED << */ pionRouge /* << CANCEL */ << "  | ";
           else if(plateau[i][j]==pionBleu) cout << /* BLUE << */ pionBleu /* << CANCEL */ << "  | ";
           else if(plateau[i][j]==caseInterdite) cout <<   "" << "   | ";
        }
        cout << " " << endl;
        for(int j=0; j<nombreDeColonnes; j++) cout << "----+";
        cout << "----+" << endl;
    }
    cout  << "  ";
    for (int j=0; j<nombreDeColonnes; j++){
        //if(j>9) cout << "  |" << j;
        cout << "  | " << j;
    }
    cout << "  |" << endl;
    for(int j=0; j<nombreDeColonnes; j++) cout << "----+";
    cout << "----+" << endl;
    cout << endl;
}

/*
 * Fonction     int scoreJoueur(char couleur)
 * Description  Compter le nombre de pions de chaque joueur
 * Arguments    char couleur    (couleur du pion)
 * Renvoi       nbCouleur       (nombre de pions)
 */

int Plateau::scoreJoueur(char couleur){
    int nbCouleur=0;
    for(int i=0; i<nombreDeLignes; i++){
        for(int j=0; j<nombreDeColonnes; j++){
            if(plateau[i][j]==couleur) nbCouleur=nbCouleur+1;
        }
    }
    return nbCouleur; 
}


