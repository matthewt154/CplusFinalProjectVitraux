#include <iostream>
#include <stdexcept> //std::out_of_range
#include "Vitrail.h"
#include "Joueur.h"

using namespace std;

//constructeur par default
Joueur::Joueur(){cout<<"Default joueur"<<endl;};

//constructeur parametrisee WORKS
Joueur::Joueur(string name, Vitrail& _vitrail) :vitrail(&_vitrail), points(0), position(6), nom(name){
    //doit commencer a extreme gauche (position 6)
    cout<<"Creation joueur: "<<name<<endl;
}

//destructeur
Joueur::~Joueur(){
    delete vitrail;
}
int Joueur::getPosition() {return this->position; }
Vitrail* Joueur::getVitrail() {return this->vitrail; }
//changer les points
void Joueur::changerPoints(int p) {this->points = this->points + p;}

//WORKS
Joueur& Joueur:: operator--( int){//deplacement gauche de 1 (plus grand colonne a gauche)
          this->position--;
          if (this->position>vitrail->getColonne()){
            throw std::out_of_range("Exception out_of_range - Position sur le bord deja");
          }
          cout<<"Deplacement droite de 1"<<endl;

        return *this;
}
//WORKS
Joueur& Joueur::operator-=(const int num){//deplacement droite par tel nombre
        this->position=(this->position) - num;
        if (this->position < 0){
            throw std::out_of_range("Exception out_of_range - mouvement invalide de trop vers la droite");
          }
          cout <<"Deplacement gauche de "<<num<<endl;
        return *this;
}
//WORKS
Joueur& Joueur::operator~(){
        //permet remettre vitrier extreme gauche
        this->position=vitrail->getColonne()-1; //plus a gauche c'est nombre max de colonnes
        cout<<"Deplace joueur a extreme gauche"<<endl;
        return *this;
}
//WORKS
std::ostream &operator<<(std::ostream &out, Joueur& player ) { //WORKS
        //permet afficher etat d'un joueur
        out<<player.nom <<" : "<<player.points<<" points"<<endl;
        out<<endl;
        out<<"Vitrier a la position: "<<player.position<<endl;
        out<<"Plan:"<<endl;
        out<<endl;
        out<<"Start affiche"<<endl;
        out<<player.vitrail; //va afficher le vitrail courant du Joueu
        out<<"End affiche"<<endl;

        return out;
}

