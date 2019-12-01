/*
*   Cours:        CSI2772 - Concept avancer en C++
*   Session:      Autumne 2019
*   Remise:       6 décembre 2019
*   Author 1:     Mathieu Bellefeuille
*   # etudiant:   65013369
*   Auteur 2:     Matthew Tan
*   # etudiant:   300028206
*/

#ifndef VITRAIL_H
#define VITRAIL_H
#include <vector>
#include <iostream>

using namespace std;

class Vitrail {
private:
    //couleurs pre-definis des vitres
    const static char couleurs [];
    //Double pointeur au tableau 2D alloue dynamique
    char** fenetre;
    //varable pour colonne et rows de notre vitrail
    int colonnes, rows;
public:

    /*
    *   @param: colonne/vitre donc est composer le vitrail
    *   > constructeur parametrizer
    */
    Vitrail(int colonnes, int vitres); //constructeur parametrizer

    /*
    *   @param: vitres - lot selectionner, colonne - colonne selectionner du vitrail
    *   @return: nombre d'index vitres non utiliser
    *   > prend les vitres du lot et les met dans le vitrail a la colonne referencer
    */
    int construireVitrail(vector<char> vitres, int colonne);

    /*
    *   @param: colonne- colonne a evaluer
    *   @return: true si la colonne est pleine
    *   > retourne vrai si colonne est complete
    */
    bool estComplete(int colonne);

    /*
    *   @param: colonne- colonne a evaluer
    *   @return: true si colonne changer
    *   > verifie si au moin une vitre a ete changer dans la colonne
    */
    bool estEnConstruction(int colonne);

    /*
    *   @return: le nombre de la colonne
    */
    int getColonne();

    /*
    *   > Affiche le vitrail
    */
    friend std::ostream &operator<<(std::ostream& os, const Vitrail *vitrail);


};
std::ostream &operator<<(std::ostream& os, const Vitrail *vitrail);
#endif // VITRAIL

