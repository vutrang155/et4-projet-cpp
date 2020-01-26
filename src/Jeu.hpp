#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string.h>
#include <vector>
#include <array>

#define TAILLE_TERRAIN 12



using namespace std;

class Joueur;

class Unite;


class Jeu {

	private :
	
		array<Unite*,TAILLE_TERRAIN> terrain;
		Joueur* jGauche;
		Joueur* jDroite;


	public :
		// Constructeur 
		Jeu(Joueur* j, Joueur* jj);

		// Destructeur 
		~Jeu();

		/*
		 * Deroulement du jeu 
		 */
		void deroulement();
		/*
		 * Renvoyer vrai si la case est libre 
		 */
		bool estLibreCase(int indexCase);

		/*
		 * Renvoyer l'index de l'unite 
		 */
		Unite* getUnite(int i);

		/*
		 * Renvoyer l'index de l'unite 
		 */
		int getIndex(Unite* u);
		/*
		 * Renvoyer l'unite d'un joueur
		 */
		vector<Unite*> getUnites(Joueur* j);	

		/*
		 * Ajouter dans le terrain une unite 
		 */
		void addUnite(Unite* u, int caseTerrain);

		/*
		 * Afficher le terrain
		 */
		string afficher();


		bool avancer(Unite* u);

		bool attaquer(Unite* u);

		string getDirection(Joueur* j);

		void tour(Joueur* j);

		void action1(Unite* u);
		
		void action2(Unite* u);
		
		void action3(Unite* u);

		void achatUnite(Joueur* j);

		void joueurAcheteUnite(Joueur* j, string caracteristique);

		Unite* getUniteDuTerrain(int indexUnite);

		//friend ostream& operator<<(ostream& os, Jeu& jeu);

		
		
};

/*
ostream& operator<<(ostream& os, Jeu& jeu)
{
    os << jeu.afficher();
    return os;
}
 */

#endif
