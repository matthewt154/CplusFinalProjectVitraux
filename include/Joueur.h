#ifndef JOUEUR_H
#define JOUEUR_H
#include <ostream>
using namespace std;
class Joueur {

private:
    //nom du joueur
    string nom;
    //point du joueur lors du match
    int points;
    //position du vitrier
    int position;
    //recois un vitrail pour le jeu
    Vitrail* vitrail;
public:

    /*
    *   > Constructeur par default
    */
    Joueur();

    /*
    *   @param: Joueur - nom du joueur, &vitrail - associe un vitrail au joueur
    *   > Constructeur parametrizer
    */

    Joueur(string Joueur, Vitrail& vitrail); //constructeur parametrizer

    /*
    *   > Destructeur
    */
    ~Joueur();

    /*
    *   @return: le nombre de point du joueur
    */
    int getPoint();

    /*
    *   @param: int les vitres qui ne peuvent etre installe
    *   Fonction pour calculer les points du joueur a la fin de chaque tour
    *   @return: void
    */
    void calculatePoints(int unusedVitres);

    /*
    *   @return: retrourne la position du vitrier du joueur
    */
    int getPosition();

    /*
    *   @return: Retroune un pointeur vitrail associer au joueur
    */
    Vitrail* getVitrail();

    /*
    *   @param: points - point de plus a associer au joueur
    *   > mes a jour les point du joueur
    */
    void changerPoints(int points);

    /*
    *   > deplace le vitree a gauche de 1
    */
    Joueur& operator--(int );

    /*
    *   @param: position - nombre de deplacement a effectuer
    *   > deplace le vitrie a droite par un nombre
    */
    Joueur& operator-=(const int position);

    /*
    *   > remet la position du vitrier a l'extreme gauche
    */
    Joueur& operator~();

    /*
    *   > affiche l'etat du jeu du joueur
    */
    friend std::ostream &operator<<(std::ostream &out, Joueur & player ); //afficher etat d'un joueur

    /*
    *   @param: &lots reference aux lots disponibles, int action (quel action a effectuer)
    *   Fonction pour joueur une ronde du jeu, appelle pour un joueur specifique
    *   @return: void
    */
    //void playRound (Lots& lots, int action);

};

std::ostream &operator<<(std::ostream &out, const Joueur & player );
#endif // Joueur

