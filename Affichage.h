

#ifndef __Avalam__Affichage__
#define __Avalam__Affichage__

class Affichage{
public:
    void menuJoueur();
    void menuJeu();
    int lireChoixMenuJeu();
    void aPropos();
    void parametresDuJeu();
    bool lireChoixMenuParametres(); 
    void reglesDuJeu();
    int quitterLeJeu();

private:
    int choixMenu;
    int choixParametres; 
};


#endif 
