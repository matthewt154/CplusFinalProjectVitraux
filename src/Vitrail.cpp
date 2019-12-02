/*
*   Cours:        CSI2772 - Concept avancer en C++
*   Session:      Autumne 2019
*   Remise:       6 décembre 2019
*   Author 1:     Mathieu Bellefeuille
*   # etudiant:   65013369
*   Auteur 2:     Matthew Tan
*   # etudiant:   300028206
*/

#include <stdlib.h> //rand operation
#include <stdexcept> //invalid argument exception
#include <vector>
#include <iostream>
#include <time.h>
#include "Vitrail.h"

using namespace std;
const char Vitrail::couleurs[]= {'G','J','B','R','O'}; //couleurs pre-definis des vitres

//constructeur parametrizer
Vitrail::Vitrail(int icolonnes, int vitres) : colonnes(icolonnes), rows(vitres){
        /*
        [[1,2,3,4]
         [2,3,4,5]
         [5,6,7,8]]
         change rows to access column
        */
        //the array works like fenetre [rows][colonnes]
        fenetre = new char*[rows]; //creation des rangees
        for (int c=0; c<rows; c++) {
                fenetre[c]=new char[colonnes];
        }//creation des colonnes
        char first,second;
        int H; //nombre aleatoire, vitres de premiere couleur
        int r; //random colour variable
        r=rand() %5;
        for (int i=0; i<colonnes; i++) { //pour chaque colonne (row position in array)
            first=0;
            second=0; //NULL maybe?
            r=rand()%5;
            first= couleurs[r]; //choisit couleurs aleatoire de la liste
            while (true) { //assure que pas la meme couleur
                r=rand()%5;
                second = couleurs[r];
                if (second != first) {break;}
            }
            H=rand()%rows; //random number in the range 0 to vitres (cases dans les colonnes)

            for (int p=0; p<H; p++) { //premiere couleur des vitres dans colonne (descend les rows)
                fenetre[p][i]= first;
                }

            for (int d=H; d<rows; d++){//deuxieme couleur
                fenetre[d][i]= second;
            }

        } //seulement 1 ou 2 couleurs par colonne
}

int Vitrail::construireVitrail(std::vector<char> vitres, int colonne) {
        //prend les vitres du vector, place dans colonne
        //si corrspond a couleur necessaire remplace avec x (complete)
        //retourne int (how many not placed successfully)
        //si colonne complete lancer invalid argument
        int actualColumn=colonnes-colonne-1; //colonnes-colonne parce que numerote a l'inverse
        vector<char>::iterator it;
        if(estComplete(actualColumn)){
                throw std::invalid_argument("Colonne déja complété");
        }
        int initSize=vitres.size(); //vitre disponible a placer
        for (int i=0; i<rows ; i++) { //descend les rows
            if (!vitres.empty()) { //vector not empty
                //doit iterer tous les elements du vecteur
                for (it=vitres.begin(); it!=vitres.end(); it++) {
                    char tmp1 = fenetre[i][actualColumn];
                    if (tmp1== *it) {
                        fenetre[i][actualColumn]='X';
                        vitres.erase(it); //get rid of the value at position, automatically reduces size
                        it--; //decrement iterator to compensate
                    }

                }
            }
            else {break;}
        }
        return (4-initSize); //nombre de vitres PAS placer
    }

bool Vitrail::estComplete(int colonne) {//WORKS TESTED
        int actualColumn= colonnes-colonne-1;
        int complete=0;
        for (int i=0; i<rows; i++){
            if (fenetre[i][actualColumn]=='X') {complete++;} //counts as complete if value of row is X
        }
        if (complete==rows) {return true;} //all rows complete
        else {return false;}

    }

bool Vitrail::estEnConstruction(int colonne){ //WORKS
        //retourne vrai si au moins une vitre a ete installe
        int actualColumn= colonnes-colonne-1;
        bool construction=false;
        for (int i=0; i<rows; i++) {
            if (fenetre[i][actualColumn]=='X') {
                construction=true;
                break;
            }
        }
        return construction;
    }

std::ostream &operator<<(std::ostream &output, const Vitrail *item ){ //WORKS
    //Cette classe doit aussi surcharger l’opérateur d’insertion << permettant l’affichage à la
    //console de l’état des vitraux:
    //include extra row for numbering (going down)
        for (int i=0; i<item->rows; i++) {
            for (int j=0; j<item->colonnes; j++) {
                output <<item->fenetre[i][j] <<"  ";
            }
            output <<""<<endl;
        }
        //numbering at bottom
        for (int n=item->colonnes-1; n>=0; n--) {
            output <<n<<"  ";
        }
        //output<<3;
        return output;
    }

int Vitrail::getColonne() {return this->colonnes;}
