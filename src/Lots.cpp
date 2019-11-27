#include <iostream>
#include <cstdlib>
#include "Lots.h"

using namespace std;

// constructeur par defaut
Lots::Lots(){
        lotFenetre = new char* [5];
        for(int i = 0; i<5; i++){
            lotFenetre[i] = new char[4];
            for(int y = 0; y < 4; i++){
                fenetre[i][y] = couleurs[rand() %5];
            }
        }
    }

// constructeur destructeur
Lots::~Lots(){}

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

Lots::reset(){
        for(int i = 0; i<5; i++){
            for(int y = 0; y < 4; i++){
                fenetre[i][y] = couleurs[rand() %5];
            }
        }
    }

Vitrail &operator <<(){
        /*
        *
        *   CHECK FOR IOSTREAM BOOK
        *
        */

        cout<< "Lots: "<<endl;
        cout <<""<<endl;

        //imprime chaque char de chaque lot
        for (int i=0; i<5; i++) {
            for (int j=0; j<4; j++) {
                cout <<lotFenetre[i][j] <<"  ";
            }
            cout <<""<<endl;
        }

        //nombre au bas de la matrice
        for (int n=5; n>=0; n--) {
            cout <<n<<"  ";
        }

        cout<<"Surplus:"
        cout <<""<<endl;

        //imprimer le lot de surplus
        cout<< "[";
        for(vector <char> :: iterator it = v.begin(); it != v.end(); ++it){
            cout<<*it<< "  ";
        }
        cout<< "]";

    }

