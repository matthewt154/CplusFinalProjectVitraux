#include "Lots.h"
#include "Vitrail.h"
#include "Joueur.h"
#include <iostream>
#include "ostreamTest.h"
#include <vector>
using namespace std;

int main(){
    /* Testing methods
    Vitrail* vit=new Vitrail(7,5);
    cout <<vit<<endl;
    vector<char> vect{'C','O','J','O','G'};
    cout<<"Appel a construireVitrail"<<endl;
    vit->construireVitrail(vect, 5);
    cout<<vit<<endl;
    bool comp=vit->estEnConstruction(5);
    if (comp==true){cout<<"Complete"<<endl;}
    else {cout<<"Not complete"<<endl;}
    string name="Joueur A";
    //Test Joueur
    Joueur joueur(name, *vit); //creation de Joueur
    joueur--;
    cout<<joueur<<endl; //testing operator <<
    joueur-=(2);
    cout <<joueur<<endl;
    ~joueur;
    cout<<joueur<<endl;

    Lots lots; //testing lots
    cout <<lots;
    lots.ramasseVitre('B',2);
    cout<<lots;
    lots.reset_L();
    cout<<lots;
    */

    int nColonne = 7;               //valeur par defaut de colonne du vitrail
    int nVitre = 5;                 // valeur par defaut du nombre de vitre par colonne
    Vitrail* vitre=new Vitrail(nColonne, nVitre);     //initialize la grille de vitrail pour jouer (2 joueuers utilisent le meme)
    //cout<< vitre <<endl;
    Lots lots; //faut aussi creer des Lots au debut (joueurs prennent du meme)
     //demande a utilisateur le nombre de vitre et colonne sinon defaut
    string name;
    cout<< "Entrez le nom du premier joueur: ";
    cin>> name;
    Joueur joueur1(name, *vitre );      //Lots de vitre du joueur 1
    cout<<joueur1<<endl;
    cout<< "Entrez le nom du deuxieme joueur: ";
    cin>> name;
    Joueur joueur2(name, *vitre);      //Lots de vitre du joueur 2
    cout<<joueur2<<endl;
    cout<<lots;
    bool gameflag = true;   //condition vrais pour continuer a jouer - false jeu terminer

    while(gameflag){

    }



    return 0;

};
