#include "Element.hpp"
#include <iostream>
#ifndef CREATURE_HPP_
#define CREATURE_HPP_

class Creature : public Element {
private:
    int id;
    int vieMax;
    int vie;
    int force;
    int xp;
    int argent;
public:
    Creature(string nom,char abbreviation, int id, int vieMax, int force, int xp, int argent );
    virtual ~Creature();
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
    virtual bool taper(Creature* cible);
    virtual string description() const;
    virtual string fullDescription() const;
};

#endif /* CREATURE_HPP_ */
