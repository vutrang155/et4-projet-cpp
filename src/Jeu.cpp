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
Jeu::Jeu(Joueur* j, Joueur* jj)
{
    jGauche = j;
    jDroite = jj;
}
// Destructeur 
Jeu::~Jeu()
{
    delete this->jGauche;
    delete this->jDroite;
}

/*
 * Deroulement du jeu 
 */
void Jeu::deroulement()
{
	

    for(int cpt = 0; cpt < NOMBRE_TOURS; cpt++)
    {
        jGauche->augmenterArgent(8);
        jDroite->augmenterArgent(8);

        tour(jGauche);
        tour(jDroite);
    }
	
    if(jGauche->getHp() <= 0)
    {
        cout << "Le joueur à droite a gagné" << endl;
    }

    else if(jDroite->getHp() <= 0)
    {
        cout << "Le joueur à gauche a gagné" << endl;
    }

    else
    {
        cout << "Match nul" << endl;
    }
    
}

string Jeu::getDirection(Joueur* j)
{
    if(j->getPositionBase().compare("Gauche") == 0)
    {
        return "->";
    }

    return "<-";

}



void Jeu::action1(Unite* u)
{
    u->setIsAction1Effectuee(attaquer(u));
}


void Jeu::action2(Unite* u)
{
    if(!u->getCaracteristique().compare("Catapulte"))
    {
        avancer(u);
    }
}

void Jeu::action3(Unite* u)
{
    if((u->getCaracteristique().compare("Fantassin") == 0 && u->getIsAction1Effectuee() == false) || u->getCaracteristique().compare("SuperSoldat") == 0)
    {
        attaquer(u);

    }

    else if(u->getCaracteristique().compare("Catapulte") == 0 && u->getIsAction1Effectuee() == false)
    {
        avancer(u);

    }

}


void Jeu::tour(Joueur* j)
{
	string positionBase = j->getPositionBase();

	vector<Unite*> unitesJoueur = getUnites(j);
	


    //Action 1
    if(j->getPositionBase().compare("Gauche"))
    {
        //De gauche à droite
        for(int i = 0; i < unitesJoueur.size(); i++)
        {
            action1(unitesJoueur[i]);	
        }	
        
    }
    
    else
    {
        //De droite à gauche
        for(int i = unitesJoueur.size() - 1; i >= 0 ; i--)
        {
            action1(unitesJoueur[i]);	
        }	
    }





    //Action 2
    if(j->getPositionBase().compare("Gauche"))
    {
        //De droite à gauche
        for(int i = unitesJoueur.size() - 1; i >= 0 ; i--)
        {
            action2(unitesJoueur[i]);	
        }	
        
    }
    
    else
    {
        //De gauche à droite
        for(int i = 0; i < unitesJoueur.size(); i++)
        {
            action2(unitesJoueur[i]);	
        }	
    }




    //Action 3
    if(j->getPositionBase().compare("Gauche"))
    {
        //De droite à gauche
        for(int i = unitesJoueur.size() - 1; i >= 0 ; i--)
        {
            action3(unitesJoueur[i]);	
        }	
        
    }
    
    else
    {
        //De gauche à droite
        for(int i = 0; i < unitesJoueur.size(); i++)
        {
            action3(unitesJoueur[i]);	
        }	
    }

	
}







