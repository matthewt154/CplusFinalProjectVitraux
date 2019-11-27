#ifndef VITRAIL_H
#define VITRAIL_H
#include <vector>

using namespace std;

class Vitrail {
private:
    char** fenetre; //Double pointeur au tableau 2D alloue dynamique
    const char couleurs [5]= {'G','J','B','R','O'}; //couleurs pre-definis des vitres
    int colonnes, rows;
public:

    Vitrail(); //constructeur par default

    Vitrail(int colonnes, int vitres){}; //constructeur parametrizer

    //prendre vitres du vector et mettre dans vitrail a colonne
    int construireVitrail(vector<char> vitres, int colonne);

    //retourne vrai si colonne est complete
    bool estComplete(int colonne);

    //est ce que au moins un vitre installe
    bool estEnConstruction(int colonne);

    //affichage des vitrails
    ostream &operator<<(Vitrail &);

    int getColonne();

};
#endif // VITRAIL

