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

    };

}

Game::~Game() {
    // Destructeur
    this->carte.~Carte();
    this->monstres.clear();
    this->equipements.clear();
}

void Game::creerCarte() {
    // Crée une nouvelle carte pour le jeu
    this->carte = Carte(20, this->hero);
    this->niveau += 1;
}

void Game::ajouterMessage(const string& message) {
    this->messages.push_back(message);
}

void Game::lireMessages() const {
    for (const string& message : this->messages) {
        cout << message << endl;
    }
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

Creature Game::randMonstre() const {
    // Retourne une copie d'un monstre aléatoire parmi ceux disponibles dans le dictionnaire
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, this->monstres.size() - 1);
    int index = dist(gen);
    return Creature(*(this->monstres[index])); // Retourne une copie
}

void Game::jouer() {
    cout << "Bienvenue héros !" << endl;
    while (this->hero->getVie() > 0) {
        this->carte.afficherCarte();
        this->hero->description();
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
    cout << "Vous êtes mort. Game Over." << endl;
}