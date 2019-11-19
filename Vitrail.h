#ifndef VITRAIL_H
#define VITRAIL_H
class Vitrail {
private:
    char** description; //tableau 2D alloue dynamique
public:
    Vitrail()  {
        /*
        Chaque colonne du vitrail est
initialisée de la facon suivante : 2 couleurs sont choisies au hasard; puis un nombre
aléatoire H entre 0 et le nombre de cases dans la colonne est tiré. Les H premières
cases de la colonne seront de la première couleur et le reste des cases seront de la
seconde couleur (donc il ne peut y avoir que 1 ou 2 couleurs dans une colonne).
*/
    }

    int construireVitrail(std ::vector<char> vitres, int colonne) {
        //TO_DO
    }
    bool estComplete(int colonne) {
        //TO_DO
    }
    bool estEnConstruction(int colonne){
        //TO_DO
    }

    //Cette classe doit aussi surcharger l’opérateur d’insertion << permettant l’affichage à la
    //console de l’état des vitraux comme suit :
};
#endif // VITRAIL
