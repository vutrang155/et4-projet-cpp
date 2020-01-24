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
		Joueur(Jeu& parJeu, PositionBase parPositionBase);
		
	
	public :
		void jouer();
		bool avancer(Unite& u);
		bool attaquer(Unite& u);
		bool acheter(Caracteristique c);
	
	
		
	public :
		int getHp();
		int getArgent();
		PositionBase getPositionBase();
		
	public : 
		void setHp();
		void setArgent();
}
