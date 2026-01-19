#include "Creature.hpp"

Creature::Creature(string nom,string abbreviation, int vieMax, int force, int xp, int argent) : Element(nom, abbreviation) {
    this->vieMax = vieMax;
    this->vie = vieMax;
    this->force = force;
    this->xp = xp;
    this->argent = argent;
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

int Creature::getXp() const {
    return this->xp;
}


int Creature::getArgent() const {
    return this->argent;
}

Armes Creature::getArme() const {
	return this->arme;
}

Armures Creature::getArmure() const {
	return this->armure;
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

void Creature::setXp(int nouvelXp) {
    this->xp = nouvelXp;
}

void Creature::setArgent(int nouvelArgent) {
    this->argent = nouvelArgent;
}

void Creature::setArme(Armes nouvelleArme) {
	this->arme = nouvelleArme;
}

void Creature::setArmure(Armures nouvelleArmure) {
	this->armure = nouvelleArmure;
}





bool Creature::taper(Creature* cible) const {
    // Inflige des dégâts à la cible et retourne true si la cible est vaincue, faux sinon.
    cible->setVie(cible->getVie() - max( 0, (this->force + this->arme.getDegats()) - cible->getArmure().getRes_physique()));
    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    else {
        return false; // La cible est toujours en vie
    }
}

string Creature::fullDescription() const {
    return "<" + std::string(this->getNom()) + "> (Vie: " + to_string(this->vie) + "/" + to_string(this->vieMax) + ", Force: " + to_string(this->force) + ")";
}
