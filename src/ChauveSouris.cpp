#include "ChauveSouris.hpp"

ChauveSouris::ChauveSouris(string nom, int vieMax, int force, int xp, int argent)
    : Creature(nom, '🦇', vieMax, force, xp, argent) {
}


bool ChauveSouris::taper(Creature* cible) {
    return ChauveSouris:: voleVie(cible);
}

bool ChauveSouris::voleVie(Creature* cible) {
    int vieVolee = int(this->getForce() / 2 ) + 1;
    this->setVie(std::min(this->getVie() + vieVolee, this->getVieMax()));

    cible->setVie(cible->getVie() - vieVolee);
    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    return false; // La cible est toujours en vie
}