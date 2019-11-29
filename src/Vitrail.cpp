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
        //cout << "Vitrail constructor begin"<<endl;
        //the array works like fenetre [rows][colonnes]
        fenetre = new char*[rows]; //creation des rangees
        for (int c=0; c<rows; c++) {fenetre[c]=new char[colonnes]; }//creation des colonnes
        //cout <<"Creation de colonnes et de rows succes"<<endl;
        char first,second;


        int H; //nombre aleatoire, vitres de premiere couleur
        int r; //random colour variable
        srand(time(NULL)); //make sure it's truly random every time
        r=rand() %5;
        //cout<<r;
        for (int i=0; i<colonnes; i++) { //pour chaque colonne (row position in array)
            first=0;
            second=0; //NULL maybe?
            r=rand()%5;
            first= couleurs[r]; //choisit couleurs aleatoire de la liste
            //cout <<"First: "<<first<<endl;
            while (true) { //assure que pas la meme couleur
                r=rand()%5;
                second = couleurs[r];
                if (second != first) {break;}
            }
            //cout <<"Second: "<<second<<endl;

            H=rand()%rows; //random number in the range 0 to vitres (cases dans les colonnes)

            for (int p=0; p<H; p++) { //premiere couleur des vitres dans colonne (descend les rows)
                fenetre[p][i]= first;
                }

            for (int d=H; d<rows; d++){//deuxieme couleur
                fenetre[d][i]= second;
            }

        } //seulement 1 ou 2 couleurs par colonne
        //cout << "Vitrail constructor end"<<endl;

}

int Vitrail::construireVitrail(std::vector<char> vitres, int colonne) { //WORKS
        //prend les vitres du vector, place dans colonne
        //si corrspond a couleur necessaire remplace avec x (complete)
        //retourne int (how many placed successfully)
        //si colonne complete lancer invalid argument
        int actualColumn=colonnes-colonne-1; //colonnes-colonne parce que numerote a l'inverse
        vector<char>::iterator it;
        if(estComplete(actualColumn)){
                throw std::invalid_argument("Colonne déja complété");
        }
        int initSize=vitres.size();
        int success=0; //combien de vitres places
        for (int i=0; i<rows ; i++) { //descend les rows
            if (!vitres.empty()) { //vector not empty
                //doit iterer tous les elements du vecteur
                cout<<"Not empty"<<endl;
                for (it=vitres.begin(); it!=vitres.end(); it++) {
                    if (fenetre[i][actualColumn]==*it) {
                        fenetre[i][actualColumn]='X';
                        cout<<"X added"<<endl;
                        //problem with erase
                        vitres.erase(it); //get rid of the value at position, automatically reduces size
                        it--;
                        cout <<"Vector element erased"<<endl;
                        success++;
                        cout<<"Increment success"<<endl;
                    }
                }
            }
            else {break;}
        }
        return (initSize-success); //nombre de vitres PAS places
    }

bool Vitrail::estComplete(int colonne) {
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
                cout<<"enConstruction vrai"<<endl;
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
