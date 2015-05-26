/*
 * Fichier      Plateau.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#include "Plateau.h"
#include "Case.h"
#include "Couleur.h"
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <stdexcept>
#include <algorithm>

using namespace std;

/*
 * Fonction     Plateau(unsigned int lignes, unsigned int colonnes)
 * Description  Methode constructeur de la classe
 * Arguments    unsigned int lignes : nombre de lignes du plateau
                unsigned int colonnes : nombre de colonnes du plateau
 * Renvoi       Rien
 */

Plateau::Plateau(unsigned int lignes, unsigned int colonnes){
    nombreDeLignes=lignes;
    nombreDeColonnes=colonnes;
    plateau=new Case*[nombreDeLignes];
    
    for(unsigned int i=0; i<nombreDeLignes; i++){
        plateau[i]=new Case[nombreDeColonnes];
        for(unsigned int j=0; j<nombreDeColonnes; j++){
            Case* c=new Case(i,j, caseVide,1);
            plateau[i][j]=*c;
        }
    }
}

/*
 * Fonction     ~Plateau()
 * Decription   Methode destructeur de la classe
 * Arguments    Aucun
 * Renvoi       Rien
 */

Plateau::~Plateau(){
    for(int i=0; i<nombreDeLignes; i++){
        delete [] plateau[i];
    }
    delete [] plateau;
}

/*
 * Fonction     char_nonvalide(char c)
 * Decription   fonction qui test si un char est bien un pionBleu ou un pionRouge ou une caseInterdite
 * Arguments    char c : correspond au caractère de mon fichier
 * Renvoi       bool
 */

bool char_nonvalide (char c){
    return (c!=tourBleu)&&(c!=tourRouge)&&(c!=caseInterdite);
}

/*
 * Fonction     lectureFichier()
 * Decription   Methode qui lit dans un fichier
 * Arguments    Aucun
 * Renvoi       Rien
 */

void Plateau::lectureFichier(){
    ifstream fichier("/Users/Admin/Desktop/Avalam/Avalam/avalam.txt", ios::in);
    string contenu((istreambuf_iterator<char>(fichier)), istreambuf_iterator<char>());
    contenu.erase(remove_if(contenu.begin(),contenu.end(), char_nonvalide), contenu.end());
    
    for(unsigned int i=0; i<nombreDeLignes; i++){
        for(unsigned int j=0; j<nombreDeColonnes; j++){
            plateau[i][j].setLigne(i);
            plateau[i][j].setColonne(j);
            plateau[i][j].setTour(contenu[i*nombreDeLignes+j]);
        }
    }
}

/*
 * Fonction     afficherPlateau()
 * Decription   Methode qui affiche le plateau de jeu
 * Arguments    Aucune
 * Renvoi       Rien
 */

void Plateau::afficherPlateau(){
    for(unsigned int j=0; j<nombreDeColonnes; j++) cout << "----+";
    cout << "----+" << endl;
    for(unsigned int i=0; i<nombreDeLignes; i++){
        if(i>9) cout << i << "  | ";
        else cout << i << "   | ";
        for(unsigned int j=0; j<nombreDeColonnes; j++){
            if(plateau[i][j].getTour()==tourRouge) cout << /*RED <<*/ tourRouge  << /*CANCEL  <<*/ "  | ";
            else if(plateau[i][j].getTour()==tourBleu) cout << /*BLUE <<*/ tourBleu  << /*CANCEL <<*/ "  | ";
            else cout <<   "" << "   | ";
        }
        cout << " " << endl;
        for(unsigned int j=0; j<nombreDeColonnes; j++) cout << "----+";
        cout << "----+" << endl;
    }
    cout  << "  ";
    for (unsigned int j=0; j<nombreDeColonnes; j++){
        if(j>9) cout << "  |" << j;
        else cout << "  | " << j;
    }
    cout << "  |" << endl;
    for(unsigned int j=0; j<nombreDeColonnes; j++) cout << "----+";
    cout << "----+" << endl;
    cout << endl;
}

/*
 * Fonction     int scoreJoueur(char couleur)
 * Description  Compter le nombre de pions de chaque joueur
 * Arguments    char couleur : couleur du pion
 * Renvoi       nbCouleur : nombre de pions d'une couleur donnée
 */

