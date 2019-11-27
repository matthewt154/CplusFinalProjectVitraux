#include "Lots.h"
#include "Vitrail.h"
#include "Joueur.h"
#include <iostream>

using namespace std;

int main(){
    bool gameflag = true;   //condition vrais pour continuer a jouer - false jeu terminer
    Joueur* joueur1 = new Joueur();      //Lots de vitre du joueur 1
    Joueur* joueur2 = new Joueur();      //Lots de vitre du joueur 2

    int nColonne = 7;               //valeur par defaut de colonne du vitrail
    int nVitre = 5;                 // valeur par defaut du nombre de vitre par colonne

    //demande a utilisateur le nombre de vitre et colonne sinon defaut
    cout<< "Entree un nombre de colonne(defaut - 7): ";
    cin>> nColonne;
    cout<< "Entree un nombre de vitre par colonne (default - 5): ";
    cin>> nVitre;

    //initialize la grille de vitrail pour jouer
    Vitrail* vitre = new Vitrail(nColonne, nVitre);

    while(gameflag){

    }
    return 0;

};



