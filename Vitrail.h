#ifndef VITRAIL_H
#define VITRAIL_H


using namespace std;
class Vitrail {
private:
    char** fenetre; //Double pointeur au tableau 2D alloue dynamique
    const char couleurs [5]= {'G', 'J','B','R','O'}; //couleurs pre-definis des vitres
    int colonnes, rows;
public:
    Vitrail(int colonnes, int vitres); //constructeur

    //prendre vitres du vector et mettre dans vitrail a colonne
    int construireVitrail(std ::vector<char> vitres, int colonne);

    //retourne vrai si colonne est complete
    bool estComplete(int colonne);

    //est ce que au moins un vitre installe
    bool estEnConstruction(int colonne);

    //affichage des vitrails
    const &operator <<();

    int getColonne() {return this.colonnes}

};
#endif // VITRAIL
