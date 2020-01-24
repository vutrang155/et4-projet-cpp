class Joueur {
	private :
		int hp;
		int argent;
		
	public :
		Joueur();
		
	
	public :
		void jouer();
		bool avancer(Unite& u);
		bool attaquer(Unite& u);
		bool acheter(Caracteristique c);
	
	
		
	public :
		int getHp();
		int getArgent();
		
	public : 
		void setHp();
		void setArgent();
}
