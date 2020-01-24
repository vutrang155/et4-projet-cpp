#include <iostream>



Unite::Unite(Joueur parJoueur)
{
	id = currentId;
	
	currentId++;
	
	joueur = parJoueur;
}








void Unite::estAttaque(int)
{
	
}






int Unite::getId()
{
	return id;
}

Joueur Unite::getJoueur()
{
	return joueur;
}


Caracteristique Unite::getC()
{
	return c;
}


int Unite::getHp()
{
	return hp;
}

int Unite::getAtt()
{
	return att;
}


int Unite::getP()
{
	return p;
}








void Unite::setJoueur(Joueur parJoueur)
{
	joueur = parJoueur;
}


void Unite::setC(Caracteristique parC)
{
	c = parC
}


void Unite::setHp(int parHp)
{
	hp = parHp;
}



void Unite::setAtt(int parAtt)
{
	att = parAtt;
}


void Unite::setP(int parP)
{
	p = parP;	
}





