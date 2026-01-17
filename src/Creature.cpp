#include "Creature.hpp"

Creature::Creature(string nom,char abbreviation, int id, int vieMax, int force, int argent, int xp) : Element(nom, abbreviation) {
    this->id = id;
    this->vieMax = vieMax;
    this->vie = vieMax;
    this->force = force;
    this->xp = xp;
    this->argent = argent;
}

Creature::~Creature() {
    cout << "<"  << this->getNom() << "> a ete vaincu" << endl;
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

bool Creature::taper(Creature* cible) {
    // Inflige des dégâts à la cible et retourne true si la cible est vaincue, faux sinon.
    cible->setVie(cible->getVie() - this->force);
    // Affichage pour joueur
    cout << this->description() << " attaque " << cible->description() << endl;
    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    else {
        return false; // La cible est toujours en vie
    }
}

string Creature::description() const {
    return "<" + this->getNom() + "> (Vie: " + to_string(this->vie) + "/" + to_string(this->vieMax) + ")";
}

string Creature::fullDescription() const {
    return "<" + std::string(this->getNom()) + "> (Vie: " + to_string(this->vie) + "/" + to_string(this->vieMax) + ", Force: " + to_string(this->force) + ")";
}
