#include "Creature.hpp"

class Vampire : public Creature {
private:

public:
    Vampire(string nom, int vieMax, int force, int xp, int argent );



    bool voleVie(Creature* cible) ;
    bool taper(Creature* cible) ;
    string fullDescription() const;
};
