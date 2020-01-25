#ifndef JOUEUR_H
#define JOUEUR_H
#include "Unite.hpp"
enum PositionBase {
	Gauche,
	Droite
};


class Joueur {
	private :
		int jeu
		int hp;
		int argent;
		PositionBase positionBase;
		
	public :
		Joueur();

		Joueur(Jeu& parJeu, PositionBase parPositionBase);
		
	
	public :
		void jouer();
		bool avancer(Unite& u);
		bool attaquer(Unite& u);
		bool acheter(Caracteristique c);
		
		int getHp();
		int getArgent();
		PositionBase getPositionBase();
		
		void setHp();
		void setArgent();
};
#endif
