/*
 * Armes.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */

#include "Armes.hpp"

Armes::Armes(string nom, string abbreviation, int prix, int degats, int magie) : Equipement(nom, abbreviation, prix) {
	this->degats = degats;
	this->magie = magie;
}

int Armes::getDegats() const {
	return this->degats;
}

int Armes::getMagie() const {
	return this->magie;
}
