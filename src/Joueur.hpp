#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string.h>



using namespace std;

class Jeu;

class Unite;


class Joueur {
	private :
		int hp;
		int argent;
		string positionBase;
		
	public :
		Joueur();

		Joueur(string parPositionBase);
		
	
	public :
		void jouer();
		void acheter(string caracteristique);
		bool estAttaque(int valAttaque);
		void augmenterArgent(int parArgent);
		void diminuerArgent(int parArgent);
		
		int getHp();
		int getArgent();
		string getPositionBase();
		
		void setHp(int parHp);
		void setArgent();
};
#endif
