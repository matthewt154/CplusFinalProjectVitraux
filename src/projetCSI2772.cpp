#include "Lots.h"
#include "Vitrail.h"
#include "Joueur.h"
#include <iostream>
#include "ostreamTest.h"
#include <stdexcept> //out_of_range
#include <vector>
using namespace std;
//TO_DO make it pretty and comment beginning of functions comme conventions (i.e. param and return)

//fonction pour calculer les points du joueur
int calculatePoints(Joueur joueur, int unusedVitres) {
    int result=0;
    Vitrail* jvitrail = joueur.getVitrail();
    if (jvitrail->estComplete(joueur.getPosition())) { //colonne complete
        result= result+3;
        //calcul tout vitre entame a droite
        for (int i=0; i<joueur.getPosition(); i++) { //+1 si vitre en construction
            if (jvitrail->estEnConstruction(i)) {result++; }
        }
    }
    result= result - unusedVitres; //-1 pour chaque vitre pas utilise
    return result;
}

//calcul de vitres pas utilise dans vecteur apres placement sur vitrail
int unusedLots(vector<char> chosenLots ) {
    //lots non utilises detruits
    int result = chosenLots.size(); //combien de vitres restants
    chosenLots.clear();
    return result;
}

//fonction pour joueur une ronde (pour un joueur)
void playRound (Joueur joueur, Lots lots, int action) {
    int col, vitCol;
    char couleur;
    cout<<joueur<<endl;
    cout<<lots<<endl;
    while (true) {
            cout<<"Choisit une colonne du lot (-1 pour prendre du surplus): "; cin>>col; cout<<endl;
            if (col>4) {throw std::out_of_range("Entrer colonne de lot moins que 5");}
            else {break;}
        }
    //TO_DO exception handle if colour entered not from list

    cout<<"Entrer une couleur ('G', 'J','B','R','O') a prendre du lot: "; cin>>couleur; cout<<endl;
    std::vector<char> chosenLots=lots.ramasseVitre(couleur, col); //prendre les couleurs du lot

    //ACTIONS 1 ou 2 du joueur
    if (action==1) {
        //action 1 du joueur deplacer a colonne a droite et placer vitres
        while (true) {
            cout<<"Entrer la colonne ou deplacer le vitrier et placer les "<<chosenLots.size();
            cout<<" vitres de Couleur - "<<couleur<<": ";
            cin>>vitCol; cout<<endl;
            if (vitCol>6||vitCol< 0 ) {throw std::out_of_range("Entrer colonne de vitrail entre 6 et 0");}
            else {break;}
        }
        int deplacement = joueur.getPosition()-vitCol;

        if (deplacement==1){//deplacement droit de 1
            joueur--;
        } else { //deplacement droite de plus que 1
            joueur-=(deplacement);
        }
        //placer les vitres
        int success;
        success=joueur.getVitrail()->construireVitrail(chosenLots, vitCol);
        //calcul des points
        int unused = unusedLots(chosenLots);
        int p=calculatePoints(joueur, unused); //appel a methode pour calculer les points
        joueur.changerPoints(p); //ajouter les points au joueur
        //END OF ACTION 1

    } else if (action==2) { //Action 2 c'est de replacer a gauche
        //TO_DO action 2 du joueur
        //TO_DO exception handle if already at left?
        ~joueur; //methode qui place a la gauche
        int success;
        success=joueur.getVitrail()->construireVitrail(chosenLots, joueur.getPosition());
        //calcul des points
        int unused = unusedLots(chosenLots);
        int p=calculatePoints(joueur, unused); //appel a methode pour calculer les points
        joueur.changerPoints(p); //ajouter les points au joueur
        //END OF ACTION 2

    }

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//fonction principal du programme
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(){
    /* Testing methods
    Vitrail* vit=new Vitrail(7,5);
    cout <<vit<<endl;
    vector<char> vect{'C','O','J','O','G'};
    cout<<"Appel a construireVitrail"<<endl;
    vit->construireVitrail(vect, 5);
    cout<<vit<<endl;
    bool comp=vit->estEnConstruction(5);
    if (comp==true){cout<<"Complete"<<endl;}
    else {cout<<"Not complete"<<endl;}
    string name="Joueur A";
    //Test Joueur
    Joueur joueur(name, *vit); //creation de Joueur
    joueur--;
    cout<<joueur<<endl; //testing operator <<
    joueur-=(2);
    cout <<joueur<<endl;
    ~joueur;
    cout<<joueur<<endl;

    Lots lots; //testing lots
    cout <<lots;
    lots.ramasseVitre('B',2);
    cout<<lots;
    lots.reset_L();
    cout<<lots;
    */

    int nColonne = 7;               //valeur par defaut de colonne du vitrail
    int nVitre = 5;                 // valeur par defaut du nombre de vitre par colonne
    Vitrail* vitre=new Vitrail(nColonne, nVitre);     //initialize la grille de vitrail pour jouer (2 joueuers utilisent le meme)
    Lots lots; //faut aussi creer des Lots au debut (joueurs prennent du meme)
     //TO_DO demande a utilisateur le nombre de vitre et colonne sinon defaut
    string name;
    cout<< "Entrez le nom du premier joueur: ";
    cin>> name; cout<<endl;
    Joueur joueur1(name, *vitre );      //Creation de joueuer 1
    cout<< "Entrez le nom du deuxieme joueur: ";
    cin>> name; cout<<endl;
    Joueur joueur2(name, *vitre);      //Creation du joueur 2
    bool gameflag = true;   //condition vrais pour continuer a jouer - false jeu terminer
    int action;
    //TO_DO alternate between players
    while(gameflag){
            //tour du joueur 1
        cout<<joueur1<<endl;
        cout<<lots<<endl;
        while (true) {
            cout <<"Quel action voulez vous effectuer? (1=deplacement droite, 2= revenir a position extreme gauche): ";
            cin >>action; cout<<endl;
            if (action<1||action>2) {throw std::invalid_argument("Entrer action 1 ou 2");}
            else {break;}
        }
        playRound(joueur1, lots, action); //appel a methode pour effectuer une ronde
        if (lots.isEmpty()) {
            gameflag=false;
            break;
        }
        //etat modifier du joueur 1 et des lots
        cout <<joueur1 <<endl;
        cout<<lots<<endl;

        //tour du joueur 2
        cout<<joueur2<<endl;
        cout<<lots<<endl;
        while (true) {
            cout <<"Quel action voulez vous effectuer? (1=deplacement droite, 2= revenir a position extreme gauche): ";
            cin >>action; cout<<endl;
            if (action<1||action>2) {throw std::invalid_argument("Entrer action 1 ou 2");}
            else {break;}
        }
        playRound(joueur2, lots, action); //appel a methode pour effectuer une ronde
        if (lots.isEmpty()) {
            gameflag=false;
            break;
        }
        //etat modifier du joueur 2 et des lots
        cout <<joueur2 <<endl;
        cout<<lots<<endl;

        //va repeter et revenir au joueur 1
    }

    //TO_DO what happens when lots is empty?


    return 0;

};
