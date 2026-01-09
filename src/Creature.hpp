#include "Element.hpp"

#ifndef CREATURE_HPP_
#define CREATURE_HPP_

class Creature : public Element {
private:
    int vieMax;
    int vie;
    int force;
    int xp;
    int argent;
public:
    Creature(string nom,char abbreviation, int vieMax, int force, int xp, int argent );
    int getVieMax() const;
    int getVie() const;
    int getForce() const;
    int getXp() const;
    int getArgent() const;
    void setVie(int nouvelleVie);
    void setVieMax(int nouvelleVieMax);
    void setForce(int nouvelleForce);
    void setXp(int nouvelXp);
    void setArgent(int nouvelArgent);
    bool taper(Creature* cible) const;
    string fullDescription() const;
};

#endif /* CREATURE_HPP_ */
