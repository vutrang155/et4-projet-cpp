enum Caracteristique {
	Fantassin,
	Archer,
	Catapulte,
	SSoldat
};

class Unite {
	
	public :
		static int currentId = 0;
	
	private :
		int id;
		Joueur joueur;
		Caracteristique c;
		int hp;
		int att;
		int portee;
		
		
	public :
		Unite(Joueur parJoueur, Caracteristique parC);

		/**
		 * Enlever les points de vie de ce joueur
		 * param :	a : points d'attaque de l'enemi
		 **/
		void estAttaque(int);
		
	public :
		int getId();
		Joueur getJoueur();
		Caracteristique getC();
		int getHp();
		int getAtt();
		int getPortee();
		
	public :
		void setJoueur(Joueur parJoueur);
		void setC(Caracteristique parC);
		void setHp(int parHp);
		void setAtt(int parAtt);
		void setPortee(int parPortee);
}
