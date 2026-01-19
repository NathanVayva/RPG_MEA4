/*
 * Equipement.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */

#include "Equipement.hpp"

Equipement::Equipement(string nom, string abbreviation, int prix) : Element(nom, abbreviation) {
	this->prix = prix;
}

Equipement::~Equipement() {}

int Equipement::getPrix() {
	return this->prix;
}
