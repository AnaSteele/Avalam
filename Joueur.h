/*
 * Fichier      Joueur.h
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#ifndef __Avalam__Joueur__
#define __Avalam__Joueur__

#include <string>

// TYPE DE JOUEUR 
//enum class typePlayer {Humain, Ordi};

class Joueur{
private:
    std::string nom;
    int id;
    int score;
    char couleur;

public:
    Joueur();
    Joueur(int jId, std::string jNom, int jScore, char jCouleur);
    
    std::string getNom();
    
    int getId();
    
    char getCouleur();
    
    void saisieNomJoueur();
    void choixCouleurTour();
    void setTour(char couleur);
    void setNom(std::string nom);
};





#endif 
