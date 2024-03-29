/*
*   Cours:        CSI2772 - Concept avancer en C++
*   Session:      Autumne 2019
*   Remise:       6 d�cembre 2019
*   Author 1:     Mathieu Bellefeuille
*   # etudiant:   65013369
*   Auteur 2:     Matthew Tan
*   # etudiant:   300028206
*/

#ifndef LOTS_H
#define LOTS_H
#include <iostream>
#include <vector>

/*
* @Initialization par default
*/
class Lots {

private:

    // Vector pour garder le surplus des vitraux (Char associer � couleur)
    std::vector<char> surplus;
    //Referance au couleur possible
    const char couleurs [5]= {'G', 'J','B','R','O'};
    //Store les lots de vitre
    char** lotFenetre;

public:

    /*
    *   > Constructeur par default
    */
    Lots();

    /*
    *   > Destructeur
    */
    ~Lots();

    /*
    *   @param: coul - pour une vitre, col - colonne associer au lot
    *   @return: true if couleur dans colonne
    *   > if numeroLot negatif = vitre ramasser dans le surplus
    */
    bool getLot(char coul, int col);

    /*
    *   @return: true si la colonne du lot est vide
    */
    bool lotColonneEmpty(int col);
    /*
    *   @return: true si surplus est vide
    */
    bool surplusEmpty();

    /*
    *   @return: true si seulement Lot empty
    */
     bool LotsEmpty();
    /*
    *   @return: true si Lots et surplus sont vide
    */
    bool isEmpty();

    /*
    *   @param: couleur - pour une vitre, numeroLot - Lot associer au vitre
    *   @return: vector composer de vitre du lot � ramasser
    *   > if numeroLot negatif = vitre ramasses dans le surplus
    */
    std::vector<char> ramasseVitre(char couleur, int numeroLot);

    /*
    *   > recharge les lot de vitraux au hasard
    *   > avec surplus vide
    */
    void reset_L(void);

    /*
    *   > affichage des lot
    */
    friend std::ostream &operator<<(std::ostream &os, Lots &lot );

};

std::ostream &operator<<(std::ostream &os, Lots &lot );
#endif // LOTS_H
