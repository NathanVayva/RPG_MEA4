    #include "Creature.hpp"

class Troll : public Creature {
private:
    int vieMax;
    int vie;
    int force;
    int xp;
    int argent;
public:
    Troll(string nom, int vieMax, int force, int xp, int argent );
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


    bool mordre(Creature* cible) ;
    bool taper(Creature* cible) ;   
    string fullDescription() const;
};