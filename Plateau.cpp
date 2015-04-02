/*
 *  Fichier     Plateau.cpp
 *  Dossier     Mini-projet "Avalam"
 *  Auteur      Marine Taliercio
 *  Date        Date de début du projet
 *
 *
 */

/*
 * Les Inclusions
 */

#include "Plateau.h"
#include "Menu.h"
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <vector>
using namespace std;

/*
 *  Fonction        Plateau::Plateau()
 *                  Methode constructeur de la classe
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

Plateau::Plateau(){
    partieNulle=0;
    _nbrLignes=11;
    _nbrColonnes=13;
    _nbrPionsAEmpiler=5;
    plateau = new char*[_nbrLignes];
    for(int i=0 ; i<_nbrLignes; i++){
        plateau[i] = new char[_nbrColonnes];
        for(int j=0 ; j<_nbrColonnes; j++){
            plateau[i][j]=caseVide;
        }
    }
}

/*
 *  Code        Plateau::~Plateau()
 *  Dossier     Methode destructeur de la classe
 *  Paramètres  Aucun
 *  Return      Rien
 */

Plateau::~Plateau(){
    for(int i=0; i<_nbrLignes; i++){
        delete[] plateau[i];
    }
    delete[] plateau;
}

/*
 *  Code        void Plateau::initialiser()
 *  Dossier     Initialiser le plateau avec plateau[i][j]
 *  Paramètres  Aucun
 *  Return      Rien
 */

void Plateau::initialiser(){
    plateau = new char*[_nbrLignes];
    for(int i=0 ; i<_nbrLignes; i++){
        plateau[i] = new char[_nbrColonnes];
        for(int j=0 ; j<_nbrColonnes; j++){
            plateau[i][j]=caseVide;
        }
    }
    
    for(int i=0; i<_nbrLignes; i+=2){
        for(int j=1; j<_nbrColonnes; j+=2){
            plateau[i][j]=pionRouge;
        }
    }
    
    for(int i=1; i<_nbrLignes; i+=2){
        for(int j=0; j<_nbrColonnes; j+=2){
            plateau[i][j]=pionJaune;
        }
    }
    
    for(int i=0; i<1; i++){
        for(int j=0; j<9; j++){
            plateau[i][j]=caseVide;
        }
    }
    
    for(int i=1; i<2; i++){
        for(int j=0; j<5; j++){
            plateau[i][j]=caseVide;
        }
    }
    
    for(int i=0; i<4; i++){
        for(int j=11; j<_nbrColonnes; j++){
            plateau[i][j]=caseVide;
        }
    }
    
    for(int i=7; i<_nbrLignes; i++){
        for(int j=0; j<2; j++){
            plateau[i][j]=caseVide;
        }
    }
    for(int i=9; i<10; i++){
        for(int j=8; j<_nbrColonnes; j++){
            plateau[i][j]=caseVide;
        }
    }
    for(int i=10; i<_nbrLignes; i++){
        for(int j=5; j<_nbrColonnes; j++){
            plateau[i][j]=caseVide;
        }
    }
    plateau[5][6]=caseVide;
}


/*
 *  Code        int Plateau::compterPions(char couleur)
 *  Dossier     compter le nombre de pions
 *  Paramètres  char couleur    definit la couleur du pion
 *  Return      nbcouleur   le nombre de pions en fonction de la couleur
 */

int Plateau::scoreJoueurs(char couleur){
    int i,j;
    int nbcouleur=0;
    for(i=0;i<_nbrLignes;i++){
        for(j=0;j<_nbrColonnes;j++){
            if(plateau[i][j]==couleur) nbcouleur=nbcouleur+1;
        }
    }
    return nbcouleur;
}

/*
 *  Code        void Plateau::afficher()
 *  Dossier     afficher le plateau avec les chiffres
 *  Paramètres  aucun
 *  Return      rien
 */

