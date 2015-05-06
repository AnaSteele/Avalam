
#ifndef __Avalam__Case__
#define __Avalam__Case__

class Case{
public:
    Case();
    ~Case();
    Case(int l, int c, char t, int cpt);
    char getTour();
    int getLigne();
    int getColonne();
    int getCompteur();
    
private:
    int ligne;
    int colonne;
    char tour;
    int compteur;
};

#endif
