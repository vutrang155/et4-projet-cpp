#ifndef JOUEUR_H
#define JOUEUR_H
#include "Unite.hpp"
class Joueur {
	private :
		int hp;
		int argent;
		
	public :
		Joueur();

		void jouer();
		bool avancer(Unite& u);
		bool attaquer(Unite& u);
		bool acheter(Caracteristique c);
		
		int getHp();
		int getArgent();
		
		void setHp();
		void setArgent();
};
#endif
