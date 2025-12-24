/*
 * personnage.h
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */
#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

class Ennemi;

class Personnage {
private:
	string nom;
	int vie_max;
	int vie;
	int force;
	int vitesse;
	int mana_max;
	int mana;

public:
	Personnage(string n, int vm , int f, int vi,int mm );
	virtual ~Personnage();

	//actions
	void virtual attaquer(Ennemi* cible);

	//getters
	int get_vie_max();
	int get_vie();
	int get_force();
	int get_vitesse();
	int get_mana();
	int get_mana_max();
	string get_nom();

	//setters
	void set_vie_max(int new_vie);
	void set_vie(int new_vie);
	void set_force(int new_force);
	void set_vitesse(int new_vitesse);
	void set_mana(int new_mana);
	void set_mana_max(int new_mana);
	void set_nom(string new_nom);


};

#endif /* PERSONNAGE_H_ */
