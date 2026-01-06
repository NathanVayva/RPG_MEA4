/*
 * Armes.hpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */

#ifndef ARMES_HPP_
#define ARMES_HPP_

#include "Equipement.hpp"

class Armes : public Equipement {
private:
	int degats;
	int magie;
public:
	Armes(string nom, char abbreviation, int prix, int degats,int magie);
	int getDegats();
	int getMagie();
};

#endif /* ARMES_HPP_ */
