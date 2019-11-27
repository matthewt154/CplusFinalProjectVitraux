#include <cstdlib> //rand operation
#include <stdexcept> //invalid argument exception
#include <vector>
#include "Vitrail.h"

using namespace std
//constructeur
Vitrail::Vitrail(int colonnes, int vitres)  {
        this.colonnes = colonnes;
        this.rows=vitres;
        //vitres --> rows
        fenetre = new char*[colonnes];

        char first,second;


        int H; //nombre aleatoire, vitres de premiere couleur

        for (int i=0; i<colonnes; i++) { //pour chaque colonne
            first=second=0; //NULL maybe?
            first= couleurs[rand() %5]; //choisit couleurs aleatoire de la liste
            while (true) { //assure que pas la meme couleur
                second = couleurs[rand() %5];
                if (second != first) {break;}
            }

            H=rand()%vitres; //random number in the range 0 to vitres (cases dans les colonnes)
            for (int p=0; p<H; p++) { //premiere couleur des vitres dans colonne
                fenetre[p][i]= first;
                }
            for (int d=H; d<vitres; d++){//deuxieme couleur
                fenetre[d][i]= second;
            }
        } //seulement 1 ou 2 couleurs par colonne
}

Vitrail::construireVitrail(std ::vector<char> vitres, int colonne) {
        //prend les vitres du vector, place dans colonne
        //si corrspond a couleur necessaire remplace avec x (complete)
        //retourne int (how many placed successfully)
        //si colonne complete lancer invalid argument
        if (estComplete()) {throw std:invalid_argument("Colonne déja complété");}
        int success=0; //combien de vitres places
        for (int i=0; i<rows ; i++) {
            if (!vitres.empty()) { //vector not empty
                if (fenetre[i][colonnes]==vitres.front()) {
                    fenetre[i][colonne]='X';
                    //reduce size of vector (with swap, new vector, and optimises capacity)
                    vector<char>v(vitres.size()-1);
                    vector<char>vitres.swap(v); //effectively reduces size to new size-1
                    success++;
                }
            }
        }
        return success;
    }

Vitrail::estComplete(int colonne) {

        int complete=0;
        for (int i=0; i<rows; i++){
            if (fenetre[i][colonne]=='X') {complete++;} //counts as complete if value of row is X
        }
        if (complete==rows) {return true;} //all rows complete
        else {return false; }

    }

Vitrail::estEnConstruction(int colonne){
        //retourne vrai si au moins une vitre a ete installe
        bool construction=false;
        for (int i=0; i<rows; i++) {
                if (fenetre[i][colonne]=='X') {
                    construction=true;
                }
        }
        return construction;
    }

Vitrail::Vitrail &operator <<(){
    //Cette classe doit aussi surcharger l’opérateur d’insertion << permettant l’affichage à la
    //console de l’état des vitraux:
    //include extra row for numbering (going down)
        for (int i=0; i<rows; i++) {
            for (int j=0; j<colonnes; j++) {
                cout <<fenetre[i][j] <<"  ";
            }
            cout <<""<<endl;
        }
        //numbering at bottom
        for (int n=colonnes; n>=0; n--) {
            cout <<n<<"  ";
        }

    }
