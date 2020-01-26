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
}
// Destructeur 
Jeu::~Jeu()
{
    delete this->j1;
    delete this->j2;
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
	std::cout << j->getPositionBase();
	/*
	for(int i = 0; i < TAILLE_TERRAIN; i++)
	{
	    if(terrain[i] != nullptr) { // Verifie la case est vide
            //if (terrain[i]->getJoueur()->getPositionBase().compare(j->getPositionBase())) {
                //unitesJoueur.push_back(terrain[i]);
            //}
        }
	}*/
	return unitesJoueur;
}	


/*
 * Ajouter dans le terrain une unite 
 */
void Jeu::addUnite(Unite* u, int caseTerrain)
{
	terrain[caseTerrain] = u;
}


/*
string Jeu::afficher()
{
	return "Test affichage du jeu";
}
 */

/*
 * Afficher le terrain
 */
string Jeu::afficher(){
	string ret = "|";

	// Afficher les cases
	for (int i = 0; i < TAILLE_TERRAIN; i++){
		ret += "| ";
		if (terrain[i] != nullptr) { // If not found
            if (terrain[i]->getJoueur() == j1)
                ret += "j1.";
            else
                ret += "j2.";

            ret += to_string(terrain[i]->getId());
        }
        ret += " |";
    }
    ret += "|\n";

	// Afficher les informations sur le terrain
    //vector<Unite*> u1 = this->getUnites(j1);
    //vector<Unite*> u2 = this->getUnites(j2);
    //std::cout << j1->getPositionBase();
    //this->getUnites(j1);
	ret += "Joueur 1 : \n";
	return ret;

}



Unite* Jeu::getUnite(int i)
{
	return terrain[i];

}




