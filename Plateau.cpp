/*
 *  Fichier     Plateau.cpp
 *  Dossier     Mini-projet "Avalam"
 *  Auteur      
 *  Date        Date de début du projet
 *
 *
 */

/*
 * Les Inclusions
 */

#include        "Plateau.h"
#include        "Menu.h"
#include        "Joueur.h"

#include        <iostream>
#include        <ncurses.h>
#include        <fstream>
#include        <string>
#include        <cstdlib>
#include        <vector>
#include        <map>
#include        <locale>

using namespace std;

/*
 *  Fonction        Plateau::Plateau()
 *  Description     Methode constructeur de la classe
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

Plateau::Plateau(){
    _partieNulle=0;
    _nbrLignes=11;
    _nbrColonnes=13;
    _plateau = new char*[_nbrLignes];
    for(int i=0 ; i<_nbrLignes; i++){
        _plateau[i] = new char[_nbrColonnes];
        for(int j=0 ; j<_nbrColonnes; j++){
            _plateau[i][j]=caseVide;
        }
    }
}

/*
 *  Fonction        Plateau::~Plateau()
 *  Description     Methode destructeur de la classe
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

Plateau::~Plateau(){
    for(int i=0; i<_nbrLignes; i++){
        delete[] _plateau[i];
    }
    delete[] _plateau;
}

/*
 *  Fonction        void Plateau::initialiser()
 *  Description     Initialiser le plateau avec plateau[i][j]
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

void Plateau::initialiser(){
    _plateau = new char*[_nbrLignes];
    for(int i=0 ; i<_nbrLignes; i++){
        _plateau[i] = new char[_nbrColonnes];
        for(int j=0 ; j<_nbrColonnes; j++){
            _plateau[i][j]=caseVide;
        }
    }
    
    for(int i=0; i<_nbrLignes; i+=2){
        for(int j=1; j<_nbrColonnes; j+=2){
            _plateau[i][j]=pionRouge;
        }
    }
    
    for(int i=1; i<_nbrLignes; i+=2){
        for(int j=0; j<_nbrColonnes; j+=2){
            _plateau[i][j]=pionJaune;
        }
    }
    
    for(int i=0; i<1; i++){
        for(int j=0; j<9; j++){
            _plateau[i][j]=caseVide;
        }
    }
    
    for(int i=1; i<2; i++){
        for(int j=0; j<5; j++){
            _plateau[i][j]=caseVide;
        }
    }
    
    for(int i=0; i<4; i++){
        for(int j=11; j<_nbrColonnes; j++){
            _plateau[i][j]=caseVide;
        }
    }
    
    for(int i=7; i<_nbrLignes; i++){
        for(int j=0; j<2; j++){
            _plateau[i][j]=caseVide;
        }
    }
    for(int i=9; i<10; i++){
        for(int j=8; j<_nbrColonnes; j++){
            _plateau[i][j]=caseVide;
        }
    }
    for(int i=10; i<_nbrLignes; i++){
        for(int j=5; j<_nbrColonnes; j++){
            _plateau[i][j]=caseVide;
        }
    }
    _plateau[5][6]=caseVide;
}


/*
 *  Fonction        int Plateau::compterPions(char couleur)
 *  Description     Compter le nombre de pions
 *  Arguments       char couleur    definit la couleur du pion
 *  Renvoie         nbcouleur       le nombre de pions en fonction de la couleur
 */

int Plateau::scoreJoueurs(char _couleur){
    int i,j;
    int nbcouleur=0;
    for(i=0;i<_nbrLignes;i++){
        for(j=0;j<_nbrColonnes;j++){
            if(_plateau[i][j]==_couleur) nbcouleur=nbcouleur+1;
        }
    }
    return nbcouleur;
}

