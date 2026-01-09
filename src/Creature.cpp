#include "Creature.hpp"

Creature::Creature(string nom,char abbreviation, int vieMax, int force) : Element(nom, abbreviation) {
    this->vieMax = vieMax;
    this->vie = vieMax;
    this->force = force;
}

int Creature::getVieMax() const {
    return this->vieMax;
}

int Creature::getVie() const {
    return this->vie;
}

int Creature::getForce() const {
    return this->force;
}

void Creature::setVie(int nouvelleVie) {
    this->vie = nouvelleVie;
}

void Creature::setVieMax(int nouvelleVieMax) {
    this->vieMax = nouvelleVieMax;
}

void Creature::setForce(int nouvelleForce) {
    this->force = nouvelleForce;
}

bool Creature::taper(Creature* cible) const {
    // Inflige des dégâts à la cible et retourne true si la cible est vaincue, faux sinon.
    cible->setVie(cible->getVie() - this->force);
    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    else {
        return false; // La cible est toujours en vie
    }
}

string Creature::fullDescription() const {
    return "<" + this->getNom() + "> (Vie: " + to_string(this->vie) + "/" + to_string(this->vieMax) + ", Force: " + to_string(this->force) + ")";
}