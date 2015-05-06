

#include "Joueur.h"
#include <iostream>
using namespace std;

Joueur::Joueur(){
    m_id = 0;
    m_name = "Player";
    m_score = 0;
}

Joueur::Joueur(int id, string nom, int score){
    m_id = id;
    m_name = nom;
    m_score = score;
}

string Joueur::getNom() const {
    return m_name;
}

int Joueur::getId() const{
    return m_id; 
}

void Joueur::saisieNomJoueur(){
    string nom;
    cout << "Player" << m_id << " name >> ";
    cin >> nom;
    m_name=nom;
    locale loc;
    string::iterator it;
    for(it=nom.begin(); it!=nom.end(); it++){
        if(isalpha(*it,loc)) cout << "";
        else{
            /*do{
                cout << *it << " n'est pas une lettre ! " << endl;
                saisieNomJoueur();
                //cout << "Player" << m_id << "name >> ";
                //cin >> nom;
            }while(!isalpha(*it,loc));*/
            do{
                cout << *it << " n'est pas une lettre ! " << endl;
                cin.clear();
                std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
                //cout << "Player" << m_id << "name >> ";
                //cin >> nom;
            }while(!isalpha(*it, loc));
        }
    }
}






