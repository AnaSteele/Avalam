/*
 * Fichier      Joueur.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#include "Joueur.h"
#include "Case.h"
#include <iostream>
#include <limits>

using namespace std;

/*
 * Fonction     Joueur()
 * Description  Constructeur d'un joueur
 * Arguments    Aucun
 * Renvoi       Rien
 */

Joueur::Joueur(){
    id = 0;
    nom = "Joueur";
    score = 0;
    couleur = ' ';
}

/*
 * Fonction     Joueur()
 * Description  Constructeur d'un joueur avec arguments
 * Arguments    int jId (identifiant), string jNom (Nnom), int jScore (score), char jCouleur (couleur)
 * Renvoi       Rien
 */

Joueur::Joueur(int jId, string jNom, int jScore, char jCouleur){
    id = jId;
    nom = jNom;
    score = jScore;
    couleur = jCouleur;
}

/*
 * Fonction     getNom()
 * Description  Fonction qui retourne le nom du joueur
 * Arguments    Aucun
 * Renvoi       string nom (nom du joueur)
 */

string Joueur::getNom() {
    return nom;
}

/*
 * Fonction     setNom(string jNom)
 * Description  Fonction qui met à jour le nom d'un joueur
 * Arguments    string jNom
 * Renvoi       Rien
 */

void Joueur::setNom(string jNom){
    nom=jNom;
}

/*
 * Fonction     getId()
 * Description  Fonction qui renvoie l'identifiant d'un joueur
 * Arguments    Aucun
 * Renvoi       int id
 */

int Joueur::getId(){
    return id;
}

/*
 * Fonction     getCouleur()
 * Description  Fonction qui renvoie la couleur d'un joueur
 * Arguments    Aucun
 * Renvoi       char couleur
 */

char Joueur::getCouleur(){
    return couleur;
}

/*
 * Fonction     setTour(char jCouleur)
 * Description  Fonction qui met à jour la couleur d'un joueur
 * Arguments    char jCouleur
 * Renvoi       Rien
 */

void Joueur::setTour(char jCouleur){
    couleur=jCouleur;
}

/*
 * Fonction     saisieNomJoueur()
 * Description  Fonction pour saisir le prenom d'un joueur
 * Arguments    Aucun
 * Renvoi       Rien
 */

void Joueur::saisieNomJoueur(){
    string jNom;
    cout << "PRENOM DU Joueur" << id << " >> ";
    cin >> jNom;
    nom=jNom;
    locale loc;
    string::iterator it;
    for(it=nom.begin(); it!=nom.end(); it++){
        if(isalpha(*it,loc)) cout << "";
        else{
            do{
                cout << *it << " n'est pas une lettre ! " << endl;
                saisieNomJoueur();
            }while(!isalpha(*it,loc));
        }
    }
}

/*
 * Fonction     choixCouleurTour()
 * Description  Fonction pour que le joueur choisisse la couleur de ses tours
 * Arguments    Aucun
 * Renvoi       Rien
 */

void Joueur::choixCouleurTour(){
    int couleurTour;
    cout << nom << " CHOIX DE LA COULEUR >> ";
    cin >> couleurTour;
    couleur=couleurTour;
    if(couleurTour==1) couleur=tourBleu;
    else couleur=tourRouge;
}
