#include <iostream>
#include <string.h>
#include <array>
#include <vector>

#include "Jeu.hpp"
#include "Unite.hpp"
#include "Joueur.hpp"


using namespace std;

/*ostream& operator<<(ostream& os, Jeu& jeu)
{
	os << jeu.afficher();

	return os;
}
*/

ostream& operator<<(ostream& os, Unite& u) {
		os << u.getCaracteristique() << " " << u.getId();
        os << ", Joueur " << u.getJoueur()->getPositionBase();
		os << ", HP : " << u.getHp();
		os << endl;

		return os;

}	

int main()
{
	Jeu* jeu = new Jeu();

	Joueur* joueurGauche = new Joueur(jeu,"Gauche");

    Joueur* joueurDroite = new Joueur(jeu,"Droite");

	
	Unite* uGauche = new Unite(joueurGauche,"Fantassin");
	
	jeu->addUnite(uGauche,1);


    Unite* uDroite = new Unite(joueurDroite,"Fantassin");

    
    

/*
    bool aAvance = true;

    while(aAvance)
    {
        aAvance = jeu->avancer(uGauche);
    }

    cout << "Case 10: "  << *(jeu->getUnite(10)) << endl; 
*/



/*

    jeu->addUnite(uDroite,3);

	cout << "Case 1: "  << *(jeu->getUnite(1)) << endl;
    cout << "Case 3: "  << *(jeu->getUnite(3)) << endl;



	jeu->avancer(uDroite);

    while

	cout << "L'unité a avancé" << endl << endl;

	cout << "Case 1: "  << *(jeu->getUnite(1)) << endl;
	cout << "Case 2: "  << *(jeu->getUnite(2)) << endl;

    jeu->avancer(uDroite);

    cout << "L'unité a avancé" << endl << endl;

	cout << "Case 1: "  << *(jeu->getUnite(1)) << endl;
	cout << "Case 2: "  << *(jeu->getUnite(2)) << endl;

*/


	cout << jeu->afficher();

	return 0;
}
