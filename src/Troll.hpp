    #include "Creature.hpp"

class Troll : public Creature {
private:

public:
    Troll(string nom, int vieMax, int force, int xp, int argent );



    bool mordre(Creature* cible) ;
    bool taper(Creature* cible) override;
    string description() const override;
    string fullDescription() const override;
};
