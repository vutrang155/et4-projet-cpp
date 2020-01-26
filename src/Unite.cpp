#include <iostream>

#include "Jeu.hpp"
#include "Joueur.hpp"
#include "Unite.hpp"

#define PORTEE1 1
#define PORTEE2 2
#define PORTEE3 3




int Unite::currentId = 0;


Unite::Unite(Joueur* parJoueur, string parCaracteristique)
{
	caracteristique = parCaracteristique;

	if(parCaracteristique.compare("Fantassin") == 0)
	{
		prix = 10;
		hp = 10;
		att = 4;
		portee = PORTEE1;
	}

	else if(parCaracteristique.compare("Archer") == 0)
	{
		prix = 12;
		hp = 7;
		att = 3;
		portee = PORTEE2;
	}

	else if(parCaracteristique.compare("Catapulte") == 0)
	{
		prix = 22;
		hp = 12;
		att = 6;
		portee = PORTEE3;
	}

	else
	{
		cout << "L'unité SuperSoldat ni aucune autre ne peut pas être ajoutée";
		exit(EXIT_FAILURE);
	}		




	id = currentId;

	currentId++;


	joueur = parJoueur;


}

Unite::~Unite() {
    currentId--;
}
void Unite::estAttaque(int valAttaque)
{
	hp -= valAttaque;
}

int Unite::getId()
{
	return id;
}

Joueur* Unite::getJoueur()
{
	return joueur;
}


string Unite::getCaracteristique()
{
	return caracteristique;
}


int Unite::getHp()
{
	return hp;
}

int Unite::getAtt()
{
	return att;
}


int Unite::getPrix()
{
	return prix;
}


int Unite::getPortee()
{
	return portee;
}

bool Unite::getIsAction1Effectuee()
{
	return isAction1Effectuee;
}


void Unite::setJoueur(Joueur* parJoueur)
{
	joueur = parJoueur;
}


void Unite::setCaracteristique(string parCaracteristique)
{
	caracteristique = parCaracteristique;
}

void Unite::devenirSuperSoldat() {
    if(getCaracteristique().compare("Fantassin") == 0) {
        setCaracteristique("Super-soldat");
    }
    else {
        std::cout << "seul un fantassin peut devenir supersoldat" << std::endl;
    }
}


void Unite::setHp(int parHp)
{
		hp = parHp;
}



void Unite::setAtt(int parAtt)
{
		att = parAtt;
}

void Unite::setIsAction1Effectuee(bool parIsAction1Effectuee)
{
		isAction1Effectuee = parIsAction1Effectuee;
}





