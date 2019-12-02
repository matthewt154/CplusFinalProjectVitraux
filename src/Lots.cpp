/*
*   Cours:        CSI2772 - Concept avancer C++
*   Session:      Autumne 2019
*   Remise:       6 d�cembre 2019
*   Author 1:     Mathieu Bellefeuille
*   # etudiant:   65013369
*   Auteur 2:     Matthew Tan
*   # etudiant:   300028206
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Lots.h"
using namespace std;

// constructeur par defaut
Lots::Lots(){

        lotFenetre = new char* [4];

        for(int i = 0; i<4; i++){
            lotFenetre[i] = new char[5];
            for(int y = 0; y < 5; y++){
                lotFenetre[i][y] = couleurs[rand() %5]; //loading random colours in Lots
            }
        }

    }
// constructeur destructeur
Lots::~Lots(){
     for (int i=0; i < 5; i++)
        delete[] lotFenetre[i];
    delete[] lotFenetre;
}

bool Lots::getLot(char coul, int col){
        bool result=false;
        if(col < 0){
                if(!surplus.empty()){
                    for(std::vector <char> :: iterator it = surplus.begin(); it != surplus.end(); ++it){
                        if (*it == coul){
                            result =  true;
                            break;
                        }
                    }
                }else{
                    return false;
                }

        }else{
            for (int i=0; i<4;i++){
                if (lotFenetre[i][4-col] == coul){
                    result =  true;
                    break;
                }
            }
        }

    return result;
}

bool Lots::lotColonneEmpty(int col){
    int cnt = 0;
    for (int i=0; i<4;i++){
        if (lotFenetre[i][4-col] == '.'){
            cnt++;
        }
    }
    if(cnt == 4){
        return true;
    }
    return false;
}

bool Lots::LotsEmpty(){
    int cnt=0;
        for(int i = 0; i<5; i++){
            if (lotFenetre[0][i]=='.') { cnt++;} //only need to check first element of column
        }
        if (cnt==5) { // tout les colonnes de lots sont vides
                return true;
        }
    return false;
}

bool Lots::surplusEmpty(){

    return surplus.empty();
}
bool Lots::isEmpty() { //check si lots et son surplus est vide
    if (surplus.empty()) {
        int cnt=0;
        for(int i = 0; i<5; i++){
            if (lotFenetre[0][i]=='.') { cnt++;} //only need to check first element of column
        }
        if (cnt==5) {return true; } //surplus vide et tout les colonnes de lots sont vides
        else {return false; }
    } else {
        return false;
    }
}

std::vector<char> Lots:: ramasseVitre(char couleur, int numeroLot){
    std::vector<char> LotOfSameColor;
    if(numeroLot < 0){
            for(int i = 0; i < surplus.size(); i++){
                    cout<<"crash pas-1"<<endl;
                if(surplus[i] == couleur){
                        cout<<"crash pas"<<endl;
                    LotOfSameColor.push_back(surplus[i]);
                cout<<"crash pas1"<<endl;
                    surplus.erase(surplus.begin()+i);
                }
            }
    }else{
        int actualLots= 4-numeroLot; //have to reverse the lots index
        for (int i=0; i<4;i++){
            if (lotFenetre[i][actualLots] ==couleur){
                LotOfSameColor.push_back(couleur);
                lotFenetre[i][actualLots]='.';
            } else{
                surplus.push_back(lotFenetre[i][actualLots]);
                lotFenetre[i][actualLots] = '.';
            }
        }

    }
    return LotOfSameColor;
}

void Lots::reset_L(){
     for(int i = 0; i<4; i++){
            for(int y = 0; y < 5; y++){
                lotFenetre[i][y] = couleurs[rand() %5];
            }
        }
        //reset surplus aussi
        surplus.clear();
    }

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
        output <<endl;

        //imprimer le lot de surplus
        output<< "[";
        for(std::vector <char> :: iterator it = lot.surplus.begin(); it != lot.surplus.end(); ++it){
            output<<*it<< "  ";
        }
        output<< "]"<<endl;
        return output;
}