void Plateau::afficher(){
    cout << endl << endl;
    
    for(int i=0; i< _nbrLignes; i++){
        if(i>9) cout << i<<"  | "; // premier pipe apres n° de ligne >9
        else cout << i <<"   | "; // premier pipe apres n° de ligne <9
        for(int j=0; j<_nbrColonnes; j++){
            if(plateau[i][j]==pionRouge) cout << RED << pionRouge << CANCEL;
            else if(plateau[i][j]==pionJaune) cout << YELLOW << pionJaune << CANCEL;
            else cout << CANCEL;
            if (plateau[i][j]==pionRouge || plateau[i][j]==pionJaune) cout << "  | ";
            else cout << "   | ";
        }
        cout << " " << endl;
        for(int j=0; j<_nbrColonnes; j++){
            cout << "----+";
        }
        cout << "----+" << endl;
    }
    cout << "  ";
    
    for(int j=0; j<_nbrColonnes; j++){
        if(j>9) cout << "  |" <<j ;
        else cout << "  | " <<j ;
    }
    cout << "  |" << endl;
    cout << endl;
    
    cout << "Il y a "<< scoreJoueurs(pionRouge) << " pions" << RED << " rouge." << CANCEL <<endl ;
    cout << "Il y a "<< scoreJoueurs(pionJaune)<< " pions" << YELLOW << " jaune." << CANCEL <<endl ;
}

/*
 *  Code        int Plateau::testSiFinDePartie(char couleur, int affiche, char typeJoueur)
 *  Dossier     tester si fin de partie (plus de deplacement de pions possibles, vainqueur...)
 *  Paramètres  char couleur
 *              int afficher
 *              char typeJoueur
 *  Return      1 si partie finie, 0 sinon
 */

int Plateau::testSiFinDePartie(char couleur, char typeJoueur){
    bool victoire;
    if(partieNulle==1) return victoire=1;
    if(scoreJoueurs(pionRouge)>scoreJoueurs(pionJaune)) cout << "Joueur rouge a gagner" << endl;
    else if(scoreJoueurs(pionJaune)>scoreJoueurs(pionRouge)) cout << "Joueur jaune a gagner" << endl;
    else cout << "egalité" << endl;
    return victoire=0;
}

/*
 *  Code        void Plateau::mettrePartieNulle()
 *  Dossier     positionne à 1 la variable PartieNulle
 *  Paramètres  aucun
 *  Return      rien
 */

void Plateau::mettrePartieNulle(){
    partieNulle=1;
}

/*
 *
 */

void Plateau::joueurHumain(){
    cout << "* Saisie des coordonnées du pion à déplacer *" << endl;
    do {
        do{
            do{
                cout << "Ligne case de depart >>";
                cin >> Depart.ligne;
                cout << "Colonne case de depart >>";
                cin >> Depart.colonne;
                
                deplacementPossible();
                
                if(plateau[Depart.ligne][Depart.colonne]==caseVide){
                    cout << "il n'y a pas de pion" << endl;
                    cout << "re rentrer les coordonnées de depart svp" << endl;
                }
            }while(plateau[Depart.ligne][Depart.colonne]==caseVide);
            
            //do{
                do{
                    cout << "Ligne case d'arrivee >>";
                    cin >> Arrivee.ligne;
                    cout << "Colonne case d'arrivee >>";
                    cin >> Arrivee.colonne;
                
                    /*if ((Arrivee.ligne==Depart.ligne+1 && Arrivee.colonne==Depart.colonne+1) || (Arrivee.ligne==Depart.ligne+1 && Arrivee.colonne==Depart.colonne-1) || (Arrivee.ligne==Depart.ligne-1 && Arrivee.colonne==Depart.colonne+1) || (Arrivee.ligne==Depart.ligne-1 && Arrivee.colonne==Depart.colonne-1)){
                        effectuerDeplacement(couleur, Depart, Arrivee);
                        chercherCoordonneesTour();
                    }*/
                    
                    
                    if (plateau[Arrivee.ligne][Arrivee.colonne]==caseVide){
                        cout << "vous ne pouvez pas deplacez sur un vide" <<endl;
                        cout << "re rentrer les coordonnées d'arrivee svp"<< endl;
                    }
                
                }while(plateau[Arrivee.ligne][Arrivee.colonne]==caseVide);
                
                    /*if((Arrivee.ligne!=Depart.ligne+1 && Arrivee.colonne!=Depart.colonne+1) || (Arrivee.ligne!=Depart.ligne+1 && Arrivee.colonne!=Depart.colonne-1) || (Arrivee.ligne!=Depart.ligne-1 && Arrivee.colonne!=Depart.colonne+1) || (Arrivee.ligne!=Depart.ligne-1 && Arrivee.colonne!=Depart.colonne-1)) {
                        cout << "ERREUR >> VOUS NE POUVEZ PAS SAUTER UN TROU ! " << endl;
                    }*/
                
            /*}while((Arrivee.ligne!=Depart.ligne+1 && Arrivee.colonne!=Depart.colonne+1) || (Arrivee.ligne!=Depart.ligne+1 && Arrivee.colonne!=Depart.colonne-1) || (Arrivee.ligne!=Depart.ligne-1 && Arrivee.colonne!=Depart.colonne+1) || (Arrivee.ligne!=Depart.ligne-1 && Arrivee.colonne!=Depart.colonne-1));*/
            
            if((Depart.ligne<0 || Depart.ligne>_nbrLignes) || (Depart.colonne<0 || Depart.colonne>_nbrColonnes) || (Arrivee.ligne<0 || Arrivee.ligne>_nbrLignes) || (Arrivee.colonne<0 || Arrivee.colonne>_nbrColonnes)) cout << "coordonnées hors plateau" << endl;
            
            }while ((Depart.ligne<0 || Depart.ligne>_nbrLignes) || (Depart.colonne<0 || Depart.colonne>_nbrColonnes) || (Arrivee.ligne<0 || Arrivee.ligne>_nbrLignes) || (Arrivee.colonne<0 || Arrivee.colonne>_nbrColonnes));
        
        if(Depart.ligne==Arrivee.ligne && Depart.colonne==Depart.colonne) cout << "coordonnées depart meme que arrivee" << endl;
        
    }while(Depart.ligne==Arrivee.ligne && Depart.colonne==Depart.colonne);
    effectuerDeplacement(couleur, Depart, Arrivee);
    chercherCoordonneesTour();
}

