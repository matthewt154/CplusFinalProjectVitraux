#include <iostream>
#include <cstdlib>
#include <vector>
#include "Lots.h"

std::vector<char> surplus;
char** Lots::lotFenetre;
// constructeur par defaut
Lots::Lots(){
        lotFenetre = new char* [5];
        for(int i = 0; i<5; i++){
            lotFenetre[i] = new char[4];
            for(int y = 0; y < 4; i++){
                lotFenetre[i][y] = couleurs[rand() %5];
            }
        }
    }

// constructeur destructeur
Lots::~Lots(){
     for (int i=0; i < 5; i++)
        delete[] lotFenetre[i];
    delete[] lotFenetre;
}

std::vector<char> ramasseVitre(char couleur, int numeroLot){
    std::vector<char> LotOfSameColor;

    if(numeroLot < 0){

            for(std::vector <char> :: iterator it = surplus.begin(); it != surplus.end(); ++it){
                if(*it == couleur){
                    LotOfSameColor.push_back(*it);
                    *it == '.';
                }
            }
    }else{

        for(auto &vitreChar: Lots::lotFenetre[numeroLot]){
                if(vitreChar == couleur){
                    LotOfSameColor.push_back(couleur);
                    vitreChar = '.';
                }else{
                    surplus.push_back(vitreChar);
                    vitreChar = '.';
                }
            }
    }
    return LotOfSameColor;
}

void Lots::reset_L(){
     for(int i = 0; i<5; i++){
            for(int y = 0; y < 4; i++){
                lotFenetre[i][y] = couleurs[rand() %5];
            }
        }
    }

std::ostream &operator<<(std::ostream &output, Lots &lot ) {
        output<< "Lots: "<<std::endl;
        output <<""<<std::endl;

        //imprime chaque char de chaque lot
        for (int i=0; i<5; i++) {
            for (int j=0; j<4; j++) {
                output <<lot.lotFenetre[i][j] <<"  ";
            }
            output <<""<<std::endl;
        }
         //nombre au bas de la matrice
        for (int n=5; n>=0; n--) {
            output <<n<<"  ";
        }

        output<<"Surplus:";
        output <<""<<std::endl;

        //imprimer le lot de surplus
        output<< "[";
        for(std::vector <char> :: iterator it = surplus.begin(); it != surplus.end(); ++it){
            output<<*it<< "  ";
        }
        output<< "]";


        return output;
}