/*
 *  Fonction        void Plateau::afficher()
 *  Description     Afficher le plateau avec les chiffres
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

void Plateau::afficher(){
    cout << endl << endl;
    
    for(int i=0; i< _nbrLignes; i++){
        if(i>9) cout << i<<"  | "; // premier pipe apres n° de ligne >9
        else cout << i <<"   | "; // premier pipe apres n° de ligne <9
        for(int j=0; j<_nbrColonnes; j++){
            if(_plateau[i][j]==pionRouge) cout << RED << pionRouge << CANCEL;
            else if(_plateau[i][j]==pionJaune) cout << YELLOW << pionJaune << CANCEL;
            else cout << CANCEL;
            if (_plateau[i][j]==pionRouge || _plateau[i][j]==pionJaune) cout << "  | ";
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
    
    cout << "*******************************************" << endl;
    cout << "*************** SCORES ********************" << endl;
    cout << "*******************************************" << endl;
    cout << _prenom1 << " >> " << RED << scoreJoueurs(pionRouge) << CANCEL << endl;
    cout << _prenom2 << " >> " << YELLOW << scoreJoueurs(pionJaune) << CANCEL << endl;
}

/*
 *  Fonction        int Plateau::testSiFinDePartie(char couleur, int affiche, char typeJoueur)
 *  Description     Tester si fin de partie (plus de deplacement de pions possibles, vainqueur...)
 *  Arguments       char couleur
 *                  int afficher
 *                  char typeJoueur
 *  Renvoie         1 si partie finie, 0 sinon
 */

int Plateau::testSiFinDePartie(char _couleur, char _typeJoueur){
    bool victoire;
    if(_partieNulle==1) return victoire=1;
    if(scoreJoueurs(pionRouge)>scoreJoueurs(pionJaune)) cout << "Joueur rouge a gagner" << endl;
    else if(scoreJoueurs(pionJaune)>scoreJoueurs(pionRouge)) cout << "Joueur jaune a gagner" << endl;
    else cout << "egalité" << endl;
    return victoire=0;
}

/*
 *  Fonction        void Plateau::mettrePartieNulle()
 *  Description     Positionne à 1 la variable PartieNulle
 *  Arguments       Aucun
 *  Renvoie         Rien
 */

void Plateau::mettrePartieNulle(){
    _partieNulle=1;
}

/*
 * Fonction         void Plateau::joueurHumain()
 * Descritpion      Fonction qui gere un coup humain
 * Arguments        Aucun
 * Renvoie          Rien
 */

void Plateau::joueurHumain(){
    cout << "* Saisie des coordonnées du pion à déplacer *" << endl;
    do {
        do{
            do{
                cout << "Ligne case de depart >>";
                cin >> _Depart.ligne;
                cout << "Colonne case de depart >>";
                cin >> _Depart.colonne;
                
                deplacementPossible();
                
                if(_plateau[_Depart.ligne][_Depart.colonne]==caseVide){
                    cout << "il n'y a pas de pion" << endl;
                    cout << "re rentrer les coordonnées de depart svp" << endl;
                }
            }while(_plateau[_Depart.ligne][_Depart.colonne]==caseVide);
        
            do{
                cout << endl;
                cout << "Ligne case d'arrivee >>";
                cin >> _Arrivee.ligne;
                cout << "Colonne case d'arrivee >>";
                cin >> _Arrivee.colonne;
                
                if((_Arrivee.ligne==_Depart.ligne+1 && _Arrivee.colonne==_Depart.colonne+1) ||
                    (_Arrivee.ligne==_Depart.ligne+1 && _Arrivee.colonne==_Depart.colonne-1) ||
                    (_Arrivee.ligne==_Depart.ligne-1 && _Arrivee.colonne==_Depart.colonne+1) ||
                    (_Arrivee.ligne==_Depart.ligne-1 && _Arrivee.colonne==_Depart.colonne-1)) {
                    cout << "ok";
                    effectuerDeplacement(_couleur, _Depart, _Arrivee);
                    chercherCoordonneesTour();
                    _deplacement=true;
                }
 
                else{
                    cout << "ERREUR" << endl;
                    _deplacement=false;
                }
 
 
                if (_plateau[_Arrivee.ligne][_Arrivee.colonne]==caseVide){
                    cout << "vous ne pouvez pas deplacez sur un vide" <<endl;
                    cout << "re rentrer les coordonnées d'arrivee svp"<< endl;
                }
                
            }while(_plateau[_Arrivee.ligne][_Arrivee.colonne]==caseVide || _deplacement==false);
            
            if((_Depart.ligne<0 || _Depart.ligne>_nbrLignes) || (_Depart.colonne<0 || _Depart.colonne>_nbrColonnes) || (_Arrivee.ligne<0 || _Arrivee.ligne>_nbrLignes) || (_Arrivee.colonne<0 || _Arrivee.colonne>_nbrColonnes)) cout << "coordonnées hors plateau" << endl;
            
            }while ((_Depart.ligne<0 || _Depart.ligne>_nbrLignes) || (_Depart.colonne<0 || _Depart.colonne>_nbrColonnes) || (_Arrivee.ligne<0 || _Arrivee.ligne>_nbrLignes) || (_Arrivee.colonne<0 || _Arrivee.colonne>_nbrColonnes));
        
        if(_Depart.ligne==_Arrivee.ligne && _Depart.colonne==_Depart.colonne) cout << "coordonnées depart meme que arrivee" << endl;
        
    }while(_Depart.ligne==_Arrivee.ligne && _Depart.colonne==_Depart.colonne);
}

