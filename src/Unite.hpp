#ifndef UNITE_H
#define UNITE_H

#include <iostream>
#include <string.h>

using namespace std;



/*
 * #include "Joueur"
 *
 * A eviter : Circular Dependencies
 * https://stackoverflow.com/questions/7665912/double-include-solution
 */

class Jeu;

class Joueur;




class Unite {

		public : 
				static int currentId;
		private :
				int id;
				Joueur* joueur;
				string caracteristique;
				int hp;
				int att;
				int portee;
				int prix;


		public :
				Unite(Joueur* parJoueur, string parCaracteristique);
				/**
				 * Enlever les points de vie de ce joueur
				 * param :	a : points d'attaque de l'enemi
				 **/
				void estAttaque(int);

				/*
				 * Getters
				 */
				int getId();
				Joueur* getJoueur();
				string getCaracteristique();
				int getHp();
				int getAtt();
				int getPortee();

				/*
				 * Setters
				 */
				void setJoueur(Joueur* parJoueur);
				void setCaracteristique(string parCaracteristique);
				void setHp(int parHp);
				void setAtt(int parAtt);
				void setPortee(int parPortee);
};

#endif
