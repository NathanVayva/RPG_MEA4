#include "Creature.hpp"
#include "Consommables.hpp"
#include "Armes.hpp"
#include "Armures.hpp"
#include <random>

#include <vector>

#ifndef PERSONNAGE_HPP_
#define PERSONNAGE_HPP_



class Personnage : public Creature {
private:
    int xpMax;
    int niveau;
    int magieMax;
    int magie;
    std::vector<Consommables> inventaire;
public:
    Personnage(string nom, string abbreviation, int vieMax, int force, int magieMax);
    int getXpMax() const;
    int getNiveau() const;
    int getMagieMax() const;
    int getMagie() const;
    vector<Consommables> getInventaire() const;
    void setXpMax(int nouvelXpMax);
    void setNiveau(int nouveauNiveau);
    void setMagieMax(int nouvelleMagieMax);
    void setMagie(int nouvelleMagie);
    void setInventaire(vector<Consommables> nouvelInventaire);
    void addObjet(const Consommables &c);
    void afficherInventaire();
    void magasin(unsigned int seed);



    bool taper(Creature* cible);
    string fullDescription() const;

    bool utiliserObjet( Creature* cible);









};

#endif /* PERSONNAGE_HPP_ */
