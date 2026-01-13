#include "Vampire.hpp"

Vampire::Vampire(string nom, int vieMax, int force, int xp, int argent)
    : Creature(nom, '🧛', vieMax, force, xp, argent) {
}


bool Vampire::taper(Creature* cible) {
    return Vampire:: voleVie(cible);
}

bool Vampire::voleVie(Creature* cible) {
    int vieVolee = int(this->getForce() / 2 ) + 1;
    this->setVie(std::min(this->getVie() + vieVolee, this->getVieMax()));

    cible->setVie(cible->getVie() - vieVolee);
    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    return false; // La cible est toujours en vie
}