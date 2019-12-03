/*
*   Cours:        CSI2772 - Concept avancer en C++
*   Session:      Autumne 2019
*   Remise:       6 décembre 2019
*   Author 1:     Mathieu Bellefeuille
*   # etudiant:   65013369
*   Auteur 2:     Matthew Tan
*   # etudiant:   300028206
*/

#include <iostream>
#include <stdexcept> //std::out_of_range
#include "Vitrail.h"
#include "Joueur.h"

using namespace std;

//constructeur par default
Joueur::Joueur(){};


//constructeur parametrisee
Joueur::Joueur(string name, Vitrail& _vitrail, int position) :vitrail(&_vitrail), points(0), position(position), nom(name){
    //doit commencer a extreme gauche (position 6)
}

//destructeur
Joueur::~Joueur(){
    delete vitrail;
}

int Joueur::getPosition() {return this->position; }

Vitrail* Joueur::getVitrail() {return this->vitrail; }

void Joueur::changerPoints(int p) {this->points = this->points + p;}

int Joueur::getPoint(){return points;}

string Joueur::getName(){return nom;}

void Joueur::calculatePoints(int unusedVitres) {
    int result=0;
    if (vitrail->estComplete(position)) { //colonne complete alors calcule les points
        result= result+3;
        //calcul tout vitre entamer de 0 au vitrier
        for (int i=0; i<position; i++) { //+1 si vitre en construction
            if (vitrail->estEnConstruction(i)) {
                    result++;
            }
        }
    }
    result= result - unusedVitres; //-1 pour chaque vitre pas utilise
    this->points+=result;
    return;
}

Joueur& Joueur:: operator--( int){//deplacement gauche de 1 (plus grand colonne a gauche)
          this->position--;
          if (this->position>vitrail->getColonne()){
            throw std::out_of_range("Exception out_of_range - Position sur le bord deja");
          }
        return *this;
}

Joueur& Joueur::operator-=(const int num){//deplacement droite par tel nombre
        this->position=(this->position) - num;
        if (this->position < 0){
            throw std::out_of_range("Exception out_of_range - mouvement invalide de trop vers la droite");
          }
        return *this;
}

Joueur& Joueur::operator~(){
        //permet remettre vitrier extreme gauche
        this->position=vitrail->getColonne()-1; //plus a gauche c'est nombre max de colonnes
        return *this;
}

std::ostream &operator<<(std::ostream &out, Joueur& player ) {
        //permet afficher etat d'un joueur
        out<<"Joueur "<<player.nom <<": "<<player.points<<" points"<<endl;
        out<<endl;
        out<<"Vitrier a la position: "<<player.position<<endl;
        out<<endl;
        out<<"Plan:"<<endl;
        out<<endl;
        out<<player.vitrail; //va afficher le vitrail courant du Joueur
        out<<endl;

        return out;
}

