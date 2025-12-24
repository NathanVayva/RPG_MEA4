/*
 * Guerrier.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */

#include "Guerrier.h"
#include "Personnage.hpp"
#include "Ennemi.h"

Guerrier::Guerrier(const string nom	)
: Personnage(nom, /*viemax*/ 120, /*mana max*/20, /*force*/ 10, /*vitesse*/ 5 )
{
}

Guerrier::~Guerrier() = default;

// actions
void Guerrier::attaquer (Ennemi& cible )
{
	cible.recevoir_degats(calcule_degats())
}

int Guerrier::calcule_degats()
{
	return get_force;
}


















