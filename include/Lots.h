#ifndef LOTS_H
#define LOTS_H
#include <iostream>
#include <vector>

/*
* @Initialization par default
*/
class Lots {

private:

    // Vector pour garder le surplus des vitraux (Char associer à couleur)
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
    *   @return: true si Lots et surplus sont vide
    */

    bool isEmpty();

    /*
    *   @param: couleur - pour une vitre, numeroLot - Lot associer au vitre
    *   @return: vector composer de vitre du lot à ramasser
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
