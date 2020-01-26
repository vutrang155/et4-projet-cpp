#include <iostream>
#include <string.h>
#include <array>
#include <vector>

#include "Jeu.hpp"
#include "Unite.hpp"
#include "Joueur.hpp"


using namespace std;

ostream& operator<<(ostream& os, Jeu& jeu) 
{
	os << jeu.afficher();

	return os;
}	

ostream& operator<<(ostream& os, Unite& u) {
		os << u.getCaracteristique() << " " << u.getId() << endl;
		os << "HP : " << u.getHp() << endl;
		os << endl;

		return os;

}	

int main()
{
	Jeu* jeu = new Jeu();

	Joueur* joueur = new Joueur(jeu,"Gauche");

	
	Unite* u = new Unite(joueur,"Fantassin");
	
    
	jeu->addUnite(u,1);

    

	cout << "Case 1:"  << *(jeu->getUnite(1)) << endl;



	jeu->avancer(u,"->");

	cout << "L'unité a avancé" << endl;;

	//cout << "Case 1:"  << *(jeu->getUnite(1)) << endl;
	cout << "Case 2:"  << *(jeu->getUnite(2))




	return 0;
}