int Plateau::scoreJoueur(char couleur){
    int nbCouleur=0;
    for(unsigned int i=0; i<nombreDeLignes; i++){
        for(unsigned int j=0; j<nombreDeColonnes; j++){
           if(plateau[i][j].getTour()==couleur) nbCouleur=nbCouleur+1;
        }
    }
    return nbCouleur; 
}

/*
 * Fonction     demandeDeplacement()
 * Decription   Methode qui demande un deplacement a un joueur
 * Arguments    Aucune
 * Renvoi       Rien
 */

void Plateau::demandeDeplacement(){
    do{
        cout << "**************************************" << endl;
        cout << "*********** CASE DE DEPART ***********" << endl;
        cout << "**************************************" << endl;
        cout << "LIGNE >>";
        cin >> ligne;
        Depart.setLigne(ligne);
        cout << "COLONNE >>";
        cin >> colonne;
        Depart.setColonne(colonne);
        testDepart();
        
        if(test==true) deplacementPossible();
        else cout << "ERREUR >> DEPART IMPOSSIBLE" << endl;
        
    }while(test==false || (diagonaleBasDroite==false && diagonaleBasGauche==false && diagonaleHautDroite==false && diagonaleHautGauche==false && haut==false && droite==false && gauche==false && bas==false));
    
    do{
        cout << "**************************************" << endl;
        cout << "*********** CASE D'ARRIVEE ***********" << endl;
        cout << "**************************************" << endl;
        cout << "LIGNE >>";
        cin >> ligne;
        Arrivee.setLigne(ligne);
        cout << "COLONNE >>";
        cin >> colonne;
        Arrivee.setColonne(colonne);
        
        testArrivee();
    
        if(test==true) effectuerDeplacement(couleur, Depart, Arrivee);
        else cout << "ERREUR >> DEPLACEMENT IMPOSSIBLE" << endl;
        
    }while(test==false);
}

/*
 * Fonction     effectuerDeplacement(char couleur,Case Depart, Case Arrivee)
 * Description  Fonction qui deplace une tour d'une Case Depart à une Case Arrivee
 * Arguments    char couleur : couleur de la tour
                Case Depart : case qui va se retrouver vide apres deplacement de sa tour
                Case Arrivee : case qui va acceuillir une nouvelle tour
 * Renvoi       Rien
 */

void Plateau::effectuerDeplacement(char couleur,Case Depart, Case Arrivee){
    plateau[Arrivee.getLigne()][Arrivee.getColonne()].setCompteur((plateau[Depart.getLigne()][Depart.getColonne()].getCompteur())
                                                                  +(plateau[Arrivee.getLigne()][Arrivee.getColonne()].getCompteur()));
    plateau[Depart.getLigne()][Depart.getColonne()].setCompteur(0);
    if(plateau[Depart.getLigne()][Depart.getColonne()].getTour()==tourRouge) plateau[Arrivee.getLigne()][Arrivee.getColonne()].setTour(tourRouge);
    else plateau[Arrivee.getLigne()][Arrivee.getColonne()].setTour(tourBleu);
    plateau[Depart.getLigne()][Depart.getColonne()].setTour(caseVide);
}

/*
 * Fonction     deplacementPossible()
 * Description  Fonction qui affiche tous les déplacement possible à partir de la Case Depart
 * Arguments    Aucun
 * Renvoi       Rien
 */

void Plateau::deplacementPossible(){
    cout << "DEPLACEMENT DIAGONALE EN BAS A DROITE >> ";
    testDiagonaleBasDroite();
    cout << "DEPLACEMENT DIAGONALE EN BAS A GAUCHE >> ";
    testDiagonaleBasGauche();
    cout << "DEPLACEMENT DIAGONALE EN HAUT A DROITE >> ";
    testDiagonaleHautDroite();
    cout << "DEPLACEMENT DIAGONALE EN HAUT A GAUCHE >> ";
    testDiagonaleHautGauche();
    cout << "DEPLACEMENT EN HAUT >> ";
    testHaut();
    cout << "DEPLACEMENT EN BAS >> ";
    testBas();
    cout << "DEPLACEMENT A DROITE >> ";
    testDroite();
    cout << "DEPLACEMENT A GAUCHE >> ";
    testGauche();
}

