/*
 * Armures.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */

#include "Armures.hpp"

Armures::Armures(string nom, char abbreviation, int prix, int res_phy, int res_mag) : Equipement(nom, abbreviation, prix) {
	this->resistance_physique = res_phy;
	this->resistance_magique = res_mag;
}

int Armures::getRes_magique() {
	return this->resistance_magique;
}

int Armures::getRes_physique() {
	return this->resistance_physique;
}
