#include <iostream>
#include <stdexcept> //std::out_of_range
#include "Vitrail.h"
#include "Joueur.h"

using namespace std
//constructeur par defaut
Joueur::Joueur(string nom) :points(0), position(0) {
        this.nom=nom;

}

const Joueur & operator++(){//deplacement gauche de 1 (plus grand colonne a gauche)
          Joueur.position=this.position++;
          if (Joueur.position>vitrail.getColonne()){
            throw std::out_of_range("Exception out_of_range - Position sur le bord deja");
          }
            return Joueur;
}

Joueur::Joueur & operator-=(const int position){//deplacement droite par tel nombre
        Joueur.position=this.position+position;
        if (Joueur.position<0){
            throw std::out_of_range("Exception out_of_range - mouvement invalide de trop vers la droite");
          }
        return Joueur;
}

Joueur::Joueur & operator~(){
        //permet remettre vitrier extreme gauche
        Joueur.position=vitrail.getColonne(); //plus a gauche c'est nombre max de colonnes
        return Joueur;
}

Joueur::Joueur & operator<<(){
        //permet afficher etat d'un joueur
        cout<<nom <<": "<<points<<" points"<<endl;
        cout<<endl;
        cout<<"Vitrier a la position "<<position<<endl;
        cout<<"Plan:"<<endl;
        vitrail.construireVitrail(); //va afficher le vitrail courant du Joueur
}

