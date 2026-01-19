#include "Zombie.hpp"
#include <random>

Zombie::Zombie(string nom, int vieMax, int force, int xp, int argent)
    : Creature(nom, "🧟‍♂️", vieMax, force, xp, argent) {
}


bool Zombie::taper(Creature* cible) {
    return Zombie:: mordre(cible);
}

bool Zombie::mordre(Creature* cible) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dice(1, 6);

    int degatInfection = 0;

    if (dice(gen) == 1) { // 1 sur 6 de chance d'infecter la cible
        degatInfection = 5; // Dégâts d'infection
    }

    cible->setVie(cible->getVie() - max( 0, (this->getForce() + this->getArme().getDegats()) - cible->getArmure().getRes_physique()) + degatInfection);

    if (cible->getVie() <= 0) {
        return true; // La cible est vaincue
    }
    return false; // La cible est toujours en vie
}
