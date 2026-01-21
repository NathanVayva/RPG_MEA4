#ifndef VOLEUR_HPP_
#define VOLEUR_HPP_

#include "Personnage.hpp"

class Voleur : public Personnage {
private:
    float chanceEsquive;   // 0.0 → 1.0
    float chanceCritique;
public:
    Voleur(std::string nom);

    float getChanceEsquive() const;
    float getChanceCritique() const;

    bool taper(Creature* cible) override;
    string description() const override;
    string fullDescription() const override;
};

#endif
