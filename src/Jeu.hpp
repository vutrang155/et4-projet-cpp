#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string.h>
#include <vector>

#include "Joueur.hpp"



using namespace std;




class Jeu {
	private :
		Unite** terrain;
		Joueur j1;
		Joueur j2;
	public :
		// Constructeur 
		Jeu();
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


		void avancer(Unite* u, string direction);

		bool attaquer(Unite* u, string direction, bool isAction1Effectueee);

		string getDirection(Joueur* j);

		void tour(Joueur* j);

		
};

ostream& operator<<(ostream& os, const Jeu& jeu) ; 

#endif
