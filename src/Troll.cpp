#include "Troll.hpp"
#include <random>

Troll::Troll(string nom, int vieMax, int force, int xp, int argent)
    : Creature(nom, "🧌 ", vieMax, force, xp, argent) {
}

string Troll::description() const {
    return "<" + this->getNom() + "> (Vie: " + to_string(this->getVie()) + "/" + to_string(this->getVieMax()) + ")";
}

bool Troll::taper(Creature* cible) {
    // Inflige des dégâts à la cible et retourne true si la cible est vaincue, faux sinon.
    cible->setVie(cible->getVie() - max( 0, (this->getForce() + this->getArme().getDegats()) - cible->getArmure().getRes_physique()));
    cout << this->description() << " attaque " << cible->description() << endl;
    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    else {
        return false; // La cible est toujours en vie
    }
}

string Troll::fullDescription() const {
        return "<" + std::string(this->getNom()) + "> (Vie: " + to_string(this->getVie()) + "/" + to_string(this->getVieMax()) + ", Force: " + to_string(this->getForce()) + ")";
}




