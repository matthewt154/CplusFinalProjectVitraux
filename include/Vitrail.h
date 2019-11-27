#ifndef VITRAIL_H
#define VITRAIL_H
#include <vector>
#include <iostream>

using namespace std;

class Vitrail {
private:

    const char couleurs [5]= {'G','J','B','R','O'}; //couleurs pre-definis des vitres

public:

    char** fenetre; //Double pointeur au tableau 2D alloue dynamique
    int colonnes, rows;

    Vitrail(); //constructeur par default

    Vitrail(int colonnes, int vitres); //constructeur parametrizer

    //prendre vitres du vector et mettre dans vitrail a colonne
    int construireVitrail(vector<char> vitres, int colonne);

    //retourne vrai si colonne est complete
    bool estComplete(int colonne);

    //est ce que au moins un vitre installe
    bool estEnConstruction(int colonne);

    //affichage des vitrails
    std::ostream &operator<<(Vitrail &);

    int getColonne();

};
#endif // VITRAIL

