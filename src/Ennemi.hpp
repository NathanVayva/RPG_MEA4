/*
 * Ennemi.h
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */

#include "Creature.hpp"

#ifndef ENNEMI_HPP_
#define ENNEMI_HPP_

class Ennemi : public Creature{
private:

public:
	Ennemi( string nom, char abbreviation, int force, int viemax, int xp, int argent);
	virtual ~Ennemi();

	//actions
	bool taper(Creature* cible);
};

//actions
bool taper(Creature* cible);


















#endif /* ENNEMI_HPP_ */
