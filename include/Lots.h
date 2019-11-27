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

public:
    Lots();
    ~Lots();
    //double pointeur de matrice du lot
    static char** lotFenetre;

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
<<<<<<< HEAD
    std::ostream &operator<<( Lots &lot );
=======
    const operator<<();
>>>>>>> e3fa66677ce39027d06de389a6e1dc3674e00c83
};

#endif // LOTS_H
