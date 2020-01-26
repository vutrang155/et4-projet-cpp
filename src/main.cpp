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


void testAvancer();
void testAttaquerFantassin();
void testAttaquerCatapulte();
void testAchat();


int main()
{
    //testAvancer();
    //testAttaquerCatapulte();
    testAttaquerFantassin();
    //testAttaquerCatapulte();

    //testAchat();

    return 0;

}

void testAchat()
{
    Joueur *joueurGauche = new Joueur("Gauche");
    Joueur *joueurDroite = new Joueur("Droite");
    Jeu *jeu = new Jeu(joueurGauche, joueurDroite);

    joueurDroite->augmenterArgent(10);

    //for(int i = 0; i < 2; i++)
    //{
        
        

    jeu->achatUnite(joueurDroite);

    cout << "ARGENT : " << joueurDroite->getArgent() << endl;


        //cout << *(jeu->getUniteDuTerrain(0));
        
    //}
    


}



void testAvancer() {
    Joueur *joueurGauche = new Joueur("Gauche");
    Joueur *joueurDroite = new Joueur("Droite");
    Jeu *jeu = new Jeu(joueurGauche, joueurDroite);


    Unite *uGauche = new Unite(joueurGauche, "Archer");

    jeu->addUnite(uGauche, 1);


    Unite *uDroite = new Unite(joueurDroite, "Fantassin");
    bool aAvance = true;
    while (aAvance) {
        aAvance = jeu->avancer(uGauche);
    }

//cout << "Case 10: "  << *(jeu->getUnite(10)) << endl;


    jeu->addUnite(uDroite, 3);

/*
	cout << "Case 1: "  << *(jeu->getUnite(1)) << endl;
    cout << "Case 3: "  << *(jeu->getUnite(3)) << endl;
*/


    cout << jeu->afficher();
    jeu->avancer(uDroite);


//while

    cout << "L'unité a avancé" << endl << endl;

/*
cout << "Case 1: "  << *(jeu->getUnite(1)) << endl;
cout << "Case 2: "  << *(jeu->getUnite(2)) << endl;
 */

    jeu->avancer(uDroite);

    cout << "L'unité a avancé" << endl << endl;

/*
cout << "Case 1: "  << *(jeu->getUnite(1)) << endl;
cout << "Case 2: "  << *(jeu->getUnite(2)) << endl;
 */

    cout << jeu->afficher();
}
void testAttaquerFantassin() {
    Joueur *joueurGauche = new Joueur("Gauche");
    Joueur *joueurDroite = new Joueur("Droite");
    Jeu *jeu = new Jeu(joueurGauche, joueurDroite);

    // Creer une unite pour le joueur 1
    /*
    Unite *uGauche = new Unite(joueurGauche, "Archer");
    jeu->addUnite(uGauche, 4);
    Unite *uGauche1 = new Unite(joueurGauche, "Fantassin");
    jeu->addUnite(uGauche1, 5);
    Unite *uDroite = new Unite(joueurDroite, "Fantassin");
    jeu->addUnite(uDroite, 6);
     */
    Unite *uGauche = new Unite(joueurGauche, "Archer");
    jeu->addUnite(uGauche, 10);
    cout << jeu->afficher();
    //bool aAvance = true;
    //bool aAvance2 = true;

    /*
    while (aAvance && aAvance2) {
        aAvance = jeu->avancer(uGauche);
        aAvance2 = jeu->avancer(uDroite);
    }
     */


    cout << jeu->afficher();
    // Attaquer :
    jeu->attaquer(uGauche);
    jeu->attaquer(uGauche);
    jeu->attaquer(uGauche);
    cout << "attaque j1.1 -> j2.0\n";
    cout << jeu->afficher();
}

void testAttaquerCatapulte() {
    Joueur *joueurGauche = new Joueur("Gauche");
    Joueur *joueurDroite = new Joueur("Droite");
    Jeu *jeu = new Jeu(joueurGauche, joueurDroite);
    // Creer une unite pour le joueur 1
    Unite *uGauche = new Unite(joueurGauche, "Catapulte");
    jeu->addUnite(uGauche, 2);
    Unite *uGauche2 = new Unite(joueurGauche, "Fantassin");
    jeu->addUnite(uGauche2, 4);
    Unite *uDroite = new Unite(joueurDroite, "Fantassin");
    jeu->addUnite(uDroite, 5);
    Unite *uDroite2= new Unite(joueurDroite, "Fantassin");
    jeu->addUnite(uDroite2, 6);
    cout << jeu->afficher();

    cout << jeu->afficher();
    // Attaquer :
    jeu->attaquer(uGauche);
    cout << "attaque j1.1 -> j2.0\n";
    cout << jeu->afficher();
}