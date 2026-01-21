#include "Mage.hpp"


Mage::Mage(std::string nom)
    : Personnage(nom, "🧙 ", 70, 6, 100),
      puissanceMagique(20),
      coutSort(15)
{
}

int Mage::getPuissanceMagique() const {
    return puissanceMagique;
}

bool Mage::lancerSort(Creature* cible) {
    if (!cible || cible->getVie() <= 0)
        return false;

    if (getMagie() < coutSort)
        return false;

    setMagie(getMagie() - coutSort);

    int degats = getForce() + puissanceMagique;
    cible->setVie(cible->getVie() - degats);
    return true;
}

string Mage::description() const {
    return "<" + this->getNom() + "> (Vie: " + to_string(this->getVie()) + "/" + to_string(this->getVieMax()) + ")";
}

bool Mage::taper(Creature* cible) {
    return lancerSort(cible);   // le mage attaque toujours par magie
}

std::string Mage::fullDescription() const {
    return "Mage " + getNom() + " " + getAbbreviation() +
           " (Vie " + std::to_string(getVie()) + "/" + std::to_string(getVieMax()) +
           ", Mana " + std::to_string(getMagie()) + "/" + std::to_string(getMagieMax()) +
           ", Puissance magique " + std::to_string(puissanceMagique) + ")";
}
