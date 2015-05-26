/*
 * Fichier      main.cpp
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#include "Jeu.h"
#include <iostream>

using namespace std;

int main(){
    cout << "**************************************" << endl;
    cout << "*              BIENVENUE             *" << endl;
    cout << "*                                    *" << endl;
    cout << "*               Avalam               *" << endl;
    cout << "*    Réalisé par Marine TALIERCIO    *" << endl;
    cout << "**************************************" << endl;
    
    Jeu avalam;
    avalam.lancer();
    return 0;
}
