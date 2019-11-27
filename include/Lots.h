#ifndef LOTS_H
#define LOTS_H

/*
* @Initialization par default -
*/
class Lots {

private:

    // Vector pour grader le surplus des vitraux (Char associer à couleur)
    vector<char> surplus(0);
    const char couleurs [5]= {'G', 'J','B','R','O'};

public:
    //double pointeur de matrice du lot
    char** lotFenetre;

    /*
    *   @param: couleur - pour une vitre, numeroLot - Lot associer au vitre
    *   @return: vector composer de vitre du lot à ramasser
    *   > if numeroLot negatif = vitre ramasses dans le surplus
    */
    vector<char> ramasseVitre(char couleur, int numeroLot){}

    /*
    *   > recharge les lot de vitraux au hasard
    *   > surplus vide
    */
    void reset(){}

    /*
    *   > affichage des lot
    */
    const operator<<();
};

#endif // LOTS_H
