#ifndef GUERRIER_HPP_
#define GUERRIER_HPP_

#include "Personnage.hpp"

class Guerrier : public Personnage {
private:
    float tauxCritique;   // entre 0 et 1
public:
    Guerrier(std::string nom);

    int getBonusForce() const;
    float getTauxCritique() const;

    bool taper(Creature* cible) override;
    string description() const override;
    string fullDescription() const override;
};

#endif
