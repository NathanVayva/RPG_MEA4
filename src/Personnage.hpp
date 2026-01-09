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
    int getXp() const;
    int getXpMax() const;
    int getNiveau() const;
    int getMagieMax() const;
    int getMagie() const;
    int getArgent() const;
    void setArgent(int nouveauArgent);
    void setXp(int nouvelXp);
    void setXpMax(int nouvelXpMax);
    void setNiveau(int nouveauNiveau);
    void setMagieMax(int nouvelleMagieMax);
    void setMagie(int nouvelleMagie);
    bool taper(Creature* cible);
    string fullDescription() const;
};

#endif /* PERSONNAGE_HPP_ */
