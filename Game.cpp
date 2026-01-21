#include "Game.hpp"

Game::Game(Personnage* hero) : carte(20, hero) {
    this->niveau = 1;
    this->hero = hero;
    this->messages.clear();

    // Initialisation des monstres et équipements disponibles
    
    // Initialisation des actions
    actions['z'] = [this](Personnage& hero) {
        // Déplacer vers le haut
        this->carte.deplacement(&hero, Coordonnee(0, -1));
    };

    actions['s'] = [this](Personnage& hero) {
        // Déplacer vers le bas
        this->carte.deplacement(&hero, Coordonnee(0, 1));
    };

    actions['d'] = [this](Personnage& hero) {
        // Déplacer vers la droite
        this->carte.deplacement(&hero, Coordonnee(1, 0));
    };

    actions['q'] = [this](Personnage& hero) {
        // Déplacer vers la gauche
        this->carte.deplacement(&hero, Coordonnee(-1, 0));
    };

    actions['i'] = [this](Personnage& hero) {
        // Affichage fullDescription du personnage
        this->printMessage(this->hero->fullDescription());
    };

    actions['k'] = [this](Personnage& hero) {
        // Arrête le jeu
        this->hero->setVie(0);
    };

    // Equipements disponibles
    this->equipements.push_back(new Armes("Epée de feu", 'e', 1, 100, 15, 5));
    this->equipements.push_back(new Armures("Armure de glace", 'a', 1, 120, 5, 15));
    this->equipements.push_back(new Armes("Bâton magique", 'b', 1, 120, 5, 20));
    this->equipements.push_back(new Armures("Bouclier robuste", 'o', 1, 80, 8, 5));
    this->equipements.push_back(new Consommables("Potion de soin", 's', 1, 20, 15, 0, 0, 0, 0));
    this->equipements.push_back(new Consommables("Elixir de mana", 'm', 1, 25, 0, 0, 10, 0, 0));
    this->equipements.push_back(new Consommables("Potion de force", 'g', 1, 30, 0, 15, 0, 0, 0));
    this->equipements.push_back(new Consommables("Potion de résistance", 'r', 1, 35, 0, 0, 0, 10, 10));

    // Monstres disponibles
    this->monstres.push_back(new ChauveSouris("ChauveSouris",6,2,6,30));
}

Game::~Game() {
    // Destructeur
    this->carte.~Carte();
    for (Creature* ennemi : this->monstres) {
        delete ennemi;
    }
    this->monstres.clear();
    this->equipements.clear();
}

void Game::decorerCarte() {
    // Place n monstres sur la carte
    // Nb monstre aléatoire
    random_device rd;
    mt19937 gen(rd());
    // Correction nb monstres max
    int max = this->niveau + 3;
    if (max > this->carte.getMatriceSize() - 2) {
        // Plus de monstres que de cases libres
        max = this->carte.getMatriceSize() - 2;
    }
    uniform_int_distribution<> dist(this->niveau, max);
    int nbMonstre = dist(gen);
    // Place les monstres à un endroit aléatoire
    for (int i=0; i < nbMonstre; i++) {
        Creature* monstres = this->randMonstre();
        this->carte.placerElement(monstres,this->carte.getCoordLibre());
        this->carte.setEnnemisRestants(this->carte.getEnnemisRestants() + 1);
    }
}

void Game::creerCarte() {
    // Crée une nouvelle carte pour le jeu
    this->carte = Carte(20, this->hero);
    this->niveau += 1;
}

void Game::printMessage(string message) const {
    cout << message << endl;
}

Equipement Game::randEquipement() const {
    // Retourne une copie d'un équipement aléatoire parmi ceux disponibles dans le dictionnaire
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, this->equipements.size() - 1);
    int index = dist(gen);
    return Equipement(*(this->equipements[index])); // Retourne une copie
}

void Game::placerCoffreAleatoire() {
    // Place un coffre contenant un équipement aléatoire au centre d'une pièce aléatoire
    Equipement objet = this->randEquipement(); // Obtenir un équipement aléatoire
    Piece piece = this->carte.randomPieceExistante(); // Obtenir une pièce aléatoire
    Coordonnee centre = piece.centre(); // Obtenir le centre de la pièce
    // On vérifie que le centre n'est pas déjà occupé
    while (this->carte.getElementAt(centre).has_value() || this->carte.getCreatureAt(centre).has_value()) {
        // Si le centre est déjà occupé, choisir une nouvelle pièce
        piece = this->carte.randomPieceExistante();
        centre = piece.centre();
    }
    // Construction du coffre
    Coffre* tresor = new Coffre("Coffre", 'c', &objet);
    this->carte.placerElement(tresor, centre);
}

Creature* Game::randMonstre() const {
    // Retourne une copie d'un monstre aléatoire parmi ceux disponibles dans le dictionnaire
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, this->monstres.size() - 1);
    int index = dist(gen);
    return new Creature(*monstres[index]); // Retourne une copie
}

bool Game::tour() {
    bool tourFini = false;
    char c = _getch();
    while (this->actions.count(c) == 0) {
        c = _getch();
    }
    if (c == 'z' || c == 'q' || c == 'd' || c == 's' || c == 'k') {
        tourFini = true;
    }
    this->actions[c](*this->hero); // Exécuter l'action associée
    return tourFini;
}

void Game::jouer() {
    this->placerCoffreAleatoire();
    this->decorerCarte();
    cout << "Bienvenue " << this->hero->getNom() << " !" << endl;
    while (this->hero->getVie() > 0) {
        cout << this->carte.afficherCarte() << endl;
        this->hero->description();
        // Tour hero
        bool tourFini = false;
        while (tourFini == false) {
            tourFini = this->tour();
        }
        // Bouger tous les monstres vers le héros
        this->carte.deplacerTousLesMonstres();

        // Change de niveau si tous les monstres sont morts
        // marche pas encore
        if (this->carte.getEnnemisRestants() == 0) {
            this->niveau += 1;
            // On détruit la carte actuelle et on en refait une
            this->carte.clearPieces();
            this->carte.clearMatrice();
            // Ajoute des pièces à la carte
            this->carte.genererPiece(10);
            while (this->carte.getPiecesArelier().size() < 2) {
                this->carte.genererPiece(1);
            }
            this->carte.atteindreToutesPieces();
            this->carte.initHeroCarte(this->hero);
            this->decorerCarte();
            this->placerCoffreAleatoire();
            cout << endl << endl;
            cout << "Bien joue hero ! Tous les monstres ont ete elimines !" << endl;
            cout << "Bienvenu au niveau superieur : niveau " << this->niveau << endl;
            cout << endl;
        }
    }
}