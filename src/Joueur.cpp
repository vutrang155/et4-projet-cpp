#include <iostream>
#include <string.h>
#include <array>


#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Unite.hpp"


#define POINTS_DE_VIE_JOUEUR_DEBUT 50


using namespace std;




Joueur::Joueur(Jeu* parJeu, string parPositionBase)
{
	if(parPositionBase.compare("Gauche") != 0 && parPositionBase.compare("Droite") != 0)
	{
		cout << "On ne peut choisir qu'un joueur à Gauche ou à Droite sur le terrain" << endl;
		exit(EXIT_FAILURE);
	}

	positionBase = parPositionBase;
	
	jeu = parJeu; 

	hp = POINTS_DE_VIE_JOUEUR_DEBUT;
	
	argent = 8;
}




void Joueur::jouer()
{
	
}




/*
void Joueur::acheter(string caracteristique)
{
	
}
*/

bool Joueur::estAttaque(int valAttaque)
{
	
	hp -= valAttaque;

	if(hp <= 0)
	{
		return true;
	}

	return false;

}


		

int Joueur::getHp()
{
	return hp;
}


int Joueur::getArgent()
{
	return argent;
}

string Joueur::getPositionBase()
{
	return positionBase;
}






void Joueur::setHp(int parHp)
{
	hp = parHp;
}

void Joueur::augmenterArgent(int parArgent)
{
	argent += parArgent;
}

void Joueur::diminuerArgent(int parArgent)
{
	argent -= parArgent;
}

