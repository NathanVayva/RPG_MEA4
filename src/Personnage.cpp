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

	cout<<"Quel objet voulez vous utiliser ? (-1 pour quitter)" << endl;

	long unsigned int emplacement;
	cin >> emplacement;

	if(emplacement == static_cast<long unsigned int>(-1))
	{
		cout << "Vous quittez l'utilisation d'objet." << endl;
		return false;
	}

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
        this->setVie(max(this->getVie() + objet.getVie(), this->getVieMax()));
    }

    if (objet.getMana() != 0) {
        cout << "vous retrouvez " << objet.getMana() << " points de mana" << endl;
        this->setMagie(max(this->getMagie() + objet.getMana(), this->getMagieMax()));
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

void Personnage::magasin(unsigned int seed)
{

	//unsigned int seed = 42; // valeur fixe pour reproduire la suite
    std::mt19937 gen(seed); // générateur Mersenne Twister initialisé avec la seed
    std::uniform_int_distribution<> dist(2, 4); // nombres entre 2 et 4
	int nb_objet = dist(gen);


	cout << "Bienvenue au magasin !" << nb_objet << endl;
	cout << "Votre argent: " << this->getArgent() << " pièces d'or" << endl;

	// Exemple d'objets disponibles à l'achat
	vector<Equipement*> objetsDisponibles = {	//toujours présent dans le magasin
		new Consommables("Potion de vie", "pv", 10, 20, 0, 0, 0, 0),
		new Consommables("Potion de mana", "pm", 15, 0, 0, 15, 0, 0),
		new Consommables("Bombe", "b", 25, 0, 30, 0, 0, 0)
	};

	for(int i = 0; i < nb_objet; i++)
	{
	 std::uniform_int_distribution<> id_objet(0, 9); // nombres entre 0 et 9

	 cout << "passage " << i << " / " << nb_objet << endl;

	 switch (id_objet(gen))
	 {
		 case 0:
			 objetsDisponibles.push_back(new Armes("Épée en fer", "ef", 50, 15, 0));
			 break;
		 case 1:
			 objetsDisponibles.push_back(new Armes("Bâton de mage", "bm", 60, 5, 10));
			 break;
		 case 2:
			 objetsDisponibles.push_back(new Armures("Cotte de mailles", "cm", 40, 10, 5));
			 break;
		 case 3:
			 objetsDisponibles.push_back(new Armures("Robe de sorcier", "rs", 45, 5, 15));
			 break;
		 case 4:
			 objetsDisponibles.push_back(new Consommables("Elixir de vie", "ev", 30, 50, 0, 0, 0, 0));
			 break;
		 case 5:
			 objetsDisponibles.push_back(new Consommables("Elixir de mana", "em", 35, 0, 0, 50, 0, 0));
			 break;
		case 6:
			 objetsDisponibles.push_back(new Armes("Dague empoisonnée", "de", 70, 10, 5));
			 break;

		case 7:
			 objetsDisponibles.push_back(new Armures("Bouclier en acier", "ba", 55, 15, 0));
			 break;
		case 8:
			 objetsDisponibles.push_back(new Armes("Hache de guerre", "hw", 80, 20, 0));
			 break;
		case 9:
			 objetsDisponibles.push_back(new Armures("Armure lourde", "al", 90, 20, 10));
			 break;
		 default:
			 // Ne rien ajouter
			 break;
	 }
	}

	cout << "Voici ce que j'ai a vous proposer :" << endl;
	for (long unsigned int i = 0; i < objetsDisponibles.size(); i++) {
		cout << i << ": " << objetsDisponibles[i]->getNom()
			 << " (Prix: " << objetsDisponibles[i]->getPrix() << " pièces d'or)" << endl;
	}

	cout << "Quel objet souhaitez-vous acheter ? (entrez le numéro ou -1 pour quitter)" << endl;
	int choix;
	cin >> choix;

	if (choix == -1) {
		cout << "Vous quittez le magasin." << endl;
		return;
	}

	if (choix >= 0 && static_cast<long unsigned int>(choix) < objetsDisponibles.size()) {
		Equipement* objetChoisi = objetsDisponibles[choix];
		if (this->getArgent() >= objetChoisi->getPrix()) {
			this->setArgent(this->getArgent() - objetChoisi->getPrix());
			if (Consommables* c = dynamic_cast<Consommables*>(objetChoisi)) { //verifie si c'est un consommable
				this->addObjet(*c);
			}
			if (Armes* a = dynamic_cast<Armes*>(objetChoisi)) { //verifie si c'est une arme
				this->setArme(*a);
			}
			if (Armures* ar = dynamic_cast<Armures*>(objetChoisi)) { //verifie si c'est une armure
				this->setArmure(*ar);
			}

			cout << "Vous avez acheté " << objetChoisi->getNom() << " !" << endl;
		} else {
			cout << "Vous n'avez pas assez d'argent pour acheter cet objet." << endl;
		}
	} else if (choix != static_cast<int>(-1)) {
		cout << "Choix invalide." << endl;
	}

	cout << "Merci de votre visite !" << endl;
}



