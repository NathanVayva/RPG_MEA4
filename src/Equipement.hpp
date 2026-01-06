/*
 * Equipement.hpp
 *
 *  Created on: 16 déc. 2025
 *      Author: mea
 */
#include "Element.hpp"

#ifndef EQUIPEMENT_HPP_
#define EQUIPEMENT_HPP_

class Equipement : public Element {
private:
	int prix;
public:
	Equipement(string nom, char abbreviation, int prix);
	virtual ~Equipement();
	int getPrix();
};



#endif /* EQUIPEMENT_HPP_ */
