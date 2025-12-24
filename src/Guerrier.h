/*
 * Guerrier.h
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */
#include<stdio.h>
#include<string>
#include <iostream>
#include "Personnage.hpp"
using namespace std;


#ifndef GUERRIER_H_
#define GUERRIER_H_


class Guerrier : public Personnage {
public:
	Guerrier(const string nom);
	virtual ~Guerrier();

	//actions
	void attaquer(Ennemi* cible) override;
	int calcule_degats();



};

#endif /* GUERRIER_H_ */
