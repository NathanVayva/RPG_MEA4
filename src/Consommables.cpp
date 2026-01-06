/*
 * Consommables.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */

#include "Consommables.hpp"

Consommables::Consommables(string nom, char abbreviation, int prix, int vie, int degats, int mana, int resistance_magique, int resistance_physique) :
Equipement(nom, abbreviation, prix) {
	this->vie = vie;
	this->degats = degats;
	this->mana = mana;
	this->resistance_magique = resistance_magique;
	this->resistance_physique = resistance_physique;
}

int Consommables::getDegats() {
	return this->degats;
}
int Consommables::getMana() {
	return this->mana;
}
int Consommables::getRes_mag() {
	return this->resistance_magique;
}
int Consommables::getRes_phys() {
	return this->resistance_physique;
}
int Consommables::getVie() {
	return this->vie;
}


