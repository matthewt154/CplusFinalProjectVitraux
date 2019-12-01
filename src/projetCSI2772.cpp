#include "Lots.h"
#include "Vitrail.h"
#include "Joueur.h"
#include <iostream>
#include <string.h>
#include <limits>
#include "ostreamTest.h"
#include <stdexcept> //out_of_range
#include <vector>
using namespace std;
//TO_DO make it pretty and comment beginning of functions comme conventions (i.e. param and return)

/*
//calcul de vitres pas utilise dans vecteur apres placement sur vitrail
int unusedLots(vector<char> chosenLots ) {
    //lots non utilises detruits
    int result = chosenLots.size(); //combien de vitres restants
    chosenLots.clear();
    return result;
}
*/


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//fonction principal du programme
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(){

    cout<<"| --------------------------------|"<<endl;
    cout<<"|   "<<"Bienvenu au Jeu du Vitrail"<<"    |"<<endl;
    cout<<"| --------------------------------|"<<endl;
    cout<<endl;

    int nColonne = 7;   //valeur par defaut de colonne du vitrail
    int nVitre = 5;     // valeur par defaut du nombre de vitre par colonne
    while(true){ // Demande utilisateur colonne/ vitre par default OU selection personaliser

        char reponse;
        cout<<"Valeur par default du vitrail - (7 colonne, 5 vitre par colonne)"<<endl;
        cout<<"Utiliser valeur par defaut pour initializer le vitrail "<<endl;
        cout<<"YES (Y) - NON (N)"<<endl;
        cin>>reponse;
        if(reponse == 'Y'){
            break;
        }else if(reponse == 'N' ){
            while(true){ //demande utilisateur pour nombre de colonne initial du vitrail

                cout<<"Entree le nombre de colonne - (Par default - 7 colonne): "; cin>>nColonne; cout<<endl;
                if( nColonne <= 0){
                    cout<<"Entree un nombre plus grand que zero: ";
                }

                if(!(cin)){
                    throw std::invalid_argument("Valeur fournir illegal - arret du program");
                }

                else{
                    break;
                }
            }

            while(true){//demande utilisateur pour nombre de colonne initial du vitrail
                cout<<"Entree le nombre de vitre par colonne - (Par default - 5 vitre): "; cin>>nVitre; cout<<endl;
                if( nVitre <= 0){
                    cout<<"Entree un nombre plus grand que zero.";
                }
                if(!(cin)){
                    throw std::invalid_argument("Valeur fournir illegal - arret du program");
                }
                else{
                    break;
                }
            }
            break;
        }
    }

    Vitrail* vitrailJoueur1=new Vitrail(nColonne, nVitre);     //initialize la grille de vitrail pour joueur1
    Vitrail* vitrailJoueur2=new Vitrail(nColonne, nVitre);     //initialize la grille de vitrail pour joueur2
    Lots lots; //Lots du jeu

    //Creation de joueuer 1
    string name;
    cout<< "Entrez le nom du premier joueur: ";
    cin>> name; cout<<endl;
    Joueur joueur1(name, *vitrailJoueur1 );

    //Creation du joueur 2
    cout<< "Entrez le nom du deuxieme joueur: ";
    cin>> name; cout<<endl;
    Joueur joueur2(name, *vitrailJoueur2);

    //Liste des joueur
    Joueur listJoueur[2] = {joueur1,joueur2};

    //Nombre de tour jouer - Vas determiner a qui le tour (modulo)

    //tien le nombre de tour jouer
    int gameCounter = 0;
    //contient le joueur actif a jouer
    Joueur joueurActif;
    //determine l'action du joueur a prendre
    int action;

    //nombre de phase
    int phase = 0;

    while(true){

        //vas decider qui est a jouer
        //pair = joueur1
        //impair = joueur2
        joueurActif = listJoueur[gameCounter%2];

            //tour du joueur 1
        cout<<joueurActif<<endl;
        cout<<lots<<endl;

        cout <<"Quel action voulez vous effectuer?"<<endl;
        cout<< "Selectionner une colonne du vitrail entre Vitrier et 0          (1)"<<endl;
        cout<< "Positionner le vitrier a l'extrem gauche (selection de cette colonne) (2)"<<endl;
        cout<<"Entree votre choix: ";
        while (true) {//Check selection du l'utilisateur ou lance exception
            cin >>action; cout<<endl;
            if (action<1||action>2) {
                cout<<"Choix impossible"<<endl;
                cout<<"Selectionner entre: "<<endl;
                cout<< "Selectionner une colonne du vitrail entre 0 et le vitrier        (1)"<<endl;
                cout<< "Positionner le vitrier a l'extrem gauche (selection de cette colonne) (2)"<<endl;
                cout<<"Entree votre choix: ";
            }
            if(!(cin)){throw std::invalid_argument("Valeur fournir illegal - arret du program");}
            else {break;}
        }
        /* This call works, but not in the method (could always get it out)
        vector<char> vect{'C','O','J','O','G'};
        joueur1.getVitrail()->construireVitrail(vect, 4);
        cout<<joueur1;
        */

        //BEGIN playRound
    int col, vitCol;
    char couleur;
    vector<char> chosenLots;

    //ACTIONS 1 ou 2 du joueur
    if (action==1) {
    cout<<joueurActif<<endl;
    cout<<lots<<endl;
//Utilisateur choisis un lots (deux prochain boucle while)
    //Demande a l'utilisateur d'entree un choix de colonne
    //VALEUR RETOUR = int col
    while (true) {
            cout<<"Choisit une colonne du lot entre 0 et 4. (-1 pour le surplus): "; cin>>col; cout<<endl;
            if (col>4 || col < -1) {
                    cout<<"Entrer colonne correspondant a un lot: ";
                    cout<<endl;
            }
            if(!(cin)){
                    throw std::invalid_argument("Valeur fournir illegal - arret du program");
            }else {
                break;
            }
        }
    //demande a l'utilisateur d'entree un choix de couleur a selectionner
    //TO_DO add code to strip characters spaces away
    //VALEUR RETOUR = char couleur
    while(true){
        cout<<"Entrer une couleur ( G , J , B , R , O ) a prendre du lot: "; cin>>couleur; cout<<endl;
        if(couleur == 'G' || couleur == 'J' || couleur == 'B' || couleur == 'R' || couleur == 'O'){
                if(lots.getLot(couleur,col)){
                    chosenLots=lots.ramasseVitre(couleur, col); //prendre les couleurs du lot
                    break;
                }else{
                    cout<<"La couleur selectionner n'est pas dans la colonne du lot"<<endl;
                }
        }
        if(!(cin)){
                    throw std::invalid_argument("Valeur fournir illegal - arret du program");
        }
        else{
            cout<<"Couleur non approprier."<<endl;
        }
    }
    //demande a l'utilisitateur pour place le lot dans vitrie
    //VALEUR RETOUR = int vitCol
    while (true) {
            cout<<"Vous avez selectionner du lot "<<chosenLots.size()<<" vitres de Couleur - "<<chosenLots.front()<<endl;
            cout<<"Selectionner une colonne entre 0 et vitrier pour placer votre selection: ";
            cin>>vitCol; cout<<endl;
            if (vitCol>joueurActif.getPosition() || vitCol< 0 ) {
                    cout<< "Effectuez une selection entre 0 et le vitrier "<<joueurActif.getPosition();
                    cout<<endl;
            }
            if(!(cin)){throw std::invalid_argument("Valeur fournir illegal - arret du program");}
            else {break;}
        }
    //place vitrier du joueur a la bonne colonne
        int deplacement = joueurActif.getPosition()-vitCol;
        if (deplacement==1){//deplacement droit de 1
            joueurActif--;
        } else { //deplacement droite de plus que 1
            joueurActif-=(deplacement);
        }
        //PROBLEM modifies vitrail strangely (weird matrix style)
    //placer les vitres
        int success=0;
        Vitrail *temp = joueurActif.getVitrail();
        success = temp->construireVitrail(chosenLots, vitCol); //this is correct but not outside of function

    //calcul des points";
        //Was crashing otherwise !!!!!
        /*
        int result = 0;
        if (joueurActif.getVitrail()->estComplete(joueurActif.getPosition())) { //colonne complete
            cout<<"in condition"<<endl;
            result= result+3;
            //calcul tout vitre entamer de 0 au vitrier
            for (int i=0; i<joueurActif.getPosition(); i++) { //+1 si vitre en construction
                if (joueur.getVitrail()->estEnConstruction(i)) {result++; }
            }
        }
        */
        //result= result - success; //-1 pour chaque vitre pas utilise
        joueurActif.calculatePoints(success);
        //joueurActif.changerPoints(result);


    }
    if (action==2) { //Action 2 c'est de replacer a gauche
        cout<<joueurActif<<endl;
        cout<<lots<<endl;
        int beforeVitrier = joueurActif.getPosition();
        ~joueurActif; //methode qui place le vitrier a l'extreme gauche
        //si utilisateur deja a la position extreme gauche
        if(beforeVitrier == joueurActif.getPosition()){
    //Utilisateur choisis un lots (deux prochain boucle while)
            //Demande a l'utilisateur d'entree un choix de colonne
            //VALEUR RETOUR = int col
            cout<<"*****************************************"<<endl;
            cout<<"Votre selection de lot sera placer par"<<endl;
            cout<<"default dans la colonne la plus a gauche."<<endl;
            cout<<"*****************************************"<<endl;
            cout<<endl;
            while (true) {
                    cout<<"Choisit une colonne du lot entre 0 et 4. (-1 pour le surplus): "; cin>>col; cout<<endl;
                    if (col>4 || col < -1) {
                            cout<<"Entrer colonne correspondant a un lot: ";
                            cout<<endl;
                    }
                    if(!(cin)){
                            throw std::invalid_argument("Valeur fournir illegal - arret du program");
                    }else {
                        break;
                    }
                }
            //demande a l'utilisateur d'entree un choix de couleur a selectionner du lot
            //TO_DO add code to strip characters spaces away
            //VALEUR RETOUR = char couleur
            while(true){

            cout<<"Entrer une couleur ( G , J , B , R , O ) a prendre du lot: "; cin>>couleur; cout<<endl;
            if(couleur == 'G' || couleur == 'J' || couleur == 'B' || couleur == 'R' || couleur == 'O'){
                    if(lots.getLot(couleur,col)){
                        chosenLots=lots.ramasseVitre(couleur, col); //prendre les couleurs du lot
                        break;
                    }else{
                        cout<<"La couleur selectionner n'est pas dans la colonne du lot"<<endl;
                    }
            }
            if(!(cin)){
                        throw std::invalid_argument("Valeur fournir illegal - arret du program");
            }
            else{
                cout<<"Couleur non approprier."<<endl;
            }
        }
            int success;
            success=joueurActif.getVitrail()->construireVitrail(chosenLots, joueurActif.getPosition());
            //calcul des points
            int unused = unusedLots(chosenLots);
            joueurActif.calculatePoints(success); //appel a methode pour calculer les points
            //joueurActif.changerPoints(p); //ajouter les points au joueur
        }
    }//END OF ACTION 2

        //END playRound
        //vas cree un appelle a l'autre joueur
        gameCounter++;

        if(phase == 4){
            Joueur gagnant;
            if(joueur1.getPoint()<joueur2.getPoint()){
                gagnant = joueur2;
            }else{
                gagnant = joueur1;
            }
            cout<<"**********************************************"<<endl;
            cout<<"Le gagnant de la partie est: "<<gagnant<<endl;
            cout<<"**********************************************"<<endl;
            break;
        }
        if (lots.isEmpty()) {
            lots.reset_L();
            phase++;
        }
        //PROBLEM modifies it but plan is weird matrix style (something wrong with modifying vitrail)
        //Solution: pass by reference instead of object in playRound (solved)
        //Solution 2:

        //etat modifier du joueur 1 et des lots
        //cout <<joueur1 <<endl;
        //cout<<lots<<endl;
/*
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
        */
    }

    //TO_DO what happens when lots is empty?


    return 0;

};
