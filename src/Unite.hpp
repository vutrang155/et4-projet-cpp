#ifndef UNITE_H
#define UNITE_H

/*
 * #include "Joueur"
 *
 * A eviter : Circular Dependencies
 * https://stackoverflow.com/questions/7665912/double-include-solution
 */
class Joueur;

enum Caracteristique {
		Fantassin,
		Archer,
		Catapulte,
		SSoldat
};

class Unite {

		public : 
				static int currentId;
		private :
				int id;
				Joueur* joueur;
				Caracteristique c;
				int hp;
				int att;
				int portee;
				int prix;


		public :
				Unite(Joueur* parJoueur, Caracteristique parC);
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
				Caracteristique getC();
				int getHp();
				int getAtt();
				int getPortee();

				/*
				 * Setters
				 */
				void setJoueur(Joueur parJoueur);
				void setC(Caracteristique parC);
				void setHp(int parHp);
				void setAtt(int parAtt);
				void setPortee(int parPortee);
};

#endif