/*
 * Fonction         void Plateau::deplacementPossible
 * Description      Fonction qui affiche les deplacements possible par rapport au coordonnées de depart d'un pion
 * Arguments        Aucun
 * Renvoie          Rien
 */

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

/*
 * Fonction         void Plateau::testBasDroite
 * Description      Fonction qui teste si dans la diagonale en bas a droite de la case choisie il y a un pion. Si oui il affiche les coordonnées 
 *                  de celle-ci
 * Arguments        Aucun
 * Renvoie          Rien
 */

void Plateau::testBasDroite(){
    if(((_Depart.ligne+1)<0 || (_Depart.ligne+1)>_nbrLignes) || (_Depart.colonne+1<0 || _Depart.colonne+1>_nbrColonnes))
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if(_plateau[_Depart.ligne+1][_Depart.colonne+1]==pionJaune || _plateau[_Depart.ligne+1][_Depart.colonne+1]==pionRouge){
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << _Depart.ligne+1 << ";" << _Depart.colonne+1 << "]" << endl;
    }
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}

/*
 * Fonction         void Plateau::testBasGauche
 * Description      Fonction qui teste si dans la diagonale en bas a gauche de la case choisie il y a un pion. Si oui il affiche les coordonnées
 *                  de celle-ci
 * Arguments        Aucun
 * Renvoie          Rien
 */

void Plateau::testBasGauche(){
    if(((_Depart.ligne+1)<0 || (_Depart.ligne+1)>_nbrLignes) || (_Depart.colonne-1<0 || _Depart.colonne-1>_nbrColonnes))
            cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if (_plateau[_Depart.ligne+1][_Depart.colonne-1]==pionJaune || _plateau[_Depart.ligne+1][_Depart.colonne-1]==pionRouge){
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << _Depart.ligne+1 << ";" << _Depart.colonne-1 << "]" << endl;
    }
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}

/*
 * Fonction         void Plateau::testHautDroite
 * Description      Fonction qui teste si dans la diagonale en haut a droite de la case choisie il y a un pion. Si oui il affiche les coordonnées
 *                  de celle-ci
 * Arguments        Aucun
 * Renvoie          Rien
 */

void Plateau::testHautDroite(){
    if(((_Depart.ligne-1)<0 || (_Depart.ligne-1)>_nbrLignes) || (_Depart.colonne+1<0 || _Depart.colonne+1>_nbrColonnes))
            cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if(_plateau[_Depart.ligne-1][_Depart.colonne+1]==pionJaune || _plateau[_Depart.ligne-1][_Depart.colonne+1]==pionRouge){
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << _Depart.ligne-1 << ";" << _Depart.colonne+1 << "]" << endl;
    }
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}

