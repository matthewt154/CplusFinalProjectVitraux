#ifndef LOTS_H
#define LOTS_H
#include <iostream>
#include <vector>

/*
* @Initialization par default -
*/
class Lots {

private:

    // Vector pour grader le surplus des vitraux (Char associer à couleur)
    std::vector<char> surplus;
    const char couleurs [5]= {'G', 'J','B','R','O'};
    char** lotFenetre;
public:

    Lots();
    ~Lots();

    bool isEmpty();

    //double pointeur de matrice du lot


    /*
    *   @param: couleur - pour une vitre, numeroLot - Lot associer au vitre
    *   @return: vector composer de vitre du lot à ramasser
    *   > if numeroLot negatif = vitre ramasses dans le surplus
    */
    std::vector<char> ramasseVitre(char couleur, int numeroLot);

    /*
    *   > recharge les lot de vitraux au hasard
    *   > surplus vide
    */
    void reset_L(void);

    /*
    *   > affichage des lot
    */

    friend std::ostream &operator<<(std::ostream &os, Lots &lot );

};

std::ostream &operator<<(std::ostream &os, Lots &lot );
#endif // LOTS_H
