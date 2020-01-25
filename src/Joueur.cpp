#include <iostream>
#include "Unite.hpp"
#include "Joueur.hpp"

#include "Jeu.hpp"

using namespace std;

Joueur::Joueur(Jeu& parJeu, PositionBase parPositionBase)
{
	positionBase = parPositionBase;
	
	jeu = parJeu; 

	hp = 50;
	
	argent = 8;
}




void Joueur::jouer()
{
	
}


bool Joueur::avancer(Unite& u)
{

	jeu.deplacerUnite(u, positionBase);


}

bool Joueur::attaquer(Unite& u)
{
	
}

bool Joueur::acheter(Caracteristique c)
{
	
}


		

int Joueur::getHp()
{
	return hp;
}


int Joueur::getArgent()
{
	return argent;
}

PositionJoueur Joueur::getPositionBase()
{
	return positionBase;
}






void Joueur::setHp(int parHp)
{
	hp = parHp;
}

void Joueur::setArgent(int parArgent)
{
	argent = parArgent;
}

