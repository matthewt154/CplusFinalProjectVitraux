#ifndef JOUEUR_H
#define JOUEUR_H
#include <stdexcept> //std::out_of_range
#include <Vitrail.h>
using namespace std;
class Joueur {
private:
    string nom;
    int points;
    int position; //position du vitrier
    Vitrail* vitrail; //need to set it somehow? - parametre de constructeur

public:

    Joueur(nom) :points(0), position(0) {
        this.nom=nom;

    }
    const Joueur & operator++(){//deplacement gauche de 1 (plus grand colonne a gauche)
          Joueur.position=this.position++;
          if (Joueur.position>vitrail.getColonne()){
            throw std::out_of_range("Exception out_of_range - Position sur le bord deja");
          }
            return Joueur;
    }
    const Joueur & operator-=(const int position){//deplacement droite par tel nombre
        Joueur.position=this.position+position;
        if (Joueur.position<0){
            throw std::out_of_range("Exception out_of_range - mouvement invalide de trop vers la droite");
          }
        return Joueur;
    }

    const Joueur & operator~(){
        //permet remettre vitrier extreme gauche
        Joueur.position=vitrail.getColonne(); //plus a gauche c'est nombre max de colonnes
        return Joueur;
    }
    const Joueur & operator<<(){
        //TO_DO, permet afficher etat d'un joueur
        cout<<nom <<": "<<points<<" points"<<endl;
        cout<<endl;
        cout<<"Vitrier a la position "<<position<<endl;
        cout<<"Plan:"<<endl;
        vitrail.construireVitrail(); //va afficher le vitrail courant du Joueur
    }

};
#endif // Joueur
