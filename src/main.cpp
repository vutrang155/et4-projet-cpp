#include <iostream>
#include <string.h>
#include <array>
#include <vector>

#include "Jeu.hpp"
#include "Unite.hpp"
#include "Joueur.hpp"

int main()
{
	Jeu* jeu = new Jeu();

	Joueur* joueur = new Joueur(jeu,"Gauche");

	
	Unite* u = new Unite(joueur,"Fantassin");
	

	jeu->addUnite(u,1);

	cout << "Case 1:"  << *(jeu->getUnite(1));

	jeu->avancer(u,"->");

	printf("L'unité a avancé");

	cout << "Case 1:"  << *(jeu->getUnite(1));
	cout << "Case 2:"  << *(jeu->getUnite(2));


	return 0;
}