void Plateau::deplacementPossible(){
    cout << "********************************************" << endl;
    cout << "********** DEPLACEMENTS POSSIBLES **********" << endl;
    cout << "********************************************" << endl;
    cout << "DEPLACEMENT EN BAS A DROITE >> ";
    testBasDroite();
    cout << "DEPLACEMENT EN BAS A GAUCHE >> ";
    testBasGauche();
    cout << "DEPLACEMENT EN HAUT A DROITE >> ";
    testHautDroite();
    cout << "DEPLACEMENT EN HAUT A GAUCHE >> ";
    testHautGauche();
    
}

void Plateau::testBasDroite(){
    if(((Depart.ligne+1)<0 || (Depart.ligne+1)>_nbrLignes) || (Depart.colonne+1<0 || Depart.colonne+1>_nbrColonnes))
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if(plateau[Depart.ligne+1][Depart.colonne+1]==pionJaune || plateau[Depart.ligne+1][Depart.colonne+1]==pionRouge)
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << Depart.ligne+1 << ";" << Depart.colonne+1 << "]" << endl;
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}

void Plateau::testBasGauche(){
    if(((Depart.ligne+1)<0 || (Depart.ligne+1)>_nbrLignes) || (Depart.colonne-1<0 || Depart.colonne-1>_nbrColonnes))
            cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if (plateau[Depart.ligne+1][Depart.colonne-1]==pionJaune || plateau[Depart.ligne+1][Depart.colonne-1]==pionRouge)
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << Depart.ligne+1 << ";" << Depart.colonne-1 << "]" << endl;
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}

void Plateau::testHautDroite(){
    if(((Depart.ligne-1)<0 || (Depart.ligne-1)>_nbrLignes) || (Depart.colonne+1<0 || Depart.colonne+1>_nbrColonnes))
            cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if(plateau[Depart.ligne-1][Depart.colonne+1]==pionJaune || plateau[Depart.ligne-1][Depart.colonne+1]==pionRouge)
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << Depart.ligne-1 << ";" << Depart.colonne+1 << "]" << endl;
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}

