#include "Creature.hpp"

#ifndef PERSONNAGE_HPP_
#define PERSONNAGE_HPP_

class Personnage : public Creature {
private:
    int xpMax;
    int niveau;
    int magieMax;
    int magie;
public:
    Personnage(string nom, char abbreviation, int vieMax, int force, int magieMax);
    ~Personnage();
    int getXpMax() const;
    int getNiveau() const;
    int getMagieMax() const;
    int getMagie() const;
    void setXpMax(int nouvelXpMax);
    void setNiveau(int nouveauNiveau);
    void setMagieMax(int nouvelleMagieMax);
    void setMagie(int nouvelleMagie);
    bool taper(Creature* cible) override;
    string description() const override;
    string fullDescription() const override;
};

#endif /* PERSONNAGE_HPP_ */