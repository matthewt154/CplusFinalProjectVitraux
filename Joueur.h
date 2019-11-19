#ifndef JOUEUR_H
#define JOUEUR_H
class Joueur {
private:
    string nom;
    int points;
    //position vitrier et vitrail -> class separe?
public:
    /*
    La classe doit avoir un opérateur de pré-incrémentation -- ainsi qu’un opérateur
-=(int) permettant de déplacer le vitrier vers la droite. Si vous essayer de déplacer le
vitrier en dehors des colonnes, une exception de type std::out_of_range doit être
lancée. Elle doit aussi avoir l’opérateur ~ permettant de remettre le vitrier à l’extrême
gauche.
Cette classe doit aussi surcharger l’opérateur d’insertion << permettant l’affichage à la
console de l’état d’un joueur comme suit :
Joueur A : 0 points
Vitrier à la position 6.
Plan :
O B J R J B G
G J J R R B G
G J O R R B G
G J O R R G G
G J O R R G G
6 5 4 3 2 1 0
    */

};
#endif // Joueur
