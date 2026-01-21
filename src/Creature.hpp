#include "Element.hpp"
#include "Armes.hpp"
#include "Armures.hpp"

#ifndef CREATURE_HPP_
#define CREATURE_HPP_

class Creature : public Element {
private:
    int vieMax;
    int vie;
    int force;
    int xp;
    int argent;
    Armes arme = Armes("rien","r", 0,0,0);
    Armures armure = Armures("à poil","ap", 0,0,0);
public:
    Creature(string nom,string abbreviation, int vieMax, int force, int xp, int argent );
    int getVieMax() const;
    int getVie() const;
    int getForce() const;
    int getXp() const;
    int getArgent() const;
    Armes getArme() const;
    Armures getArmure() const;
    void setVie(int nouvelleVie);
    void setVieMax(int nouvelleVieMax);
    void setForce(int nouvelleForce);
    void setXp(int nouvelXp);
    void setArgent(int nouvelArgent);
    void setArme(Armes nouvelleArme);
    void setArmure(Armures nouvelleArmure);
    virtual bool taper(Creature* cible);
    virtual string description() const;
    virtual string fullDescription() const;
};

#endif /* CREATURE_HPP_ */
