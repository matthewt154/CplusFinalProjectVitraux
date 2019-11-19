#ifndef JOUEUR_H
#define JOUEUR_H
class Joueur {
private:
    string nom;
    int points;
    //position vitrier et vitrail -> class separe?
public:
    /*
    La classe doit avoir un op�rateur de pr�-incr�mentation -- ainsi qu�un op�rateur
-=(int) permettant de d�placer le vitrier vers la droite. Si vous essayer de d�placer le
vitrier en dehors des colonnes, une exception de type std::out_of_range doit �tre
lanc�e. Elle doit aussi avoir l�op�rateur ~ permettant de remettre le vitrier � l�extr�me
gauche.
Cette classe doit aussi surcharger l�op�rateur d�insertion << permettant l�affichage � la
console de l��tat d�un joueur comme suit :
Joueur A : 0 points
Vitrier � la position 6.
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