/*
 * Fonction     testDiagonaleBasDroite()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située dans la diagonale en bas à droite
 * Arguments    Aucun
 * Renvoi       bool diagonaleBasDroite : false si pas de deplacement possible, true sinon
 */

bool Plateau::testDiagonaleBasDroite(){
    if(Depart.getLigne()+1>nombreDeLignes-1 || Depart.getColonne()+1>nombreDeColonnes-1 || Depart.getLigne()+1<0 || Depart.getColonne()+1<0){
        cout << "HORS PLATEAU >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()+1][Depart.getColonne()+1].getCompteur()>=compteurMax){
        cout << "TOUR >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()+1][Depart.getColonne()+1].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()+1][Depart.getColonne()+1].getTour()==tourBleu || plateau[Depart.getLigne()+1][Depart.getColonne()+1].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne()+1 << ";" << Depart.getColonne()+1 << "]" << endl;
        diagonaleBasDroite=true;
    }
    else{
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    return diagonaleBasDroite;
}

/*
 * Fonction     testDiagonaleBasGauche()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située dans la diagonale en bas à gauche
 * Arguments    Aucun
 * Renvoi       bool diagonaleBasGauche : false si pas de deplacement possible, true sinon
 */

bool Plateau::testDiagonaleBasGauche(){
    if(Depart.getLigne()+1>nombreDeLignes-1 || Depart.getColonne()-1>nombreDeColonnes-1 || Depart.getLigne()+1<0 || Depart.getColonne()-1<0){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasGauche=false;
    }
    else if(plateau[Depart.getLigne()+1][Depart.getColonne()-1].getCompteur()>=compteurMax){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasGauche=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()+1][Depart.getColonne()-1].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if (plateau[Depart.getLigne()+1][Depart.getColonne()-1].getTour()==tourBleu || plateau[Depart.getLigne()+1][Depart.getColonne()-1].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne()+1 << ";" << Depart.getColonne()-1 << "]" << endl;
        diagonaleBasGauche=true;
    }
    else{
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasGauche=false;
    }
    return diagonaleBasGauche; 
}

/*
 * Fonction     testDiagonaleHautDroite()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située dans la diagonale en haut à droite
 * Arguments    Aucun
 * Renvoi       bool diagonaleHautDroite : false si pas de deplacement possible, true sinon
 */

bool Plateau::testDiagonaleHautDroite(){
    if(Depart.getLigne()-1>nombreDeLignes-1 || Depart.getColonne()+1>nombreDeColonnes-1 || Depart.getLigne()-1<0 || Depart.getColonne()+1<0){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleHautDroite=false;
    }
    else if(plateau[Depart.getLigne()-1][Depart.getColonne()+1].getCompteur()>=compteurMax){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleHautDroite=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()-1][Depart.getColonne()+1].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()-1][Depart.getColonne()+1].getTour()==tourBleu || plateau[Depart.getLigne()-1][Depart.getColonne()+1].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne()-1 << ";" << Depart.getColonne()+1 << "]" << endl;
        diagonaleHautDroite=true;
    }
    else {
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleHautDroite=false;
    }
    return diagonaleHautDroite;
}

/*
 * Fonction     testDiagonaleHautGauche()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située dans la diagonale en haut à gauche
 * Arguments    Aucun
 * Renvoi       bool diagonaleHautGauche : false si pas de deplacement possible, true sinon
 */

bool Plateau:: testDiagonaleHautGauche(){
    if(Depart.getLigne()-1>nombreDeLignes-1 || Depart.getColonne()-1>nombreDeColonnes-1 || Depart.getLigne()-1<0 || Depart.getColonne()-1<0){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleHautGauche=false;
    }
    else if(plateau[Depart.getLigne()-1][Depart.getColonne()-1].getCompteur()>=compteurMax){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleHautGauche=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()-1][Depart.getColonne()-1].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()-1][Depart.getColonne()-1].getTour()==tourBleu || plateau[Depart.getLigne()-1][Depart.getColonne()-1].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne()-1 << ";" << Depart.getColonne()-1 << "]" << endl;
        diagonaleHautGauche=true;
    }
    else{
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleHautGauche=false;
    }
    return diagonaleHautGauche;
}

/*
 * Fonction     testHaut()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située au dessus de celle ci
 * Arguments    Aucun
 * Renvoi       bool haut : false si pas de deplacement possible, true sinon
 */

