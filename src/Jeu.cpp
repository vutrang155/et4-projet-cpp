#include "Jeu.hpp"
#include <iostream>
#include <array>

#define TAILLE_TERRAIN 12

// Constructeur 
Jeu::Jeu() {
}
// Destructeur 
~Jeu::Jeu(){
}

/*
 * Deroulement du jeu 
 */
void Jeu::deroulement(){ 
}
/*
 * Renvoyer vrai si la case est libre 
 */
bool Jeu::estLibreCase(int indexCase) {
}

/*
 * Renvoyer l'index de l'unite 
 */
int Jeu::getIndex(Unite& u) {
}

/*
 * Renvoyer l'unite d'un joueur
 */
&Unite[] Jeu::getUnites(Joueur j){
}	


/*
 * Ajouter dans le terrain une unite 
 */
void Jeu::addUnite(Uniter u){
}


void Jeu::deplacerUnite(Unite &u, PositionBase positionBase)
{
	int indexUnite = getIndex(u);
	
	//Unité du joueur à gauche
	if((srtcmp(positionBase,"Gauche") && estLibreCase(indexUnite + 1)))
	{
		terrain[indexUnite + 1] = terrain[indexUnite];

	}

	//Unite du joueur à droite
	else if(srtcmp(positionBase,"Droite") && estLibreCase(indexUnite - 1) 
	{
		terrain[indexUnite - 1] = terrain[indexUnite];

	}

	//PEUT-ETRE A MODIFIER
		terrain[indexUnite] = null;

}


/*
 * Afficher le terrain
 */
string Jeu::afficher(){
	&Unite[] u1, u2; 
	string ret = "|";

	u1 = getUnites(j1);
	u2 = getUnites(j2);
	for (int i = 0; i < TAILLE_TERRAIN; i++){
		ret += "|\t";
		ret += terrain.getJoueur() == j1 ? j1+"." : j2+".";
		ret += terrain.getId(); 
		ret += "\t|";
	}
	ret += "|\n";
	ret += "Joueur 1 : \n";
	for (int i = 0; i < sizeof(u1); i++) {
			g
	}	
}

&ostream operator<<(ostrem &os, const Jeu& jeu) {
		os << afficher()
}	



