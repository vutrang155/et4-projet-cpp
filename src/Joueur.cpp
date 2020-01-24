#include <iostream>

Joueur::Joueur()
{
	hp = 50;
	
	argent = 8;
}




void Joueur::jouer()
{
	
}

bool Joueur::avancer(Unite& u)
{
	
}

bool Joueur::attaquer(Unite& u)
{
	
}

bool Joueur::acheter(Caracteristique c)
{
	
}


		

int Joueur::getHp()
{
	return hp;
}


int Joueur::getArgent()
{
	return argent;
}








void Joueur::setHp(int parHp)
{
	hp = parHp;
}

void Joueur::setArgent(int parArgent)
{
	argent = parArgent;
}



}
