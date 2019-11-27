#include "Joueur.h"

Joueur::Joueur(){}

Joueur::Joueur(Vitrail* vit): vitrail(vit){}

Joueur::~Joueur()
{
    delete vit;
}
