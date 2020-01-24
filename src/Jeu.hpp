#ifndef JEU_H
#define JEU_H

#include <string.h>
#include "Joueur.hpp"
#include "Unite.hpp"

class Jeu {
	private :
		Unite[] terrain;
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
		bool estLibreCase(...);

		/*
		 * Renvoyer l'index de l'unite 
		 */
		Unite &getUnite(int i);

		/*
		 * Renvoyer l'index de l'unite 
		 */
		int getIndex(Unite& u);
		/*
		 * Renvoyer l'unite d'un joueur
		 */
		&Unite[] getUnites(Joueur j);	

		/*
		 * Ajouter dans le terrain une unite 
		 */
		void addUnite(Uniter u);

		/*
		 * Afficher le terrain
		 */
		string afficher()

		friend &ostream operator<<(ostrem &os, const Jeu& jeu); 
}

#endif
