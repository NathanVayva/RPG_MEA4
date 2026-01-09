#include "Personnage.hpp"

Personnage::Personnage(string nom, char abbreviation, int vieMax, int force, int magieMax)
    : Creature(nom, abbreviation, vieMax, force, 0, 0) {
    this->niveau = 1;
    this->xpMax = this->niveau * 20;
    this->magieMax = magieMax;
    this->magie = magieMax;
}


int Personnage::getXpMax() const {
    return this->xpMax;
}

int Personnage::getNiveau() const {
    return this->niveau;
}

int Personnage::getMagieMax() const {
    return this->magieMax;
}

int Personnage::getMagie() const {
    return this->magie;
}



void Personnage::setXpMax(int nouvelXpMax) {
    this->xpMax = nouvelXpMax;
}

void Personnage::setNiveau(int nouveauNiveau) {
    this->niveau = nouveauNiveau;
}

void Personnage::setMagie(int nouvelleMagie) {
    this->magie = nouvelleMagie;
}

void Personnage::setMagieMax(int nouvelleMagieMax) {
    this->magieMax = nouvelleMagieMax;
}

bool Personnage::taper(Creature* cible) {
    // Utilise la méthode taper de la classe Creature
    bool cibleVaincue = Creature::taper(cible);
    if (cibleVaincue) {
        // Gagne de l'XP en fonction du niveau de la créature vaincue
        this->setXp(this->getXp() + cible->getXp() );
        // Vérifie si le personnage peut monter de niveau
        if (this->getXp() >= this->getXpMax()) {
            this->setXp(this->getXp() - this->getXpMax());
            this->setNiveau(this->getNiveau() + 1);
            this->setXpMax(this->getNiveau() * 20);
            // Augmente les attributs du personnage à chaque niveau
            this->setVieMax(this->getVieMax() + this->getNiveau()*2); // Augmente la vie maximale
            this->setVie(this->getVieMax()); // Restaure la vie au maximum
            this->setForce(this->getForce() + 2); // Augmente la force
            this->setMagieMax(this->getMagieMax() + 5); // Augmente la magie maximale
            this->setMagie(this->getMagieMax()); // Restaure la magie au maximum
        }
        // Gagne de l'or
        this->setArgent(this->getArgent() + cible->getArgent() );
    }
    return cibleVaincue;
}

string Personnage::fullDescription() const {
    return "<" + this->getNom() + "> (Vie: " + to_string(this->getVie()) + "/" + to_string(this->getVieMax()) +
           ", Force: " + to_string(this->getForce()) +
           ", Magie: " + to_string(this->getMagie()) + "/" + to_string(this->getMagieMax()) +
           ", XP: " + to_string(this->getXp()) + "/" + to_string(this->getXpMax()) +
           ", Niveau: " + to_string(this->getNiveau()   ) + ")";
}
