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

		if(strcmp(parCaracteristique, "Fantassin"))
		{
			prix = 10;
			hp = 10;
			att = 4;
			portee = PORTEE1;
		}

		else if(strcmp(parCaracteristique, "Archer"))
		{
			prix = 12;
			hp = 7;
			att = 3;
			portee = PORTEE2;
		}

		else if(strcmp(parCaracteristique, "Catapulte"))
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


attaque(Unite uatt, Unite udefense)
{
		/*switch(uatt.getC())
		  case


*/	
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
		return c;
}


int Unite::getHp()
{
		return hp;
}

int Unite::getAtt()
{
		return att;
}


int Unite::getPortee()
{
		return portee;
}


void Unite::setJoueur(Joueur* parJoueur)
{
		joueur = parJoueur;
}


void Unite::setC(string parCaracteristique)
{
		caracteristique = parCaracteristique
}


void Unite::setHp(int parHp)
{
		hp = parHp;
}



void Unite::setAtt(int parAtt)
{
		att = parAtt;
}