/*
 * Fonction         void Plateau::testHautGauche
 * Description      Fonction qui teste si dans la diagonale en haut a gauche de la case choisie il y a un pion. Si oui il affiche les coordonnées
 *                  de celle-ci
 * Arguments        Aucun
 * Renvoie          Rien
 */

void Plateau::testHautGauche(){
    if(((_Depart.ligne-1)<0 || (_Depart.ligne-1)>_nbrLignes) || (_Depart.colonne-1<0 || _Depart.colonne-1>_nbrColonnes))
        cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
    else if(_plateau[_Depart.ligne-1][_Depart.colonne-1]==pionJaune || _plateau[_Depart.ligne-1][_Depart.colonne-1]==pionRouge){
        cout << "DEPLACEMENT POSSIBLE DE VOTRE PION EN [" << _Depart.ligne-1 << ";" << _Depart.colonne-1 << "]" << endl;
    }
    else cout << "PAS DE DEPLACEMENT POSSIBLE." << endl;
}

/*
 * Fonction         void Plateau::effectuerDeplacement(char lacouleur, CoordonneesCase Depart, CoordonneesCase Arrivee)
 * Description      effectue le deplacement d'un pion
 * Arguments        Aucun
 * Renvoie          Rien
 */

void Plateau::effectuerDeplacement(char _lacouleur,CoordonneesCase _Depart, CoordonneesCase _Arrivee)
{
    if(_plateau[_Depart.ligne][_Depart.colonne]==pionRouge){
        _plateau[_Arrivee.ligne][_Arrivee.colonne]=pionRouge;
    }
    else _plateau[_Arrivee.ligne][_Arrivee.colonne]=pionJaune;
    
    _plateau[_Depart.ligne][_Depart.colonne]=caseVide;
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
    cout << "historique des coordonnées d'arrivée" << endl;
    CoordonneesCase c;
    c.ligne = _Arrivee.ligne;
    c.colonne=_Arrivee.colonne;
    _tab.push_back(c);
    for(vector<CoordonneesCase>::iterator it=_tab.begin(); it !=_tab.end(); it++)
    {
        cout << "ligne: " << (*it).ligne << " ";
        cout << "colonne: " << (*it).colonne << endl;
        cout << "-----------------------------" << endl; ;
    }
    map<CoordonneesCase,int> map; // definition d'une map qui contient un couple de coordonnées et un int qui correspond au nombre de fois ou elle a été rencontrées
    for(vector<CoordonneesCase>::iterator it=_tab.begin(); it!=_tab.end(); it++){
        std::map<CoordonneesCase, int>::iterator f=map.find(*it);
        // si l'élément n'existe pas je l'ajoute en disant qu'il a été trouvé une seule fois
        if(f==map.end()) map.insert(pair<CoordonneesCase, int>(*it,1)); // si l'élément existe deja je vais ajouter 1 au nombre de fois ou il a été trouvé
        else map[*it]++;
        // je vais parcourir tab, et pour chaque coordonnées qu'il contient je regarde si je l'ai dans ma map. si elle n'y est pas je l'ajoute, et si elle y est je dis qu'elle a été rencontrée une nouvelle fois
    }
    for (std::map<CoordonneesCase, int>::iterator it=map.begin(); it!=map.end(); it++){
        if(it->second==4) cout << "Il y a une Tour en  [" << it->first.ligne << ";" << it->first.colonne << "]" << endl;
        // enfin je regarde dans ma map si je trouve une coordonnée qui a été rencontrée 4 fois
    }
    
    // si une coordonnées a été entré 4 fois je l'ajoute dans le vector. quand on entre de nouvelles coordonnées on verifie qu'elle n'y sont pas
    CoordonneesCase coordonneesEntrees={c.ligne,c.colonne};
    vector<CoordonneesCase>::iterator it=find(_vectorDeCoordConnues.begin(), _vectorDeCoordConnues.end(), coordonneesEntrees);;
    // si elles existent
    if(it!=_vectorDeCoordConnues.end()) {
        cout << "existe";
        // code ici
        // interdire acces
        
    }
    // si elle n'existent pas
    else {
        cout << "existe pas";
        // code ici
        // rentrer cette coordonnées dans le fichier et interdire son acces
    }
}

