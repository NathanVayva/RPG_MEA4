#include "Carte.hpp"
#include "utilitaire.hpp"

const map<char, Coordonnee> Carte::dir = {
    {'z', Coordonnee(0, -1)},
    {'s', Coordonnee(0, 1)},
    {'d', Coordonnee(1, 0)},
    {'q', Coordonnee(-1, 0)}
};

Carte::Carte(int size) {
    // Initialisation de la matrice et des pièces
    // Remplie la carte avec des caractères vides pour l'instant
    this->size = size;
    matrice = vector<vector<char>>(size,vector<char>(size, Carte::vide));
}

Carte::~Carte() {
    // Destructeur
    elements.clear();
}

void Carte::ajouterPiece(Piece p) {
    this->piecesArelier.push_back(p);
    for (int i=p.getC1().getY(); i<= p.getC2().getY(); i++) {
        for (int j=p.getC1().getX(); j<= p.getC2().getX(); j++) {
            matrice[i][j] = Carte::sol;
        }
    }
}

optional<Piece> Carte::trouverPiece(const Coordonnee& c) const {
    for (const Piece& p : this->piecesArelier) {
        if (p.contient(c)) {
            return p;
        }
    }
    return nullopt;
}

bool Carte::pasIntersection(const Piece& p) const {
    for (const Piece& piecesExistantes : this->piecesArelier) {
        if (p.intersection(piecesExistantes)) {
            return false; // Il y a une intersection
        }
    }
    return true; // Pas d'intersection
}

void Carte::creuser(const Coordonnee& c) {
    //Place une cellule sol aux coordonnées données.
    //Si les coordonnées correspondent à une pièce, considère la pièce comme atteinte.
    matrice[c.getY()][c.getX()] = Carte::sol;
    // Vérifier si la coordonnée appartient à une pièce
    // auto pour ne pas avoir d'erreur de type si pas de piece trouvée
    auto trouve = this->trouverPiece(c);
    if (trouve) {
        // Si pièce trouvée, on peut lui donner le type Piece
        Piece p = *trouve;
        // Passe de pièce à reliée à pièce
        this->pieces.push_back(p);
        // Sup
        this->piecesArelier.erase(
            remove(this->piecesArelier.begin(), this->piecesArelier.end(), p), // Déplace toutes les occurrences de p à la fin du vecteur
            this->piecesArelier.end()
        ); // erase(it,vector.end) supprime les éléments à partir de it jusqu'à la fin du vecteur
    }
}

void Carte::couloir(const Coordonnee& depart, const Coordonnee& arrivee) {
    // Creuse un couloir entre les coordonnées de départ et d'arrivée, d'abord verticalement puis horizontalement.
    Coordonnee d = arrivee - depart;
    Coordonnee curseur = depart;
    this->creuser(curseur);
    while (curseur.getY() != arrivee.getY()) {
        curseur = curseur + Coordonnee(0, sign(d.getY()));
        this->creuser(curseur);
    }
    while (curseur.getX() != arrivee.getX()) {
        curseur = curseur + Coordonnee(sign(d.getX()), 0);
        this->creuser(curseur);
    }
}

void Carte::atteindre() {
    // Creuse un couloir depuis le centre d'une pièce déjà atteinte jusqu'au centre de la pièce p.
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // roomA
    std::uniform_int_distribution<> distA(0, pieces.size() - 1);
    const Piece& pieceA = pieces[distA(gen)];

    // roomB
    std::uniform_int_distribution<> distB(0, piecesArelier.size() - 1);
    const Piece& pieceB = piecesArelier[distB(gen)];

    // Relier les deux pièces
    this->couloir(pieceA.centre(), pieceB.centre());
}

void Carte::atteindreToutesPieces() {
    // Commence en ajoutant une pièce dans la liste des pièces atteintes.
    this->pieces.push_back(piecesArelier.back());
    piecesArelier.pop_back();
    // Répète l'opération d'atteindre jusqu'à ce que toutes les pièces soient reliées.
    while (!piecesArelier.empty()) {
        this->atteindre();
    }
}

