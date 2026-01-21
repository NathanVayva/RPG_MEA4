#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Personnage.hpp"

class Mage : public Personnage {
private:
    int puissanceMagique;     // bonus de dégâts des sorts
    int coutSort;            // mana consommée par sort
public:
    Mage(std::string nom);

    int getPuissanceMagique() const;

    bool lancerSort(Creature* cible);
    
    bool taper(Creature* cible) override;
    string description() const override;
    string fullDescription() const override;
};

#endif