void Plateau::testHautGauche(){
    if(((Depart.ligne-1)<0 || (Depart.ligne-1)>_nbrLignes) || (Depart.colonne-1<0 || Depart.colonne-1>_nbrColonnes))
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if(plateau[Depart.ligne-1][Depart.colonne-1]==pionJaune || plateau[Depart.ligne-1][Depart.colonne-1]==pionRouge)
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << Depart.ligne-1 << ";" << Depart.colonne-1 << "]" << endl;
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}


/*
 *
 */

bool Plateau::effectuerDeplacement(char lacouleur,CoordonneesCase Depart, CoordonneesCase Arrivee)
{
    bool deplacement=false;
    if(plateau[Depart.ligne][Depart.colonne]==pionRouge){
        plateau[Arrivee.ligne][Arrivee.colonne]=pionRouge;
    }
    else {
        plateau[Arrivee.ligne][Arrivee.colonne]=pionJaune;
    }
    if(plateau[Arrivee.ligne][Arrivee.colonne]){
        cpt++;
        //cout << cpt;
    }
    if(cpt==5) cout << "tour" << endl;
    deplacement=true;
    plateau[Depart.ligne][Depart.colonne]=caseVide;
    return deplacement;
}



/*bool Plateau::estUneTour(){
    int cptPions=0;
    bool victoire=false;
    char pionAChercher=caseVide;
    if(_tourJoueur==true) pionAChercher=pionRouge;
    else pionAChercher=pionJaune;
    int i=0, j=0;
    while(i<_nbrLignes){
        while(_nbrColonnes){
            if(plateau[i][j]==pionAChercher){
                cptPions++;
            }
            else cptPions=0;
        }
        if(cptPions==_nbrPionsAEmpiler){
            victoire=true;
            return victoire;
        }
    }
    return 0;
}*/

/*
 *  Code        Joueur::prenomsJoueur(char typeJoueur)
 *  Dossier     Fonctions de saisie des prenoms des joueurs
 *  Paramètres  char typeJoueur     variables qui permet de savoir si l'utilisateur est un humain                                           ou une machine
 *  Return      Rien
 */

void Plateau::prenomsJoueurs(char typeJoueur)
{
    if(typeJoueur=='h'){
        cout << "Joueur1, Entrez votre prénom >>> ";
        cin >> prenom1;
        cout << "Joueur2, Entrez votre prénom >>> ";
        cin >> prenom2;
        /*if (strcmp(prenom1, prenom2)==0) cout << "ERREUR >> PRENOMS DES JOUEURS IDENTIQUES" << endl;
        do{
            cout << "ERREUR >> PRENOMS DES JOUEURS IDENTIQUES" << endl;
            prenomsJoueurs(typeJoueur);
        }while(strcmp(prenom1, prenom2)!=0);*/
    }
    else if (typeJoueur=='o'){
        cout << "Joueur, Entrez votre prénom >>> ";
        cin >> prenom1;
        cout << "Ordi, Entrez votre prenom >>> ";
        cin >> prenom2;
    }
    cout << "Bienvenue dans la partie " << prenom1 << " et " << prenom2 << endl;
}

/*
 *  Code        Joueur::joueEnPremier()
 *  Dossier     Fonction pour savoir lequel des deux joueurs commencent
 *  Paramètres  Aucun
 *  Return      Rien
 */

void Plateau::joueEnPremier()
{
    string choixJoueur;
    cout << "Entrez votre prénom pour commencer en premier >>> ";
    cin >> choixJoueur;
    
    if (choixJoueur == prenom1) _tourJoueur=false;
    else if (choixJoueur == prenom2) _tourJoueur=true;
    else{
        while(choixJoueur!=prenom1 && choixJoueur!=prenom2){
            cout << " Vous avez entrez un mauvais prénom ! >> ";
            cin >> choixJoueur;
        }
    }
}

/*
 *  Code        Joueur::aQuiDeJouer()
 *  Dossier     Fonction qui gere la main des joueurs
 *  Paramètres  Aucun
 *  Return      booleen
 */

bool Plateau::aQuiDeJouer(){
    if(_tourJoueur == true) _tourJoueur = false;
    else if(_tourJoueur == false) _tourJoueur = true;
    return _tourJoueur;
}