void Plateau::prenomsJoueurs(char _typeJoueur)
{
    if(_typeJoueur=='h'){
        locale loc;
        string::iterator it;
        
        cout << "Joueur1, Entrez votre prénom >>> "; cin >> _prenom1;
        for(it=_prenom1.begin(); it!=_prenom1.end(); it++){
            if(isalpha(*it,loc)) cout << " ";
            else{
                do{
                    cout << *it << " n'est pas une lettre" << endl;
                    cout << "Joueur1, Entrez votre prénom >>> "; cin >> _prenom1;
                }while(!isalpha(*it,loc));
            }
        }
        cout << endl;
        cout << "Joueur2, Entrez votre prénom >>> "; cin >> _prenom2;
        for(it=_prenom2.begin(); it!=_prenom2.end(); it++){
            if(isalpha(*it,loc)) cout << "OK ";
            else{
                do{
                    cout << *it << " n'est pas une lettre" << endl;
                    cout << "Joueur2, Entrez votre prénom >>> "; cin >> _prenom2;
                }while(!isalpha(*it,loc));
            }
        }
        cout << endl;
    }
    else if (_typeJoueur=='o'){
        cout << "Joueur, Entrez votre prénom >>> ";
        cin >> _prenom1;
        cout << "Ordi, Entrez votre prenom >>> ";
        cin >> _prenom2;
    }
    
    else if(_typeJoueur=='d'){
        _prenom1="Joueur1";
        _prenom2="Joueur2";
        cout << "ATTRIBUTION DE PRENOMS PAR DEFAUT >> " << _prenom1 << " ET " << _prenom2 << endl;
        
    }
    cout << "BIENVENUE DANS LA PARTIE " << _prenom1 << " ET " << _prenom2 << endl;
    joueEnPremier();
}

void Plateau::choixPrenomsJoueurs(){
    char choix;
    if(choix!='o' || choix!='O' || choix!='n' || choix!='N'){
        cout << "VOULEZ-VOUS SAISIR VOS PRENOMS ? (O-N) >> ";
        cin >> choix;
        cout << endl;
        if (choix=='o' || choix=='O') prenomsJoueurs('h');
        else if (choix=='n' || choix=='N') prenomsJoueurs('d');
        else {
            cout << "ERREUR" << endl;
            choixPrenomsJoueurs();
        }
    }
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
    
    if (choixJoueur == _prenom1) _tourJoueur=false;
    else if (choixJoueur == _prenom2) _tourJoueur=true;
    else{
        while(choixJoueur!=_prenom1 && choixJoueur!=_prenom2){
            cout << " Vous avez entrez un mauvais prénom ! >> ";
            cin >> choixJoueur;
        }
    }
}

/*
 *  Code        Joueur::aQuiDeJouer()
 *  Dossier     Fonction qui gère la main des joueurs
 *  Paramètres  Aucun
 *  Return      booléen
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
    cout << "       3 - SAUVEGARDER LA PARTIE " << endl;
    cout << "       4 - QUITTER LA PARTIE" << endl;
}

/*
 *  Code        Joueur::lancerMenuJoueur()
 *  Dossier     Methode qui gere toutes les fonctions des joueurs
 *  Paramètres  Aucun
 *  Return      Rien
 */

void Plateau::lancerMenuJoueur(){
    int choix = 0;
    menuJoueur();
    if(_tourJoueur == false) cout << _prenom1 << ", que voulez-vous faire >>> " ;
    else cout << _prenom2 << ", que voulez-vous faire >>> ";
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
            cout << "* SAUVEGARDER LA PARTIE *" << endl;
            cout << "NON DEVELOPPÉE" << endl;
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







