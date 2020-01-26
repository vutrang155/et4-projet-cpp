#include <iostream>
#include <string.h>
#include <array>
#include <vector>

#include "Jeu.hpp"
#include "Unite.hpp"
#include "Joueur.hpp"


#define NOMBRE_TOURS 50


using namespace std;




// Constructeur 
Jeu::Jeu() 
{
	terrain[TAILLE_TERRAIN] = { nullptr };
}
// Destructeur 
Jeu::~Jeu()
{

}

/*
 * Deroulement du jeu 
 */
void Jeu::deroulement()
{
	/*

		for(int cpt = 0; cpt < NOMBRE_TOURS; cpt++)
		{
			j1.augmenterArgent(8);
			j2.augmenterArgent(8);

			tour("Gauche");

			tour("Droite");

		}
		

	*/

}

string Jeu::getDirection(Joueur* j)
{
	if(j->getPositionBase().compare("Gauche") == 0)
	{
		return "->";
	}

	return "<-";
	
}

/*
void Jeu::tour(Joueur* j)
{
	string positionBase = j->getPositionBase();

	vector<Unite*> unitesJoueur = getUnites(j);
	
	string direction = getDirection(j);


	for(Unite* u : unitesJoueur)
	{
		bool action1effectuee =  attaquer(u, direction, false);	
		avancer(u,direction);
		attaquer(u, direction, action1effectuee);
	

	}	
	
}

*/

/*
bool Jeu::attaquer(Unite* u, string direction, bool isAction1Effectueee)
{
	
	return true;
	
}
*/

bool Jeu::avancer(Unite* u)
{	

	int indexUnite = getIndex(u);


	if(u->getJoueur()->getPositionBase() == "Gauche" && estLibreCase(indexUnite + 1) && indexUnite != TAILLE_TERRAIN - 1)
	{
		terrain[indexUnite] = NULL;

		terrain[indexUnite + 1] = u;

		return true;

	}


	else if(u->getJoueur()->getPositionBase() == "Droite" && estLibreCase(indexUnite - 1) && indexUnite != 1)
	{
		terrain[indexUnite] = NULL;

		terrain[indexUnite - 1] = u;

		return true;
	}


	return false;

}



/*
void Jeu::phaseActions1(PositionBase positionBase)
{
	for(Unite* u : terrain)
	{
		if(*u.getJoueur().getPositionBase() == positionBase)
		{
			action1(u);

		}

	}

}
*/




/*
 * Renvoyer vrai si la case est libre 
 */
bool Jeu::estLibreCase(int indexCase) 
{
	if(terrain[indexCase] == nullptr)
	{
		return true;
	}

	return false;
}

/*
 * Renvoyer l'index de l'unite 
 */
int Jeu::getIndex(Unite* u) 
{
	for(int i = 0; i < TAILLE_TERRAIN; i++)
	{
		if(terrain[i] == u)
		{
			return i;
		}
	}

	return -1;
}

/*
 * Renvoyer l'unite d'un joueur
 */
vector<Unite*> Jeu::getUnites(Joueur* j)
{
	vector<Unite*> unitesJoueur;

	for(int i = 0; i < TAILLE_TERRAIN; i++)
	{	

		if(terrain[i]->getJoueur()->getPositionBase().compare(j->getPositionBase()))
		{
			unitesJoueur.push_back(terrain[i]);
		}
	
	}

	return unitesJoueur;
}	


/*
 * Ajouter dans le terrain une unite 
 */
void Jeu::addUnite(Unite* u, int caseTerrain)
{
	terrain[caseTerrain] = u;
}


string Jeu::afficher()
{
	return "Test affichage du jeu";
}

/*
 * Afficher le terrain
 */
 /*
string Jeu::afficher(){
	&Unite[] u1, u2; 
	string ret = "|";

	u1 = getUnites(j1);
	u2 = getUnites(j2);
	for (int i = 0; i < TAILLE_TERRAIN; i++){
		ret += "|\t";
		ret += terrain.getJoueur() == j1 ? j1+"." : j2+".";
		ret += terrain.getId(); 
		ret += "\t|";
	}
	ret += "|\n";
	ret += "Joueur 1 : \n";
	for (int i = 0; i < sizeof(u1); i++) {
			
	}	

}
*/


Unite* Jeu::getUnite(int i)
{
	return terrain[i];

}




