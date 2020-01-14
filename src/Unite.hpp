enum Characteristique {
	Fantassin,
	Archer,
	Catapulte,
	SSoldat
};

class Unite {
	private :
		Joueur joueur;
		Characteristique c;
		int hp;
		int att;
		int p;
	public :
		Unite(joueur);

		/**
		 * Enlever les points de vie de ce joueur
		 * param :	a : points d'attaque de l'enemi
		 **/
		void estAttaque(int);
}
