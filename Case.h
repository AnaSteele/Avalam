/*
 * Fichier      Case.h
 *              Mini-Projet "Avalam"
 * Auteur       Marine Taliercio
 * Date         2015
 */

#ifndef __Avalam__Case__
#define __Avalam__Case__

const char tourRouge = 'R';
const char tourBleu= 'B';
const char caseInterdite= 'X';
const char caseVide= ' ';

class Case{
private:
    unsigned int ligne;
    unsigned int colonne;
    unsigned int compteur;
    char tour;

public:
    Case();
    Case(unsigned int l, unsigned int c, char t, unsigned int cpt);
    ~Case();
    
    char getTour();
    
    void setTour(char t);
    void setLigne(unsigned int);
    void setColonne(unsigned int);
    void setCompteur(unsigned int);
    
    int getLigne();
    int getColonne();
    int getCompteur();
};

#endif
