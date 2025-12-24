/*
 * Ennemi.h
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */

#ifndef ENNEMI_H_
#define ENNEMI_H_

class Ennemi {
private:
	int vie_max;
	int vie;
	int force;
	int vitesse;
	int mana_max;
	int mana;
public:
	Ennemi(int vm , int mm , int f, int vi);
	virtual ~Ennemi();
};

//actions
virtual void recevoir_degats(int degats);


















#endif /* ENNEMI_H_ */