bool Plateau::testHaut(){
    if(Depart.getLigne()-1>nombreDeLignes-1 || Depart.getColonne()>nombreDeColonnes-1 || Depart.getLigne()-1<0 || Depart.getColonne()<0){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        haut=false;
    }
    else if(plateau[Depart.getLigne()-1][Depart.getColonne()].getCompteur()>=compteurMax){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        haut=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()-1][Depart.getColonne()].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()-1][Depart.getColonne()].getTour()==tourBleu || plateau[Depart.getLigne()-1][Depart.getColonne()].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne()-1 << ";" << Depart.getColonne() << "]" << endl;
        haut=true;
    }
    else{
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        haut=false;
    }
    return haut;
}

/*
 * Fonction     testBas()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située au dessous de celle ci
 * Arguments    Aucun
 * Renvoi       bool bas : false si pas de deplacement possible, true sinon
 */

bool Plateau::testBas(){
    if(Depart.getLigne()+1>nombreDeLignes-1 || Depart.getColonne()>nombreDeColonnes-1 || Depart.getLigne()+1<0 || Depart.getColonne()<0){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        bas=false;
    }
    else if(plateau[Depart.getLigne()+1][Depart.getColonne()].getCompteur()>=compteurMax){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        bas=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()+1][Depart.getColonne()].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()+1][Depart.getColonne()].getTour()==tourBleu || plateau[Depart.getLigne()+1][Depart.getColonne()].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne()+1 << ";" << Depart.getColonne() << "]" << endl;
        bas=true;
    }
    else {
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        bas=false;
    }
    return bas;
}

/*
 * Fonction     testDroite()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située a droite de celle ci
 * Arguments    Aucun
 * Renvoi       bool droite : false si pas de deplacement possible, true sinon
 */

bool Plateau::testDroite(){
    if(Depart.getLigne()>nombreDeLignes-1 || Depart.getColonne()+1>nombreDeColonnes-1 || Depart.getLigne()<0 || Depart.getColonne()+1<0){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        droite=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()+1].getCompteur()>=compteurMax){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        droite=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()][Depart.getColonne()+1].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()+1].getTour()==tourBleu || plateau[Depart.getLigne()][Depart.getColonne()+1].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne() << ";" << Depart.getColonne()+1 << "]" << endl;
        droite=true;
    }
    else {
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        droite=false;
    }
    return droite;
}

/*
 * Fonction     testGauche()
 * Description  Fonction qui cherche s'il y a un deplacement possible de la case depart à la case située a gauche de celle ci
 * Arguments    Aucun
 * Renvoi       bool gauche : false si pas de deplacement possible, true sinon
 */

bool Plateau::testGauche(){
    if(Depart.getLigne()>nombreDeLignes-1 || Depart.getColonne()-1>nombreDeColonnes-1 || Depart.getLigne()<0 || Depart.getColonne()-1<0){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        gauche=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()-1].getCompteur()>=compteurMax){
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        gauche=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Depart.getLigne()][Depart.getColonne()-1].getCompteur()>compteurMax){
        cout << "TROP DE PION EMPILES >> PAS DE DEPLACEMENT POSSIBLE." << endl;
        diagonaleBasDroite=false;
    }
    else if(plateau[Depart.getLigne()][Depart.getColonne()-1].getTour()==tourBleu || plateau[Depart.getLigne()][Depart.getColonne()-1].getTour()==tourRouge){
        cout << "DEPLACEMENT POSSIBLE EN [" << Depart.getLigne() << ";" << Depart.getColonne()-1 << "]" << endl;
        gauche=true;
    }
    else {
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
        gauche=false;
    }
    return gauche;
}

/*
 * Fonction     testDepart()
 * Description  Fonction qui teste les coordonnées saisies pour la case de départ
 * Arguments    Aucun
 * Renvoi       bool test
 */

