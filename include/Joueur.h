#ifndef JOUEUR_H
#define JOUEUR_H
#include <ostream>
using namespace std;
class Joueur {

private:
    string nom;
    int points;
    int position; //position du vitrier
    Vitrail* vitrail; //need to set it somehow? - parametre de constructeur
public:


    Joueur(); //constructeur par default

    Joueur(string Joueur, Vitrail& vitrail); //constructeur parametrizer

    ~Joueur(); //destructeur

    Joueur& operator--(int ); //deplacement gauche de 1, postfix increment

    Joueur& operator-=(const int position); //deplacement droite par tel nombre

    Joueur& operator~(); //remettre position a extreme gauche

    friend std::ostream &operator<<(std::ostream &out, const Joueur & player ); //afficher etat d'un joueur

};

//Joueur operator++(const Joueur &player);
std::ostream &operator<<(std::ostream &out, const Joueur & player );
#endif // Joueur

