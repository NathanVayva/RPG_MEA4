/*
 * Armures.hpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */
#include "Equipement.hpp"

#ifndef ARMURES_HPP_
#define ARMURES_HPP_

class Armures : public Equipement {
private :
	int resistance_physique;
	int resistance_magique;

public:
	Armures(string nom, string abbreviation, int prix, int resistance_physique, int resistance_magique);
	int getRes_physique();
	int getRes_magique();
};




#endif /* ARMURES_HPP_ */