bool Plateau::testDepart(){
    
    if(ligne<0 && ligne>nombreDeLignes && colonne<0 && colonne>nombreDeColonnes){
        cout << "ATTENTION >> HORS PLATEAU >> ON RECOMMENCE" << endl;
        test=false;
    }
    else if(plateau[ligne][colonne].getTour()==caseInterdite || plateau[ligne][colonne].getTour()==caseVide){
        cout << "ATTENTION >> CASE INTERDITE OU CASE VIDE >> ON RECOMMENCE" << endl;
        test=false;
    }
    else if(estUneTourPleine(ligne, colonne)){
        cout << "ERREUR >> TOUR PLEINE >> DEPLACEMENT INTERDIT >> ON RECOMMENCE" << endl;
        test=false;
    }
    else if(estUneTourNonPleine(ligne, colonne)==true){
        cout << "ERREUR >> TOUR PAS PLEINE MAIS PAS DEPAÇABLE >> ON RECOMMENCE" << endl;
        test=false;
    }
    else test=true;
    return test;
}

/*
 * Fonction     testArrivee()
 * Description  Fonction  qui teste les coordonnées saisies pour la case d'arrivee
 * Arguments    Aucun
 * Renvoi       bool test
 */

bool Plateau::testArrivee(){
    if(ligne<0 && ligne>nombreDeLignes && colonne<0 && colonne>nombreDeColonnes){
        cout << "ERREUR >> HORS PLATEAU >> ON RECOMMENCE" << endl;
        test=false;
    }
    else if ((plateau[ligne][colonne]).getTour()==caseVide || (plateau[ligne][colonne]).getTour()==caseInterdite){
        cout << "ERREUR >> CASE VIDE OU CASE INTERDITE >> ON RECOMMENCE" <<endl;
        test=false;
    }
    else if (plateau[Depart.getLigne()][Depart.getColonne()].getCompteur()+plateau[Arrivee.getLigne()][Arrivee.getColonne()].getCompteur()>compteurMax){
        cout << "ERREUR >> MAX DE PION = " << compteurMax << " >> DEPLACEMENT INTERDIT" << endl;
        test=false;
    }
    else if(Depart.getLigne()==Arrivee.getLigne() && Depart.getColonne()==Arrivee.getColonne()){
        cout << "ERREUR >> COORDONNÉES IDENTIQUE QUE DEPART ET ARRIVEE" << endl;
        test=false;
    }
    else if(abs(Depart.getLigne()-Arrivee.getLigne())<=1 && abs(Depart.getColonne()-Arrivee.getColonne())<=1){
        test=true;
    }
    else test=false;
    return test;
}

/*
 * Fonction     getCompteurMax()
 * Description  Fonction qui renvoie le compteurMax
 * Arguments    Aucun
 * Renvoi       int compteurMax : égal au nombre de tours max sur une case
 */

int Plateau::getCompteurMax(){
    return compteurMax;
}

/*
 * Fonction     setCompteurMax(unsigned int cptMax)
 * Description  Fonction qui met à jour le compteurMax
 * Arguments    unsigned int compteurMax
 * Renvoi       Rien
 */

void Plateau::setCompteurMax(unsigned int cptMax){
    compteurMax=cptMax;
}

/*
 * Fonction     estuneTourPleine(unsigned int ligne, unsigned int colonne)
 * Description  Fonction qui vérifie si la case[i][j] contient une tour pleine
 * Arguments    unsigned int ligne
                unsigned int colonne
 * Renvoi       bool tourPleine : true si le compteur=compteurMax, false sinon
 */

bool Plateau::estUneTourPleine(unsigned int ligne, unsigned int colonne){
    if(plateau[ligne][colonne].getCompteur()==compteurMax){
        cout << "Il y a une tour complete en [" << ligne << ";" << colonne << "]" << endl;
        tourPleine=true;
    }
    else tourPleine=false;
    return tourPleine;
}

/*
 * Fonction     testSiFinPartie()
 * Description  Fonction qui test s'il y a encore des coups à joués
 * Arguments    Aucun
 * Renvoi       bool finPartie : true s'il n'y a plus de coups à joués, false sinon
 */

bool Plateau::testSiFinPartie(){
    for(int i=0; i<nombreDeLignes; i++){
        for(int j=0; j<nombreDeColonnes; j++){
            if(plateau[i][j].getTour()==tourRouge || plateau[i][j].getTour()==tourBleu){
                if(estUneTourPleine(i,j) == true) finPartie=true;
                else if(estUneTourNonPleine(i,j) == true) finPartie=true;
                else finPartie = false;
            }
        }
    }
    return finPartie;
}