// Renvoyer vrai si l'unite attaque
bool Jeu::attaquer(Unite* u)
{

    if(u->getIsAction1Effectuee()) {
        int portee = 0; // Declaration de portee de l'unite
        int indexUnite = getIndex(u);
        std::string direction = u->getJoueur()->getPositionBase();
        if(direction.compare("Gauche") == 0) portee = u->getPortee();
        if(direction.compare("Droite") == 0) portee = 0 - u->getPortee();

        if(portee >= 0) { // Si Gauche
            for(int i = 1; i <= portee; i++) {
                if (u->getCaracteristique().compare("Catapulte") != 0) {
                    if (!estLibreCase(indexUnite + i) && indexUnite + i != TAILLE_TERRAIN - 1) {
                        Unite *attaquee = terrain[indexUnite + i];
                        if (attaquee->getJoueur() != u->getJoueur()) {
                            attaquee->estAttaque(u->getAtt());
                            // si hp = 0
                            if (attaquee->getHp() <= 0) {
                                /* Remporte l'argent */
                                std::string attaqueeType = attaquee->getCaracteristique();
                                if (attaqueeType.compare("Archer") == 0) u->getJoueur()->augmenterArgent(6);
                                if (attaqueeType.compare("Catapulte") == 0) u->getJoueur()->augmenterArgent(10);
                                else u->getJoueur()->augmenterArgent(5);

                                terrain[indexUnite + i] = nullptr;
                                // Si l'attaqueur est fantassin
                                if (u->getCaracteristique().compare("Fantassin") == 0) u->devenirSuperSoldat();
                                return true;
                            }
                        }
                        else { return false;}
                    }
                } else {
                    if (i != 1) {
                        if (!estLibreCase(indexUnite + i) && indexUnite + i != TAILLE_TERRAIN - 1) {
                            Unite *attaquee = terrain[indexUnite + i];
                            attaquee->estAttaque(u->getAtt());

                            // si hp = 0
                            if (attaquee->getHp() <= 0) {
                                /* Remporte l'argent */
                                std::string attaqueeType = attaquee->getCaracteristique();
                                if (attaqueeType.compare("Archer") == 0) u->getJoueur()->augmenterArgent(6);
                                if (attaqueeType.compare("Catapulte") == 0) u->getJoueur()->augmenterArgent(10);
                                else u->getJoueur()->augmenterArgent(5);
                                terrain[indexUnite + i] = nullptr;
                            }
                        }
                    }
                }
            }
        }
        else { // Sinon
            for(int i = -1; i >= portee; i--) {
                if (u->getCaracteristique().compare("Catapulte") != 0) {
                    if (!estLibreCase(indexUnite + i) && indexUnite + i != TAILLE_TERRAIN - 1) {
                        Unite *attaquee = terrain[indexUnite + i];
                        if (attaquee->getJoueur() != u->getJoueur()) {
                            attaquee->estAttaque(u->getAtt());
                            // si hp = 0
                            if (attaquee->getHp() <= 0) {
                                /* Remporte l'argent */
                                std::string attaqueeType = attaquee->getCaracteristique();
                                if (attaqueeType.compare("Archer") == 0) u->getJoueur()->augmenterArgent(6);
                                if (attaqueeType.compare("Catapulte") == 0) u->getJoueur()->augmenterArgent(10);
                                else u->getJoueur()->augmenterArgent(5);

                                terrain[indexUnite + i] = nullptr;
                                // Si l'attaqueur est fantassin
                                if (u->getCaracteristique().compare("Fantassin") == 0) u->devenirSuperSoldat();
                                return true;
                            }
                        }
                        else { return false;}
                    }
                } else {
                    if (i != 1) {
                        if (!estLibreCase(indexUnite + i) && indexUnite + i != TAILLE_TERRAIN - 1) {
                            Unite *attaquee = terrain[indexUnite + i];
                            attaquee->estAttaque(u->getAtt());

                            // si hp = 0
                            if (attaquee->getHp() <= 0) {
                                /* Remporte l'argent */
                                std::string attaqueeType = attaquee->getCaracteristique();
                                if (attaqueeType.compare("Archer") == 0) u->getJoueur()->augmenterArgent(6);
                                if (attaqueeType.compare("Catapulte") == 0) u->getJoueur()->augmenterArgent(10);
                                else u->getJoueur()->augmenterArgent(5);
                                terrain[indexUnite + i] = nullptr;
                            }
                        }
                    }
                }
            }

        }
    }
    return true;

}



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
        if(terrain[i] != nullptr) { // Verifie la case est vide
            string directionUnite = terrain[i]->getJoueur()->getPositionBase();
            string directionJoueur = j->getPositionBase();
            if (directionUnite.compare(directionJoueur) == 0) {
                unitesJoueur.push_back(terrain[i]);
            }
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

/*
 * Afficher le terrain
 */
string Jeu::afficher(){
    string ret = "|";

	// Afficher les cases
	for (int i = 0; i < TAILLE_TERRAIN; i++){
		ret += "| ";
		if (terrain[i] != nullptr) { // If not found
            if (terrain[i]->getJoueur() != jGauche)
                ret += "d.";
            else
                ret += "g.";

            ret += to_string(terrain[i]->getId());
        }
        ret += " |";
    }
    ret += "|\n";

	// Afficher les informations sur le terrain
    vector<Unite*> u1 = this->getUnites(jGauche);
    ret += "Joueur Gauche : \n  $";
    ret += to_string(jGauche->getArgent());
    ret += "\t";
    ret += jGauche->getHp();
    ret += " Hp";
    ret += "\n";
    for (auto u = u1.begin(); u != u1.end(); u++) {
        ret += "\tg.";
        ret += to_string((*u)->getId());
        ret += " : ";
        ret += "\n\t\tType : ";
        ret += (*u)->getCaracteristique();
        ret += "\n\t\tPositionBase : ";
        ret += (*u)->getJoueur()->getPositionBase();
        ret += "\n\t\tHP : ";
        ret += to_string((*u)->getHp());
    }
    vector<Unite*> u2 = this->getUnites(jDroite);
    ret += "\nJoueur Droite: \n  $";
    ret += to_string(jDroite->getArgent());
    ret += "\t";
    ret += jDroite->getHp();
    ret += " Hp";
    ret += "\n";
    for (auto u = u2.begin(); u != u2.end(); u++) {
        ret += "\td.";
        ret += to_string((*u)->getId());
        ret += " : ";
        ret += "\n\t\tType : ";
        ret += (*u)->getCaracteristique();
        ret += "\n\t\tPositionBase : ";
        ret += (*u)->getJoueur()->getPositionBase();
        ret += "\n\t\tHP : ";
        ret += to_string((*u)->getHp());
    }
    ret += "\n";
    return ret;

}



Unite* Jeu::getUnite(int i)
{
    return terrain[i];

}




