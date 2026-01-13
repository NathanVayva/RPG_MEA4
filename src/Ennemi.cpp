/*
 * Ennemi.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */

#include "Ennemi.hpp"


Ennemi::Ennemi( string nom, char abbreviation, int force, int viemax, int xp, int argent)
    : Creature(nom, abbreviation, force, viemax, argent, xp){
};

Ennemi::~Ennemi() = default;


//actions

bool Ennemi::taper(Creature* cible) {
    // Implémentation de la méthode taper pour Ennemi
    return cible->setVie(cible->getVie() - this->getForce()), cible->getVie() <= 0;
}













