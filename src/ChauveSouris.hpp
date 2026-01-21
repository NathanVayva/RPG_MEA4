#include "Creature.hpp"

class ChauveSouris : public Creature {
private:

public:
    ChauveSouris(string nom, int vieMax, int force, int xp, int argent );



    bool voleVie(Creature* cible) ;
    bool taper(Creature* cible) override;
    string description() const override;
    string fullDescription() const override;
};