/*
 *  Code        Joueur::menuJoueur()
 *  Dossier     Affichage du menu des joueurs
 *  Paramètres  Aucun
 *  Return      Rien
 */

void Plateau::menuJoueur()
{
    cout << endl;
    cout << "*******************************************" << endl;
    cout << "*************** MENU JOUEUR ***************" << endl;
    cout << "*******************************************" << endl;
    cout << "       1 - DEPLACER UN PION" << endl;
    cout << "       2 - FAIRE UNE PAUSE" << endl;
    cout << "       3 - SAUVEGARDER LA PARTIE" << endl;
    cout << "       4 - QUITTER LA PARTIE" << endl;
}

/*
 *  Code        Joueur::lancerMenuJoueur()
 *  Dossier     Methode qui gere toutes les fonctions des joueurs
 *  Paramètres  Aucun
 *  Return      Rien
 */

void Plateau::lancerMenuJoueur(){
    int choix = 0 ;
    menuJoueur();
    if(_tourJoueur == false) cout << prenom1 << ", que voulez-vous faire >>> " ;
    else cout << prenom2 << ", que voulez-vous faire >>> ";
    cin >> choix ;
    
    switch (choix){
        case 1:{
            cout << "* DEPLACER UN PION *" << endl;
            joueurHumain();
            break;
        }
        
        case 2:{
            if(_tourJoueur == false) _tourJoueur=true;
            else _tourJoueur=false;
            
            cout << "* FAIRE UNE PAUSE *" << endl;
            cout << "Pour reprendre la partie tapez sur Entrée >> ";
            int c;
            while((c=getchar())!='\n' && c!=EOF);
            getchar();
            break;
        }
            
        case 3:{
            cout << "* SAUVEGARDER LA PARTIE *";
            break;
        }
            
        case 4:{
            cout << "* QUITTER LA PARTIE *";
            quitter();
            break;
        }
            
        default:{
            cout << "ERREUR >> LE MENU QUE VOUS AVEZ CHOISI N'EXISTE PAS" << endl;
            lancerMenuJoueur();
            break;
        }
    }
}

/*
 *
 */

int Plateau::quitter(){
    exit(1);
}

/*
 *
 */

/*void Plateau::tabCoupJoue(){
    cout << "********************************************" << endl;
    cout << "******** HISTORIQUE DES COUPS JOUES ********" << endl;
    cout << "********************************************" << endl;
    CoordonneesCase d;
    CoordonneesCase a;
    d.ligne = Arrivee.ligne;
    d.colonne=Arrivee.colonne;
    a.ligne = Arrivee.ligne;
    a.colonne=Arrivee.colonne;
    tab.push_back(d);
    for(vector<CoordonneesCase>::iterator it=tab.begin(); it !=tab.end(); it++){
        cout << "DEPART" << endl;
        cout << "Ligne >> " << (*it).ligne << " ";
        cout << "Colonne >> " << (*it).colonne << endl;
        //cout << "-----------------------------" << endl; ;
    }
    tab.push_back(a);
    for(vector<CoordonneesCase>::iterator it2=tab.begin(); it2 !=tab.end(); it2++){
        cout << "ARRIVEE" << endl;
        cout << "Ligne >> " << (*it2).ligne << " ";
        cout << "Colonne >> " << (*it2).colonne << endl;
        cout << "-----------------------------" << endl; ;
    }
}*/

void Plateau::chercherCoordonneesTour(){
    
    cout << "tableau de coup" << endl;
    CoordonneesCase c;
    c.ligne = Arrivee.ligne;
    c.colonne=Arrivee.colonne;
    tab.push_back(c);
    for(vector<CoordonneesCase>::iterator it=tab.begin(); it !=tab.end(); it++)
    {
        cout << "ligne: " << (*it).ligne << " ";
        cout << "colonne: " << (*it).colonne << endl;
        cout << "-----------------------------" << endl; ;
    }

    
}


/*inline bool Plateau::operator==(CoordonneesCase const& c1, CoordonneesCase const& c2) {
    return c1.ligne == c2.ligne && c1.colonne == c2.colonne;
}

inline bool Plateau::operator!=(CoordonneesCase const& c1, CoordonneesCase const& c2) {
    return !(c1 == c2);
}*/

















