#ifndef JOUEUR_H
#define JOUEUR_H

<<<<<<< HEAD

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();

    protected:

    private:
};

#endif // JOUEUR_H
=======
using namespace std;
class Joueur {
private:
    string nom;
    int points;
    int position; //position du vitrier
    Vitrail* vitrail; //need to set it somehow? - parametre de constructeur

public:
    Joueur(string nom):points(0), position(0); //constructeur

    const Joueur operator++(); //deplacement gauche de 1

    const Joueur operator-=(const int position); //deplacement droite par tel nombre

    const Joueur operator~(); //remettre position a extreme gauche

    const Joueur operator<<(); //afficher etat d'un joueur

};
#endif // Joueur
>>>>>>> e3fa66677ce39027d06de389a6e1dc3674e00c83
