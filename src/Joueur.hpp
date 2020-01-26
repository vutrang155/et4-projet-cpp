#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string.h>

#include "Unite.hpp"

using namespace std;

class Jeu;




class Joueur {
	private :
		int jeu;
		int hp;
		int argent;
		string positionBase;
		
	public :
		Joueur();

		Joueur(Jeu* parJeu, string parPositionBase);
		
	
	public :
		void jouer();
		bool avancer(Unite* u);
		bool acheter(string caracteristique);
		void estAttaque(int valAttaque);
		void augmenterArgent(int parArgent);
		void diminuerArgent(int parArgent);
		
		int getHp();
		int getArgent();
		string getPositionBase();
		
		void setHp();
		void setArgent();
};
#endif
