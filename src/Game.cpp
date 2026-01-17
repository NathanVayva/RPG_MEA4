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
        this->ajouterMessage(this->hero->fullDescription());
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
    this->monstres.push_back(new ChauveSouris("ChauveSouris",1,6,2,6,30));
    this->monstres.push_back(new ChauveSouris("ChauveSouris",2,6,2,6,30));
}

Game::~Game() {
    // Destructeur
    this->carte.~Carte();
    this->monstres.clear();
    this->equipements.clear();
}

void Game::decorerCarte() {
    // Un nombre aléatoire de fois
    Creature* monstres = this->randMonstre();
    this->carte.placerElement(monstres,this->carte.getCoordLibre());
}

void Game::creerCarte() {
    // Crée une nouvelle carte pour le jeu
    this->carte = Carte(20, this->hero);
    this->niveau += 1;
}

void Game::ajouterMessage(const string& message) {
    this->messages.push_back(message);
}

void Game::lireMessages() {
    for (const string& message : this->messages) {
        cout << message << endl;
    }
    this->messages.clear();
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

void Game::jouer() {
    this->placerCoffreAleatoire();
    this->decorerCarte();
    cout << "Bienvenue " << this->hero->getNom() << " !" << endl;
    while (this->hero->getVie() > 0) {
        cout << this->carte.afficherCarte() << endl;
        this->hero->description();
        this->lireMessages();
        char c = _getch(); // Utilisation de _getch() pour capturer la touche appuyée sans appuyer sur Entrée
        while (this->actions.count(c) == 0) {
            c = _getch(); // Attendre une touche valide
        }
        if (this->actions.count(c) > 0) {
            this->actions[c](*this->hero); // Exécuter l'action associée
        }
        // Bouger tous les monstres vers le héros
        this->carte.deplacerTousLesMonstres();
    }
    cout << "Vous etes mort. Game Over." << endl;
}