#ifndef VITRAIL_H
#define VITRAIL_H
#include <vector>
#include <iostream>

using namespace std;

class Vitrail {
private:

    const static char couleurs []; //couleurs pre-definis des vitres
    char** fenetre; //Double pointeur au tableau 2D alloue dynamique
    int colonnes, rows;
public:



    Vitrail(int colonnes, int vitres); //constructeur parametrizer

    //prendre vitres du vector et mettre dans vitrail a colonne
    int construireVitrail(vector<char> vitres, int colonne);

    //retourne vrai si colonne est complete
    bool estComplete(int colonne);

    //est ce que au moins un vitre installe
    bool estEnConstruction(int colonne);

    //affichage des vitrails
    friend std::ostream &operator<<(std::ostream& os, const Vitrail *vitrail);

    int getColonne();

};
std::ostream &operator<<(std::ostream& os, const Vitrail *vitrail);
#endif // VITRAIL

