/*
*   Cours:        CSI2772 - Concept avancer C++
*   Session:      Autumne 2019
*   Remise:       6 décembre 2019
*   Author 1:     Mathieu Bellefeuille
*   # etudiant:   65013369
*   Auteur 2:     Matthew Tan
*   # etudiant:   300028206
*/
#include <conio.h>
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

/*
* NOTE IMPORTANT
* Si une erreur de undefined reference g++ est lance
* Pour le projet: effectuer CLEAN ensuite rebuild project
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
    int position = 6;
    while(true){        // Demande utilisateur colonne/ vitre par default OU selection personaliser

        char reponse;
        cout<<"Valeur par default du vitrail - (7 colonne, 5 vitre par colonne)"<<endl;
        cout<<"Utiliser valeur par defaut pour initializer le vitrail "<<endl;
        cout<<"YES (Y) - NON (N)"<<endl;
        cin>>reponse;
        if(reponse == 'Y'){
            break;
        }else if(reponse == 'N' ){
            while(true){ //demande utilisateur pour nombre de colonne initial du vitrail

                cout<<"Entree le nombre de colonne: "; cin>>nColonne; cout<<endl;
                position = nColonne - 1;
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
                cout<<"Entree le nombre de vitre par colonne: "; cin>>nVitre; cout<<endl;
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
    Lots lots;                                                 //Lots du jeu

    //Creation de joueuer 1
    string name;
    cout<< "Entrez le nom du premier joueur: ";
    cin>> name; cout<<endl;
    Joueur joueur1(name, *vitrailJoueur1,position );

    //Creation du joueur 2
    cout<< "Entrez le nom du deuxieme joueur: ";
    cin>> name; cout<<endl;
    Joueur joueur2(name, *vitrailJoueur2,position);


    Joueur listJoueur[2] = {joueur1,joueur2};       //Liste des joueur
    int gameCounter = 0;                            //tien le nombre de tour jouer
    Joueur joueurActif;                             //contient le joueur actif a jouer
    int action;                                     //determine l'action du joueur a prendre
    int phase = 0;                                  //nombre de phase
    while(true){

        //vas decider qui est a jouer
        //pair = joueur1
        //impair = joueur2
        joueurActif = listJoueur[gameCounter%2];
        if(gameCounter == 0 ){
            cout<<"//////////////////////////////////////////"<<endl;
            cout<<"//**************************************//"<<endl;
            cout<<"//**   Initialization de la partie    **//"<<endl;
            cout<<"//**************************************//"<<endl;
            cout<<"//////////////////////////////////////////"<<endl;
        }
        if(gameCounter>0){
            cout<<"//////////////////////////////////////////"<<endl;
            cout<<"//**************************************//"<<endl;
            cout<<"//**       CHANGEMENT DE JOUEUR       **//"<<endl;
            cout<<"//**************************************//"<<endl;
            cout<<"//////////////////////////////////////////"<<endl;
        }

        cout<<joueurActif<<endl;
        cout<<lots<<endl;
        cout<<"**************************************************************************"<<endl;
        cout <<"Quel action voulez vous effectuer?"<<endl;
        cout<< "Selectionner une colonne du vitrail entre Vitrier et 0                (1)"<<endl;
        cout<< "Positionner le vitrier a l'extrem gauche (selection de cette colonne) (2)"<<endl;
        cout<<"**************************************************************************"<<endl;
        cout<<"Entree votre choix: ";

        while (true) {//Check selection du l'utilisateur ou lance exception
            cin >>action; cout<<endl;
            if (action<1||action>2) {
                cout<<"*************************************************************************"<<endl;
                cout<<"Choix impossible"<<endl;
                cout<<"Selectionner une possibiliter de la list ci-dessous: "<<endl;
                cout<<"---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---"<<endl;
                cout<<"Selectionner une colonne du vitrail entre 0 et le vitrier             (1)"<<endl;
                cout<<"Positionner le vitrier a l'extrem gauche (selection de cette colonne) (2)"<<endl;
                cout<<"*************************************************************************"<<endl;
                cout<<"Entree votre choix: ";
            }else if(!(cin)){throw std::invalid_argument("Valeur fournir illegal - arret du program");}
            else {break;}
        }
        //BEGIN Round
            int col, vitCol;
            char couleur;
            vector<char> chosenLots;

            //ACTIONS 1 ou 2 du joueur
            if (action==1) {
        //Utilisateur choisis un lots (deux prochain boucle while)
            //Demande a l'utilisateur d'entree un choix de colonne
            //VALEUR RETOUR = int col
            cout<<"***************************************************************"<<endl;
            cout<<"Choisit une colonne du lot entre 0 et 4. (-1 pour le surplus): "<<endl;
            cout<<"***************************************************************"<<endl;
            cout<<"Entree votre choix: ";

            while (true) {
                    cin>>col; cout<<endl;
                     if (col>4 || col < -1) {
                            cout<<"Entrer colonne correspondant a un lot ou le surplus: ";
                    }else if(col == -1 && lots.surplusEmpty()){
                        cout<<"Option invalide: Le surplus est vide!! "<<endl;
                        cout<<"Entrer colonne correspondant a un lot: ";
                    }else if(col > 0 && lots.LotsEmpty()){
                        cout<<"Option invalide: Le lots est vide!! "<<endl;
                        cout<<"Selectionner du surplus (-1): ";
                    }else if(col > 0 && lots.lotColonneEmpty(col)){
                        cout<<"Option invalide: La colonne est vide "<<endl;
                        cout<<"Entrer colonne correspondant a un lot plein: ";
                    }else if(!(cin)){
                            throw std::invalid_argument("Valeur fournir illegal - arret du program");
                    }else {
                        break;
                    }
                }
        //demande a l'utilisateur d'entree un choix de couleur a selectionner
            //VALEUR RETOUR = char couleur
            while(true){
                cout<<"***********************************************************"<<endl;
                cout<<"Entrer une couleur ( G , J , B , R , O ) a prendre: "<<endl;
                cout<<"***********************************************************"<<endl;
                cout<<"Entree votre choix: ";
                cin>>couleur; cout<<endl;
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
        //demande a l'utilisitateur pour place le lot dans le vitrier
            //VALEUR RETOUR = int vitCol
            cout<<"**************************************************************************"<<endl;
            cout<<"Vous avez selectionner du lot "<<chosenLots.size()<<" vitres de Couleur - "<<chosenLots.front()<<endl;
            cout<<"Selectionner une colonne entre 0 et vitrier ("<<joueurActif.getPosition()<<") pour placer votre selection: "<<endl;
            cout<<"**************************************************************************"<<endl;
            cout<<"Entree votre choix: ";
            while (true) {

                    cin>>vitCol; cout<<endl;
                    if (vitCol>joueurActif.getPosition() || vitCol< 0 ) {
                            cout<< "Effectuez une selection entre 0 et le vitrier "<<joueurActif.getPosition();
                            cout<<endl;
                    }else if(!(cin)){throw std::invalid_argument("Valeur fournir illegal - arret du program");}
                    else {break;}
                }

            //placer les vitres
                int success;
                Vitrail *temp = joueurActif.getVitrail();
                success = temp->construireVitrail(chosenLots, vitCol);
            //place vitrier du joueur a la bonne colonne
                int deplacement = joueurActif.getPosition()-vitCol;
                if (deplacement==1){//deplacement droit de 1
                    joueurActif--;
                } else { //deplacement droite de plus que 1
                    joueurActif-=(deplacement);
                }
            //calcul des points
                joueurActif.calculatePoints(success);
                cout<<joueurActif<<endl;
                cout<<lots<<endl;
                listJoueur[gameCounter%2] = joueurActif;

    }
    if (action==2) { //Action 2 c'est de replacer a gauche
        int beforeVitrier = joueurActif.getPosition();
        ~joueurActif; //methode qui place le vitrier a l'extreme gauche
        //si utilisateur deja a la position extreme gauche
        if(beforeVitrier == joueurActif.getPosition()){
    //Utilisateur choisis un lots (deux prochain boucle while)
            //Demande a l'utilisateur d'entree un choix de colonne
            //VALEUR RETOUR = int col
            cout<<"*****************************************"<<endl;
            cout<<"Votre selection de lot sera placer par"<<endl;
            cout<<"default dans a l'extreme gauche."<<endl;
            cout<<"Vitrier a la position: "<<joueurActif.getPosition()<<endl;
            cout<<"*****************************************"<<endl;
            cout<<endl;
            cout<<"***************************************************************"<<endl;
            cout<<"Choisit une colonne du lot entre 0 et 4. (-1 pour le surplus): "<<endl;
            cout<<"***************************************************************"<<endl;
            cout<<"Entree votre choix: ";

            while (true) {
                    cin>>col; cout<<endl;
                     if (col>4 || col < -1) {
                            cout<<"Entrer colonne correspondant a un lot ou le surplus: ";
                    }else if(col == -1 && lots.surplusEmpty()){
                        cout<<"Option invalide: Le surplus est vide!! "<<endl;
                        cout<<"Entrer colonne correspondant a un lot: ";
                    }else if(col > 0 && lots.LotsEmpty()){
                        cout<<"Option invalide: Le lots est vide!! "<<endl;
                        cout<<"Selectionner du surplus (-1): ";
                    }else if(col > 0 && lots.lotColonneEmpty(col)){
                        cout<<"Option invalide: La colonne est vide "<<endl;
                        cout<<"Entrer colonne correspondant a un lot plein: ";
                    }else if(!(cin)){
                            throw std::invalid_argument("Valeur fournir illegal - arret du program");
                    }else {
                        break;
                    }
                }
        //demande a l'utilisateur d'entree un choix de couleur a selectionner
            //VALEUR RETOUR = char couleur
            while(true){
                cout<<"***********************************************************"<<endl;
                cout<<"Entrer une couleur ( G , J , B , R , O ) a prendre: "<<endl;
                cout<<"***********************************************************"<<endl;
                cout<<"Entree votre choix: ";
                cin>>couleur; cout<<endl;
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
            joueurActif.calculatePoints(success);
            cout<<joueurActif<<endl;
            cout<<lots<<endl;
            listJoueur[gameCounter%2] = joueurActif;
        }else{
            cout<<"Le vitrier a ete replacer a l'extreme gauche."<<endl;
            cout<<"Position du vitrier: "<< joueurActif.getPosition()<<endl;
            listJoueur[gameCounter%2] = joueurActif;
        }
    }//END OF ACTION 2

        //END playRound
        //Vas demander pour acceder joute de l'autre joueur
        cout<<"***************************************************"<<endl;
        cout<<"Appuier sur une touche pour passer a l'autre joueur"<<endl;
        cout<<"***************************************************"<<endl;
        getch(); //command to wait until key is hit
        gameCounter++; // permet d'alterner entre les joueur
        if (lots.isEmpty()) { //permet de savoir si une phase est terminer
            lots.reset_L();
            phase++;
        }
        //affiche le gagant de la partie apres 5 phases (lots reset)
        if(phase == 5){
            Joueur gagnant;
            if(joueur1.getPoint()<joueur2.getPoint()){
                gagnant = joueur2;
            }else{
                gagnant = joueur1;
            }
            cout<<"**********************************************"<<endl;
            cout<<"Le gagnant de la partie est: "<<gagnant.getName()<<endl;
            cout<<"avec un total de "<<gagnant.getPoint()<<" points"<<endl;
            cout<<"**********************************************"<<endl;
            break;
        }
    }

    return 0;

};
