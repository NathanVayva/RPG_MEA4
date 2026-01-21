///*
// * main.cpp
// *
// *  Created on: 16 déc. 2025
// *      Author: mea
// */
//
#include "Armes.hpp"
#include "Armures.hpp"
#include "Piece.hpp"
#include "Creature.hpp"
#include "Personnage.hpp"
#include "Carte.hpp"
#include "Game.hpp"
#include "Guerrier.hpp"
#include "Mage.hpp"
#include "Voleur.hpp"

int main() {
	Personnage* hero = nullptr;
	bool valide = false;
	cout << "Heros choisissez votre classe :" << endl;
	cout << "1 : Guerrier" << endl;
	cout << "2 : Mage" << endl;
	cout << "3 : Voleur" << endl;
	while (valide == false) {
		char choix = getchar();
		valide = true;
		switch (choix)
		{
		case '1':
			hero = new Guerrier("Hurl");
			hero->setArgent(100);
			hero->addObjet(Consommables("Potion de vie", "pv", 10, 20, 0, 0, 0, 0));
			break;
		case '2':
			hero = new Mage("Erasmus");
			hero->setArgent(100);
			hero->addObjet(Consommables("Potion de vie", "pv", 10, 20, 0, 0, 0, 0));
			break;
		case '3':
			hero = new Voleur("Sasuke");
			hero->setArgent(100);
			hero->addObjet(Consommables("Potion de vie", "pv", 10, 20, 0, 0, 0, 0));
			cout << "Voleur selected" << endl;
			break;
		default:
			valide = false;
			break;
		}
	}
	Game jeu(hero);
	jeu.jouer();
	return 0;
}
