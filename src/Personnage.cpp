#include "Personnage.hpp"

Personnage::Personnage(string nom, string abbreviation, int vieMax, int force, int magieMax)
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


vector<Consommables> Personnage::getInventaire() const {
	return this->inventaire;
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


void Personnage::setInventaire(vector<Consommables> nouvelInventaire) {
	this->inventaire = nouvelInventaire;
}

void Personnage::addObjet(const Consommables &c)
{
	this->inventaire.push_back(c);
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

bool Personnage::utiliserObjet(Creature* cible)
{
	this->afficherInventaire();

	cout<<"Quel emplacement d'objet utiliser ? " << endl;

	long unsigned int emplacement;
	cin >> emplacement;

    if (emplacement >= this->inventaire.size()) {
        cout << "emplacement hors inventaire" << endl;
        return false;
    }

    Consommables objet = this->inventaire[emplacement]; // copie volontaire

    cout << "vous utilisez " << objet.getNom() << endl;

    if (objet.getDegats() != 0) {
        cout << "vous infligez " << objet.getDegats() << " dégâts" << endl;
        cible->setVie(cible->getVie() - objet.getDegats());
    }

    if (objet.getVie() != 0) {
        cout << "vous vous soignez de " << objet.getVie() << " points de vie" << endl;
        this->setVie(this->getVie() + objet.getVie());
    }

    if (objet.getMana() != 0) {
        cout << "vous retrouvez " << objet.getMana() << " points de mana" << endl;
        this->setMagie(this->getMagie() + objet.getMana());
    }

    // Suppression APRÈS utilisation
    this->inventaire.erase(this->inventaire.begin() + emplacement);

    if (cible->getVie() <= 0) {
        cible->setVie(0);
        cout << cible->getNom() << " est vaincu !" << endl;
        return true;
    }

    return false;
}


void Personnage::afficherInventaire()
{
	vector<Consommables> inventaire = this->getInventaire() ;

	cout<<"				INVENTAIRE:"<< endl;

	for (long unsigned int i=0; i< inventaire.size(); i++)
	{
		cout<< i << ": " << inventaire[i].getNom() << endl;
	}
}