Piece Carte::randomPiece() const {
    random_device rd;
    mt19937 gen(rd());
    // Coordonnée 1 aléatoire
    uniform_int_distribution<> distC1(0, this->size - 3);
    int x1 = distC1(gen);
    int y1 = distC1(gen);
    Coordonnee c1(x1, y1);
    // Coordonnée 2 aléatoire
    uniform_int_distribution<> distSize(3, 8);
    int x2 = min(c1.getX() + distSize(gen), this->size - 1);
    int y2 = min(c1.getY() + distSize(gen), this->size - 1);
    Coordonnee c2(x2, y2);
    // Crée la pièce à partir des coordonnées
    return Piece(c1, c2);
}

void Carte::genererPiece(int nbPieces) {
    // Génère une pièce aléatoire qui n'intersecte pas avec les pièces existantes et l'ajoute aux pièces à relier.
    for (int i=0; i < nbPieces; i++) {
        Piece p = this->randomPiece();
        if (this->pasIntersection(p)) {
            this->ajouterPiece(p);
        }
    }
}

bool Carte::contient(const Coordonnee& c) const {
    // Vérifie si les coordonnées sont dans les limites de la carte.
    return (0 <= c.getX() && c.getX() < this->size && 0 <= c.getY() && c.getY() < this->size);
}

bool Carte::contient(const Element& e) const {
    return this->elements.count(e);
}

string Carte::afficherCarte() const {
    string s = "";
    for (const auto& row : this->matrice) {
        for (char c : row) {
            s += c; // char à string
        }
        s += '\n';
    }
    return s;
}

void Carte::placerElement(const Element& e, const Coordonnee& c) {
    if (this->contient(c) ) {
        if (this->matrice[c.getY()][c.getX()] != Carte::sol) {
            throw invalid_argument("Cette case contient déjà un élément");
        }
        if (this->elements.count(e)) {
            throw invalid_argument("Element déjà présent sur la carte");
        this->matrice[c.getY()][c.getX()] = e.getAbbreviation();
        this->elements[e] = c; // Ajoute l'élément à la carte
        }
    }
}

optional<Element> Carte::getElementAt(const Coordonnee& c) const {
    if (!this->contient(c)) {
        throw out_of_range("Coordonnée hors de la carte");
    }
    char abbr = this->matrice[c.getY()][c.getX()];
    if (abbr == Carte::sol) {
        return nullopt; // Pas d'élément à cette position
    }
    else {
        for (const auto& pair : this->elements) {
            if (pair.first.getAbbreviation() == abbr) {
                return pair.first; // Retourne l'élément trouvé
            }
        } 
    }
}

Coordonnee Carte::getPosition(const Element& e) const {
    auto it = this->elements.find(e);
    if (it != this->elements.end()) {
        return it->second; // Retourne la coordonnée associée à l'élément
    } else {
        throw invalid_argument("Element non trouvé sur la carte");
    }
}

void Carte::enleverElement(const Coordonnee& c) {
    optional<Element> elemOpt = this->getElementAt(c);
    if (elemOpt) {
        Element elem = *elemOpt;
        this->elements.erase(elem); // Supprime l'élément de la carte
        this->matrice[c.getY()][c.getX()] = Carte::sol; // Remet la case à sol
    } else {
        throw invalid_argument("Aucun élément à cette position");
    }
}

void Carte::deplacement(const Element& e, const Coordonnee& direction) {
    Coordonnee nouvellePos = this->getPosition(e) + direction;
    if (!this->contient(nouvellePos)) {
        throw out_of_range("Nouvelle position hors de la carte");
    }
    if (this->matrice[nouvellePos.getY()][nouvellePos.getX()] != Carte::sol) {
        // Prevoir d'ajouter la fonction combat
        throw invalid_argument("La nouvelle position est déjà occupée");
    }
    Coordonnee anciennePos = this->getPosition(e);
    // Met à jour la matrice
    this->matrice[anciennePos.getY()][anciennePos.getX()] = Carte::sol;
    this->matrice[nouvellePos.getY()][nouvellePos.getX()] = e.getAbbreviation();
    // Met à jour la position dans la map
    this->elements[e] = nouvellePos;
}

void Carte::deplacerTousLesMonstres() {
    // Déplace tous les monstres qui ont d'une distance de moins de 6 cases de l'élément joueur
    for (const auto& pair : this->elements) {
        const Element& e = pair.first;
        Coordonnee posActuelle = pair.second;
        // Génère une direction aléatoire parmi les directions possibles
        // if distance hero < 6 
    }
}