/*
 * Fonction     victoire()
 * Description  Fonction qui détermine quel est le gagnant de la partie
 * Arguments    Aucun
 * Renvoi       bool : true si un des deux joueurs à gagner, false sinon
 */

bool Plateau::victoire(){
    if(finPartie==true){
        cout << "**************************************" << endl;
        cout << "********** FIN DE LA PARTIE **********" << endl;
        cout << "**************************************" << endl;
        if(scoreJoueur(tourRouge)>scoreJoueur(tourBleu)){
            cout << "LE JOUEUR AUX TOURS ROUGE GAGNE" << endl;
            return true;
        }
        else if(scoreJoueur(tourRouge)<scoreJoueur(tourBleu)){
            cout << "LE JOUEUR AUX TOURS BLEU GAGNE" << endl;
            return true;
        }
        else{
            cout << "IL Y A EGALITE" << endl;
            int nbrTourBleu=0;
            int nbrTourRouge=0;
            for(int i=0; i<nombreDeLignes; i++){
                for(int j=0; j<nombreDeColonnes; j++){
                    if(plateau[i][j].getTour()==tourBleu && plateau[i][j].getCompteur()==compteurMax) nbrTourBleu++;
                    else if (plateau[i][j].getTour()==tourRouge && plateau[i][j].getCompteur()==compteurMax) nbrTourRouge++;
                }
            }
            if(nbrTourBleu > nbrTourRouge) cout << "LE JOUEUR AUX TOURS BLEU GAGNE" << endl;
            else cout << "LE JOUEUR AUX TOURS ROUGE GAGNE" << endl;
            return true;
        }
    }
    else return false;
}

/*
 * Fonction     estuneTourNonPleine(unsigned int ligne, unsigned int colonne)
 * Description  Fonction qui vérifie si la case[i][j] est une tour non pleine
 * Arguments    unsigned int ligne
                unsigned int colonne
 * Renvoi       bool tourNonPleine : true si elle est non pleine false sinon
 */

