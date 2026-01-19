#include "Guerrier.hpp"
#include <random>

Guerrier::Guerrier(std::string nom)
    : Personnage(nom, "🧔 ", 120, 15, 20),
      tauxCritique(0.20f)
{
}


float Guerrier::getTauxCritique() const {
    return tauxCritique;
}

bool Guerrier::taper(Creature* cible) {
    if (!cible || cible->getVie() <= 0)
        return false;

    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    int degats = getForce() ;

    if (dis(gen) < tauxCritique) {
        degats *= 2;  // coup critique
    }

    cible->setVie(cible->getVie() - degats);
    return true;
}

std::string Guerrier::fullDescription() const {
    return "Guerrier " + getNom() + " " +
           getAbbreviation() +
           " (Vie " + std::to_string(getVie()) + "/" + std::to_string(getVieMax()) +
           ", Force " + std::to_string(getForce()) +
           ", Crit " + std::to_string(int(tauxCritique * 100)) + "%)";
}
