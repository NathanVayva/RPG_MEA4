#include "Voleur.hpp"
#include <random>

Voleur::Voleur(std::string nom)
    : Personnage(nom, "🥷 ", 80, 12, 30),
      chanceEsquive(0.30f),
      chanceCritique(0.40f)
{
}

float Voleur::getChanceEsquive() const {
    return chanceEsquive;
}

float Voleur::getChanceCritique() const {
    return chanceCritique;
}

string Voleur::description() const {
    return "<" + this->getNom() + "> (Vie: " + to_string(this->getVie()) + "/" + to_string(this->getVieMax()) + ")";
}

bool Voleur::taper(Creature* cible) {
    if (!cible || cible->getVie() <= 0)
        return false;

    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    int degats = getForce();

    if (dis(gen) < chanceCritique) {
        degats *= 3;   // gros backstab
    }

    cible->setVie(cible->getVie() - degats);
    return true;
}

std::string Voleur::fullDescription() const {
    return "Voleur " + getNom() + " " +
           getAbbreviation() +
           " (Vie " + std::to_string(getVie()) + "/" + std::to_string(getVieMax()) +
           ", Force " + std::to_string(getForce()) +
           ", Crit " + std::to_string(int(chanceCritique * 100)) +
           "%, Esquive " + std::to_string(int(chanceEsquive * 100)) + "%)";
}