bool Plateau::estUneTourNonPleine(unsigned int ligne, unsigned int colonne){
    if(ligne-1==-1){
        if((plateau[ligne][colonne-1].getTour()==caseVide || plateau[ligne][colonne-1].getTour()==caseInterdite ||
            plateau[ligne][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne-1].getTour()==caseVide || plateau[ligne+1][colonne-1].getTour()==caseInterdite ||
            plateau[ligne+1][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne].getTour()==caseVide || plateau[ligne+1][colonne].getTour()==caseInterdite ||
            plateau[ligne+1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne+1].getTour()==caseVide || plateau[ligne+1][colonne+1].getTour()==caseInterdite ||
            plateau[ligne+1][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne+1].getCompteur()>compteurMax) &&
           (plateau[ligne][colonne+1].getTour()==caseVide || plateau[ligne][colonne+1].getTour()==caseInterdite ||
            plateau[ligne][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne+1].getCompteur()>compteurMax)){
            cout << "tour non complete mais non deplaçable en [" << ligne << ";" << colonne << "]" << endl;
            tourNonPleine=true;
        }
        else tourNonPleine=false;
    }
    
    else if(colonne-1==-1){
        if((plateau[ligne-1][colonne].getTour()==caseVide || plateau[ligne-1][colonne].getTour()==caseInterdite ||
            plateau[ligne-1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne-1][colonne+1].getTour()==caseVide || plateau[ligne-1][colonne+1].getTour()==caseInterdite ||
            plateau[ligne-1][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne+1].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne].getTour()==caseVide || plateau[ligne+1][colonne].getTour()==caseInterdite ||
            plateau[ligne+1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne+1].getTour()==caseVide || plateau[ligne+1][colonne+1].getTour()==caseInterdite ||
            plateau[ligne+1][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne+1].getCompteur()>compteurMax) &&
           (plateau[ligne][colonne+1].getTour()==caseVide || plateau[ligne][colonne+1].getTour()==caseInterdite ||
            plateau[ligne][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne+1].getCompteur()>compteurMax)){
            cout << "tour non complete mais non deplaçable en [" << ligne << ";" << colonne << "]" << endl;
               tourNonPleine=true;
        }
        else tourNonPleine=false;
    }
    
    else if(ligne+1==nombreDeLignes){
        if((plateau[ligne-1][colonne].getTour()==caseVide || plateau[ligne-1][colonne].getTour()==caseInterdite ||
            plateau[ligne-1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne-1][colonne+1].getTour()==caseVide || plateau[ligne-1][colonne+1].getTour()==caseInterdite ||
            plateau[ligne-1][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne+1].getCompteur()>compteurMax) &&
           (plateau[ligne][colonne+1].getTour()==caseVide || plateau[ligne][colonne+1].getTour()==caseInterdite ||
            plateau[ligne][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne+1].getCompteur()>compteurMax) &&
           (plateau[ligne-1][colonne-1].getTour()==caseVide || plateau[ligne-1][colonne-1].getTour()==caseInterdite ||
            plateau[ligne-1][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne][colonne-1].getTour()==caseVide || plateau[ligne][colonne-1].getTour()==caseInterdite ||
            plateau[ligne][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne-1].getCompteur()>compteurMax)){
            cout << "tour non complete mais non deplaçable en [" << ligne << ";" << colonne << "]" << endl;
            tourNonPleine=true;
        }
        else tourNonPleine=false;
    }
    
    else if(colonne+1==nombreDeColonnes){
        if((plateau[ligne-1][colonne].getTour()==caseVide || plateau[ligne-1][colonne].getTour()==caseInterdite ||
            plateau[ligne-1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne-1].getTour()==caseVide || plateau[ligne+1][colonne-1].getTour()==caseInterdite ||
            plateau[ligne+1][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne].getTour()==caseVide || plateau[ligne+1][colonne].getTour()==caseInterdite ||
            plateau[ligne+1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne-1][colonne-1].getTour()==caseVide || plateau[ligne-1][colonne-1].getTour()==caseInterdite ||
            plateau[ligne-1][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne][colonne-1].getTour()==caseVide || plateau[ligne][colonne-1].getTour()==caseInterdite ||
            plateau[ligne][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne-1].getCompteur()>compteurMax)){
            cout << "tour non complete mais non deplaçable en [" << ligne << ";" << colonne << "]" << endl;
            tourNonPleine=true;
        }
        else tourNonPleine=false;
    }
    else if(ligne>0 && ligne<nombreDeLignes && colonne>0 && colonne<nombreDeColonnes){
       if((plateau[ligne+1][colonne-1].getTour()==caseVide || plateau[ligne+1][colonne-1].getTour()==caseInterdite ||
            plateau[ligne+1][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne].getTour()==caseVide || plateau[ligne+1][colonne].getTour()==caseInterdite ||
            plateau[ligne+1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne-1][colonne-1].getTour()==caseVide || plateau[ligne-1][colonne-1].getTour()==caseInterdite ||
            plateau[ligne-1][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne-1][colonne].getTour()==caseVide || plateau[ligne-1][colonne].getTour()==caseInterdite ||
            plateau[ligne-1][colonne].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne].getCompteur()>compteurMax) &&
           (plateau[ligne-1][colonne+1].getTour()==caseVide || plateau[ligne-1][colonne+1].getTour()==caseInterdite ||
            plateau[ligne-1][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne-1][colonne+1].getCompteur()>compteurMax)  &&
           (plateau[ligne][colonne-1].getTour()==caseVide || plateau[ligne][colonne-1].getTour()==caseInterdite ||
            plateau[ligne][colonne-1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne-1].getCompteur()>compteurMax) &&
           (plateau[ligne][colonne+1].getTour()==caseVide || plateau[ligne][colonne+1].getTour()==caseInterdite ||
            plateau[ligne][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne][colonne+1].getCompteur()>compteurMax) &&
           (plateau[ligne+1][colonne+1].getTour()==caseVide || plateau[ligne+1][colonne+1].getTour()==caseInterdite ||
            plateau[ligne+1][colonne+1].getCompteur()==compteurMax || plateau[ligne][colonne].getCompteur()+plateau[ligne+1][colonne+1].getCompteur()>compteurMax)){
            cout << "tour non complete mais non deplaçable en [" << ligne << ";" << colonne << "]" << endl;
            tourNonPleine=true;
        }
       else tourNonPleine=false;
    }
    else tourNonPleine=false;
return tourNonPleine;
}
