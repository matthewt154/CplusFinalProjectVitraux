#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Lots.h"
using namespace std;
//std::vector<char> surplus;
//char** Lots::lotFenetre;
// constructeur par defaut
Lots::Lots(){ //WORKS

        lotFenetre = new char* [4];

        for(int i = 0; i<4; i++){
            lotFenetre[i] = new char[5];
            for(int y = 0; y < 5; y++){
                lotFenetre[i][y] = couleurs[rand() %5]; //loading random colours in Lots
            }
        }
        cout<<"Creation success dun lot"<<endl;
    }

// constructeur destructeur
Lots::~Lots(){
     for (int i=0; i < 5; i++)
        delete[] lotFenetre[i];
    delete[] lotFenetre;
}

//WORKS (without pointers)
std::vector<char> Lots:: ramasseVitre(char couleur, int numeroLot){
    cout<<"Commencer ramasseVitre"<<endl;
    std::vector<char> LotOfSameColor;

    if(numeroLot < 0){

            for(std::vector <char> :: iterator it = surplus.begin(); it != surplus.end(); ++it){
                if(*it == couleur){
                    LotOfSameColor.push_back(*it);
                    *it == '.';
                }
            }
    }else{
        /*
        I see what you were trying to do with pointers but it's causing a bug so
        I'm going by the naive way for now
        char *ptr;
        ptr=lotFenetre[0];
        while(ptr){
            cout<<ptr;
                        if(ptr[numeroLot] == couleur){
                            LotOfSameColor.push_back(couleur);
                            *ptr = '.';
                        //cout<<"Found color"<<endl;
                        }else{
                            surplus.push_back(*ptr);
                            *ptr = '.';
                            //cout<<"Surplus"<<endl;
                        }
                         *ptr++;
                         cout<<"Increment pointer"<<endl;
                    }
            }
            */
        for (int i=0; i<4;i++){
            if (lotFenetre[i][numeroLot] ==couleur){
                LotOfSameColor.push_back(couleur);
                lotFenetre[i][numeroLot]='.';
            } else{
                surplus.push_back(lotFenetre[i][numeroLot]);
                lotFenetre[i][numeroLot] = '.';
            }
        }

    }
    return LotOfSameColor;
}

//WORKS
void Lots::reset_L(){
     for(int i = 0; i<4; i++){
            for(int y = 0; y < 5; y++){
                lotFenetre[i][y] = couleurs[rand() %5];
            }
        }
        //reset surplus aussi
        surplus.clear();
        cout <<"Lots reset"<<endl;
    }

//WORKS (for now)
std::ostream &operator<<(std::ostream &output, Lots &lot ) {
        output<< "Lots: "<<std::endl;
        output <<""<<std::endl;

        //imprime chaque char de chaque lot
        for (int i=0; i<4; i++) {
            for (int j=0; j<5; j++) {
                output <<lot.lotFenetre[i][j] <<"  ";
            }
            output <<""<<std::endl;
        }
         //nombre au bas de la matrice
        for (int n=4; n>=0; n--) {
            output <<n<<"  ";
        }
        output<<endl;
        output<<"Surplus:";
        output <<""<<std::endl;

        //imprimer le lot de surplus
        output<< "[";
        for(std::vector <char> :: iterator it = lot.surplus.begin(); it != lot.surplus.end(); ++it){
            output<<*it<< "  ";
        }
        output<< "]"<<endl;


        return output;
}


