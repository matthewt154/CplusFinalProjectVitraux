#include <iostream>
#include <cstdlib>
#include <vector>
#include "Lots.h"

using namespace std;
vector<char> surplus;
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
        delete[] tab[i];
    delete[] tab;
}

Lots::vector<char> ramasseVitre(char couleur, int numeroLot){
    vector<char> LotOfSameColor;

    if(numeroLot < 0){

            for(vector <char> :: iterator it = surplus.begin(); it != surplus.end(); ++it){
                if(*it == couleur){
                    LotOfSameColor.push_back(*it);
                    *it == ".";
                }
            }
    }else{

        for(auto &vitreChar: fenetre[numeroLot]){
                if(vitreChar == couleur){
                    LotOfSameColor.push_back(couleur);
                    vitreChar = ".";
                }else{
                    surplus.push_back(vitreChar);
                    vitreChar = ".";
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
        output<< "Lots: "<<endl;
        output <<""<<endl;

        //imprime chaque char de chaque lot
        for (int i=0; i<5; i++) {
            for (int j=0; j<4; j++) {
                output <<lot.lotFenetre[i][j] <<"  ";
            }
            output <<""<<endl;
        }
         //nombre au bas de la matrice
        for (int n=5; n>=0; n--) {
            output <<n<<"  ";
        }

        output<<"Surplus:";
        output <<""<<endl;

        //imprimer le lot de surplus
        output<< "[";
        for(vector <char> :: iterator it = surplus.begin(); it != surplus.end(); ++it){
            output<<*it<< "  ";
        }
        output<< "]";


        return output;
}


