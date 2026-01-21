#include "Creature.hpp"

class Zombie : public Creature {
private:

public:
    Zombie(string nom, int vieMax, int force, int xp, int argent );



    bool mordre(Creature* cible) ;
    bool taper(Creature* cible) override;
    string description() const override;
    string fullDescription() const override;
};
