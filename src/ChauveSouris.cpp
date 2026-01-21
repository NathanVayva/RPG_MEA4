#include "ChauveSouris.hpp"

ChauveSouris::ChauveSouris(string nom, int vieMax, int force, int xp, int argent)
    : Creature(nom, "🦇 ", vieMax, force, xp, argent) {
}


bool ChauveSouris::taper(Creature* cible) {
    return ChauveSouris:: voleVie(cible);
}

bool ChauveSouris::voleVie(Creature* cible) {
    int vieVolee = max( 0, (this->getForce() + this->getArme().getDegats()) - cible->getArmure().getRes_physique());
    this->setVie(std::min(this->getVie() + vieVolee, this->getVieMax()));

    // Inflige des dégâts à la cible et retourne true si la cible est vaincue, faux sinon.
    cible->setVie(cible->getVie() - vieVolee);
    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    else {
        return false; // La cible est toujours en vie
    }
}

string ChauveSouris::description() const {
    return "<" + this->getNom() + "> (Vie: " + to_string(this->getVie()) + "/" + to_string(this->getVieMax()) + ")";
}

string ChauveSouris::fullDescription() const {
        return "<" + std::string(this->getNom()) + "> (Vie: " + to_string(this->getVie()) + "/" + to_string(this->getVieMax()) + ", Force: " + to_string(this->getForce()) + ")";
}
