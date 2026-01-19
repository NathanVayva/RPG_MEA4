/*
 * Consommables.hpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */
#include "Equipement.hpp"

#ifndef CONSOMMABLES_HPP_
#define CONSOMMABLES_HPP_


class Consommables : public Equipement {
private:
	int vie;
	int degats;
	int mana;
	int resistance_magique;
	int resistance_physique;

public:
	Consommables(string nom, string abbreviation, int prix, int vie, int degats, int mana, int resistance_magique, int resistance_physique);
	int getVie();
	int getDegats();
	int getMana();
	int getRes_mag();
	int getRes_phys();
};


#endif /* CONSOMMABLES_HPP_ */
