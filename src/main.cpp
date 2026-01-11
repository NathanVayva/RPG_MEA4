/*
 * main.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */

#include "Armes.hpp"
#include "Armures.hpp"
#include "Piece.hpp"
#include "Creature.hpp"
#include "Personnage.hpp"
#include "Carte.hpp"
#include "Game.hpp"
#include "Guerrier.hpp"

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
			hero = new Guerrier();
			break;
		case '2':
			// Mage hero = Mage();
			cout << "Mage selected" << endl;
			break;
		case '3':
			// Mage hero = Voleur();
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


