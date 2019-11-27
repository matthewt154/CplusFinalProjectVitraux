#include "Lots.h"
#include "Vitrail.h"
#include "Joueur.h"
#include <iostream>

using namespace std;

int main(){

    int nColonne = 7;               //valeur par defaut de colonne du vitrail
    int nVitre = 5;                 // valeur par defaut du nombre de vitre par colonne
    Vitrail* vitre = new Vitrail(nColonne, nVitre);     //initialize la grille de vitrail pour jouer

     //demande a utilisateur le nombre de vitre et colonne sinon defaut
    string name;
    cout<< "Entree le nom du permier joueur: ";
    cin>> name;
    Joueur* joueur1 = new Joueur(name, *vitre );      //Lots de vitre du joueur 1

    cout<< "Entree le nom du deuxieme joueur: ";
    cin>> name;
    Joueur* joueur2 = new Joueur(name, *vitre);      //Lots de vitre du joueur 2

    bool gameflag = true;   //condition vrais pour continuer a jouer - false jeu terminer
/*
    while(gameflag){

    }

*/
    return 0;

};
