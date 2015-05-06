
/*
 * Inclusions
 */

#ifndef __Avalam__Joueur__
#define __Avalam__Joueur__

#include <string>

//enum class typePlayer {Humain, Ordi};

class Joueur{
public:
    Joueur();
    Joueur(int id, std::string nom, int score);
    std::string getNom() const;
    int getId() const;
    void saisieNomJoueur();
    
private:
    std::string m_name;
    int m_id;
    int m_score;
};



#endif 
