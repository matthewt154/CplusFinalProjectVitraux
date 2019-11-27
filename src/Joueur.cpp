#include <iostream>
#include <stdexcept> //std::out_of_range
#include "Vitrail.h"
#include "Joueur.h"

using namespace std;

//constructeur par default
Joueur::Joueur(){};

//constructeur parametrizer
Joueur::Joueur(string name, Vitrail& _vitrail) :vitrail(&_vitrail), points(0), position(0), nom(name){}

//destructeur
Joueur::~Joueur(){
    delete vitrail;
}
Joueur& Joueur::operator++(){//deplacement gauche de 1 (plus grand colonne a gauche)
          this->position++;
          if ((*this).position>vitrail.getColonne()){
            throw std::out_of_range("Exception out_of_range - Position sur le bord deja");
          }
        return *this;
}

Joueur& Joueur::operator-=(const int position){//deplacement droite par tel nombre
        this->position=(this->position) + position;
        if (this->position < 0){
            throw std::out_of_range("Exception out_of_range - mouvement invalide de trop vers la droite");
          }
        return *this;
}

Joueur& Joueur::operator~(){
        //permet remettre vitrier extreme gauche
        this->position=vitrail->getColonne(); //plus a gauche c'est nombre max de colonnes
        return *this;
}

std::ostream &operator<<(std::ostream &out, Joueur &player ) {
        //permet afficher etat d'un joueur
        out<<player.nom <<" : "<<player.points<<" points"<<endl;
        out<<endl;
        out<<"Vitrier a la position: "<<player.position<<endl;
        out<<"Plan:"<<endl;
        out<<endl;
        out<<player.vitrail; //va afficher le vitrail courant du Joueur

        return out;
}

